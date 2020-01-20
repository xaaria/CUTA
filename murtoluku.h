/* murtoluku.h */


struct Murtoluku {
  int os;
  int nim;
};

typedef struct Murtoluku Murtoluku;

int min(int a, int b);
int max(int a, int b);

Murtoluku   supistettuML(int os, int nim);
Murtoluku   lisaaML(Murtoluku a, Murtoluku b);
Murtoluku   vahennaML(Murtoluku a, Murtoluku b);
Murtoluku   kerroML(Murtoluku a, Murtoluku b);
Murtoluku   jaaML(Murtoluku a, Murtoluku b);
void        tulostaML(Murtoluku ml);