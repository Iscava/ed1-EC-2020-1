#include <stdio.h>
#include <stdlib.h>

int max(int x, int y){
     return (x > y) ? x : y;
}

int function(int k, int n){

	if(n == 1) return n;
    if (k == 1) return n;

	int i, res, min = __INT_MAX__;

 	for (i = 1; i <= n; i++){
        res = max(function(k - 1, i - 1), function(k, n - i));
        if (res < min)
            min = res;
    }

	return min + 1;
}


int main(){

	int x, y;
	scanf("%d %d", &x, &y);
	printf("%d",function(y, x));

    return 0;
}
