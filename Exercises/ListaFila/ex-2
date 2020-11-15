#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Crianca
{
    int n;
    char name[48];
    struct Crianca *next;
    struct Crianca *prev;
} Crianca_t;

typedef Crianca_t *crc;

typedef struct Circle
{
    crc head;
    int tam;
} Circle_t;

typedef Circle_t *circle;

void push(circle circle, char *name, int num)
{
    crc new_element = (crc)malloc(sizeof(Crianca_t));
    strcpy(new_element->name, name);
    new_element->n = num;

    if (!circle->head)
    {
        new_element->next = new_element;
        new_element->prev = new_element;
        circle->head = new_element;
    }
    else
    {
        new_element->next = circle->head;
        new_element->prev = circle->head->prev;
        new_element->prev->next = new_element;
        circle->head->prev = new_element;
    }
    circle->tam++;
}

void copy(crc dest, crc src)
{
    strcpy(dest->name, src->name);
    dest->n = src->n;
    dest->next = src->next;
    dest->prev = src->prev;
}

void right(circle circle, int k, crc rCri)
{
    int i = 0;
    crc aux = circle->head;
    while (i++ < k)
    {
        aux = aux->prev;
    }
    copy(rCri, aux);
    if (aux == circle->head)
        circle->head = aux->next;
    aux->next->prev = aux->prev;
    aux->prev->next = aux->next;
    free(aux);
    circle->tam--;
}

void left(circle circle, int k, crc rCri)
{
    int i = 0;
    crc aux = circle->head;
    while (i++ < k)
    {
        aux = aux->next;
    }
    copy(rCri, aux);
    if (aux == circle->head)
        circle->head = aux->next;
    aux->next->prev = aux->prev;
    aux->prev->next = aux->next;
    free(aux);
    circle->tam--;
}

void count(circle circle, crc winner)
{
    int head_number = circle->head->n;
    Crianca_t rCri;
    while (circle->tam > 1)
    {
        if (head_number % 2 == 0)
        {
            right(circle, head_number, &rCri);
        }
        else
        {
            left(circle, head_number, &rCri);
        }
        head_number = rCri.n;
    }
    copy(winner, circle->head);
}

circle create()
{
    circle new_element = (circle)malloc(sizeof(Circle_t));
    if (!new_element)
        return NULL;
    new_element->head = NULL;
    new_element->tam = 0;
    return new_element;
}

int main()
{
    circle circle = create();
    int n, num;
    scanf("%d", &n);
    char name[48];
    while (n--)
    {
        scanf("%s %d", name, &num);
        push(circle, name, num);
    }
    Crianca_t vencedor;
    count(circle, &vencedor);
    printf("%s", vencedor.name);
}
