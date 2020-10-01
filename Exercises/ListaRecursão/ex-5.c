#include <stdio.h>

typedef struct{
    int q;
    int v;
} dinheiro;

int soma(dinheiro notas[], int contador, int saque){

    if (saque == 0){
        return 1;
    }
    if (saque < 0){
        return 0;
    }
    if (contador < 0){
        return 0;
    }
    int esquerda, direita;
    if (notas[contador].q <= 0){
        esquerda = 0;
    }
    else{
        notas[contador].q--;
        esquerda = soma(notas, contador, saque - notas[contador].v);
        notas[contador].q++;
    }
    direita = soma(notas, contador - 1, saque);
    return esquerda + direita;
}

int main(void){
    int t, x;
    dinheiro n[6];

    scanf("%d", &t);

    for (x = 0; x < 6; x++){
        scanf("%d", &n[x].q);
    }
    for (x = 0; x < 6; x++){
        if (x == 0) n[x].v = 2;
        else if (x == 1) n[x].v = 5;
        else if (x == 2) n[x].v = 10;
        else if (x == 3) n[x].v = 20;
        else if (x == 4) n[x].v = 50;
        else if (x == 5) n[x].v = 100;
    }
    printf("%d\n", soma(n, 5, t));
    return 0;
}
