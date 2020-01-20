#include <stdio.h>
#include <stdlib.h>
#include "murtoluku.h"

Murtoluku   supistettuML(int os, int nim) {

  int l, s, gcd; /* helpers, larger and smaller. Greatest Common Divisor */
  Murtoluku res; /* actual result var. [if os or nim != 0] */

  /* Make checks first */
  if(os == 0 || nim == 0) {
    Murtoluku zero;
    zero.os = 0;
    zero.nim = 0;
    return zero;
    /* is printed as 0 */
  }
  /* if nim is negative, multpl. both by -1 */
  if(nim < 0) {
    os *= -1;
    nim *= -1;
  }

  /* ALG. starts */
  l = max( abs(os), abs(nim) );
  s = min( abs(os), abs(nim) );

  while(l != s) {
    l -= s;
    if(l < s) {
      int tmp;
      tmp = l;
      l = s;
      s = tmp;
    }
  }
  /* after l == s */
  gcd = l; /* or s */

  /* Part 2 */
  
  res.os = os/gcd;
  res.nim = nim/gcd;
  
  return res; 

}

Murtoluku   lisaaML(Murtoluku a, Murtoluku b) {
  
  int m1, m2;
  m1 = a.nim;
  m2 = b.nim;
  
  a.os *= m2;
  a.nim *= m2;

  b.os *= m1;
  b.nim *= m1;

  /* */
  return supistettuML(a.os+b.os, b.nim);
}

Murtoluku   vahennaML(Murtoluku a, Murtoluku b) {
  int m1, m2;
  m1 = a.nim;
  m2 = b.nim;
  
  a.os *= m2;
  a.nim *= m2;

  b.os *= m1;
  b.nim *= m1;

  /* */
  return supistettuML(a.os-b.os, b.nim);
}

Murtoluku   kerroML(Murtoluku a, Murtoluku b) {
  return supistettuML(
    a.os*b.os,
    a.nim*b.nim
  );
}

/* Jakolasku on kertomista käänteisluvulla! */
Murtoluku   jaaML(Murtoluku a, Murtoluku b) {
  
  /* Swtich b's values */
  int tmp;
  tmp = b.os;
  b.os = b.nim;
  b.nim = tmp;
  return kerroML(a,b);
}

void        tulostaML(Murtoluku ml) {
  if(ml.os != 0 && ml.nim != 1) {
    printf("%d/%d", ml.os, ml.nim);
  }
  else if (ml.os == 0) {
    printf("0");
  } 
  /* nim == 0, print as int */
  else if(ml.nim == 1) {
    printf("%d", ml.os);
  }
  else {
    printf("Error at printing");
    exit(0);
  }

}


int min(int a, int b) {
  return (a <= b) ? (a) : (b);
}
int max(int a, int b) {
  return (a >= b) ? (a) : (b);
}