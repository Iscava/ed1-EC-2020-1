#include <stdio.h>

main(){

    float matriz[3][3];

    float *p = matriz;

        for(int i = 0; i<9; i++){

        *(p+i) = i;
    }

    for(int i = 0; i<9; i++){
        printf("%p\n", p+i);
        printf("%.2f\n", *(p+i));
    }

}
