#include <stdio.h>
#include <stdlib.h>
#include "kertotaulu.h"

/*
  Läpäissyt testit 2019-02-18
*/

Kertotaulu * luoKertotaulu(uint a, uint b, uint c, uint d) {
  
  Kertotaulu *kt;     /* struct Kertotaulu that has memb. 'kertotaulu'. This pointer is returned */
  uint **kt_;         /* dynamically allocated 2D array */
  uint ai;            /* iterator */
  uint i, j;          /* row and col. iterators */
  i = 1;
  j = 1;

  /* memory for kt */
  kt = malloc( sizeof(Kertotaulu) );

  if(kt == NULL || a > b || c > d) {
    printf("Error\n");
    exit(0);
  }

  kt->a=a; kt->b=b; kt->c=c; kt->d=d;

  /* kts. dia 90 */
  kt_ = malloc( (d-c+2) * sizeof(uint*) ); /* varaa rivejä X kpl, jotka sis. pointterit uint:iin. [*,*,*,*,*] --> [uint, uint ...] */
  if(kt_ == NULL) { printf("Memory error! #1"); exit(0); }
  
  /* Varaa jokaiseen sarakkeeseen rivi joka on Y kokoinen. Palautettu osoite asetetaan sarakkeen arvoksi */
  for(ai=0; ai<(d-c+2); ai++) {
    uint *p;
    p = malloc( (b-a+2) * sizeof(uint) ); /* each sub-array contains d-c+2 blocks (each size is uint).  */
    if(p == NULL) { printf("Memory error! #2"); exit(0); }

    kt_[ai] = p;
  }
  
  /* Osa 2a -- Otsikkorivit ja sarakkeet */
  for(i=1; i<=(d-c+1); i++) {
    kt_[i][0] = c+i-1;
  }
  for(j=1; j<=(b-a+1); j++) {
    kt_[0][j] = a+j-1;
  }

  /* Osa 2b -- Aseta kertolaskun arvot */
  for(i=1;i<=(d-c+1); i++) {
    for(j=1;j<=(b-a+1); j++) {
      uint m;
      m = (i+c-1) * (j+a-1);
      /*printf("[<%u, %u> %u*%u = %3d]", i, j, (a+j-1),(c+i-1), m);
      */
      kt_[i][j] = m;
      
    }
    /*printf("\n");
    */
  }
  /*printf("\n###\n");
  */
  kt->kertotaulu = kt_;
  /* */
  return kt;
}


void tuhoaKertotaulu(Kertotaulu *kt) {

  /*
    Vapauta kt-olion kertotaulu-jäsenen jokaisen indekin pointterin osoittama taulukko.
    Sitten vapauta itse kertotaulu-olio (tai siis viite siihen)
    Lopuksi vapauta koko struct kt
  */
  uint **kt_;
  uint i;
  kt_ = kt->kertotaulu;

  /* Vapauta jokaisen solun osoittama taulukko * -> [*,*,*,*] */
  for(i=0; i <= (kt->d-kt->c+1); i++) {
    /*printf("free %u | ", i); */
    free( kt_[i] );
  }

  /* Vapauta koko olio */
  free(kt_);
  free(kt);

  return;
}