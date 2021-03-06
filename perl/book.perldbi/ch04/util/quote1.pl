#!/usr/bin/perl -w
#
# ch04/util/quote1: Demonstrates the use of the $dbh->quote() method

use DBI;

### The string to quote
my $string = "Don't view in monochrome (it looks 'fuzzy')!";

### Connect to the database
my $dbh = DBI->connect( undef, undef, undef, {
    RaiseError => 1
} );

### Escape the string quotes...
my $quotedString = $dbh->quote( $string );

### Use quoted string as a string literal in a SQL statement
my $sth = $dbh->prepare( "
        SELECT *
        FROM media
        WHERE description = $quotedString
      " );
$sth->execute();

exit;
