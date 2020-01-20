#include<stdio.h>
/*
  utf8.c
  utf8.h
*/

/*
  11000011 on 195 ja 10100100 on 164 eli
  tämä tavupari kuvaa UTF-8-koodauksessa merkkiä 'ä'.
*/




#include "utf8.h"

int main(void) {
  unsigned int koodit[6] = {228, 49340, 49457, 12477, 12491, 12540};
  unsigned char utf8[5];
  int i = 0;

  for(i = 0; i < 6; ++i) {
    utf8_koodaa(koodit[i], utf8);
    printf("%s\n", utf8);
  }
  return 0;
}



void utf8_koodaa(unsigned int merkki, unsigned char utf8[]) {


}
