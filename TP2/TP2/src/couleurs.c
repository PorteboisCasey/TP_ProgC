#include <stdio.h>

// Structure pour représenter une couleur RGBA
struct Couleur {
    unsigned char rouge;
    unsigned char vert;
    unsigned char bleu;
    unsigned char alpha;
};

int main() {
    // Tableau de 10 couleurs
    struct Couleur couleurs[10] = {
        {0xef, 0x78, 0x12, 0xff},  // Orange vif
        {0x44, 0xc8, 0x64, 0xff},  // Vert moyen
        {0x1a, 0x2b, 0x8c, 0xff},  // Bleu foncé
        {0xff, 0x14, 0x93, 0xff},  // Rose vif
        {0x8b, 0x45, 0x13, 0xff},  // Marron
        {0x4b, 0x00, 0x82, 0xff},  // Violet foncé
        {0x00, 0xff, 0xff, 0xff},  // Cyan
        {0xff, 0xd7, 0x00, 0xff},  // Or
        {0x00, 0x80, 0x00, 0xff},  // Vert foncé
        {0x4a, 0x4a, 0x4a, 0xff}   // Gris
    };
    
    // Affichage des couleurs
    printf("Liste des couleurs en format RGBA:\n\n");
    
    for (int i = 0; i < 10; i++) {
        printf("Couleur %d:\n", i + 1);
        printf("Rouge : %d\n", couleurs[i].rouge);
        printf("Vert  : %d\n", couleurs[i].vert);
        printf("Bleu  : %d\n", couleurs[i].bleu);
        printf("Alpha : %d\n", couleurs[i].alpha);
        printf("\n");
    }
    
    return 0;
}

