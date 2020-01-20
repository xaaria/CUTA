#include <stdio.h>
#include "kortit.h"


const char *MAIDEN_NIMET[MAA_LKM + 1] = {"", "Hertta","Ruutu","Risti","Pata" };
const char *KORTTIEN_NIMET[MAA_KOKO + 1] = { "","ässä", "kakkonen", "kolmonen", "nelonen", "viitonen", "kuutonen", "seiska", "kasi", "ysi", "kymppi", "jätkä", "rouva", "kunkku" };


void tulostaKortti(Kortti k) {
  printf("%s%s", MAIDEN_NIMET[k.maa], KORTTIEN_NIMET[k.arvo]);
}

void tulostaKorttiOs(const Kortti *k) {
  printf("%s%s", MAIDEN_NIMET[(*k).maa], KORTTIEN_NIMET[(*k).arvo]);
}