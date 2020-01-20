/* genhaku.c */
#include <stdio.h>
#include "genhaku.h"
/*
 onko n-alkioisessa taulukossa mista jokin sellainen kohta, jossa esiintyy
 m-alkioisen taulukon mita kaikki alkiot (per�kk�in ja alkuper�isess� j�rjestyksess�).
 Jos v�hint��n yksi t�llainen kohta l�ytyy, palauttaa funktio ensimm�isen sellaisen kohdan indeksin.
 Muussa tapauksessa palautetaan arvo n.
 Huomaa, ett� taulukot mista ja mita vastaanotetaan geneerisin�.

 if( *(a+1)==1) {

  *( ((char*)mista)+(3*koko) )
*/

size_t etsi(void *mista, size_t n, void *mita, size_t m, size_t koko) {

  unsigned int i = 0;
  size_t matches = 0; /* osuman pituus. Jos sama kuin m: osuma */


  for(i=i;i<n; i++) {

    /*printf("%u | ", i);
    */

    char c1 = *( ((char*)mista) + (i*koko) );
    char c2 = *( ((char*)mita) + (matches*koko) );

    /*printf("%d <> %d |", c1, c2);
    */
   printf("%d <> %d |", c1, c2);

    if( c1==c2 ) {
      /*printf("\t--> sama!");
      */
      matches++;

      /* jos osuma, palauta nyk. indeksi miinus pituus, eli matchin alkuindeksi */
      if(matches == m) {
        size_t mi = i+1-m;
        printf("Osuma indeksissa: %u. matches: %u ", mi, matches);
        
        return mi;
      }

    } else {
      /* ei osumaa, nollaa osumamäärä */
      matches = 0;
      /*continue;*/
    }
    /*printf("\n");*/
  }

  /* else, no match */
  /*printf("palauta N");
  */
  return n;
}
