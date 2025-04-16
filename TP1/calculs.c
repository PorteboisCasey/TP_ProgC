#include <stdio.h>

/**
 * Programme qui implémente une calculatrice simple avec switch
 * Exercice 1.8 du TP1
 */
int main() {
    // Déclaration des variables
    int num1, num2;
    char op;
    
    // Initialisation des variables (valeurs d'exemple)
    num1 = 25;
    num2 = 7;
    op = '*';  // Opérateur à tester
    
    // Affichage des valeurs initiales
    printf("Calculatrice simple\n");
    printf("-----------------\n\n");
    printf("Nombres: num1 = %d, num2 = %d\n", num1, num2);
    printf("Opérateur: '%c'\n\n", op);
    
    // Utilisation de switch pour déterminer l'opération à effectuer
    printf("Résultat: ");
    switch(op) {
        case '+':
            // Addition
            printf("%d + %d = %d\n", num1, num2, num1 + num2);
            break;
            
        case '-':
            // Soustraction
            printf("%d - %d = %d\n", num1, num2, num1 - num2);
            break;
            
        case '*':
            // Multiplication
            printf("%d * %d = %d\n", num1, num2, num1 * num2);
            break;
            
        case '/':
            // Division (avec vérification de division par zéro)
            if (num2 == 0) {
                printf("Erreur: Division par zéro impossible!\n");
            } else {
                printf("%d / %d = %d (division entière)\n", num1, num2, num1 / num2);
                printf("          = %.2f (division réelle)\n", (float)num1 / num2);
            }
            break;
            
        case '%':
            // Modulo (reste de la division)
            if (num2 == 0) {
                printf("Erreur: Modulo par zéro impossible!\n");
            } else {
                printf("%d %% %d = %d\n", num1, num2, num1 % num2);
            }
            break;
            
        case '&':
            // ET bit à bit
            printf("%d & %d = %d\n", num1, num2, num1 & num2);
            printf("En binaire: %d & %d = ", num1, num2);
            
            // Affichage en binaire (simplifié pour 8 bits)
            for (int i = 7; i >= 0; i--) {
                printf("%d", (num1 & num2) >> i & 1);
            }
            printf("\n");
            break;
            
        case '|':
            // OU bit à bit
            printf("%d | %d = %d\n", num1, num2, num1 | num2);
            printf("En binaire: %d | %d = ", num1, num2);
            
            // Affichage en binaire (simplifié pour 8 bits)
            for (int i = 7; i >= 0; i--) {
                printf("%d", (num1 | num2) >> i & 1);
            }
            printf("\n");
            break;
            
        case '~':
            // NON bit à bit (complément à un)
            printf("~%d = %d\n", num1, ~num1);
            printf("~%d = %d\n", num2, ~num2);
            
            // Affichage en binaire (simplifié pour 8 bits)
            printf("En binaire: ~%d = ", num1);
            for (int i = 7; i >= 0; i--) {
                printf("%d", (~num1) >> i & 1);
            }
            printf("\n");
            break;
            
        default:
            // Opérateur non reconnu
            printf("Opérateur '%c' non reconnu. Utilisez: +, -, *, /, %%, &, |, ~\n", op);
    }
    
    return 0;
}

#include <stdio.h>

/**
 * Programme qui effectue différentes opérations selon l'opérateur fourni
 * Exercice 1.8 du TP1
 */
int main() {
    // Déclaration des variables
    int num1, num2;
    char op;
    
    // Initialisation des variables (valeurs d'exemple)
    num1 = 25;
    num2 = 7;
    op = '*';  // Vous pouvez changer cet opérateur pour tester différentes opérations
    
    // Affichage des valeurs initiales
    printf("Calculatrice simple\n");
    printf("-----------------\n\n");
    printf("Nombres: num1 = %d, num2 = %d\n", num1, num2);
    printf("Opérateur: '%c'\n\n", op);
    
    // Utilisation de switch pour déterminer l'opération à effectuer
    printf("Résultat: ");
    switch(op) {
        case '+':
            // Addition
            printf("%d + %d = %d\n", num1, num2, num1 + num2);
            break;
            
        case '-':
            // Soustraction
            printf("%d - %d = %d\n", num1, num2, num1 - num2);
            break;
            
        case '*':
            // Multiplication
            printf("%d * %d = %d\n", num1, num2, num1 * num2);
            break;
            
        case '/':
            // Division (avec vérification de division par zéro)
            if (num2 == 0) {
                printf("Erreur: Division par zéro impossible!\n");
            } else {
                printf("%d / %d = %d (division entière)\n", num1, num2, num1 / num2);
                printf("          = %.2f (division réelle)\n", (float)num1 / num2);
            }
            break;
            
        case '%':
            // Modulo (reste de la division)
            if (num2 == 0) {
                printf("Erreur: Modulo par zéro impossible!\n");
            } else {
                printf("%d %% %d = %d\n", num1, num2, num1 % num2);
            }
            break;
            
        case '&':
            // ET bit à bit
            printf("%d & %d = %d\n", num1, num2, num1 & num2);
            printf("En binaire: %d & %d = ", num1, num2);
            
            // Affichage en binaire (simplifié pour 8 bits)
            for (int i = 7; i >= 0; i--) {
                printf("%d", (num1 & num2) >> i & 1);
            }
            printf("\n");
            break;
            
        case '|':
            // OU bit à bit
            printf("%d | %d = %d\n", num1, num2, num1 | num2);
            printf("En binaire: %d | %d = ", num1, num2);
            
            // Affichage en binaire (simplifié pour 8 bits)
            for (int i = 7; i >= 0; i--) {
                printf("%d", (num1 | num2) >> i & 1);
            }
            printf("\n");
            break;
            
        case '~':
            // NON bit à bit (complément à un)
            printf("~%d = %d\n", num1, ~num1);
            printf("~%d = %d\n", num2, ~num2);
            
            // Affichage en binaire (simplifié pour 8 bits)
            printf("En binaire: ~%d = ", num1);
            for (int i = 7; i >= 0; i--) {
                printf("%d", (~num1) >> i & 1);
            }
            printf("\n");
            break;
            
        default:
            // Opérateur non reconnu
            printf("Opérateur '%c' non reconnu. Utilisez: +, -, *, /, %%, &, |, ~\n", op);
    }
    
    return 0;
}

