

## Problem:
$a="//GMDB_Customiza��es/Padr�o%20de%20Constru��o/Documentos/";
$i=0;
while( $i<=length($a) ) {
    $c=substr($a,$i,1); $i++;
    printf "%s   %03d   %x   \n", $c, ord($c), ord($c);
}

## to try:
    $hexdigit = (0 .. 9, 'a' .. 'f')[$num & 15];

