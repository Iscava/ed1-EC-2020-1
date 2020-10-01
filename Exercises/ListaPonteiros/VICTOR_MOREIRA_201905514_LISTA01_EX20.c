#include <stdio.h>

main(){

    int n;

    printf("Digite a quantidade de valores: ");
    scanf("%d", &n);

    float array[n];
    float *p = array;

    negativos(p, n);



}

int negativos(float *vet, int N){

    int nums=0;

    for(int i = 0; i<N; i++){
        printf("Digite o valor %d: ", i+1);
        scanf("%f", (vet+i));
    }

    for(int i = 0; i<N; i++){
        if((*(vet+i))<0){
            nums++;
        }
    }
    return printf("\nExistem %d numeros negativos.\n", nums);
}
