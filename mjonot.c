#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mjonot.h"

char ** kopioi_mjt(char *mjt[], size_t lkm) {

  /* allocate lkm sized char block of mem with malloc(). That is lkm*size */
  char **cp; /* array of char pointers! [*,*,*,*] -> char */
  int i;
  
  
  cp = malloc(lkm*sizeof(char *)); 

  /**/
  
  for(i=0; i<lkm; i++) {
    char *c; /* place for the copy */
    c = malloc( (strlen(mjt[i])+1) *sizeof(char)); /* allocate memory for copy, returns the mem.addr. */
    
    /* copy current pos. to "c" */
    strcpy(c, mjt[i]);
    
    cp[i] = c;
  }

  return cp;

}

/*

  == Yhteenveto ==
  # Saadaan taulukko mjt, joka sisältää pointtereita (eri mittasiiin) merkkijonoihin. Siksi parametri mjt on char** tai char *mjt[]
  # Alustetaan muuttuja cp, joka on viite taulukkoon joka sis. pointtereita, siis **cp
  # Varataan kopiolle tilaa: koko on elementtien lkm kertaa char-pointterin koko. (malloc saa tämän parametrina). Palauttaa viitteen tämän 
    taulukon alkuun. Siksi cp = malloc(...)
  # (osa 2) Käydään läpi mjt [*,*,*,*...] läpi yksitellen.
  # Varataan siis muistista paikka char:n sisällölle: Varatun muistin määrä on kys. mj:n pituus + lopetusmerkki (eli 1) kertaa char-pointterin koko.
    Ota muistipaikka talteen muuttujaan c.
  # Kopioi nyk. merkkijono c:n osoittamaan paikkaan
  # Kun tämä on tehty X kertaa, palauta alussa luotu muistipaikka cp
    Palautettu cp on siis osoite taulukkoon (/on taulukko) jossa char-pointtereita, jotka os. kopioituihin merkkijonoihin.


*/