#include <stdio.h>

/**
 * Programme qui génère une pyramide de nombres
 * Exercice 1.10 du TP1
 */
int main() {
    // Déclaration de la hauteur de la pyramide
    int n = 5;
    
    printf("Génération d'une pyramide de nombres de hauteur %d\n", n);
    printf("------------------------------------------------\n\n");
    
    // Boucle pour chaque ligne de la pyramide
    for (int i = 1; i <= n; i++) {
        // Boucle pour les espaces avant les nombres (pour centrer)
        for (int j = 1; j <= n - i; j++) {
            printf(" ");
        }
        
        // Boucle pour les nombres croissants (1 à i)
        for (int j = 1; j <= i; j++) {
            printf("%d", j);
        }
        
        // Boucle pour les nombres décroissants (i-1 à 1)
        for (int j = i - 1; j >= 1; j--) {
            printf("%d", j);
        }
        
        // Passage à la ligne suivante
        printf("\n");
    }
    
    printf("\nPyramide générée avec succès!\n");
    
    // Démonstration avec une hauteur différente
    int autre_hauteur = 7;
    printf("\nBonus: Pyramide de hauteur %d\n", autre_hauteur);
    printf("---------------------------\n\n");
    
    // Génération d'une pyramide de hauteur différente
    for (int i = 1; i <= autre_hauteur; i++) {
        // Espaces pour le centrage
        for (int j = 1; j <= autre_hauteur - i; j++) {
            printf(" ");
        }
        
        // Nombres croissants
        for (int j = 1; j <= i; j++) {
            printf("%d", j);
        }
        
        // Nombres décroissants
        for (int j = i - 1; j >= 1; j--) {
            printf("%d", j);
        }
        
        printf("\n");
    }
    
    return 0;
}

