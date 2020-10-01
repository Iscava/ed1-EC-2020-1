#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

typedef int boolean;

typedef struct Element
{
    char name[20];
    struct Element *prev;
    struct Element *next;
} Element_t;

typedef Element_t *member;

member grandmother = NULL;

void _initList()
{
    member new_element = (member)malloc(sizeof(Element_t));
    strcpy(new_element->name, "Arlete");
    new_element->next = NULL;
    new_element->prev = NULL;
    grandmother = new_element;
}

void _end()
{
    boolean condition = TRUE;
    member actual = (member)grandmother;
    while (condition)
    {
        if (actual->next == NULL)
        {
            actual->next = grandmother;
            grandmother->prev = actual;
            condition = FALSE;
        }
        actual = actual->next;
    }
}

void _inserts(char *name)
{
    member new_element = (member)malloc(sizeof(Element_t));
    strcpy(new_element->name, name);
    new_element->next = NULL;
    boolean condition = TRUE;
    member actual = (member)grandmother;
    while (condition)
    {
        if (actual->next == NULL)
        {
            new_element->prev = actual;
            actual->next = new_element;
            condition = FALSE;
        }
        actual = actual->next;
    }
}

void _delete(char *name)
{
    boolean condition = TRUE;
    member actual = (member)grandmother;
    member helper;
    while (condition)
    {
        if (strcmp(actual->next->name, name) == 0)
        {
            helper = actual->next;
            actual->next = actual->next->next;
            free(helper);
            condition = FALSE;
        }
        actual = actual->next;
    }
}

int _game(char **name, char **position, int n)
{
    member actual = (member)grandmother;
    int count = 0, points = 0;
    while (count < n)
    {
        int i = 0;
        while (i < 3)
        {                    
            if (!strcmp(position[count], "horario"))
            {                    
                if (!strcmp(actual->name, name[count]))
                {
                    _delete(name[count]);
                    points++;
                }
                actual = actual->next;
            }
            else
            {
                if (!strcmp(actual->name, name[count]))
                {
                    _delete(name[count]);
                    points++;
                }
                actual = actual->prev;
            }
            i++;
        }
        count++;
    }
    return points;
}

int main()
{
    _initList();

    int i;
    char name[15];
    int count = 0;

    while (TRUE)
    {
        scanf("%s", name);
        if (!strcmp(name, "FIM"))
            break;
        _inserts(name);
        count++;
    }

    _end();

    char answer[40];
    char *word;
    char **grandchildren = malloc(count * sizeof(*grandchildren));
    int lin;
    for (lin = 0; lin < count; lin++)
    {
        grandchildren[lin] = malloc(20 * sizeof(*grandchildren[lin]));
    }
    char **position = malloc(count * sizeof(*position));
    for (lin = 0; lin < count; lin++)
    {
        position[lin] = malloc(20 * sizeof(*position[lin]));
    }

    for (i = 0; i < count; i++)
    {
        scanf("%s %s", grandchildren[i], position[i]);
    }

    int result = _game(grandchildren, position, count);
    printf("%d", result);

    return 0;
}
