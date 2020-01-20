#include <stdio.h>
#include <stdlib.h>
#include "rectangle.h"
#include "vertailu.h"

static void tulostaRT(Rectangle* rt[], int lkm) {
  int i = 0;
  for(i = 0; i < lkm; ++i) {
    printf("%d %d %d %d\n", rt[i]->origin.x, rt[i]->origin.y, rt[i]->width, rt[i]->height);
  }
  printf("\n");
}

int main(int argc, char *argv[]) {

  int i = 0;

  /* pointteri alkuun ja koko-1 */
  qsort(argv + 1, argc - 1, sizeof(char *), mjPitAakkosVrt);
  for(i = 1; i < argc; ++i) {
    printf("%s\n", argv[i]);
  }



  
  Rectangle* rt[4];
  rt[0] = createRectangle3(10, 20);
  move(rt[0], 5, 5);

  rt[1] = createRectangle3(8, 5);
  move(rt[1], 5, -5);

  rt[2] = createRectangle3(7, 100);
  move(rt[2], -10, 25);
  
  rt[3] = createRectangle3(20, 20);


  qsort(rt, 4, sizeof(Rectangle *), rectAlaVrt);
  tulostaRT(rt, 4);

  qsort(rt, 4, sizeof(Rectangle *), rectXyVrt);
  tulostaRT(rt, 4);

  qsort(rt, 4, sizeof(Rectangle *), rectLeveysVrt);
  tulostaRT(rt, 4);
  
  for(i = 0; i < 4; ++i) {
    free(rt[i]);
  }
  
  return 0;
}