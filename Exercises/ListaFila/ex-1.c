#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int hr, min, crt;
} row;

int main(int argc, char **argv)
{
    int num = 0, aux = 0, hr = 0, min = 0, cont = 0, i, end = 0;
    row v[25], fila[25];

    scanf("%d", &num);

    for (i = 0; i < num; i++)
        scanf("%d%d%d", &v[i].hr, &v[i].min, &v[i].crt);

    i = 0;
    while (hr < 19)
    {
        while ((hr * 60 + min) >= (v[aux].hr * 60 + v[aux].min) && aux < num)
        {
            fila[end].hr = v[aux].hr;
            fila[end].min = v[aux].min;
            fila[end].crt = v[aux].crt;
            end++;
            aux++;
        }
        if (end != 0)
        {
            if ((hr * 60 + min) > (fila[i].hr * 60 + fila[i].min + fila[i].crt))
                cont++;

            i++;
        }
        else if (aux >= num)
            break;

        if (i == end)
        {
            end = 0;
            i = 0;
        }
        hr = hr + (min + 30) / 60;
        min = (min + 30) % 60;
    }
    printf("%d", cont);
    return 0;
}
