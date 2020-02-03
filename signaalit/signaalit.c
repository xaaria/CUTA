#include <setjmp.h>
#include <signal.h>
#include "signaalit.h"


jmp_buf paluuTila;


/* Funktio, joka on tarkoitettu käsittelemään signaali SIGFPE. */
void hoidaSIGFPE(int sig) {
  longjmp(paluuTila, SIGFPE);
}

 /* Funktio, joka on tarkoitettu käsittelemään signaali SIGSSEGV. */
void hoidaSIGSEGV(int sig) {

  /* mihin hypätään */
  longjmp(paluuTila, SIGSEGV);

}