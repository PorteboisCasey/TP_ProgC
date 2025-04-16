#include <stdio.h>
#include <ctype.h>

#define TAILLE_MAX 200

int est_voyelle(char c) {
    c = tolower(c);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y');
}

int main() {
    char texte[TAILLE_MAX];
    int voyelles = 0, consonnes = 0;
    int i = 0;
    
    printf("Entrez une chaine de caracteres (max %d caracteres): ", TAILLE_MAX - 1);
    
    if (fgets(texte, TAILLE_MAX, stdin) == NULL) {
        printf("Erreur lors de la lecture de la chaine.\n");
        return 1;
    }
    
    while (texte[i] != '\0') {
        if (isalpha(texte[i])) {
            if (est_voyelle(texte[i])) {
                voyelles++;
            } else {
                consonnes++;
            }
        }
        i++;
    }
    
    printf("\nAnalyse de la chaine:\n");
    printf("Nombre de voyelles: %d\n", voyelles);
    printf("Nombre de consonnes: %d\n", consonnes);
    printf("Nombre total de lettres: %d\n", voyelles + consonnes);
    
    if (voyelles + consonnes == 0) {
        printf("Aucune lettre detectee dans la chaine.\n");
    } else {
        float pourcentage_voyelles = (float)voyelles / (voyelles + consonnes) * 100;
        printf("Pourcentage de voyelles: %.1f%%\n", pourcentage_voyelles);
        printf("Pourcentage de consonnes: %.1f%%\n", 100 - pourcentage_voyelles);
    }
    
    return 0;
}

