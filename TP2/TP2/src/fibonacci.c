#include <stdio.h>

int main() {
    int n = 7;  // Nombre de termes à générer
    unsigned long long u0 = 0, u1 = 1, un;
    
    printf("Suite de Fibonacci jusqu'au terme U%d:\n", n);
    
    // Affichage des deux premiers termes
    if (n >= 0) printf("%llu", u0);
    if (n >= 1) printf(", %llu", u1);
    
    // Génération des termes suivants
    for (int i = 2; i <= n; i++) {
        un = u0 + u1;
        printf(", %llu", un);
        
        // Mise à jour pour le prochain terme
        u0 = u1;
        u1 = un;
    }
    
    printf("\n");
    return 0;
}

