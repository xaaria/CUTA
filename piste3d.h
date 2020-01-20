
struct Piste3D {
  double x;
  double y;
  double z;
};

typedef struct Piste3D Piste3D; /* tietue nimellä Piste3D... */

double etaisyys(Piste3D a, Piste3D b);
void tulosta(Piste3D p, int tarkkuus);