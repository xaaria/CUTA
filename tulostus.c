#include <stdlib.h>
#include <stdio.h>
#include "tulostus.h"
/*

  3-Tiedostoon tulostus :: tulostus.c 

  Toteuta funktio 
  void tulostaDblTaulu(double *taulu, size_t lkm, const char *taulNimi, int tarkkuus, const char *tiedNimi),
  joka tulostaa parametrinaan saamansa double-taulukon taulu lkm ensimmäistä 
  alkiota parametrin tiedNimi nimiseen tiedostoon tarkkuus desimaalin tarkkuudella niin,
  että kunkin indeksin i alkio tulostetaan omalle rivilleen muodossa:
    nimi[i] = arvo
*/

/*
void testaus() {

  FILE* tied = fopen("tiedosto_testi.txt", "ab");
  fprintf(tied, "moi kaikki :D");

}*/

void tulostaDblTaulu(double *taulu, size_t lkm, const char *taulNimi, int tarkkuus, const char *tiedNimi) {

  int i = 0;
  FILE* tied = fopen(tiedNimi, "w");

  for(i=i; i<=lkm-1; i++) {

    /*printf("%s[%d] = %.*f\n", taulNimi, i, tarkkuus, taulu[i]);
    */
    fprintf(tied, "%s[%d] = %.*f\n", taulNimi, i, tarkkuus, taulu[i] );
    
  }

  fclose(tied);

}