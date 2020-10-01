#include <stdio.h>

int fibonacci(int n, int i, int c, int termo1, int termo2);

int fibonacci(int n, int i, int c, int termo1, int termo2){

    if(c == n){
        return 0;
    }else{
        i = termo1 + termo2;
        termo1 = termo2;
        termo2 = i;
        printf("%d ", i);
        return  fibonacci(n, i, c+1, termo1, termo2);
        // 0 1 1 2 3 5
    }

}

int main(){

    int n = 0, c = 0;

    scanf("%d", &n);

    if(n<0){
        return 0;
    }else{
        if(n == 0){
            printf("0");
        }else if(n == 1){
            printf("0 1");
        }else{
            printf("0 1 ");
            fibonacci(n,0,1,0,1);
        }
    }

return 0;
}
