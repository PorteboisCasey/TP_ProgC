#include <stdio.h>

// Calcule la longueur d'une chaîne
int longueur_chaine(const char *chaine) {
    int longueur = 0;
    while (chaine[longueur] != '\0') {
        longueur++;
    }
    return longueur;
}

// Copie une chaîne dans une autre
void copie_chaine(char *destination, const char *source) {
    int i = 0;
    while (source[i] != '\0') {
        destination[i] = source[i];
        i++;
    }
    destination[i] = '\0';
}

// Concatène deux chaînes
void concatene_chaines(char *destination, const char *source) {
    int dest_len = longueur_chaine(destination);
    int i = 0;
    
    while (source[i] != '\0') {
        destination[dest_len + i] = source[i];
        i++;
    }
    destination[dest_len + i] = '\0';
}

int main() {
    char chaine1[50] = "Hello";
    char chaine2[50] = " World!";
    char chaine3[100];
    
    // Test de longueur
    printf("Longueur de chaine1: %d\n", longueur_chaine(chaine1));
    printf("Longueur de chaine2: %d\n", longueur_chaine(chaine2));
    
    // Test de copie
    copie_chaine(chaine3, chaine1);
    printf("Copie de chaine1 dans chaine3: %s\n", chaine3);
    
    // Test de concaténation
    concatene_chaines(chaine3, chaine2);
    printf("Après concaténation avec chaine2: %s\n", chaine3);
    
    return 0;
}

