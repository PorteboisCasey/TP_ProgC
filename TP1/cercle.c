#include <stdio.h>
#include <math.h>

/**
 * Programme qui calcule l'aire et le périmètre d'un cercle
 * Exercice 1.2 du TP1
 */
int main() {
    // Déclaration et initialisation du rayon
    double rayon = 5.0;  // Valeur du rayon en unités arbitraires
    
    // Calcul de l'aire du cercle (π * r²)
    double aire = M_PI * rayon * rayon;
    
    // Calcul du périmètre du cercle (2 * π * r)
    double perimetre = 2 * M_PI * rayon;
    
    // Affichage des résultats
    printf("Pour un cercle de rayon %.2f :\n", rayon);
    printf("- Aire = %.2f unités²\n", aire);
    printf("- Périmètre = %.2f unités\n", perimetre);
    
    return 0;
}

