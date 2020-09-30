#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Element{
	int ligacoes;
	char nome[20], tel[10];
	struct Element * prox;
};

typedef struct Element element;

element * lista_inicia();
void lista_liga(element * LISTA, char * nome);
void lista_insere(element * LISTA, const char * nome, const char * numero, int qnt);
void lista_remove(element * LISTA, char * nome);
void lista_imprime(element * LISTA);
element * atPos(element * LISTA, int index);
void node_swipe(element * LISTA, element * nodeA, element * nodeB);
int indexOf(element * LISTA, element * Node);
void lista_ordena(element * LISTA);

element * lista_inicia(){
	element * LISTA = (element*)malloc(sizeof(element));
	if(!LISTA){
		printf("Não alocada!\n");
		exit(1);
	}
	LISTA->prox = NULL;
	return LISTA;
}

void lista_liga(element * LISTA, char * nome){
	element * percorre = LISTA->prox;
	while(percorre!=NULL){
		if(strcmp(percorre->nome, nome) == 0){
			percorre->ligacoes++;
			break;
		}
		percorre = percorre->prox;
	}
}

void lista_insere(element * LISTA, const char * nome, const char * numero, int qnt){
	element * percorre = LISTA;
	element * novo = lista_inicia();

	while(percorre->prox != NULL) percorre = percorre->prox;

	percorre->prox = novo;
	memcpy(novo->nome, nome, strlen(nome)+1);
	memcpy(novo->tel, numero, strlen(numero)+1);
	novo->ligacoes = qnt;
}

void lista_remove(element * LISTA, char * nome){
	element * atual = LISTA->prox;
	element * anterior = LISTA;

	while(atual!=NULL){
		if(strcmp(atual->nome, nome)==0){
			anterior->prox = atual->prox;
			free(atual);
			break;
		}
		anterior = atual;
		atual = atual -> prox;
	}
}

void lista_imprime(element * LISTA){
	element * percorre = LISTA->prox;

	while(percorre!=NULL){
		printf("%s - %s %d\n", percorre->nome, percorre->tel,percorre->ligacoes);
		percorre = percorre->prox;
	}
}

int lista_size(element * LISTA){
	int c=0;
	while(LISTA->prox!=NULL){
		LISTA = LISTA->prox;
		c++;
	}
	return c;
}

element * atPos(element * LISTA, int index){
	int c= 0;
	element * percorre = LISTA;

	while(percorre!=NULL){
		if(c==index){
			return percorre;
		}
		percorre = percorre-> prox;
		c++;
	}
}

int indexOf(element * LISTA, element * Node){
	int c=0;
	while(LISTA != NULL){
		if(LISTA == Node) return c;
		LISTA = LISTA->prox;
		c++;
	}
}

void node_swipe(element * LISTA, element * nodeA, element * nodeB){
	if(nodeA == nodeB) return;
	int indexA = indexOf(LISTA, nodeA); 
	int indexB = indexOf(LISTA, nodeB); 
	element * pa = atPos(LISTA, indexA-1); 
	element * pb = atPos(LISTA, indexB-1);
	pa->prox = nodeB; 
	pb->prox = nodeA; 
	element * aux = nodeA->prox; 
	nodeA->prox = nodeB->prox; 
	nodeB->prox = aux; 
}

void lista_ordena(element * LISTA){
	int i, j;
	int size = lista_size(LISTA);

	for(i = 0 ; i < size-1; i++){
		for(j = 0 ; j < size -i -1 ; j++){
			element * nodeJ = atPos(LISTA, j+2);
			element * nodeI = atPos(LISTA, j+1);
			if(nodeI->ligacoes < nodeJ->ligacoes){
				node_swipe(LISTA, nodeI, nodeJ);
			}
		}	
	}

}


int main(){
	element * LISTA = lista_inicia();
	lista_insere(LISTA, (char *)"Hermanoteu", (char *)"4523-2248", 300);
	lista_insere(LISTA, (char *)"Ooloneia", (char *)"4523-4887", 299);

	while(1){
		char op;
		char nome[20], tel[10];
		int qntLigacoes;

		scanf("%c", &op);
		if(op == 'F'){
			lista_ordena(LISTA);
			lista_imprime(LISTA);
			return 0;	
		} 
		else if(op == 'L'){
			scanf(" %s", nome);
			lista_liga(LISTA, nome);
		}
		else if(op == 'I'){
			scanf(" %s", nome);
			scanf(" %s", tel);
			scanf(" %d", &qntLigacoes);
			lista_insere(LISTA, nome, tel, qntLigacoes);
		}
		else if(op == 'R'){
			scanf("%s", nome);
			lista_remove(LISTA, nome);
		}
	}


}