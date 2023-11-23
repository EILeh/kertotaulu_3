#include <stdio.h>
#include <stdlib.h>
#include "kertotaulu.h"

Kertotaulu * luoKertotaulu(uint a, uint b, uint c, uint d)
{
    uint i = 0;
    uint j = 0;
    Kertotaulu *k = malloc(sizeof(Kertotaulu));

    if (a > b || c > d)
    {
        return NULL;
    }


    if (k == NULL)
    {
        return NULL;
    }

    k->a = a;
    k->b = b;
    k->c = c;
    k->d = d;

    k->kertotaulu = malloc((d - c + 2) * sizeof(uint *));

    for (i = 0; i < (d - c + 2); ++i)
    {
        k->kertotaulu[i] = malloc((b - a + 2) * sizeof(uint));
    }

    for (i = 1; i <= (d - c + 1); ++i)
    {
        k->kertotaulu[i][0] = c + i - 1;
    }

    for (j = 1; j <= (b - a + 1); ++j)
    {
        k->kertotaulu[0][j] = a + j - 1;
    }

    for (i = 1; i <= (d - c + 1); ++i)
    {
        for (j = 1; j <= (b - a + 1); ++j)
        {
            k->kertotaulu[i][j] = (c + i - 1) * (a + j - 1);
        }
    }

    return k;


}

void tuhoaKertotaulu(Kertotaulu *kt)
{
    int i = 0;

    for (i = 0; i < (kt->d - kt->c + 2); ++i)
    {
        free(kt->kertotaulu[i]);
    }

    free(kt->kertotaulu);
    free(kt);
}

