#include <stdio.h>

void afficher_binaire(int nombre) {
    // Pour un int de 32 bits
    int bits = sizeof(int) * 8;
    int premier_1_trouve = 0;
    
    printf("%d en binaire : ", nombre);
    
    // Parcourt les bits de gauche à droite
    for (int i = bits - 1; i >= 0; i--) {
        int bit = (nombre >> i) & 1;
        if (bit == 1) {
            premier_1_trouve = 1;
        }
        // N'affiche les bits qu'à partir du premier 1 trouvé
        if (premier_1_trouve) {
            printf("%d", bit);
        }
    }
    // Si le nombre est 0, affiche 0
    if (!premier_1_trouve) {
        printf("0");
    }
    printf("\n");
}

int main() {
    // Test avec les nombres demandés
    int nombres[] = {0, 4096, 65536, 65535, 1024};
    int taille = sizeof(nombres) / sizeof(nombres[0]);
    
    for (int i = 0; i < taille; i++) {
        afficher_binaire(nombres[i]);
    }
    
    return 0;
}

