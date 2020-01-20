#include <stdio.h>
#include <limits.h>
#include "bitit.h"

/*
  - long ei toimi?
  - WETO valittaa -1:stä
*/

int main(int argc, char *argv[]) {

  printf("System CHAR_BIT: %d \n", CHAR_BIT);

  scharBitit(-33);
  shortBitit(2015);
  intBitit(2015);
  longBitit(2015);


  return 0;
}


void scharBitit(signed char x) {


  unsigned int pos = CHAR_BIT;
  unsigned short num_zeros = 0;
  unsigned short num_ones = 0;

  /*printf("%d\n", x);
  */
  for(pos; pos>=1; pos--) {
      /*printf("pos: %d \n", pos);
      */
    if((x>>pos-1) & 1) {
      printf("1");
      num_ones++;
    } else {
      printf("0");
      num_zeros++;
    }
  }

  printf("\n%d\n%d\n\n", num_zeros, num_ones);
}

void shortBitit(short int x) {

  unsigned int pos = CHAR_BIT*sizeof(short);
  unsigned short num_zeros = 0;
  unsigned short num_ones = 0;

  printf("%d\n", x);

  for(pos; pos>=1; pos--) {
      /*printf("pos: %d \n", pos);
      */
    if((x>>pos-1) & 1) {
      printf("1");
      num_ones++;
    } else {
      printf("0");
      num_zeros++;
    }
  }

  printf("\n%d\n%d\n\n", num_zeros, num_ones);

}

void intBitit(int x) {

  unsigned int pos = CHAR_BIT*sizeof(int);
  unsigned short num_zeros = 0;
  unsigned short num_ones = 0;

  printf("%d\n", x);

  for(pos; pos>=1; pos--) {
      /*printf("pos: %d \n", pos);
      */
    if((x>>pos-1) & 1) {
      printf("1");
      num_ones++;
    } else {
      printf("0");
      num_zeros++;
    }
  }

  printf("\n%d\n%d\n\n", num_zeros, num_ones);

}


void longBitit(long int x) {

  unsigned int pos = CHAR_BIT*sizeof(long int);
  unsigned short num_zeros = 0;
  unsigned short num_ones = 0;

  printf("%d\n", x);

  for(pos; pos>=1; pos--) {
      /*printf("pos: %d \n", pos);
      */
    if((x>>pos-1) & 1) {
      printf("1");
      num_ones++;
    } else {
      printf("0");
      num_zeros++;
    }
  }

  printf("\n%d\n%d\n\n", num_zeros, num_ones);

}

