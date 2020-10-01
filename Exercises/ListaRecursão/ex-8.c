#include <stdio.h>

void hanoi(int x, char orig, char dest, char aux){

	if (x == 1){
		printf("\n(%c,%c)", orig, dest);
	}
	else{
		hanoi(x - 1, orig, aux, dest);
		printf("\n(%c,%c)", orig, dest);
		hanoi(x - 1, aux, dest, orig);
	}
}

int main(){
	int x;
	scanf("%d", &x);
	hanoi(x, 'O', 'D', 'A');
	return 0;
}
