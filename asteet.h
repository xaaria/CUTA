
enum Asteikko {
  Celsius,
  Fahrenheit,
  Kelvin
};


typedef enum Asteikko Asteikko;

struct Lampotila {
  float lampotila;
  Asteikko asteikko;
};

typedef struct Lampotila Lampotila;


/* funcs */
float muunna(Lampotila a, Asteikko b);
float erotus(Lampotila a, Lampotila b, Asteikko c);