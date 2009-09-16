/*
    $RCSFile$ $Revision: 1.3 $
*/

char mod_alteracao_rcsid[] = "$Id: mod_alteracao.c 6 2006-09-10 15:35:16Z marcus $";

#include "db.h"

int mod_alteracao (void)
{
    char cod_prod[COD_PROD];
    struct estoque item_alter;
    int result;

    cls();
    log("Altera��o");

    printf("Controle de Estoque\n");
    printf("-------------------\n");

    printf("\n\n");
    printf("   Altera��o \n");
    printf("   ========= \n");

    printf("\n\n");

    printf("       Digite o c�digo de produto: ");
    scanf("%s", &cod_prod);

    result = select(&item_alter, &cod_prod);

    printf("\n\n");

    if (result==0) {
        printf("    Produto n�o encontrado.\n\n");

        printf("\n\n");

        pause();
        log("Fim da Inser��o");
        return 1;

    }

    printf(" Digite as informa��es\n");
    printf(" ---------------------\n");
    printf("    Produto [%s]: ",item_alter.desc_prod); scan( &item_alter.desc_prod);
    printf("      Pre�o [%.2f]: ",item_alter.vlr_prod);scanf("%f" , &item_alter.vlr_prod);
    printf("    Estoque [%d]: ",item_alter.qtd_est  ); scanf("%d" , &item_alter.qtd_est);
    printf(" Qtd.Minima [%d]: ",item_alter.qtd_min  ); scanf("%d" , &item_alter.qtd_min);

    printf("\n\n");

    // Grava modifica��es
    //printf("Rec_id: %d \n",item_alter.rec_id);
    update(&item_alter);
    log("Registro alterado.");

    pause();
    log("Fim da Atualiza��o");

    return 0 ;
}
