#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

/*
  Läpäissyt WETON testit 2019-02-26
*/



/* Palauta solmun i sisältö, tai 0 jos laiton indeksi */
double dl_alkio(const DblLista *lista, size_t i) {
  
  DblSolmu s;
  int si = 0; /* solmu indeksi */

  if(i < 0 || i > lista->n) { 
    /*printf("Laiton indeksi\n n: %d", lista->n);
    */
    return 0; 
  } /* Laiton väli */

  s = *(lista->paa);

  /* mene eteenpäin aina indeksiin i asti. Jos tulee umpikuja: virhe */
  for(si=0; si<i; si++) {
    s = *(s.seur);
  }
  return s.data;

}



DblSolmu * dl_lisaa(DblLista *lista, size_t i, double arvo) {
  
  DblSolmu *u;  /* solmu joka asetetaan */
  DblSolmu *e;  /* edeltävä solmu */
  DblSolmu *s;
  int wi = 0;
  DblSolmu x = {-1, NULL};

  u = malloc( sizeof(DblSolmu) ); 
  /*e = malloc( sizeof(DblSolmu) );*/
  u->data = arvo;
  s = lista->paa;
  
  e = &x;

  /* jos i suurempi kuin alkioiden määrä: pävitä i listan kooksi */
  if(i >= lista->n) {
    /*printf("i on %d ", lista->n);
    */
    i = lista->n;
  }

  /* lista tyhjä, listan alkuun */
  if(i == 0 && lista->n == 0) {
    u->seur = NULL;
    lista->n = 1;
    lista->paa = u;
    /*free(e);*/
    return u;
  }

  /* mene solmuun i . s on iteroinnissa käytetty solmu */
  while(wi != i) {
    e = s;
    s = s->seur;
    wi++;
  }
  /* s on nyt solmu jonka ETEEN (=ennen) lyödään uusi solmu u */
  /* s:n seuraava on i:nnen solmun seuraava [e]->(u)->[s] */
  e->seur = u; 
  u->seur = s;
  
  /* jos lisäys tapahtui päähän. Listan pää on uusi solmu */
  if(i==0) {
    lista->paa = u;
  }
  
 
  lista->n += 1; /* listan kokoa pitää päivittää */
  return u;
}

/* Poista indeksistä i, ja palauta poistettavan arvo. 0 jos laiton indeksi */
double dl_poista(DblLista *lista, size_t i) {
  
  int it;
  double retVal;
  DblSolmu *s = lista->paa;
  DblSolmu *e = lista->paa;

  /* Parametrin tarkistus */
  if(i < 0 || i > lista->n) { return 0; }
 
  /* jos alusta. Listan koko on varmistettu olevan >= 1 */
  if(i==0) {
    /* Ota arvo taleteen, siirrä listan pää seuraavaan (voi olla tyhjä), pienennä kokoa yhdellä ja palauta arvo */
    double ret = lista->paa->data;
    lista->paa = lista->paa->seur;
    lista->n -= 1;
    return ret;
  }

  /* Etsi indeksin solmu */
  for(it=0; it<i; ++it) {
    e = s;
    s = s->seur;
    /*printf("\n>>%d %d", it, s->data );
    */ 
  }

  /* S on jälleen indeksin solmu. Poistetaan se */
  retVal = s->data;    /* ota talteen palautettava arvo */
  e->seur = s->seur;    /* Aseta edellinen osoittamaan s:n seuraavaan */
  free(s);           /* s:ää ei enää tarvita missään */
  
  /*printf(" #%d  \n", e->data );
  */
  /* muista päivittää koko */
  lista->n -= 1;
  return retVal;

}



/*  ### Valmiit ### */



DblSolmu * ds_luo(double data, DblSolmu *seur) {
  DblSolmu *ds = malloc(sizeof(DblSolmu));
  ds->data = data;
  ds->seur = seur;
  return ds;
}


DblLista * dl_luo(void) {
  DblLista *dl = malloc(sizeof(DblLista));
  dl->n = 0;
  dl->paa = NULL;
  return dl;
}


void dl_tuhoa(DblLista *dl) {
  while(dl->n > 0) {
    dl_poistaEdesta(dl);
  }
  free(dl);
}


DblSolmu * dl_lisaaEteen(DblLista *dl, double arvo) {
  dl->paa = ds_luo(arvo, dl->paa);
  dl->n += 1;
  return dl->paa;
}


double dl_poistaEdesta(DblLista *dl) {
  double arvo = 0;
  if(dl->n > 0) {
    DblSolmu *vanhaPaa = dl->paa;
    arvo = dl->paa->data;
    dl->paa = dl->paa->seur;
    free(vanhaPaa);
    dl->n -= 1;
  }
  return arvo;
}


void dl_tulosta(const DblLista *lista) {
  DblSolmu *s;
  printf("Lista:");
  for(s = lista->paa; s != NULL; s = s->seur)
  {
    printf(" %.1f", s->data);
  }
  printf("\n");
}