#include <stdio.h>

int soma(int n, int i);

int soma(int n, int i){

    if(i == n){
        return printf("%d ", i);
    }else{
      printf("%d ", i);
      return  soma(n, i+1);

    }

}

int main(){

    int n = 0;

    scanf("%d", &n);

    if(n<=0){
        return 0;
    }else{
        soma(n,1);
    }

return 0;
}
