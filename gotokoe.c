#include <stdio.h>
#include <limits.h>
#include "gotokoe.h"
/* gotokoe.c */

/*

  Toteuta goto-lausetta käyttäen funktio int max2D(int **t2d, int kork, int lev), 
  joka etsii ja palauttaa parametrinaan saamansa kaksiulotteisen int-taulukon t2d suurimman alkion arvon.
  Parametri kork kertoo taulukon korkeuden (ensimmäistä indeksiä vastaavan ulottuvuuden koko) 
  ja lev leveyden (toista indeksiä vastaavan ulottuvuuden koko).

  t2d --> int*[int*, ...] --> [int, int, int]: 

*/

int max2D(int** t2d, int kork, int lev) {

  int max = INT_MIN;
  int** t = t2d; /* hae taulun alku pointterista */

  unsigned int r = 0; /* rivit-iteraattori */
  unsigned int c = 0; /* sarake-iteraattori */

  /* Rivin maksimi */
  for(r=0; r<kork; ++r) {

    /* vaihda riviä */
    int* rivi = t[r];

    /* käy rivin arvot läpi */
    for(c=0; c<lev; ++c) {
      
      printf("olemme paikassa <%d,%d>\n", r, c);

      int val = rivi[c];
      printf("> %d\n", val);
      if( val > max) {
        printf("\tuusi maksimi %d (%d)\n", val, max);
        max = val; /* päivitä */
      }
    }

  }

  printf("return %d\n", max);
  return max;

}