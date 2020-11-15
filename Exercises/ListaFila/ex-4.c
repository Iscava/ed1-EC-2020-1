#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
typedef int boolean;

// Lista do John
typedef struct JohnRow
{
    int exercise_time;
    struct JohnRow *prev;
} JohnRow_t;

typedef JohnRow_t *johnPoint;

johnPoint firstJohn, lastJohn;

// Lista do Jack
typedef struct JackRow
{
    int exercise_time;
    struct JackRow *prev;
} JackRow_t;

typedef JackRow_t *jackPoint;

jackPoint firstJack, lastJack;

// Lista da Jade
typedef struct JadeRow
{
    int exercise_time;
    struct JadeRow *prev;
} JadeRow_t;

typedef JadeRow_t *jadePoint;

jadePoint firstJade, lastJade;

void pushJohn(int *vetor, int p)
{
    int i;
    for (i = 0; i < p; i++)
    {
        johnPoint new_Johnex = (johnPoint)malloc(sizeof(JohnRow_t));
        new_Johnex->prev = NULL;
        new_Johnex->exercise_time = vetor[i];
        if (!firstJohn)
        {
            firstJohn = new_Johnex;
            lastJohn = firstJohn;
        }
        else
        {
            lastJohn->prev = new_Johnex;
            lastJohn = new_Johnex;
            /*
            aux = firstJohn;
            while(aux){
                if(!aux->prev){
                    aux->prev = new_Johnex;
                    i == (p-1) ? lastJohn = 
                    break;
                }
                aux = aux->prev;
            }
            */
        }
    }
}

void pushJack(int *vetor, int p)
{
    int i;
    for (i = 0; i < p; i++)
    {
        jackPoint new_Jackex = (jackPoint)malloc(sizeof(JackRow_t));
        new_Jackex->exercise_time = vetor[i];
        new_Jackex->prev = NULL;
        if (!firstJack)
        {
            firstJack = new_Jackex;
            lastJack = firstJack;
        }
        else
        {
            lastJack->prev = new_Jackex;
            lastJack = new_Jackex;
        }
    }
}

void pushJade(int *vetor, int p)
{
    int i;
    for (i = 0; i < p; i++)
    {
        jadePoint new_Jadeex = (jadePoint)malloc(sizeof(JadeRow_t));
        new_Jadeex->exercise_time = vetor[i];
        new_Jadeex->prev = NULL;
        if (!firstJade)
        {
            firstJade = new_Jadeex;
            lastJade = firstJade;
        }
        else
        {
            lastJade->prev = new_Jadeex;
            lastJade = new_Jadeex;
        }
    }
}

int *verify(int d)
{
    int ex[3], pontv[3], res[3];

    johnPoint auxJohn = firstJohn;
    int pontJohn = 0, countJohn = 0, doneJohn = 0;
    while (auxJohn)
    {
        countJohn += auxJohn->exercise_time;
        if (countJohn < d)
        {
            pontJohn += countJohn;
            doneJohn++;
            ex[0] = doneJohn;
            pontv[0] = pontJohn;
        }
        auxJohn = auxJohn->prev;
    }

    jackPoint auxJack = firstJack;
    int pontJack = 0, countJack = 0, doneJack = 0;
    while (auxJack)
    {
        countJack += auxJack->exercise_time;
        if (countJack < d)
        {
            pontJack += countJack;
            doneJack++;
            ex[1] = doneJack;
            pontv[1] = pontJack;
        }
        auxJack = auxJack->prev;
    }

    jadePoint auxJade = firstJade;
    int pontJade = 0, countJade = 0, doneJade = 0;
    while (auxJade)
    {
        countJade += auxJade->exercise_time;
        if (countJade < d)
        {
            pontJade += countJade;
            doneJade++;
            ex[2] = doneJade;
            pontv[2] = pontJade
        }
        auxJade = auxJade->prev;
    }

    if (ex[0] == ex[1] && ex[0] == ex[2] ||
        ex[0] == ex[1] && ex[0] > ex[2] ||
        ex[0] == ex[2] && ex[0] > ex[1] ||
        ex[1] == ex[2] && ex[1] > ex[0])
    {
        if (pontv[0] == pontv[1] && pontv[0] == pontv[2] ||
            pontv[0] == pontv[1] && ex[0] == ex[1] ||
            pontv[0] == pontv[2] && ex[0] == ex[2] ||
            pontv[1] == pontv[2] && ex[1] == ex[2] ||
            pontv[2] < pontv[0] && ex[0] == ex[2] ||
            pontv[2] < pontv[1] && ex[1] == ex[2])
        {
            res[0] = 2;
            res[1] = ex[2];
            res[2] = pontv[2];
        }
        else if (pontv[0] < pontv[1] && ex[0] == ex[1] ||
                 pontv[0] < pontv[2] && ex[0] == ex[2])
        {
            res[0] = 0;
            res[1] = ex[0];
            res[2] = pontv[0];
        }
        else if (pontv[1] < pontv[0] && ex[1] == ex[0] ||
                 pontv[1] < pontv[2] && ex[1] == ex[2])
        {
            res[0] = 1;
            res[1] = ex[1];
            res[2] = pontv[1];
        }
    }
    else if ()
    {
    }

    int i;
    for (i = 0; i < 3; i++)
    {
    }
}

void ascOrder(int *vetor, int p)
{
    int aux, menor, i, z;
    for (i = 0; i < p; i++)
    {
        menor = vetor[i];
        for (z = i; z < p; z++)
        {
            if (vetor[z] < menor)
            {
                menor = vetor[z];
                aux = vetor[i];
                vetor[i] = vetor[z];
                vetor[z] = aux;
            }
        }
    }
}

void descOrder(int *vetor, int p)
{
    int aux, maior, i, z;
    for (i = 0; i < p; i++)
    {
        maior = vetor[i];
        for (z = i; z < p; z++)
        {
            if (vetor[z] > maior)
            {
                maior = vetor[z];
                aux = vetor[i];
                vetor[i] = vetor[z];
                vetor[z] = aux;
            }
        }
    }
}

int main()
{
    int i, z;
    int t, d, p;

    scanf("%d", &t);

    for (i = 0; i < t; i++)
    {
        scanf("%d %d", &d, &p);
        int exDiff[p];
        for (z = 0; z < p; z++)
        {
            scanf("%d", &exDiff[z]);
        }
        pushJohn(exDiff, p);
        ascOrder(exDiff, p);
        pushJack(exDiff, p);
        descOrder(exDiff, p);
        pushJade(exDiff, p);
        for (i = 0; i < p; i++)
        {
            printf("\n%d", exDiff[i]);
        }
    }
    return 0;
}
