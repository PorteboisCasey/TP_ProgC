#include <stdio.h>
#include <limits.h>
#include <float.h>

/**
 * Programme qui affecte et affiche des valeurs pour chaque type de base
 * Exercice 1.4 du TP1
 */
int main() {
    printf("Affectation et affichage des variables de types de base :\n");
    printf("--------------------------------------------------------\n\n");
    
    // Types caractères
    char c = 'A';
    unsigned char uc = 255;
    signed char sc = -128;
    
    printf("char               : %c (valeur ASCII: %d)\n", c, c);
    printf("unsigned char      : %u\n", uc);
    printf("signed char        : %d\n\n", sc);
    
    // Types entiers courts
    short s = 32767;
    unsigned short us = 65535;
    signed short ss = -32768;
    
    printf("short              : %d\n", s);
    printf("unsigned short     : %u\n", us);
    printf("signed short       : %d\n\n", ss);
    
    // Types entiers
    int i = 2147483647;
    unsigned int ui = 4294967295U;
    signed int si = -2147483648;
    
    printf("int                : %d\n", i);
    printf("unsigned int       : %u\n", ui);
    printf("signed int         : %d\n\n", si);
    
    // Types entiers longs
    long int li = 9223372036854775807L;
    unsigned long int uli = 18446744073709551615UL;
    signed long int sli = -9223372036854775808L;
    
    printf("long int           : %ld\n", li);
    printf("unsigned long int  : %lu\n", uli);
    printf("signed long int    : %ld\n\n", sli);
    
    // Types entiers très longs
    long long int lli = 9223372036854775807LL;
    unsigned long long int ulli = 18446744073709551615ULL;
    signed long long int slli = -9223372036854775808LL;
    
    printf("long long int      : %lld\n", lli);
    printf("unsigned long long : %llu\n", ulli);
    printf("signed long long   : %lld\n\n", slli);
    
    // Types à virgule flottante
    float f = 3.14159265358979323846f;
    double d = 3.14159265358979323846;
    long double ld = 3.14159265358979323846L;
    
    printf("float              : %f\n", f);
    printf("double             : %.15f\n", d);
    printf("long double        : %.15Lf\n", ld);
    
    // Démonstration de la précision
    printf("\nPrécision des types à virgule flottante :\n");
    printf("float (précision)  : %.7f\n", 1.0f/3.0f);
    printf("double (précision) : %.15f\n", 1.0/3.0);
    printf("long double        : %.18Lf\n", 1.0L/3.0L);
    
    return 0;
}

