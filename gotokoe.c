#include "gotokoe.h"
/* gotokoe.c */

/*

  Toteuta goto-lausetta käyttäen funktio int max2D(int **t2d, int kork, int lev), 
  joka etsii ja palauttaa parametrinaan saamansa kaksiulotteisen int-taulukon t2d suurimman alkion arvon.
  Parametri kork kertoo taulukon korkeuden (ensimmäistä indeksiä vastaavan ulottuvuuden koko) 
  ja lev leveyden (toista indeksiä vastaavan ulottuvuuden koko).

  t2d --> int*[int*, ...] --> [int, int, int]: 

*/

int max2D(int** t2d, int kork, int lev) {

  int max = -9999;
  int** t = t2d; /* hae taulun alku pointterista */
  int* rivi;
  int val = 0;

  unsigned int r = 0; /* rivit-iteraattori */
  unsigned int c = 0; /* sarake-iteraattori */



  goto ALKU_R;
  /* Hyppää seuraavan "iffin" yli */



  /* if-ehto */
  MAX_ASETUS:
    /*printf("aseta max: %d (oli %d) \n", val, max);
    */
    max = val;
    goto OHI_C;
  


  /* Rivin maksimi */
  ALKU_R:
    
    if(!(r < kork)) 
      goto LOPPU_R;
    

    /* Varsinainen koodi */

    /* vaihda riviä */
    rivi = t[r];
    /* käy rivin arvot läpi. Asetetaan alkuarvo */
    c = 0; 
    
    ALKU_C:
      /* päteekö luuppausehto? */
      if(!(c < lev)) 
        goto LOPPU_C;
      
      /* ei, tee itse koodi */
      /*printf("olemme paikassa <%d,%d>\n", r, c);
      */
      val = rivi[c];
      /*printf("> %d\n", val);
      */
      if( val > max)
        goto MAX_ASETUS;
        
      goto OHI_C;
    OHI_C:
      /* luupin kierros ohi, mene alkuun */
      c++;
      goto ALKU_C;
    LOPPU_C: 
      /* ei erityistä. huomaa pakollinen ; tyhjälle statementille! */
      /*printf("Loppui tämä luuppi!");
      */
      goto OHI_R;


    
  OHI_R:
    r++;
    goto ALKU_R;
  LOPPU_R:
    goto RETURN_;


  RETURN_:
    return max;

}