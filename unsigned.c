#include<stdio.h>
#include<string.h>
#include<limits.h>
#include "unsigned.h"

/*
 -- tehtävänä on toteuttaa neljä funktiota, jotka toteuttavat edellä kuvatunlaisen
 intervallin arvojen tulostuksen neljälle eri etumerkittömälle tyypille.
 Funktiot eroavat toisistaan ainoastaan sen suhteen, mitä etumerkitöntä tyyppiä arvojen käsittelyssä käytetään.
*/

int main(int argc, char* argv[]) {


  ucharIntervalli(150, 50);
  printf("\n");
  ushortIntervalli(45000, 15000);
  printf("\n");
  uintIntervalli(3300000000, 1100000000); /* 3,3 & 1,1 mrd*/
  printf("\n");
  ulongIntervalli(9000000000000000000, 3000000000000000000);


  return 0;
}

/*
Mene väli [-sade, sade], muuttaen arvot unsigned char:ksi.
Täten esim. -150 muuttuu luvuksi 106  (UMAX-sade+1 ==> 255-100+1 = 106)
*/
void ucharIntervalli(unsigned char sade, unsigned char askel) {

  printf("unsigned char:");

  int v = -sade;
  while(v <= sade) {
    printf(" %d", (unsigned char) v);
    v += askel;
  }


}

/* [−32,767, +32,767]  */
void ushortIntervalli(unsigned short sade, unsigned short askel) {

  printf("ushortIntervalli:");
  int v = -sade;
  while(v <= sade) {
    printf(" %d", (unsigned short int) v);
    v += askel;
  }
}

void uintIntervalli(unsigned int sade, unsigned int askel) {

  printf("uintIntervalli:");
  int i = 0;

  while(-sade + i*askel < -sade + (i+1)*askel ) {

    printf(" %lu", -sade + i*askel);
    printf("  [seur: %li] \n", -sade + (i+1)*askel );
    i++;
  }

  while(-sade + i*askel <= sade && -sade + i*askel >= 0) {

    printf(" %lu", -sade + i*askel);
    printf("  [seur: %li] \n", -sade + (i+1)*askel );
    i++;
  }

  /*printf("%ui", -1100000000);
  */
}



void ulongIntervalli(unsigned long sade, unsigned long askel) {

  printf("ulongIntervalli:");
  long int v = -sade;
  while(v <= sade) {
    printf(" %d", (unsigned long int) v);
    v += askel;
  }

}
