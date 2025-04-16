#include <stdio.h>
#include <stdbool.h>

/**
 * Programme qui teste les différents opérateurs arithmétiques et logiques
 * Exercice 1.5 du TP1
 */
int main() {
    // Déclaration et initialisation des variables
    int a = 16;
    int b = 3;
    
    printf("Opérations avec a = %d et b = %d :\n", a, b);
    printf("----------------------------------\n\n");
    
    // 1. Addition
    int addition = a + b;
    printf("1. Addition        : a + b = %d\n", addition);
    
    // 2. Soustraction
    int soustraction = a - b;
    printf("2. Soustraction    : a - b = %d\n", soustraction);
    
    // 3. Multiplication
    int multiplication = a * b;
    printf("3. Multiplication  : a * b = %d\n", multiplication);
    
    // 4. Division entière
    int division = a / b;
    printf("4. Division        : a / b = %d\n", division);
    
    // 5. Modulo (reste de la division)
    int modulo = a % b;
    printf("5. Modulo          : a %% b = %d\n", modulo);
    
    // 6. Comparaison d'égalité (résultat booléen)
    bool egalite = (a == b);
    printf("6. Égalité         : a == b : %s\n", egalite ? "vrai" : "faux");
    
    // 7. Comparaison supérieur (résultat booléen)
    bool superieur = (a > b);
    printf("7. Supérieur       : a > b  : %s\n", superieur ? "vrai" : "faux");
    
    // Opérations supplémentaires pour illustrer d'autres opérateurs
    printf("\nOpérations supplémentaires :\n");
    
    // Opérateurs bit à bit
    printf("ET bit à bit       : a & b  = %d\n", a & b);
    printf("OU bit à bit       : a | b  = %d\n", a | b);
    printf("XOR bit à bit      : a ^ b  = %d\n", a ^ b);
    printf("NON bit à bit      : ~a     = %d\n", ~a);
    printf("Décalage à gauche  : a << 1 = %d\n", a << 1);
    printf("Décalage à droite  : a >> 1 = %d\n", a >> 1);
    
    return 0;
}

