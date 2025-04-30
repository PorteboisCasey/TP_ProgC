#include <stdio.h>

int main() {
    int n = 5;  // Hauteur de la pyramide
    
    printf("Génération d'une pyramide de hauteur %d:\n\n", n);
    
    // Pour chaque ligne
    for (int i = 1; i <= n; i++) {
        // Espaces avant les nombres
        for (int j = 1; j <= n - i; j++) {
            printf(" ");
        }
        
        // Nombres croissants
        for (int j = 1; j <= i; j++) {
            printf("%d", j);
        }
        
        // Nombres décroissants (sauf le dernier)
        for (int j = i - 1; j >= 1; j--) {
            printf("%d", j);
        }
        
        printf("\n");
    }
    
    printf("\nGénération de la pyramide terminée.\n");
    
    return 0;
}

