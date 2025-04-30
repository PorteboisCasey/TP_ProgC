#include <stdio.h>

int main() {
    int compteur = 5;  // Doit être < 10
    
    if (compteur >= 10) {
        printf("Le compteur doit être inférieur à 10\n");
        return 1;
    }
    
    // Version avec boucle for
    printf("Triangle avec boucles for:\n");
    for (int i = 1; i <= compteur; i++) {
        for (int j = 1; j <= i; j++) {
            if (j == 1 || j == i || i == compteur) {
                printf("* ");
            } else {
                printf("# ");
            }
        }
        printf("\n");
    }
    
    // Version avec boucle while
    printf("\nTriangle avec boucle while:\n");
    int i = 1;
    while (i <= compteur) {
        int j = 1;
        while (j <= i) {
            if (j == 1 || j == i || i == compteur) {
                printf("* ");
            } else {
                printf("# ");
            }
            j++;
        }
        printf("\n");
        i++;
    }
    
    return 0;
}

