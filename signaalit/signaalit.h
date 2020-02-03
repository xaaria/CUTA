
#include <setjmp.h>

extern jmp_buf paluuTila;
void hoidaSIGFPE(int s);  /* Funktio, joka on tarkoitettu käsittelemään signaali SIGFPE. */
void hoidaSIGSEGV(int s); /* Funktio, joka on tarkoitettu käsittelemään signaali SIGSSEGV. */