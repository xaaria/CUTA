#include <stdio.h>
#include <math.h>
#include "piste3d.h"

double etaisyys(Piste3D a, Piste3D b) {
  return sqrt( pow(a.x-b.x, 2) + pow(a.y-b.y, 2) + pow(a.z-b.z, 2) );
}

void tulosta(Piste3D p, int t) {
  printf("(%.*f, %.*f, %.*f)", t, p.x, t, p.y, t, p.z);
}