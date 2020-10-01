#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef int boolean;

typedef struct Elemento_anao
{
    int n, c;
    struct Elemento_anao *prox;
} Anao;

Anao *arya = NULL;

void insere(int n, int c)
{
    boolean cond = TRUE;
    Anao *novo_elemento = (Anao *)malloc(sizeof(Anao));
    novo_elemento->n = n;
    novo_elemento->c = c;
    novo_elemento->prox = NULL;

    if (!arya)
    {
        arya = novo_elemento;
    }
    else
    {
        Anao *atual = (Anao *)arya;

        while (cond)
        {

            if (atual->prox == NULL)
            {
                atual->prox = novo_elemento;
                cond = FALSE;
            }

            atual = atual->prox;
        }
    }
};

Anao *busca(int n)
{

    Anao *atual = (Anao *)arya;

    while (atual != NULL && atual->n != n)
    {

        atual = atual->prox;
    }

    return atual;
}

void saida(int **matriz, int c, int m, int numAnoesInicio)
{
    int k, vetor[c], y, i;
    for (y = 0; y < m; y++)
    {
        Anao *atual = (Anao *)busca(numAnoesInicio + 1);
        Anao *elemento_a = NULL;
        Anao *elemento_b = NULL;
        Anao *aux = NULL;

        while (atual)
        {
            if (atual->n - numAnoesInicio == matriz[y][0])
                elemento_a = atual;

            if (atual->n - numAnoesInicio == matriz[y][1])
                elemento_b = atual;

            atual = atual->prox;
        }

        k = (elemento_b->n - elemento_a->n) + 1;

        for (i = 0; i < c; i++)
        {
            vetor[i] = 0;
        }

        for (i = 0; i < c; i++)
        {
            aux = (Anao *)elemento_a;
            int x;
            for (x = 0; x < k; x++)
            {
                if (aux->c == i + 1)
                {
                    vetor[i]++;
                }
                aux = aux->prox;
            }
        }

        int maior = 0, cor = 0;
        for (i = 0; i < c; i++)
        {
            if (vetor[i] > maior)
            {
                maior = vetor[i];
                cor = i + 1;
            }
        }
        maior > k / 2 ? printf("\nbonita %d", cor) : printf("\nfeia");
    }
}

int main()
{
    int t, n, numc, c, m, count = 0, vezes, numAn = 1;
    boolean fator = TRUE;

    scanf("%d", &t);

    vezes = t;
    int inputs[t][2], numeroAnoesTeste[t + 1];
    numeroAnoesTeste[0] = 0;
    int ***Vector_fotos = malloc(t * sizeof(**Vector_fotos));

    while (fator)
    {
        scanf("%d %d", &n, &numc);

        int numAnCount = 0;
        while (numAnCount < n)
        {
            scanf("%d", &c);
            insere(numAn, c);
            numAn++;
            numAnCount++;
        }

        scanf("%d", &m);

        int a, b;

        int **fotos = malloc(m * sizeof(*fotos));
        int lin;
        for (lin = 0; lin < m; lin++)
        {
            fotos[lin] = malloc(2 * sizeof(*fotos[lin]));
        }

        int i;
        for (i = 0; i < m; i++)
        {
            scanf("%d %d", &a, &b);
            fotos[i][0] = a;
            fotos[i][1] = b;
        }

        Vector_fotos[count] = fotos;
        inputs[count][0] = numc;
        inputs[count][1] = m;
        numeroAnoesTeste[count + 1] = numeroAnoesTeste[count] + n;

        count++;
        t--;
        if (t == 0)
            fator = FALSE;
    }

    int i;
    for (i = 0; i < vezes; i++)
    {
        saida(Vector_fotos[i], inputs[i][0], inputs[i][1], numeroAnoesTeste[i]);
    }

    return 0;
}
