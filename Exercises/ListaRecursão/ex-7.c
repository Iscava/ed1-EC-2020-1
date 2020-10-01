#include <stdio.h>

int function(int i, int* p,int f){
    if(!i) return f;
    int p1, p2;
    scanf("%d %d", &p1, &p2);

    if (p[p1 - 1] > 0 || p[p2 - 1] > 0) f--;
    if(p1 == p2 )
        p[p1] += 1;
        p[p1 - 1] += 1;
        p[p2 - 1] += 1;

    function(i - 1, p, f);
}

int main(){
    int m, n, i;
    int p1, p2;
    scanf("%d %d", &n, &m);
    int p[n];
    for(i = 0; i < n;i++) p[i] = 0;
    i = m;
    m = function(m, p, m);
    printf("%d\n", m);
}
