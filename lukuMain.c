#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "luku.h"

/*
  lukuMain.c - Esimerkkikoodi
*/

int main(int argc, char *argv[]) {
  
  char *rivi = NULL;
  size_t pit = 0;

  do {
    
    rivi = lueKunnes(stdin, '\n', &pit); /* Lukee merkkiin '\n' asti eli yhden rivin. */
    
    if(pit > 0) {
      printf("Luin %lu-merkkisen rivin: '%s'\n", (unsigned long) pit, rivi);
      printf("strlen(rivi): %lu\n", (unsigned long) strlen(rivi));
      free(rivi);
    }
    else if(rivi != NULL) {
      printf("Annoit tyhjän rivin, nyt lopetetaan...\n");
      free(rivi);
      break;
    }
    else {
      printf("Syöteriviä ei saatu luettua, joten lopetetaan!\n");
    }
  } while(rivi != NULL); /* Loppuiko syöte (ei saatu edes tyhjää riviä)? */
  
  
  return 0;
}