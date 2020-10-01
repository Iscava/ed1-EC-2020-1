#include <stdio.h>

main(){

    int array[5];
    int *p;

    p = array;

    for(int i = 0; i<5; i++){
        *(p+i) = i;
        *(p+i) += 1;

    }

    for(int i = 0; i<5; i++){

        printf("%d\n",*(p+i));

    }
}
