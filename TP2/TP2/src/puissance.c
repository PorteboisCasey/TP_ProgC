#include <stdio.h>

int main() {
    int a = 2;  // Base
    int b = 3;  // Exposant
    int resultat = 1;
    
    // Calcul de la puissance
    for (int i = 0; i < b; i++) {
        resultat *= a;
    }
    
    printf("%d à la puissance %d = %d\n", a, b, resultat);
    
    return 0;
}

