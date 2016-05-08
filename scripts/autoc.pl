#! /usr/bin/perl

use strict;
use warnings;

use JSON;
use Data::Dumper;

my $filename = $ARGV[0];
my $outdir = $ARGV[1];
my $dump = 0;

my $json_text = do {
    open(my $json_fh, "<:encoding(UTF-8)", $filename)
         or die("Can't open \$filename\": $!\n");
    local $/;
    <$json_fh>
};

my $json = JSON->new;
my $data = $json->decode($json_text);

print $data, "\n" if $dump;
print Dumper($data) if $dump;

while (my ($op, $insn) =  each $data) {
    open my $ofh, '>', $outdir.'/'.$op.'.c'
        or die "can't open output file: $!";

    my $c = "";

    $c .= << "EOM";
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
EOM

    for (@{$insn}) {
        $c .= << "EOM"
    asm ("$_");
EOM
    }

    $c .= << "EOM";
    return 0;
}
EOM

    print $ofh $c;
    close $ofh;
}
