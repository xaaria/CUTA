#include <stdlib.h>
#include <stdio.h>
#include <time.h>
/* 
  -- nykyaika.c --
  Toteuta ohjelma, joka tulostaa ruudulle tämänhetkisen päivämäärän ja ajan muodossa 
  'Viikonpäivä kk.pv.vvvv klo hh:mm', missä viikonpäivä ilmaistaan suomenkielellä 
  ja isolla alkukirjaimella ja aika vastaa järjestelmän aikavyöhykkeen mukaista paikallista aikaa.
*/


int main() {

  char s[100];
  const char* dow[7] = { "Sunnuntai", "Maanantai", "Tiistai", "Keskiviikko", "Torstai", "Perjantai", "Lauantai" };
  time_t nyt  = 0;
  struct tm* gmt_nyt; 
  /*  */
  nyt = time(NULL);
  gmt_nyt = localtime(&nyt);
  

  /* mihin, max merkkiä, formaatti, (mistä) tm-structi */
  strftime(s, 100, "%d.%m.%Y klo %H:%M", gmt_nyt);
  printf("%s %s\n", dow[gmt_nyt->tm_wday], s);

  return 0;
}