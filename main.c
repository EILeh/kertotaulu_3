#include <stdio.h>
#include <stdlib.h>
#include "kertotaulu.h"

int main(int argc, char *argv[])
{ /* Parametrit argv[1]...argv[4] ilmaisevat arvot a, b, c ja d. */
  Kertotaulu *kt = luoKertotaulu(atoi(argv[1]), atoi(argv[2]), atoi(argv[3]), atoi(argv[4]));
  uint i = 0;
  uint j = 0;
  for(i = 0; i <= (kt->d - kt->c + 1); ++i)    /* Rivit */
  {
    for(j = 0; j <= (kt->b - kt->a + 1); ++j)  /* Sarakkeet */
    {
      if((i > 0) || (j > 0)) /* Onko kyseessä muu kuin kohta [0][0]? */
      {
         printf("%4u", kt->kertotaulu[i][j]); /* 4 merkin leveys. */
      }
      else
      {
         printf("    "); /* Kohtaan [0][0] vain 4 välilyöntiä. */
      }
    }
    printf("\n");
  }
  tuhoaKertotaulu(kt);
  return 0;
}
