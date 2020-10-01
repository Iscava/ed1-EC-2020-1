#include <stdio.h>

main(){

    int n1, n2;

    printf("Digite a quantidade de valores da lista 1: ");
    scanf("%d", &n1);

    printf("Digite a quantidade de valores da lista 2: ");
    scanf("%d", &n2);

    int array1[n1];
    int array2[n2];

    int *p1 = array1, *p2 = array2;

    printf("\nLista 1:\n");

    for(int i = 0; i<n1; i++){
        printf("Digite o valor %d: ", i+1);
        scanf("%d", (p1+i));
    }

    printf("\nLista 2:\n");

    for(int i = 0; i<n2; i++){
        printf("Digite o valor %d: ", i+1);
        scanf("%d", (p2+i));
    }

    function(p1,p2, n1, n2);

}

int function(int *p1, int *p2, int n1, int n2){

    if(n1==n2){

        int arraySoma[n1];
        printf("\n");
        for(int i = 0; i<n1; i++){
            arraySoma[i] = *(p1+i) + *(p2+i);
            printf("Soma valor 1: %d\n", arraySoma[i]);
        }

        return 1;
    }else{
        return 0;
    }

}
