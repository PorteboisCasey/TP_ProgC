#include <stdio.h>

/**
 * Programme qui affiche la représentation binaire d'un nombre entier
 * Exercice 1.9 du TP1
 */

/**
 * Fonction qui affiche la représentation binaire d'un nombre entier
 * @param nombre Le nombre à convertir en binaire
 */
void afficher_binaire(int nombre) {
    // Pour stocker le nombre de bits dans un int
    int nb_bits = sizeof(int) * 8;
    
    // Pour vérifier si on a rencontré le premier 1
    int premier_bit_1_trouve = 0;
    
    printf("Représentation binaire de %d : ", nombre);
    
    // Si le nombre est 0, afficher directement 0
    if (nombre == 0) {
        printf("0");
    } else {
        // Parcourir tous les bits du nombre de gauche à droite
        for (int i = nb_bits - 1; i >= 0; i--) {
            // Extraire le bit à la position i
            int bit = (nombre >> i) & 1;
            
            // Si c'est le premier bit 1, commencer l'affichage
            if (bit == 1) {
                premier_bit_1_trouve = 1;
            }
            
            // Afficher le bit si on a déjà rencontré un bit 1
            if (premier_bit_1_trouve) {
                printf("%d", bit);
            }
        }
    }
    printf("\n");
}

/**
 * Fonction qui affiche la représentation binaire complète sur 32 bits
 * @param nombre Le nombre à afficher
 */
void afficher_binaire_complet(int nombre) {
    int nb_bits = sizeof(int) * 8;
    
    printf("Représentation sur %d bits : ", nb_bits);
    
    // Parcourir tous les bits du nombre de gauche à droite
    for (int i = nb_bits - 1; i >= 0; i--) {
        // Extraire le bit à la position i
        int bit = (nombre >> i) & 1;
        printf("%d", bit);
        
        // Ajouter un espace tous les 4 bits pour améliorer la lisibilité
        if (i % 4 == 0 && i > 0) {
            printf(" ");
        }
    }
    printf("\n");
}

int main() {
    // Liste des nombres à tester
    int nombres[] = {0, 4096, 65536, 65535, 1024};
    int nb_nombres = sizeof(nombres) / sizeof(nombres[0]);
    
    printf("Conversion de nombres en représentation binaire\n");
    printf("---------------------------------------------\n\n");
    
    // Tester pour chaque nombre dans la liste
    for (int i = 0; i < nb_nombres; i++) {
        int nombre = nombres[i];
        
        printf("Nombre %d:\n", i + 1);
        printf("- Valeur décimale: %d\n", nombre);
        printf("- Valeur hexadécimale: 0x%X\n", nombre);
        
        // Afficher en binaire sans les zéros non significatifs
        afficher_binaire(nombre);
        
        // Afficher en binaire sur 32 bits pour voir la représentation complète
        afficher_binaire_complet(nombre);
        
        printf("\n");
    }
    
    return 0;
}

