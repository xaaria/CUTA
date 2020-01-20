#include <stdlib.h>
#include "tulostus.h"

int main(int argc, char *argv[]) {
  

  if(argc == 5) {
    
    int lkm = atoi(argv[1]);
    double* t = (double*) malloc(lkm*sizeof(double));
    int i = 0;
    
    for(i = 1; i <= lkm; ++i) {
      t[i-1] = (double) i / 16;
    }
    tulostaDblTaulu(t, lkm, argv[2], atoi(argv[3]), argv[4]); 
  }
  

  return 0;
}