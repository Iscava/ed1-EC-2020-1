#include <stdio.h>

void fatorial(int n, int i);

void fatorial(int n, int i){
    if(n == 1) printf("%i", i);
    else if(n%2!=0){
        fatorial(n-2, i*n);
    }else{
        n-=1;
        fatorial(n-2, i*n);
    }

}

int main(){

int n, i = 1;
scanf("%d", &n);
fatorial(n,i);

return 0;
}
