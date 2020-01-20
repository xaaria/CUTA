#include <stdio.h>
#include <stdlib.h>
/* 

  3 Syöteluvut - luvut.c 

  Toteuta ohjelma, joka lukee käyttäjältä näppäimistöltä double -tyyppisiä
  lukuja ja tulostaa lopuksi ruudulle luettujen lukujen lukumäärän, 
  luetut luvut kasvavaan järjestykseen lajiteltuina, 
  sekä luettujen lukujen summan ja keskiarvon. 
  Tulosta kaikki liukulukuarvot kolmen desimaalin tarkkuudella.

*/

/* sorttausfunktio */
int double_cmp(const void *x, const void *y) {
  double xx = *(double*)x, yy = *(double*)y;
  if (xx < yy) return -1;
  if (xx > yy) return  1;
  return 0;
}


double sum(const double t[], const size_t len) {
  int i = 0;
  double sum = 0.0;
  for(i; i<=len-1; i++) {
    sum += t[i];
  }
  return sum;
} 

/* jos 0 elementtiä, keskiarvo 0.0 */
double avg(const double t[], const size_t len) {
  if(len == 0) { return 0; }
  return sum(t, len) / len;
} 

void printf_arr(const double t[], size_t len) {
  int i = 0;
  for(i; i<=len-1; i++) {
    printf(" %.3lf", t[i]);
  }
}


int main(void) {
  
  size_t koko = 2;
  int i = 0;
  double* vals = (double*) calloc(koko, sizeof(double));
  double sum_, avg_;
  

  /* Aloita arvojen luku striimistä */
  while( scanf("%lf", &vals[i]) == 1) {
    /* tarkasta onko tilaa, ja hanki lisää jos ei */
    if(i >= koko) {
      koko = koko*2;
      vals = (double*) realloc(vals, koko*sizeof(double)); /* uusi muistiosoite, jonka uusi koko on *2 */
    }

    /*printf("tallennettiin arvo %lf\n", vals[i] );
    */
    i++; 
  }
  /* Kun viimeinen luku on luettu, 
  säädä taulukko täsmälleen sen kokoiseksi kuin lukuja varten tarvitaan (eli tee vielä yksi realloc-kutsu). */
  
  koko = i; /* EI i+1. kun tallennettuja 1, myös indeksi on 1 (!)  */
  vals = (double*) realloc(vals, koko*sizeof(double)); 


  /* Suorita arvojen sorttaus. Käytetään qsort() */
  qsort(vals, koko, sizeof(double), double_cmp);

  sum_ = sum(vals, koko);
  avg_ = avg(vals, koko);

  printf("Luettiin %d lukua:", koko);
  printf_arr(vals, koko);
  printf("\n");
  printf("Summa: %.3lf\nKeskiarvo: %.3lf\n", sum_, avg_);

  /* vapauta muisti jotka varattiin */
  free(vals);
  

  return 0;
}