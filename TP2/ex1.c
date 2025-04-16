#include <stdio.h>

int main() {
    int secondes_total, heures, minutes, secondes;
    
    printf("Entrez un nombre de secondes a convertir: ");
    if (scanf("%d", &secondes_total) != 1 || secondes_total < 0) {
        printf("Erreur: veuillez entrer un nombre positif\n");
        return 1;
    }
    
    heures = secondes_total / 3600;
    minutes = (secondes_total % 3600) / 60;
    secondes = secondes_total % 60;
    
    printf("%d secondes = %d heures, %d minutes et %d secondes\n", 
           secondes_total, heures, minutes, secondes);
    
    return 0;
}

