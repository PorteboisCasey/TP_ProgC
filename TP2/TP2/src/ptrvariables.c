#include <stdio.h>

int main() {
    // Déclaration des variables
    char c = 'A';
    short s = 12345;
    int i = 987654321;
    long int li = 123456789L;
    long long int lli = 9876543210LL;
    float f = 3.14159f;
    double d = 2.718281828;
    long double ld = 3.14159265358979L;
    
    // Déclaration des pointeurs
    char *pc = &c;
    short *ps = &s;
    int *pi = &i;
    long int *pli = &li;
    long long int *plli = &lli;
    float *pf = &f;
    double *pd = &d;
    long double *pld = &ld;
    
    // Affichage avant modification
    printf("Avant la manipulation:\n");
    printf("char: adresse = %p, valeur = 0x%x\n", (void*)pc, (unsigned char)*pc);
    printf("short: adresse = %p, valeur = 0x%hx\n", (void*)ps, (unsigned short)*ps);
    printf("int: adresse = %p, valeur = 0x%x\n", (void*)pi, (unsigned int)*pi);
    printf("long int: adresse = %p, valeur = 0x%lx\n", (void*)pli, (unsigned long)*pli);
    printf("long long int: adresse = %p, valeur = 0x%llx\n", (void*)plli, (unsigned long long)*plli);
    
    // Pour les nombres à virgule flottante, on affiche leur représentation en mémoire
    printf("float: adresse = %p, valeur = 0x%x\n", (void*)pf, *(unsigned int*)pf);
    printf("double: adresse = %p, valeur = 0x%llx\n", (void*)pd, *(unsigned long long*)pd);
    printf("long double: adresse = %p\n", (void*)pld);
    
    // Modification via les pointeurs
    *pc += 1;      // Incrémente le caractère
    *ps += 100;    // Ajoute 100
    *pi += 1000;   // Ajoute 1000
    *pli += 10000; // Ajoute 10000
    *plli += 100000; // Ajoute 100000
    *pf *= 2.0f;   // Multiple par 2
    *pd *= 2.0;    // Multiple par 2
    *pld *= 2.0L;  // Multiple par 2
    
    printf("\nAprès la manipulation:\n");
    printf("char: adresse = %p, valeur = 0x%x\n", (void*)pc, (unsigned char)*pc);
    printf("short: adresse = %p, valeur = 0x%hx\n", (void*)ps, (unsigned short)*ps);
    printf("int: adresse = %p, valeur = 0x%x\n", (void*)pi, (unsigned int)*pi);
    printf("long int: adresse = %p, valeur = 0x%lx\n", (void*)pli, (unsigned long)*pli);
    printf("long long int: adresse = %p, valeur = 0x%llx\n", (void*)plli, (unsigned long long)*plli);
    printf("float: adresse = %p, valeur = 0x%x\n", (void*)pf, *(unsigned int*)pf);
    printf("double: adresse = %p, valeur = 0x%llx\n", (void*)pd, *(unsigned long long*)pd);
    printf("long double: adresse = %p\n", (void*)pld);
    
    return 0;
}

