#include <stdio.h>

main(){

    int var1, var2;

    printf("Var1: ");
    scanf("%d", &var1);
    printf("\nVar2: ");
    scanf("%d", &var2);

    int *var_1, *var_2;

    var_1 = &var1;
    var_2 = &var2;

    printf("\nValor 1: %p - %d \nValor 2: %p - %d", var_1,var1,var_2,var2);

    if(var_1 > var_2){
        printf("\n\nEndereco do valor 1 (%d) eh maior.\n", var1);
    }else{
        printf("\n\nEndereco do valor 2 (%d) eh maior.\n", var2);
    }
}
