#! /usr/bin/env perl
# Copyright 2016 The OpenSSL Project Authors. All Rights Reserved.
#
# Licensed under the OpenSSL license (the "License").  You may not use
# this file except in compliance with the License.  You can obtain a copy
# in the file LICENSE in the source distribution or at
# https://www.openssl.org/source/license.html

# Add new copyright and delete old ones.  Used as
#   find . -name '*.[ch]' -type f -exec perl -i.bak util/copyright.pl '{}' ';'
# This does not do everything that's needed for the consolidation.

use strict;
use warnings;

my %mapping;
open(my $mapping_file, "<", "util/mapping.txt") or die;
while (my $line = <$mapping_file>) {
    chomp($line);
    $line =~ s/#.*//;
    next if $line =~ /^$/;

    my ($path, $mapped) = split(/:/, $line, 2);
    $mapped =~ s/^ +//;
    $mapped =~ s/ +$//;
    my @mapped = split(/ +/, $mapped);
    $mapping{$path} = \@mapped;
}
close($mapping_file) or die;

sub find_copyright_line($)
{
    my ($path) = @_;
    my $mapped = $mapping{$path};
    die "No mapping for $path found!" unless $mapped && @$mapped;
    my $ret = find_mapped_copyright_line($mapped->[0]);
    foreach my $m (@$mapped) {
        my $other = find_mapped_copyright_line($m);
        die "Copyright lines in $mapped->[0] and $m did not match" unless $other eq $ret;
    }
    return $ret;
}

sub find_mapped_copyright_line($)
{
    my ($path) = @_;
    open(my $f, "<", "../openssl/$path") or die;
    while (my $line = <$f>) {
        chomp($line);
        if ($line =~ /^ \* Copyright [-0-9]+ The OpenSSL Project Authors\. All Rights Reserved\.$/) {
            close($f) or die;
            return $line;
        }
    }
    die "Could not find copyright line in ../openssl/$path";
}

# Read a multi-line comments.  If it matches a "fingerprint" of a legacy
# copyright block, then just delete it.
sub check_comment()
{
    my @lines = ( @_ );
    my $skipit = 0;

    if ($lines[$#lines] !~ m@\*/@) {
        while ( <> ) {
            push @lines, $_;
            last if m@\*/@;
            $skipit = 1 if /Copyright remains Eric Young's/i;
            $skipit = 1 if /Copyright.*The OpenSSL Project/i;
            $skipit = 1 if /Written by.*for the OpenSSL Project/i;
        }
    }

    # Look for a multi-line "written by" comment.
    if ( ! $skipit ) {
        my $text = join('', @lines);
        $skipit = 1 if $text =~ m/Written by.*for the OpenSSL Project/is;
    }

    print @lines unless $skipit;
    return $skipit;
}

# Look for leading copyright blocks and process (print/swallow) them.
while ( <> ) {
    if ($. == 1) {
        my $copyright_line = find_copyright_line($ARGV);
        print <<EOF;
/*
$copyright_line
 *
 * Licensed under the OpenSSL license (the "License").  You may not use
 * this file except in compliance with the License.  You can obtain a copy
 * in the file LICENSE in the source distribution or at
 * https://www.openssl.org/source/license.html
 */

EOF
    }
    next if m@^$@;
    last if not m@/\*@;
    last unless &check_comment($_);
}

if (defined($_)) {
    print unless m@\*/@;

    # Print rest of file.
    print while ( <> );
}
