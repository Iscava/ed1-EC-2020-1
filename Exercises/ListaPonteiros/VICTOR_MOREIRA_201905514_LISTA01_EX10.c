
#include <stdio.h>

main(){

    int array[5];

    int *p = array;

    for(int i = 0; i<5; i++){
        printf("Digite o valor %d: ", i+1);
        scanf("%d", (p+i));
        printf("\n");
    }
    printf("O dobro dos valores: \n");
    for(int i = 0; i<5; i++){
        printf("\nValor %d: %d\n", i+1,*(p+i)*2);
    }

}
