#include <stdio.h>

int main() {
    // Types char
    char c = 'A';
    signed char sc = -50;
    unsigned char uc = 250;
    
    // Types short
    short s = -32000;
    signed short ss = -32000;
    unsigned short us = 65000;
    
    // Types int
    int i = -2147483640;
    signed int si = -2147483640;
    unsigned int ui = 4294967290;
    
    // Types long
    long int li = -9223372036854775800L;
    signed long int sli = -9223372036854775800L;
    unsigned long int uli = 18446744073709551610UL;
    
    // Types long long
    long long int lli = -9223372036854775800LL;
    signed long long int slli = -9223372036854775800LL;
    unsigned long long int ulli = 18446744073709551610ULL;
    
    // Types à virgule flottante
    float f = 3.14159f;
    double d = 3.14159265359;
    long double ld = 3.14159265359L;
    
    // Affichage des valeurs
    printf("Valeurs des différents types:\n\n");
    
    printf("char: %c\n", c);
    printf("signed char: %d\n", sc);
    printf("unsigned char: %u\n", uc);
    
    printf("short: %d\n", s);
    printf("signed short: %d\n", ss);
    printf("unsigned short: %u\n", us);
    
    printf("int: %d\n", i);
    printf("signed int: %d\n", si);
    printf("unsigned int: %u\n", ui);
    
    printf("long int: %ld\n", li);
    printf("signed long int: %ld\n", sli);
    printf("unsigned long int: %lu\n", uli);
    
    printf("long long int: %lld\n", lli);
    printf("signed long long int: %lld\n", slli);
    printf("unsigned long long int: %llu\n", ulli);
    
    printf("float: %f\n", f);
    printf("double: %lf\n", d);
    printf("long double: %Lf\n", ld);
    
    return 0;
}

