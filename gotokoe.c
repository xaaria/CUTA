#include <stdio.h>
#include "gotokoe.h"
/* gotokoe.c */

/*

  Toteuta goto-lausetta käyttäen funktio int max2D(int **t2d, int kork, int lev), 
  joka etsii ja palauttaa parametrinaan saamansa kaksiulotteisen int-taulukon t2d suurimman alkion arvon.
  Parametri kork kertoo taulukon korkeuden (ensimmäistä indeksiä vastaavan ulottuvuuden koko) 
  ja lev leveyden (toista indeksiä vastaavan ulottuvuuden koko).

  t2d --> int[3][3]: 
    [][][],
    [][][],
    [][][]

*/

int max2D(int** t2d, int kork, int lev) {

  int max = 0;
  int* t = *t2d; /* hae taulun alku pointterista */

  unsigned int r = 0; /* rivit-iteraattori */
  unsigned int c = 0; /* sarake-iteraattori */

  /* Rivin maksimi */
  for(r; r<kork; r++) {
    for(c; c<lev; c++) {
      int* rivi = (int*) t[r];
      int val = rivi[c];
      if( val > max) {
        printf("%d", val);
        max = val; /* päivitä */
      }
    }
  }

  printf("return %d", max);
  return max;

}