#include <stdio.h>
#include "asteet.h"

/* does not work */

/* a is a struct. Transform into b */
float muunna(Lampotila a, Asteikko b) {
  
  if(a.asteikko == Celsius && b == Fahrenheit) {
    return a.lampotila*1.8 + 32;
  }
  else if(a.asteikko == Fahrenheit && b == Celsius) {
    return (a.lampotila - 32) / 1.8;
  }
  else if(a.asteikko == Celsius && b == Kelvin) {
    return a.lampotila + 273.15;
  } 
  else if(a.asteikko == Kelvin && b == Celsius) {
    return a.lampotila - 273.15;
  }
  
  /* F to K OR K to F*/
  else if( (a.asteikko == Fahrenheit && b == Kelvin) || (a.asteikko == Kelvin && b == Fahrenheit) ) {
    Lampotila x; /* will contain F/K as C */
    x.lampotila = muunna(a, Celsius);
    x.lampotila = Celsius;

    return muunna(x, b);
  }


  /* if transform from A to A, trivial */
  else if(a.asteikko == b) {
    return a.lampotila;
  }

}

float erotus(Lampotila a, Lampotila b, Asteikko c) {
  Lampotila x;
  x.lampotila = muunna(a, Celsius) - muunna(b, Celsius);
  x.asteikko = Celsius;
  return muunna(x,c);

}