#include <stdio.h>

main(){

    int n, k;

    printf("Digite a quantidade de valores da lista: ");
    scanf("%d", &n);

    int array[n];

    int *p = array;

    printf("\nLista:\n");

    for(int i = 0; i<n; i++){
        printf("Digite o valor %d: ", i+1);
        scanf("%d", (p+i));
    }

    printf("\nDigite a quantidade de valores por linha: ");
    scanf("%d", &k);
    printf("\n");
    function(p,n,k);
}

int function(int *p, int n, int k){

    int t=0,atual;
    atual = *(p);
    for(int i=0; i<n; i++){
        printf("%d   ", *(p+i));

        if(*(p+i)>atual){
            atual = *(p+i);
        }

        t++;
        if(t==k){
            printf("\n\n");
            t=0;
        }
    }

    return printf("Maior valor: %d\n", atual);
}
