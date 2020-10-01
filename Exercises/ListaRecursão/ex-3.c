#include <stdio.h>
#include <stdlib.h>

//void jogo(int x, int t, int l, int m, int n, int y, int k, char** string, int** pos);

void jogo(int x, int t, int l, int m, int n, int y, int k, char** string, int** pos){

    if(l == k){
        printf("%d", y);
    }else{

        for(x = 0; x < n; x++){
            for(t = 0; t < m; t++){
                if(string[x][t]=='#' && pos[l][0]==x && pos[l][1]==t){
                    jogo(x,t,l+1,m,n,y+1,k, string, pos);
                }else if(string[x][t]!='#' && pos[l][0]==x && pos[l][1]==t){
                    jogo(x,t,l+1,m,n,y,k, string, pos);
                }
            }
        }

    }
}

int main(){

    int n, m, k, y = 0, l = 0,x,t;
    scanf("%d %d", &n,&m);
    if(n<1 || m>100){
        return 0;
    }
    char **vetor = malloc(n * sizeof(*vetor));
    int linha;
    for (linha = 0; linha < n; linha++) {
        vetor[linha] = malloc(m * sizeof(*vetor[linha]));
    }
    int p;
    for(p = 0; p < n; p++){
        scanf(" %s", &vetor[p][0]);
    }
   /* int r, f;
    for(r = 0; r <n; r++){
        for(f = 0; f < m; f++){
            if(vetor[r][f]!='a'||vetor[r][f]!='#'){
                return 0;
            }
        }
    }*/
    scanf("%d", &k);
    if(k<1||k>(m*n)){
        return 0;
    }
    int **disparos = malloc(k * sizeof(*disparos));
    int lin;
    for (lin = 0; lin < k; lin++) {
        disparos[lin] = malloc(2 * sizeof(*disparos[lin]));
    }
    int u;
    for(u = 0; u < k; u++){
        scanf("%d %d", &disparos[u][0],&disparos[u][1]);
        disparos[u][0]-= 1;
        disparos[u][1]-= 1;
    }

    jogo(x, t, l, m ,n, y, k, vetor, disparos);

return 0;
}
