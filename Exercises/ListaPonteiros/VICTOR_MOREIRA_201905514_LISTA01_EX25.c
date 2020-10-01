#include <stdio.h>

main(){

 int n1, n2;
 int *pn1 = &n1, *pn2 = &n2;

 function(pn1,pn2);

}

int function(int *n1, int *n2){


    printf("Digite a nota 1: ");
    scanf("%d", n1);
    printf("Digite a nota 2: ");
    scanf("%d", n2);

    return printf("\nMedia simples: %d\nMedia ponderada: %d\n", (*n2+*n1)/2,(*n1+(*n2*2))/3);

}
