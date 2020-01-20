#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "luku.h"

/*
  lue.c
  Header-tiedosto "lue.h"


  Toteuta funktio char * lueKunnes(FILE *virta, char erotin, size_t *pituus), 
  joka lukee syötevirrasta syote merkkejä niin kauan, kunnes parametrin erotin ilmaisema merkki kohdataan (tai syötevirta virta loppuu).
    Funktio tallettaa luetut merkit dynaamisesti varaamaansa merkkijonoon ja palauttaa sen. 
  Tee tämä siten, että palautettava merkkijono ei sisällä lopussa erotinmerkkiä erotin: kyseinen merkki jätetään huomiotta. 
  Lisäksi luettujen merkkien lukumäärä (eli palautettavan merkkijonon pituus) palautetaan asettamalla se osoitinparametrin pituus osoittamaan paikkaan. 
  Funktion kutsujan vastuulle jää vapauttaa palautettu merkkijono, kun sitä ei enää tarvita.


  KESKEN: Merkkijonon kopiointi falskaa. Lopetusmerkki & strcpy?

*/

char* lueKunnes(FILE* virta, char erotin, size_t* pituus) {

  size_t kap = 1;   /* kapasiteetti */
  size_t pit = 0;   /* tämä pitää kirjaa siitä, kuinka monta merkkiä syötettä on toistaiseksi luettu (ja talletettu). */
  char* puskuri = calloc(kap, sizeof(char)); /* kapasiteetti  */ 
  int c = 0;
  int lue = 1; /* bool. */
  *pituus = 0; /* pitää nollata! */
  
  while(lue == 1) {

    c = getc(virta);

    /*printf("'%c' \n", c);
    */

    if((char) c != erotin && c != EOF) {
      
      /* Ei lopetusta + Kun olet lukenut uuden merkin, tarkista tämänhetkinen kapasiteetti ja tarvittaessa varaa lisää muistia. */
      
      if(pit == kap) {
        /*printf("\tTILA LOPPUI\n");
        */
        int i = 0;
        char* temp = puskuri; /* ota väliaikaiseen muuttujaan talteen osoite puskurin alkuun */

        kap *= 2; /* tuplaa kapas. */
        puskuri = (char*) calloc( kap, sizeof(char) ); /* voitaisiin myös tarkastaa että saatiin uusi osoite, mutta jääköön väliin */
        /*
        */
        /* ota väliaikamuistista sisältö uuteen, tilavampaan char-taulukkoon */
        for(i=0; i<pit; i++) {
          /*printf("\tCOPY %c [%d]\n", (char) temp[i], i);
          */
          puskuri[i] = temp[i];
        }

      }

      /* Tallenna merkki normaalisti */
      puskuri[pit] = (char) c;
      /*printf("Tallennettiin '%c' indeksiin [%d]\n", (char) c, pit);
      */
      pit++;
      *pituus = pit;

    } else {
      lue = 0; /* Aseta lippumuuttuja epätodeksi, ei enää jatketa lukemista */
      break;
    }

  } /* while */


  /*printf("TILANNE: pit %d ja merkki %c", pit, (char) c);
    */

  /* 
    lukemisen jälkeen: Jos pit > 0 tai kohdattiin merkki erotin, uudelleenvaraa puskuri-merkkijono (pit + 1)-tavuiseksi 
    ja aseta viimeisen siihen talletetun merkin perään lopetusmerkki '\0'. */

  if(pit > 0 || (char) c == EOF) {
    
    size_t i = 0;
    char* mj = (char*) calloc( pit+1, sizeof(char) ); /* varaa tilaa lopulliselle palautettavalle mj:lle, ja +1 lopetusmerkille */

    /* kopioi sisältö. Lopuksi laita lopetusmerkki */
    for(i=0; i<pit; i++) {
      mj[i] = puskuri[i];
    }
    mj[pit + 1] = '\0';

    return mj;
  }
  else if(pit == 0 && (char) c == EOF) {
    /*printf("pit==0 ja EOF\n");
    */
    puskuri = (char*) calloc(0, sizeof(char));
    *pituus = 0;
    return puskuri;
  } 

  /*  */
  *pituus = 0;
  return NULL;

}