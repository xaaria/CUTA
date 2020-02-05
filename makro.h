
/* Makromäärityksiä - makro.h */

/* [1] */
#ifdef OTE_DEBUG
  #include <stdio.h>
#endif

/* [2] */
#define PII 3.141592653589793

/* [3] Funktiomakro MJ, joka saa yhden parametrin ja muuntaa sen merkkijonoksi (lisää ympärille heittomerkit). */
#define STR_INDIR(x) #x
#define MJ(s) STR_INDIR(s)
 
/* [4] Jos makroa DESIMAALIT ei vielä ole määritetty, määritetään arvomakro DESIMAALIT, jonka arvo (eli korvaulista) on 3. */
#ifndef DESIMAALIT
  #define DESIMAALIT 3 
#endif 

/* [5] Jos makroa TYYPPI ei vielä ole määritetty, määritetään arvomakro TYYPPI, jonka arvo on unsigned char. */
#ifndef TYYPPI
  #define TYYPPI unsigned char
#endif 

/* 
  [6-11]
  Funktiomakro MIN, joka saa kaksi parametria ja palauttaa niistä pieniemän.
    Funktiomakro MAX, joka saa kaksi parametria ja palauttaa niistä suuremman.
  Funktiomakro MIN3, joka saa kolme parametria ja palauttaa niistä pienimmän.
    Funktiomakro MAX3, joka saa kolme parametria ja palauttaa niistä suurimman.
  Funktiomakro MIN4, joka saa neljä parametria ja palauttaa niistä pienimmän.
    Funktiomakro MAX4, joka saa neljä parametria ja palauttaa niistä suurimman. 
*/

#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MAX(a,b) ((a) > (b) ? (a) : (b))

#define MIN3(a,b,c) ((a) < MIN(b, c) ? (a) : MIN(b, c))
#define MAX3(a,b,c) ((a) > MAX(b, c) ? (a) : MAX(b, c))

#define MIN4(a,b,c,d) ((a) < MIN3(b, c, d) ? (a) : MIN3(b, c, d))
#define MAX4(a,b,c,d) ((a) > MAX3(b, c, d) ? (a) : MAX3(b, c, d))


/* [12] */
#ifdef OTE_DEBUG 
  #define debug(msg) (fprintf(stderr, msg))
#else
  #define debug(msg)
#endif