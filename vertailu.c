/* Teht. 3 - Lajittelu */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rectangle.h"
#include "vertailu.h"

/*
 Luo suorakulmion annetuilla param. ja (0,0) sijaintina.
*/
Rectangle* createRectangle3(int w, int h) {
  
  Rectangle* r  = (Rectangle*) malloc(sizeof(Rectangle));
  r->origin.x = 0; r->origin.y = 0;
  r->height   = h;
  r->width    = w;
  return r;
}

/* Siirrä keskipistettä x ja y verran */
void move(Rectangle *r, int x, int y) {
  r->origin.x += x;
  r->origin.y += y;
}

int getArea(const Rectangle *r) {
  return r->width * r->height;
}


int rectAlaVrt(const void *a, const void *b) {
  /* A verrattuna B. jos isompi, palauta 1 jne... */
  int aa, ab;
  Rectangle *a_;
  Rectangle *b_;

  a_ = *(Rectangle**) a;
  b_ = *(Rectangle**) b;

  aa = getArea(a_);
  ab = getArea(b_);

  /*printf("<%d %d %d %d>", a_->height, a_->width, b_->height, b_->width);
  */
 
  if(aa > ab) {
    return 1;
  }
  else if(ab < aa) {
    return -1;
  }
  return 0;


}


/*
  Jos kahden Rectangle-olion origin-jäsenten x-koordinaatit ovat keskenään erisuuret, 
  määräytyy järjestys niiden välisen vertailun perusteella. 
  Jos x-koordinaatit ovat keskenään yhtäsuuret, määräytyy järjestys y-koordinaattien vertailun perusteella. 
  Tulos on näin ollen 0 vain jos sekä x- että y-koordinaatit ovat samat.
*/
int rectXyVrt(const void *a, const void *b) {
  
  /* a ja b ovat pointtereita rect-pointteriin. Siispä castaa pointteriksi rect pointteriin,
  ja sitten hae sen arvo, eli rect-pointer. */
  Rectangle* ra = *(Rectangle**) a;
  Rectangle* rb = *(Rectangle**) b;

  if(ra->origin.x > rb->origin.x) {
    return 1; /* ra suurempi */
  } else if(ra->origin.x < rb->origin.x) {
    return -1; /* jos b onkin a:ta suurempi */
  } else {

    /* jos yhtä suuret: sekundaarinen lajittelu */
    if(ra->origin.y > rb->origin.y) {
      return 1;
    } else if(ra->origin.y < rb->origin.y) {
      return -1;
    } else {
      return 0; /* täysin samat origin-pisteet */
    }

  }

  /* ei koskaan päästä tänne asti? */
  return 0;
}

/*
 Ilmeisesti ensin leveys, sitten korkeus
*/
int rectLeveysVrt(const void *a, const void *b) {

  Rectangle* ra = *(Rectangle**) a;
  Rectangle* rb = *(Rectangle**) b;

  if( ra->width > rb->width ) { 
    return -1; 
  } else if(ra->width < rb->width) { 
    return 1; 
  } else {
    /* vertailu kork. mukaan */
    if( ra->width > rb->width ) { 
      return -1; 
    } else if( ra->width < rb->width ) {
      return 1;
    } else {
      return 0;
    }
  }

  return 0;
}

/* Lyhimmät ensin, saman pit. aakkosellisesti */
int mjPitAakkosVrt(const void *a, const void *b) {

  char* ma = *(char**) a;
  char* mb = *(char**) b;

  if( strlen(ma) != strlen(mb) ) {
    /* eivät samanmittaiset, katso pituuden mukaan */
    if(strlen(ma) > strlen(mb)) { return -1; } else { return 1; }
  } else {
    /* aakkosellisesti. Käy merkki kerrallaan, jos eivät samat, tee vertailu ja palauta tulos heti */
    int i = 0;
    for(i=i; i<=strlen(ma)-1; i++) {
      if(ma[i] != mb[i]) {
        if(ma[i] > mb[i]) { return 1; } else { return -1; }
      }
    }
  }

  return 0; /* tasapeli! */
}