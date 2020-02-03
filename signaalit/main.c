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

/* lukee käyttäjän syötteen, tallentaa sen taulukkoon str. Syötettä luetaan max. 255 merkkiä */


int main(int argc, char* argv[]) {


  int command = 0;
  int* luvut = NULL; /* varaa sitä mukaan kun tilaa tarvitaan, aluksi koko=0 */ 
  unsigned int luvut_lkm = 0;

  /* parametrit */
  int a, b;
  unsigned int c;
  char cmd2[50];

  /* aseta poikkeustenjäsittelijäfunktiot. <signal.h> */
  signal(SIGFPE,  hoidaSIGFPE);
  signal(SIGSEGV, hoidaSIGSEGV);

  while(1==1) {

    char cmd[100];

    if(fgets(cmd, 50, stdin) == NULL) {
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
    } else {
      /* lopeta koko ohjelman suoritus */
      return 0;
    }


    /* 
      Jatka tästä jos komento on onnistuneesti luettu ja tulkittu.
      Muuttuja command pitää tiedon siitä mikä komento annettiin
    */

      

    switch(setjmp(paluuTila)) {
      case 0:
        
        if(command==1) {
          
          int arvo = 0;

          /* tarvitaanko lisää muistikapasiteettia? */
          if( (sizeof(luvut) / sizeof(int)) >= luvut_lkm ) {
            luvut = (int*) realloc( luvut, (luvut_lkm+1)*sizeof(int) );
          }

          /* lisää jakolaskun tulos taulukkoon */
          
          arvo = a/b;
          luvut[luvut_lkm] = arvo;
          luvut_lkm += 1;
        }

        else if(command==2) {
          printf("%d\n", luvut[c]);
          /*printf("%d\n @ %d", luvut[b], b );*/
        } 

        else if(command == 3) {
          size_t i = 0;
          size_t len = sizeof(luvut) / sizeof(int);

          for(; i < len; i++) {
            printf("%d", luvut[i]);
            if(i != len-1) {
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