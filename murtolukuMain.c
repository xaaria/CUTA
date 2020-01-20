#include <stdio.h>
#include "murtoluku.h"

int main(int argc, char *argv[])
{
  tulostaML(  supistettuML(99,33)  );
  printf("\n");
  tulostaML(  supistettuML(17,31)  );
  printf("\n");
  tulostaML(  supistettuML(100, -10)  );
  printf("\n");
  tulostaML(  supistettuML(100, 10)  );
  printf("\n");
  /*tulostaML(  supistettuML(100,0)  );
  */
  /* --- */

  int i = 0;
  Murtoluku mlt[4] = {{4, 8}, {-5, -10}, {10, -2}, {225, 1150}};
  printf("Lukujen sievennys:\n");
  for(i = 0; i < 4; ++i)
  {
    printf("%d/%d = ", mlt[i].os, mlt[i].nim);
    mlt[i] = supistettuML(mlt[i].os, mlt[i].nim);
    tulostaML(mlt[i]);
    printf("\n");
  }
  printf("Laskutoimituksia:\n");
  for(i = 1; i < 4; ++i)
  {
    tulostaML(mlt[i-1]);    printf(" + ");    tulostaML(mlt[i]);
    printf(" = ");    tulostaML(lisaaML(mlt[i-1], mlt[i]));
    printf("\n");
    tulostaML(mlt[i-1]);    printf(" - ");    tulostaML(mlt[i]);
    printf(" = ");    tulostaML(vahennaML(mlt[i-1], mlt[i]));
    printf("\n");
    tulostaML(mlt[i-1]);    printf(" * ");    tulostaML(mlt[i]);
    printf(" = ");    tulostaML(kerroML(mlt[i-1], mlt[i]));
    printf("\n");
    tulostaML(mlt[i-1]);    printf(" / ");    tulostaML(mlt[i]);
    printf(" = ");    tulostaML(jaaML(mlt[i-1], mlt[i]));
    printf("\n");
  }
  return 0;
}