#include <stdio.h>

/**
 * Programme qui affiche un triangle rectangle en utilisant des boucles
 * Exercice 1.6 du TP1
 */
int main() {
    // Valeur du compteur (hauteur du triangle)
    int compteur = 5;
    
    // Vérification que compteur est strictement inférieur à 10
    if (compteur >= 10) {
        printf("La valeur du compteur doit être strictement inférieure à 10.\n");
        return 1;
    }
    
    printf("Triangle rectangle avec boucles for :\n");
    printf("-----------------------------------\n");
    
    // Première version: utilisation de boucles for
    for (int i = 1; i <= compteur; i++) {
        for (int j = 1; j <= i; j++) {
            if (j == 1 || j == i || i == compteur) {
                // Premier caractère, dernier caractère ou dernière ligne: astérisque
                printf("* ");
            } else {
                // Caractères intermédiaires: dièse
                printf("# ");
            }
        }
        printf("\n");
    }
    
    printf("\nTriangle rectangle avec boucles while :\n");
    printf("-------------------------------------\n");
    
    // Deuxième version: utilisation de boucles while
    int i = 1;
    while (i <= compteur) {
        int j = 1;
        while (j <= i) {
            if (j == 1 || j == i || i == compteur) {
                // Premier caractère, dernier caractère ou dernière ligne: astérisque
                printf("* ");
            } else {
                // Caractères intermédiaires: dièse
                printf("# ");
            }
            j++;
        }
        printf("\n");
        i++;
    }
    
    printf("\nTriangle rectangle avec boucle do-while :\n");
    printf("---------------------------------------\n");
    
    // Troisième version: utilisation de boucles do-while
    i = 1;
    do {
        int j = 1;
        do {
            if (j == 1 || j == i || i == compteur) {
                // Premier caractère, dernier caractère ou dernière ligne: astérisque
                printf("* ");
            } else {
                // Caractères intermédiaires: dièse
                printf("# ");
            }
            j++;
        } while (j <= i);
        printf("\n");
        i++;
    } while (i <= compteur);
    
    return 0;
}

