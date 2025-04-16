#include <stdio.h>

/**
 * Programme qui affiche la taille en octets des différents types de base
 * Exercice 1.3 du TP1
 */
int main() {
    printf("Tailles des types de base en C :\n");
    printf("--------------------------------\n\n");
    
    // Types caractères
    printf("char               : %lu octets\n", sizeof(char));
    printf("unsigned char      : %lu octets\n", sizeof(unsigned char));
    printf("signed char        : %lu octets\n\n", sizeof(signed char));
    
    // Types entiers courts
    printf("short              : %lu octets\n", sizeof(short));
    printf("unsigned short     : %lu octets\n", sizeof(unsigned short));
    printf("signed short       : %lu octets\n\n", sizeof(signed short));
    
    // Types entiers
    printf("int                : %lu octets\n", sizeof(int));
    printf("unsigned int       : %lu octets\n", sizeof(unsigned int));
    printf("signed int         : %lu octets\n\n", sizeof(signed int));
    
    // Types entiers longs
    printf("long int           : %lu octets\n", sizeof(long int));
    printf("unsigned long int  : %lu octets\n", sizeof(unsigned long int));
    printf("signed long int    : %lu octets\n\n", sizeof(signed long int));
    
    // Types entiers très longs
    printf("long long int      : %lu octets\n", sizeof(long long int));
    printf("unsigned long long : %lu octets\n", sizeof(unsigned long long int));
    printf("signed long long   : %lu octets\n\n", sizeof(signed long long int));
    
    // Types à virgule flottante (pas de version non-signée)
    printf("float              : %lu octets\n", sizeof(float));
    printf("double             : %lu octets\n", sizeof(double));
    printf("long double        : %lu octets\n", sizeof(long double));
    
    return 0;
}

