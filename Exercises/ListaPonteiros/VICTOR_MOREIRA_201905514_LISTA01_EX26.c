#include <stdio.h>
#include <math.h>

int raizes(float A,float B,float C,float *X1,float *X2);
float raizq(float n);

main(){

float A,B,C,x1,x2;

while(1){

printf("Digite o coeficiente A da equacao de segundo grau: ");
scanf("%f", &A);
if(A!=0){
    break;
}
printf("\nA variavel A tem que ser diferente de zero.\n\n");

}
printf("\nDigite o coeficiente B da equacao de segundo grau: ");
scanf("%f", &B);
printf("\nDigite o coeficiente C da equacao de segundo grau: ");
scanf("%f", &C);

float *X1 = &x1, *X2 = &x2;

raizes(A,B,C,X1,X2);

}


int raizes(float A,float B,float C,float *X1,float *X2){

    float delta;

    delta = (B*B)-(4*A*C);

    *X1 = ((-B) + (sqrt(delta)))/(2*A);

    *X2 = ((B * -1) - (sqrt(delta)))/(2*A);

    if(delta < 0){

        printf("\nNao tem raizes reais!");

    }else if(delta == 0){

        printf("\nAs duas raizes sao reais e iguais: %.2f", *X1);

    }else if(delta > 0){

        printf("\nExistem duas raizes reais.\n");

        printf("As raizes sao diferentes: %.2f e %.2f", *X1,*X2);

    }


return 0;
}

