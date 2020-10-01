#include <stdio.h>

main(){

    int var1, var2;

    printf("A: ");
    scanf("%d", &var1);
    printf("\nB: ");
    scanf("%d", &var2);

    int *var_1 = &var1;
    int *var_2 = &var2;

    printf("\nBEFORE:");

    printf("\n\nVar 1: %d \nVar 2: %d", var1,var2);

    printf("\n\nAFTER:");

    function(var_1, var_2);

}

int function(int *var1, int *var2){

    int x;

    *var1 = *var1 * 2;
    *var2 = *var2 * 2;

    x = *var1 + *var2;

    return printf("\n\nA: %d \nB: %d\nSoma: %d\n", *var1,*var2, x);

}


