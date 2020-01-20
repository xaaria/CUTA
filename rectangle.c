#include <stdio.h>
#include <stdlib.h>
#include "rectangle.h"

Rectangle * createRectangle(void) {
  
  Rectangle *r;
  Point *p;
  
  r = malloc(1*sizeof(Rectangle));
  p = malloc(1*sizeof(Point));
  
  if(r == NULL || p == NULL) {
    printf("malloc failed!");
    exit(0);
  }

  p->x = 0;
  p->y = 0;
  
  r->height = 0;
  r->width = 0;
  r->origin = *p;

  return r;
}




Rectangle * createRectangle2(Point p) {
  
  Rectangle *r;
  r = malloc(1*sizeof(Rectangle));
  
  if(r == NULL) {
    printf("malloc failed!");
    exit(0);
  }
  
  r->height = 0;
  r->width = 0;
  r->origin = p;

  return r;
}




Rectangle * createRectangle3(int w, int h) {
  
  Rectangle *r;
  Point *p;

  r = malloc(1*sizeof(Rectangle));
  p = malloc(1*sizeof(Point));
  
  if(r == NULL || p == NULL) {
    printf("malloc failed!");
    exit(0);
  }
  
  p->x = 0;
  p->y = 0;

  r->height = h;
  r->width = w;
  r->origin = *p;

  return r;
}




Rectangle * createRectangle4(Point p, int w, int h) {

  Rectangle *r;
  r = malloc(1*sizeof(Rectangle));
  
  if(r == NULL) {
    printf("malloc failed!");
    exit(0);
  }

  r->height = h;
  r->width = w;
  r->origin = p;
  return r;

}



/* change position to given x and y */
void move(Rectangle *r, int x, int y) {
  /* poiner->foo same as (*p).foo */
  r->origin.x = x;
  r->origin.y = y;
}




int getArea(const Rectangle *r) {
  return ( (*r).width * (*r).height) ;
}