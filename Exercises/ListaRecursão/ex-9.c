#include <stdio.h>

int ackermann(int x, int y){
	if(x == 0) return y + 1;
	if(y == 0 && x > 0) return  ackermann(x - 1, 1);
	if(y > 0 && x > 0) return ackermann(x - 1, ackermann(x, y - 1));
}

int main(){
	int x, y;
	scanf("%d %d", &x, &y);
	printf("%d\n", ackermann(x, y));

	return 0;
}
