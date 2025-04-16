#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAILLE_MAX 100

int main() {
    int tableau[TAILLE_MAX];
    int taille, i;
    int min, max;
    float somme = 0, moyenne;
    
    printf("Entrez la taille du tableau (max %d): ", TAILLE_MAX);
    if (scanf("%d", &taille) != 1 || taille <= 0 || taille > TAILLE_MAX) {
        printf("Erreur: taille invalide.\n");
        return 1;
    }
    
    printf("\nChoisissez une option:\n");
    printf("1. Entrer les valeurs manuellement\n");
    printf("2. Generer des valeurs aleatoires\n");
    
    int choix;
    if (scanf("%d", &choix) != 1 || (choix != 1 && choix != 2)) {
        printf("Choix invalide.\n");
        return 1;
    }
    
    if (choix == 1) {
        printf("\nEntrez %d valeurs entieres:\n", taille);
        for (i = 0; i < taille; i++) {
            printf("Valeur %d: ", i + 1);
            if (scanf("%d", &tableau[i]) != 1) {
                printf("Erreur: valeur invalide.\n");
                return 1;
            }
        }
    } else {
        srand(time(NULL));
        printf("\nValeurs generees: ");
        for (i = 0; i < taille; i++) {
            tableau[i] = rand() % 100;
            printf("%d ", tableau[i]);
        }
        printf("\n");
    }
    
    min = max = tableau[0];
    somme = tableau[0];
    
    for (i = 1; i < taille; i++) {
        if (tableau[i] < min) {
            min = tableau[i];
        }
        if (tableau[i] > max) {
            max = tableau[i];
        }
        somme += tableau[i];
    }
    
    moyenne = somme / taille;
    
    printf("\nResultats:\n");
    printf("Minimum: %d\n", min);
    printf("Maximum: %d\n", max);
    printf("Moyenne: %.2f\n", moyenne);
    
    return 0;
}

