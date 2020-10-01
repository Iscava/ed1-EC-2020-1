#include <stdio.h>

main(){

	int inteiro = 10, *inteiroP;
	float real = 10.5, *realP;
	char c = 'c', *cP;

	inteiroP = &inteiro;
	realP = &real;
	cP = &c;

	printf("Conteudo do ponteiro inteiro: %d", *inteiroP);
	printf("\nConteudo do ponteiro real: %f", *realP);
	printf("\nConteudo do ponteiro char: %c", *cP);

	*inteiroP = 20;
	*realP = 20.5;
	*cP = 'd';

	printf("\n\nConteudo do ponteiro inteiro: %d", *inteiroP);
	printf("\nConteudo do ponteiro real: %f", *realP);
	printf("\nConteudo do ponteiro char: %c", *cP);

}
