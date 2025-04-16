#include <stdio.h>

#define TAILLE_MAX 100

int main() {
    char chaine[TAILLE_MAX];
    char inverse[TAILLE_MAX];
    int longueur = 0;
    int i;
    
    printf("Entrez une chaine de caracteres (max %d caracteres): ", TAILLE_MAX - 1);
    
    if (fgets(chaine, TAILLE_MAX, stdin) == NULL) {
        printf("Erreur lors de la lecture de la chaine.\n");
        return 1;
    }
    
    while (longueur < TAILLE_MAX && chaine[longueur] != '\0' && chaine[longueur] != '\n') {
        longueur++;
    }
    
    if (chaine[longueur] == '\n') {
        chaine[longueur] = '\0';
    }
    
    if (longueur == 0) {
        printf("La chaine est vide.\n");
        return 0;
    }
    
    printf("Chaine originale: %s\n", chaine);
    
    for (i = 0; i < longueur; i++) {
        inverse[i] = chaine[longueur - 1 - i];
    }
    inverse[longueur] = '\0';
    
    printf("Chaine inversee: %s\n", inverse);
    
    return 0;
}

