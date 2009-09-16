/*
    $RCSFile$ $Revision: 1.3 $
*/

char menu_rcsid[] = "$Id: mod_menu.c 6 2006-09-10 15:35:16Z marcus $";
char mod_menu_id[]= "@(#) Carlos Ide";

#define VLINES 30

void cls(void)
{
    int i;
    for ( i=0; i<=VLINES; ++i )
        printf ("\n");
}


int mod_menu (void)
{
    char opt;

    cls();
    log("Menu");

    printf("Controle de Estoque\n");
    printf("-------------------\n");

    printf("\n\n");
    printf("   Menu \n");
    printf("   ==== \n");

    printf("\n\n");
    printf("       1) Consulta de item\n");
    printf("       2) Inser��o de um novo item\n");
    printf("       3) Altera��o de item \n");
    printf("       4) Exclus�o \n");
    printf("       5) Atualiza��o de estoque \n");
    printf("       6) Relat�rio \n");
    printf("       7) Consolida��o de arquivo \n");
    printf("       8) Ajuda \n");
    printf("       9) Fim \n");

    printf("\n\n");

    printf("\nEscolha sua op��o: ");

    do {
        opt = getchar();
    } while ( opt<'1' || opt>'9' );

    log("Fim do Menu.");

    return( opt-'0' ) ;
}
