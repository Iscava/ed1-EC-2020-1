#include <stdio.h>
#include <stdlib.h>

typedef struct Fila
{
    int id;
    struct Fila *prev;
} Fila_t;

typedef Fila_t *pessoa;

pessoa firstP = NULL, lastP = NULL;

void _push(int m)
{
    pessoa new_pessoa = (pessoa)malloc(sizeof(Fila_t));
    new_pessoa->prev = NULL;
    new_pessoa->id = m;
    if (!firstP)
    {
        firstP = new_pessoa;
        lastP = firstP;
    }
    else
    {
        lastP->prev = new_pessoa;
        lastP = new_pessoa;
    }
}

void _remove(int s)
{
    pessoa actual = firstP, aux, prev = actual->prev;

    while (actual)
    {
        if (actual->id == s)
        {
            aux = firstP;
            firstP = firstP->prev;
            free(aux);
            break;
        }
        //printf("\n TESTE id : %d\n s : %d", aux->prev->id, s);
        if (prev->id == s)
        {
            aux = prev;
            actual->prev = prev->prev;
            prev = actual->prev;
            free(aux);
            break;
        }
        prev = prev->prev;
        actual = actual->prev;
    }
}

void _print()
{
    pessoa aux = firstP;
    while (aux)
    {
        printf("%d ", aux->id);
        aux = aux->prev;
    }
}

int main()
{

    int i, n, s, m, numS;

    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &m);
        _push(m);
    }

    scanf("%d", &numS);
    for (i = 0; i < numS; i++)
    {
        scanf("%d", &s);
        _remove(s);
    }
    _print();
    return 0;
}
