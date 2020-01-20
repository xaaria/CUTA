#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fibonacci.h"
/*
  Merkkijono tulee luoda siten, että funktion lopulta palauttamalle merkkijonolle
  on varattu täsmälleen sen verran muistia, kuin siihen todella tarvitaan
*/

void nextFib(int *j, int *k) {
    int k2;
    k2 = *k + *j;   *j = *k;    *k = k2;
} 

char* fib_jono_mj(unsigned int n) {

  char *mj = {'\0'};
  int j,k;  /* fib. seq. */
  int i;    /* iterator */
  int kap;  /* kokonaiskapasiteetti */
  int pit;  /* kuinka MONTA merkkiä käytetty */
  int m;
  /*int doRealloc = 0; */
  int de = 1; /* Debug */

  kap = 1;  /* lopetusmerkki */
  pit = 0;  /* lopetusmerkki on i=1, mutta aloita nollasta */

  j = 0;
  k = 0;

  for(i=0; i<n; i++) {

    /* reset */
    int doRealloc = 0;

    /* päivittää j ja k */
    if(i==0) {
      k = 0;
    } else if(i==1) {
      j = 0;
      k = 1;
    } else {
      nextFib(&j, &k); 
    }

    /* jos 1. generoitava luku: ei erottimia. Purkka-if */
    if(i != 0) {
      m = printf(", %d", k);    /* palauttaa merkkien määrän! */
    } else {
      m = printf("%d", k);      /* palauttaa merkkien määrän! */
    }
    
    /*if(de==1) { printf("merkkien lkm. %d \n", m); }
    */
    /*if(de==1) { printf("%d+%d > %d\n", pit, m, kap); }
    */

    while(pit+m > kap) {
      kap *=2;
      doRealloc = 1;  /* Pitää tehdä uusi muistinvaraus */
      /*if(de==1) { printf("> uusi kapasiteetti: %d\n", kap); }
      */
    } 

    if(doRealloc==1) {
      mj = realloc(mj, (int)kap*sizeof(char));
      /*if(de==1) { printf("  uusi koko on: %d tavua. Pituus %d \n", (int)(kap*sizeof(char)) , (int)strlen(mj)); }
      */
    }


    /* 
      Tulosta luku Fi (sekä mahdollisesti pilkku ja välilyönti) merkkijonon indeksin pit kohdalle 
      funktiolla sprintf ja kasvata arvoa pit tämän tulostuskutsun paluuarvolla.
    */
    if(i != 0) {
      pit += sprintf(&mj[pit], ", %d", k)+1;
    } else {
      pit += sprintf(&mj[pit], "%d", k)+1;
    }
    
    /*if(de==1) { 
      printf("  MJ: '%s'\n", mj);
      printf("  pit: %d\n", pit); 
    }*/

    


  } /* for */

  /* Aivan lopuksi, varaa samankokoiseksi kuin pituus. Siis pituus*char:n vaatima tavumäärä */
  mj = realloc(mj, pit*sizeof(char));
  
  return mj;
}

