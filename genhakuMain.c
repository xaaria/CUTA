#include <stdio.h>
#include "genhaku.h"

/*
 03 - Geneerinen haku.
 "Aseta vastauksesi tiedostoihin genhaku.c ja genhaku.h."

 T�m�n testikoodin suorituksen pit�isi tulostaa:

  2 10
  2 10

*/

int main(void) {

  int ix[10] = {4, 1, 0, 8, 2, 9, 0, 8, 2, 9};
  int iy[4] = {0, 8, 2, 9};
  int iz[4] = {0, 9, 2, 8};
  
  short sx[10] = {4, 1, 0, 8, 2, 9, 0, 8, 2, 9};
  short sy[4] = {0, 8, 2, 9};
  short sz[4] = {0, 9, 2, 9};

  /* WETO:n testi */
  const int s = 12;
  double mista[s]  = {0.4, 0.9, 1.2, 0.6, 0.3, 0.8, 0.5, 0.9, 0.1, 1.1, 0.3, 0.8};
  double milla[2]   = {0.1, 0.2};

  typedef unsigned long ulong;

  printf("%lu %lu\n", 
    (ulong) etsi(ix, 10, iy, 4, sizeof(int)), 
    (ulong) etsi(ix, 10, iz, 4, sizeof(int)));

  printf("%lu %lu\n", 
    (ulong) etsi(sx, 10, sy, 4, sizeof(short)), 
    (ulong) etsi(sx, 10, sz, 4, sizeof(short)));

  printf("%lu\n", 
    (ulong) etsi(mista, s, milla, 2, sizeof(double))
  ); 
  
  return 0;
}
