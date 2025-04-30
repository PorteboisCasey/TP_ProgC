#include <stdio.h>

int main() {
    printf("Taille des types de base en octets :\n\n");
    
    // Types char
    printf("char : %zu\n", sizeof(char));
    printf("signed char : %zu\n", sizeof(signed char));
    printf("unsigned char : %zu\n", sizeof(unsigned char));
    
    // Types short
    printf("short : %zu\n", sizeof(short));
    printf("signed short : %zu\n", sizeof(signed short));
    printf("unsigned short : %zu\n", sizeof(unsigned short));
    
    // Types int
    printf("int : %zu\n", sizeof(int));
    printf("signed int : %zu\n", sizeof(signed int));
    printf("unsigned int : %zu\n", sizeof(unsigned int));
    
    // Types long
    printf("long int : %zu\n", sizeof(long int));
    printf("signed long int : %zu\n", sizeof(signed long int));
    printf("unsigned long int : %zu\n", sizeof(unsigned long int));
    
    // Types long long
    printf("long long int : %zu\n", sizeof(long long int));
    printf("signed long long int : %zu\n", sizeof(signed long long int));
    printf("unsigned long long int : %zu\n", sizeof(unsigned long long int));
    
    // Types à virgule flottante
    printf("float : %zu\n", sizeof(float));
    printf("double : %zu\n", sizeof(double));
    printf("long double : %zu\n", sizeof(long double));
    
    return 0;
}

