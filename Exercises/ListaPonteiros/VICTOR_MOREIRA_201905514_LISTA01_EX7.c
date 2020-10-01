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

    printf("\n\nA: %d \nB: %d", var1,var2);

    printf("\n\nAFTER:");

    function(var_1, var_2);

    printf("\n\nA: %d \nB: %d\n", var1,var2);
}

void function(int *var1, int *var2){

    *var1 = *var1 + *var2;

}
