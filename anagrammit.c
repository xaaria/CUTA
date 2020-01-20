#include<stdio.h>
#include<string.h>
#include<limits.h>
#include "anagrammit.h"
/*
  anagrammit.c

  "-- Määrittämällä UCHAR_MAX + 1 -alkioisen int-taulukon lkmt, jonka alkiossa lkmt[x] pidetään kirjaa siitä,
  kuinka monta kertaa lukuarvon x omaava merkki on kohdattu. Aluksi taulukko alustetaan nollilla,
  ja sen jälkeen kunkin merkin mj1[i] kohdalla arvoa lkmt[(unsigned char) mj1[i]] kasvatetaan yhdellä,
  ja vastaavasti kunkin merkin mj2[i] kohdalla arvoa lkmt[(unsigned char) mj2[i]] vähennetään yhdellä.
  Merkkijonot mj1 ja mj2 ovat anagrammeja jos ja vain jos taulukon lkmt kaikki arvot ovat lopussa nollia."

*/

/*
int main(int argc, char* argv[]) {


  if(argc>=3) {
    printf("Saatiin: %s & %s\n", argv[1], argv[2]);
    printf(">> %d", anagrammeja(argv[1], argv[2]));
  } else {
    printf("Parametreja liian vahan!");
  }



  return 0;
}
*/



int anagrammeja(char mj1[], char mj2[]) {

  int lkmt[UCHAR_MAX+1] = {0}; /* loput alustuvat myös arvoilla 0 */
  int ci = 0;
  int isAng = 1; /* Tosi oletuksena. muuteaan epätodeksi jos logiikka epäonnistuu... */

  /* hieman purkka, mutta ajaa asiansa. Tehdään erikseen monessa loopissa */
  for(ci; ci<=strlen(mj1)-1; ci++ ) {
    lkmt[(unsigned char) mj1[ci] ]++;
    /*printf("++ uusi arvo char: %c --> %d \n", mj1[ci], lkmt[ mj1[ci] ]);
    */
  }

  for(ci=0; ci<=strlen(mj2)-1; ci++) {
    lkmt[(unsigned char) mj2[ci] ]--;
    /*printf("-- uusi arvo char: %c --> %d \n", mj2[ci], lkmt[ mj2[ci] ]);
    */
  }

  /* [0, UCHAR_MAX, älä huomioi viimeistä taulukon arvoa] */
  for(ci=0; ci<=UCHAR_MAX; ci++) {
    /* Tarkista, onko kirjaimien ero 0, jos EI, ei ole anagrammi */
    if(lkmt[ci] != 0) {
      isAng = 0;
      break;
    }
    /*printf("%d,", lkmt[ci]);
    */
  }

  return isAng;
}
