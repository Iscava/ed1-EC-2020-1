#include <stdio.h>

main(){

    int var1, var2;

    printf("Var1: ");
    scanf("%d", &var1);
    printf("\nVar2: ");
    scanf("%d", &var2);

    int *var_1 = &var1;
    int *var_2 = &var2;

    printf("\n\nValor 1: %p - %d \nValor 2: %p - %d", var_1,var1,var_2,var2);

    function(var_1, var_2);

    printf("\n\nValor 1: %p - %d \nValor 2: %p - %d", var_1,var1,var_2,var2);

}

void function(int *var1, int *var2){

    int x;

    x = *var1;

    *var1 = *var2;
    *var2 = x;

}
