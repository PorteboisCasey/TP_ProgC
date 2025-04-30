#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAILLE 10

int main() {
    int tableauInt[TAILLE];
    float tableauFloat[TAILLE];
    
    // Initialisation du générateur de nombres aléatoires
    srand(time(NULL));
    
    // Remplissage des tableaux avec des valeurs aléatoires
    int *ptrInt = tableauInt;
    float *ptrFloat = tableauFloat;
    
    printf("Valeurs initiales:\n\n");
    printf("Tableau d'entiers:\n");
    for (int i = 0; i < TAILLE; i++) {
        *ptrInt = rand() % 100;  // Nombres entre 0 et 99
        printf("%d ", *ptrInt);
        ptrInt++;
    }
    printf("\n\nTableau de flottants:\n");
    for (int i = 0; i < TAILLE; i++) {
        *ptrFloat = (float)(rand() % 1000) / 100.0f;  // Nombres entre 0 et 9.99
        printf("%.2f ", *ptrFloat);
        ptrFloat++;
    }
    
    // Multiplication par 3 pour les indices pairs
    printf("\n\nAprès multiplication par 3 pour les indices pairs:\n\n");
    
    printf("Tableau d'entiers:\n");
    ptrInt = tableauInt;
    for (int i = 0; i < TAILLE; i++) {
        if (i % 2 == 0) {
            *ptrInt *= 3;
        }
        printf("%d ", *ptrInt);
        ptrInt++;
    }
    
    printf("\n\nTableau de flottants:\n");
    ptrFloat = tableauFloat;
    for (int i = 0; i < TAILLE; i++) {
        if (i % 2 == 0) {
            *ptrFloat *= 3.0f;
        }
        printf("%.2f ", *ptrFloat);
        ptrFloat++;
    }
    printf("\n");
    
    return 0;
}

