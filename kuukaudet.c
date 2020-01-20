#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "kuukaudet.h"
/*
  kuukaudet.c
  + kuukaudet.h
*/

const char *KK_NIMET[KK_LKM] = {
  "tammikuu","helmikuu","maaliskuu",
  "huhtikuu","toukokuu","kesäkuu",
  "heinäkuu","elokuu","syyskuu",
  "lokakuu","marraskuu","joulukuu"
};

/* index 0 for regular year, 1 for leap year */
const char KK_PAIVAT[2][KK_LKM] = {
  {31,28,31,30,31,30,31,31,30,31,30,31},
  {31,29,31,30,31,30,31,31,30,31,30,31}
};


/*int main(void) {

  printf("Helmikuu 2016: %d päivää\n", kkPituus("Helmikuu", 2016));
  printf("Helmikuu 2100: %d päivää\n", kkPituus("helmikuu", 2100));
  printf("Helmi kuu 2100: %d päivää\n", kkPituus("helmi kuu", 2100));
  
  return 0;
}
*/

/*
  Returns number of days in given month.
  -1 month name not invalid.
*/
char kkPituus(const char kkNimi[], int vuosiluku) {

  /* try to find string kkNimi from the list of months */
  int mi = -1; /* month index */
  int yi = 0;

  mi = nimenIndeksi(kkNimi);

  if(mi == -1) { return -1; }

  /* month num is valid [0,11] */
  
  yi = karkausvuosi(vuosiluku); /* param year index. returns 0 or 1 */
  /*printf("Karkasuvuosi? = %d\n | %d", yi, mi);
  */
  return KK_PAIVAT[yi][mi];

}

/*
  does s match any of strings in KK_NIMET

  to fix: length check
*/
short nimenIndeksi(const char str[]) {

  /*printf("IN >> '%s'\n", str);
  */

  int mi=0;
  for(mi; mi < KK_LKM; mi++ ) {

    int match = 1; /* match by default */
    int ci = 0;
    /*printf("  Tarkastelussa: %s\n", KK_NIMET[mi]);
    */
    
    /* quick check: Check lengths! */
    if(strlen(str) != strlen(KK_NIMET[mi]) ) {
      /*printf("Lens don't match\n");
      */
      match = 0;
      continue;
    }

    
    for(ci; ci<strlen(str); ci++) {

      char c1;
      char c2;
      c1 = tolower(str[ci]);
      c2 = tolower(KK_NIMET[mi][ci]);
      /*printf("    Vertaillaan %c <> %c\n", c1, c2 ); 
      */
      if( c1 != c2  ) {
        /*printf("#\n");
        */
        match = 0;
        /* If chars don't match, just jump to the next month */
        break;
      }
    
    }
    if(match==1) {
      return mi; /* matching month index */
    }

  }
  return -1; /* Given str (month name) didn't match any existing month name! */

}



/*
  Returns boolean value: is year a leap year.
  0 false, 1 true
*/
int karkausvuosi(int y) {
  if(y % 4 != 0 ) {
    return 0;
  }
  else if (y % 100 != 0) {
    return 1;
  }
  else if(y % 400 != 0) {
    return 0;
  }
  return 1;
}
