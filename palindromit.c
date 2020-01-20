#include<stdio.h>
#include<string.h>
#include<ctype.h>


int main(int argc, char *argv[]) {

    /*int debug = 0;*/

    /* käy läpi jokainen komentoriviparametri [1-n] */
    int i;
    for(i=1; i<=argc; i++) {

        /*if(debug==1) { printf("%s %u",  argv[i], strlen(argv[i]) ); }
        */
        int ci; /* char index */
        int isPal = 1; /* onko palindromi, tosi oletuksena */

        for(ci=0; ci<=strlen(argv[i])-1; ci++) {
            int len = strlen(argv[i]); /* ei huomioi lopetusmerkkiä */

            /*if(debug==1) { printf(" %c <> %c\n", argv[i][ci], argv[i][len-ci-1]); }*/

            if(tolower(argv[i][ci]) != tolower(argv[i][len-ci-1]) ) {
                /* ei ollut sama, ei ole palindromi */
                isPal = 0;
                printf("\"%s\": ei ole palindromi\n", argv[i]);
                break;

            }
        }
        /* jos totuusarvo säilyi, on pal. */
        if(isPal==1) {
            printf("\"%s\": on palindromi\n", argv[i]);
        }
    }


    return 0;
}
