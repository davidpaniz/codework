#!/usr/bin/perl
# $Id$
# Marcus Vinicius Ferreira    ferreira.mv[ at ]gmail.com
# Set/2006
#

use strict;

my ($new,$old);

while ( <> ) {

    chomp;
    $old = $_;
    tr /���������������� /aaaaeeeoooouuunc_/;
    tr /���������������� /AAAAEEEOOOOUUUNC_/;
    $new = $_;

    if($new eq $old) {
        print "File: keeping $old\n";
    }
    else {
        print "File: rename  $old \t $new\n";
        rename $old, $new ;
    };
};
