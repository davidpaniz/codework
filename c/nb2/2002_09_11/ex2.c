/*
   Marcus Vinicius Ferreira
   CCO-NB2 02127044
   11/Set/2002

   ex2.c

   Multiplica��o de 2 n�meros via fun��o
   Retorna 2 valores (ponteiro modificam valores in situ)

*/

#include <stdio.h>

/* OBS: Implementando fun��es K&R */
m2( x, y )
   int *x;
   int *y;
{
    *x = *x * 2;
    *y = *y * 2;
}

int main()
{
    int x,y,z;

    /* Entrada dos valores
    */
    printf("Entre com o valor de x: ");
    scanf("%d", &x);

    printf("Entre com o valor de y: ");
    scanf("%d", &y);

    /* Multiplica os 2 n�meros usando a fun��o
       (usando &<variavel> os valores ser�o modificados in situ)
    */
    m2( &x, &y);

    /* Resultado */
    printf("\n   Resultados:");
    printf("\n       x = %d ",x);
    printf("\n       y = %d \n\n",y);

    return 0;
}