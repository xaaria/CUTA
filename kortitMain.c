#include <stdio.h>
#include <locale.h>
#include "kortit.h"

int main()
{


  Kortti pakka[KORTTI_LKM];
  int i = 0;
  Maa m;
  Arvo a;
  for(m = HERTTA; m <= PATA; ++m) /* Kaikki maat läpi. */
  {
    for(a = ASSA; a <= KUNKKU; ++a) /* Kaikki arvot läpi. */
    {
      pakka[i].maa = m;
      pakka[i].arvo = a;
      if(i % MAA_KOKO) /* Välilyönti tai rivinvaihto kortin eteen? */
      {
        printf("%c", ((i % 4) == 0) ? '\n' : ' ');
      }
      if(i % 2)
      { /* Tulostaa joka toisen kortin tavallisesti... */
        tulostaKortti(pakka[i]);
      }
      else
      { /* ... ja joka toisen osoittimen kautta. */
        tulostaKorttiOs(&pakka[i]);
      }
      i += 1; /* pakka-taulukon indeksin kasvatus. */
    }
    printf("\n"); /* Rivinvaihto pakan perään. */
  }
  return 0;
}