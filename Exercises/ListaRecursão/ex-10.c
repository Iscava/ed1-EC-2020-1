#include<stdio.h>

int contador(int n){
    if (n == 0) return 0;
    return 1 + contador(n/10);
}

int function(unsigned int n, int num){

	if(n == 0){
       return 0;
	}else{
        int d = n % 10;
        if(d != 0) printf("%d", d);

        return function(n/10, num-1);
	}
}

int main(){

	int n;
	scanf("%d", &n);
	function(n, contador(n));

	return 0;
}
