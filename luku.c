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


*/

char* lueKunnes(FILE* virta, char erotin, size_t* pituus) {

  size_t kap = 1;   /* kapasiteetti */
  size_t pit = 0;   /* tämä pitää kirjaa siitä, kuinka monta merkkiä syötettä on toistaiseksi luettu (ja talletettu). */
  char* puskuri = calloc(kap, sizeof(char)); /* kapasiteetti  */ 
  int c = 0;
  int lue = 1; /* bool. */
  *pituus = 0; /* pitää nollata! */
  
  do {

    c = getc(virta);

    /*printf("'%c' \n", c);
    */

    if((char) c != erotin && c != EOF) {
      
      /* Ei lopetusta + Kun olet lukenut uuden merkin, tarkista tämänhetkinen kapasiteetti ja tarvittaessa varaa lisää muistia. */
      
      if(pit == kap) {
        /*printf("\tTILA LOPPUI\n");
        */
        kap *= 2; /* tuplaa kapas. */
        puskuri = (char*) realloc( puskuri, kap*sizeof(char) ); /* voitaisiin myös tarkastaa että saatiin uusi osoite, mutta jääköön väliin */
      }

      /* Tallenna merkki normaalisti, indeksiin jonka arvo on 'montako ennestään tallennettu'. Huomaa nollakantaisuus! */
      puskuri[pit] = (char) c;
      /*printf("Tallennettiin '%c' indeksiin [%d]\n", (char) c, pit);
      */
      pit++;
      /* turha: *pituus = pit; */

    } else {
      lue = 0; /* Aseta lippumuuttuja epätodeksi, ei enää jatketa lukemista */
    }

  } while(lue==1); /* while */


  /*printf("TILANNE: pit %d ja merkki %d\n", pit, c );
  */

  /* 
    lukemisen jälkeen: Jos pit > 0 tai kohdattiin merkki erotin, uudelleenvaraa puskuri-merkkijono (pit + 1)-tavuiseksi 
    ja aseta viimeisen siihen talletetun merkin perään lopetusmerkki '\0'. */

  if(pit > 0 || (char) c == erotin) {
    
    puskuri = (char*) realloc(puskuri, (pit+1)*sizeof(char) ); /* varaa tilaa lopulliselle palautettavalle mj:lle, ja +1 lopetusmerkille */
    puskuri[pit] = (char) '\0';
    *pituus = pit;

    return puskuri;
  }

  if(pit == 0 && c == EOF) {
    /*printf("pit==0 ja EOF\n");
    */
    puskuri = (char*) realloc(puskuri, 0);
    *pituus = 0;
    return puskuri;
  }

  return NULL;

}