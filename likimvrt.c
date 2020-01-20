#include<stdio.h>
#include <math.h>
#include "likimvrt.h"

/*
likimvrt.c

math.h for fabs() : absolute val. function
*/

static double tol = 0.000001;

/*
int main(void) {

  double d = 3*0.1;
  if(d == 0.3)
  {
    printf("Arvo d = %.20f on %.20f\n", d, 0.3);
  }
  else
  {
    printf("Arvo d = %.20f ei ole %.20f\n", d, 0.3);
  }
  printf("Toleranssi: %.20f\n", lueToleranssi());
  if(doubleVrt(d, 0.3))
  {
    printf("Arvo d = %.20f on likim‰‰rin %.20f\n", d, 0.3);
  }
  else
  {
    printf("Arvo d = %.20f ei ole likim‰‰rin %.20f\n", d, 0.3);
  }
  asetaToleranssi(0.0000000000000000001);
  printf("Uusi toleranssi: %.20f\n", lueToleranssi());
  if(doubleVrt(d, 0.3))
  {
    printf("Arvo d = %.20f on likim‰‰rin %.20f\n", d, 0.3);
  }
  else
  {
    printf("Arvo d = %.20f ei ole likim‰‰rin %.20f\n", d, 0.3);
  }
  return 0;
}
*/


double lueToleranssi() {
  return tol;
}

void asetaToleranssi(double t) {
  tol = t;
}

/* returns 0/1 */
int doubleVrt(double a, double b) {

  /* smaller or equal than */
  if(fabs(a-b) <= tol) {
    return 1;
  } else {
    return 0;
  }

}
