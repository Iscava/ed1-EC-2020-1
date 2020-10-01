#include <stdio.h>

main(){

    int var1, var2;

    printf("Valor: ");
    scanf("%d", &var1);
    printf("\nValor: ");
    scanf("%d", &var2);

    int *var_1 = &var1;
    int *var_2 = &var2;

    printf("\nBEFORE:");

    printf("\n\nVar 1: %d \nVar 2: %d", var1,var2);

    printf("\n\nAFTER:");

    function(var_1, var_2);

}

int function(int *var1, int *var2){


    if(*var1 > *var2){

    return printf("\n\nVar 1: %d \nVar 2: %d\n", *var1,*var2);

    }else{

        int x;

    x = *var1;

    *var1 = *var2;
    *var2 = x;

    return printf("\n\nVar 1: %d \nVar 2: %d\n", *var1,*var2);

    }

}
