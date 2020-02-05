#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <setjmp.h>
#include <signal.h>
#include "signaalit.h"

/*
  ohjelma, joka lukee käyttäjältä standardisyötteestä syöterivejä niin kauan, 
  kuin luettu rivi on jotain alla mainituista kolmesta muodosta 
  (muoto esitetään alla käyttäen scanf-funktion lukumääreitä)
    lisää %d %d
    tulosta %u
    tulosta


  TODO: Tarkista, että annettu komento on täsmälleen haluttu, ei vain että tyyppi on oikea...
  (jos automaattinen tarkistus tätä vaatii)

*/

int DEBUG = 0;

int main(int argc, char* argv[]) {


  int command = 0;
  unsigned int luvut_lkm  = 0;
  unsigned int koko = 1;
  int* luvut = (int*) calloc( koko, sizeof(int)  ); /* varaa sitä mukaan kun tilaa tarvitaan, aluksi koko=1 (!) */ 
  

  /* parametrit */
  int a, b;
  unsigned int c;
  char cmd2[100];

  /* aseta poikkeustenjäsittelijäfunktiot. <signal.h> */
  signal(SIGFPE,  hoidaSIGFPE);
  signal(SIGSEGV, hoidaSIGSEGV);

  while(1==1) {

    char cmd[100];

    if(fgets(cmd, 100, stdin) == NULL) {
      return 0; /* lopeta saman tien... */
    }

    /* 
      Tunnista mikä komento annettiin.
      Aseta muuttuja command tämän mukaan.
    */
    
  
    if( sscanf(cmd, "%s %d %d", &cmd2, &a,&b) == 3) {
      command = 1;
    }
    else if( sscanf(cmd, "%s %d", &cmd2, &c) == 2 ) {
      command = 2;
    }
    else if( sscanf(cmd, "%s", &cmd2) == 1 ) {
      command = 3;
    } 
    else {
      /* lopeta koko ohjelman suoritus */
      exit(0);
    }

    fflush(stdin);

    /* 
      Jatka tästä jos komento on onnistuneesti luettu ja tulkittu.
      Muuttuja command pitää tiedon siitä mikä komento annettiin
    */

      

    switch(setjmp(paluuTila)) {
      case 0:
        
        if(command==1) {
          
          int arvo = 0;

          /* tarvitaanko lisää muistikapasiteettia? */
          
          if(DEBUG==1) { printf("-- koko: %d, _lkm: %d --\n", koko, luvut_lkm ); }

          /* jos koko on sama kuin kapasiteetti JA ei olla 1. lisäyksessä, niin kasvata tilaa */
          if( luvut_lkm != 0 && koko == luvut_lkm ) {
            
            luvut = (int*) realloc( luvut, (koko++)*sizeof(*luvut) );
            /*koko++;*/

            if(luvut==NULL) { exit(0); }
            if(DEBUG==1) { printf("tilaa on nyt %d:lle\n", koko ); }
          }

          /* lisää jakolaskun tulos taulukkoon */
          
          arvo = a/b;
          luvut[luvut_lkm] = arvo;
          luvut_lkm += 1;
          if(DEBUG==1) { printf("lisattiin... koko: %d\n", luvut_lkm); }
        }

        else if(command==2) {
          printf("%d\n", luvut[c]);
          /*printf("%d\n @ %d", luvut[b], b );*/
        } 

        else if(command == 3) {
          size_t i = 0;

          if(DEBUG==1) { printf("len %d\n", koko); }

          for(; i < koko; i++) {
            printf("%d", luvut[i]);
            if(i != koko-1) {
              printf(" "); /* lukujen väliin väli */
            }
          }
          printf("\n");
        }

        break;
      
      case SIGSEGV:
        printf("Aiheutui signaali SIGSEGV\n");
        break;
      
      case SIGFPE:
        printf("Aiheutui signaali SIGFPE\n");
        break;

      default:
        printf("Aiheutui signaali UNKNOWN\n");
        break;
    }



  }

  return 0;
}