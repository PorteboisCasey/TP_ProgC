#include <stdio.h>

/**
 * Programme qui calcule une somme selon des conditions de divisibilité
 * Exercice 1.7 du TP1
 */
int main() {
    // Variable pour stocker la somme
    int somme = 0;
    
    // Nombre final atteint dans la boucle
    int dernier_nombre = 0;
    
    printf("Calcul de la somme des nombres divisibles par 5 ou 7 (mais pas par 11)\n");
    printf("------------------------------------------------------------------\n\n");
    
    // Parcourir les nombres de 1 à 1000
    for (int i = 1; i <= 1000; i++) {
        // Afficher le statut tous les 100 nombres
        if (i % 100 == 0) {
            printf("Progression: analyse du nombre %d, somme actuelle = %d\n", i, somme);
        }
        
        // Vérifier si le nombre est divisible par 11
        if (i % 11 == 0) {
            // Si divisible par 11, passer au nombre suivant
            continue;
        }
        
        // Vérifier si le nombre est divisible par 5 ou par 7
        if (i % 5 == 0 || i % 7 == 0) {
            // Ajouter ce nombre à la somme
            somme += i;
            
            // Enregistrer le dernier nombre ajouté
            dernier_nombre = i;
            
            // Si la somme dépasse 5000, arrêter la boucle
            if (somme > 5000) {
                printf("La somme a dépassé 5000 avec l'ajout du nombre %d!\n", i);
                break;
            }
        }
    }
    
    // Afficher le résultat final
    printf("\nRésultat final:\n");
    printf("- Somme finale: %d\n", somme);
    printf("- Dernier nombre ajouté: %d\n", dernier_nombre);
    
    return 0;
}

