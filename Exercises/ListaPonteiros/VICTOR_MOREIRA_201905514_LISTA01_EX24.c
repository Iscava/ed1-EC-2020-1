#include <stdio.h>

main(){

    int n,a=0,b=0;
    int *min=&a, *max=&b;

    printf("Digite a quantidade de valores da lista: ");
    scanf("%d", &n);

    int array[n];

    int *p = array;

    for(int i=0;i<n; i++){
        printf("Valor %d: ", i+1);
        scanf("%d", (p+i));
    }

    *min = *array;
    *max = *array;

    function(p,min, max, n);
}

int function(int *vet, int *min, int *max, int n){

    for(int i = 0; i < n; i++){
        if(*max<*(vet+i)){
            *max = *(vet+i);
        }
        if(*min>*(vet+i)){
            *min = *(vet+i);
        }

    }
    return printf("\n\nMenor valor: %d\nMaior valor: %d", *min, *max);
}
