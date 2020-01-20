#include <stdio.h>
#include "tetris.h"

char ruudukko[20][10] = {
"@@@@@@@@@@",  /* Rivi 0: ylin rivi.                */
"  x   x   ",  /* Rivi 1: toiseksi ylin rivi.       */
" xx   xxx ",  /* ...ja niin edelleen...            */
"xxx xxxxxx",
"@@@@@@@@@@",  /* Rivi 4: täynnä.                   */
"@@@@@@@@@@",  /* Rivi 5: täynnä.                   */
"xxxxxx xxx",
"xxxxxxx xx",
"x xxxxxxxx",
"xxx xxx xx",
"xxxxxx xxx",
"x xx xxx x",
"xxxxxxxxx ",
"xxx xxx xx",
"xxxxx xx x",
" xxxxxxxxx",
"xxx xxx xx",
"x xxxx xxx",
"xxxxx xxxx",  /* Rivi 18: toiseksi alin rivi.      */
"@@@@@@@@@@"}; /* Rivi 19: alin rivi.               */

int main(void) {
  
  int i = 0;
  paivita(ruudukko); /* Poistetaan tyhjät rivit. */
  
  /* Tulostetaa ruudukko.     */
  for(i = 0; i < 20; ++i) {
    printf("[%02d] %.10s\n", i,ruudukko[i]); /* Tulostetaan 1 rivi eli 10 merkkiä. */
  }
  
  return 0;
}

/* Removes full rows and then moves upper rows down */
void paivita(char r[20][10]) {

  int ri = 19;
  int collapse = 0; /* how many rows downwords */
int ri_ = 0; /* used in last step */

  for(;ri>0; ri--) {

    /* check if row full */
    int ci = 0; /* start from left */
    int isFull = 1; /* bool */
    for(;ci<10; ci++) {
      if(r[ri][ci] == ' ') {
        isFull = 0;
        break;
      }
    }
    /*  */
    if(isFull==1) {
      collapse++;
      /*printf("row idx %d is full\n", ri);
      */
    } else {
      /* Collapse this entire row down X rows */
      int cic = 0; /* column index */
      for(;cic<10; cic++) {
        r[ri+collapse][cic] = r[ri][cic];
      }
    }
  }

  /* then make top X rows empty (X=amount of collapsed rows) */
  
  for(;ri_<=collapse; ri_++) {
    int ci = 0; /* start from left */
    for(;ci<10; ci++) {
      r[ri_][ci] = ' ';
    }
  }




}