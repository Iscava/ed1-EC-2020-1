#include <stdio.h>

main(){

    float array[10];

    float *p = array;

    for(int i = 0; i<10; i++){
        *(p+i) = i;
    }

    for(int i = 0; i<10; i++){
        printf("%p\n", p+i);
        printf("%f\n", *(p+i));
    }

}
