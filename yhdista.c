#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include "yhdista.h"

/*
  Toteuta määräämättömän määrän parametreja ottava funktio char *yhdista(const char *mj, ...), 
  joka palauttaa uuden dynaamisesti luodun merkkijonon, johon on asetettu kaikki parametreina 
  saadut merkkijonot peräkkäin (ne on liitetty yhteen). Käytetään tehtävässä sopimusta, 
  että viimeisen varsinaisen merkkijonon jälkeen annetaan parametrina 
  NULL ilmaisemaan parametrien päättymistä.

  esim. parametreilla "yksi kaksi kolme neljä viisi kuusi seitsemän kahdeksan" 
  tulostus on "Parametrien liitos: yksikaksikolmeneljäviisikuusiseitsemänkahdeksan (pituus: 49)"
*/
int DEBUG = 0;

char* yhdista(const char *mj, ...) {

  unsigned int koko = 1;
  char* sana = (char*) malloc( sizeof(char) * (strlen(mj)+1) ); /* varaa tilaa yhdelle merkille */
  unsigned int lisatty = strlen(mj); /* montako merkkiä on yhteensä tallenenttu. Lopetusmerkkiä ei huomioitu */


  va_list args;     /* structi paramereille */
  char* w = NULL;   /* yksittäinen sana listasta */

  strcpy(sana, mj);

  sana[lisatty] = '\0';

  /* alustaa va_list:n parameterilla jotka tulevat param. "mj" jälkeen */
  va_start(args, mj); 
 
  /* lue listaa kunnes lopetusarvo NULL saavutetaan */
  while( (w = va_arg(args, char*)) != NULL ) {
    
    if(DEBUG==1)
      printf(">> %s (%d)\n", w, strlen(w));

    /* varaa tilaa lisää sen verran kuin uudessa merkkijonossa olisi verran. +1 lopetusmerkille */
    sana = (char*) realloc(sana, sizeof(char) * (lisatty+strlen(w)+1) );
    lisatty += strlen(w);
    /*sana[lisatty] = '\0';*/

    /* siirrä parametrin sisältö sananlistan loppuun */
    strncat(sana, w, 1000);

    /* tulosta tämän jälkeen koko sana */
    if(DEBUG==1)
      printf("\t'%s' (%d)\n", sana  ,strlen(sana));

  }

  va_end(args); /* sulje parametrilista */

  sana[lisatty] = '\0';

  return sana; /* palauta char* sanaan */

}