#include <stdio.h>

main(){

    int var1, var2;
    int *var_1, *var_2;

    var_1 = &var1;
    var_2 = &var2;

    printf("Valor 1: %p \nValor 2: %p", var_1, var_2);

    if(var_1 > var_2){
        printf("\n\nValor 1 eh maior.");
    }else{
        printf("\n\nValor 2 eh maior.");
    }

}
