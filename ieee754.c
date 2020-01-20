#include<stdio.h>
#include<math.h>
#include<string.h>
/*
  ieee754.c

  Toteuta ohjelma, joka saa komentoriviparametrina 32-merkkiä pitkän numeromerkeistä '0' ja '1'
  koostuvan bittijonoa esittävän merkkijonon ja kertoo,
  millaista 32-bittistä IEEE 754 -liukulukua komentoriviparametrin esittämä bittijono vastaa.
*/

int main(int argc, char* argv[]) {

  double v = 0.0;
  long int exp = 0; /* exponent */
  char bits[33] = "";
  strcpy(bits, argv[1]);
  const int CORR = 127;


  /*if(strlen(bits) != 32) { return 0; }
  */


  /* Calculate the 1. part [1.x] */
  int i = 8;
  for(i; i<=strlen(bits)-1; i++) {
    /*printf("%d", i);
    */

    /* If 1, then add */
    if(bits[i]=='1') {
      v += 1/pow(2, exp);
    }
    exp++;
  }

  printf("%.15f\n", 1.0+v);

  /* Calc. 2. part */

  int ci = 7;     /*  */
  int tot = 0;
  int m = 1;      /* multiplier */
  char sign = '+';

  for(ci;ci>=0; --ci) {
    char c = bits[ci];
    /*printf("%c \n", c); */
    m = 1; /* back to 1 */

    /*
      if last is 1, number is -(2^i) + ...
      multiplier m* is set to -1, by default 1
    */
    if(ci==0 && c=='1') {
      m = -1;
      sign = '-';
    }

    if(c == '1') {
      int bit_i = strlen(argv[1])-ci-1;
      /*printf("  %d^%d \n", 2, bit_i);*/
      tot += m*pow(2, bit_i); /* !! */
    }
  }

  double multiplier = pow(2,v-CORR);
  v = tot + multiplier;
  printf("%c\n%.10f\n%.15f\n", sign, multiplier, v);

  return 0;
}




