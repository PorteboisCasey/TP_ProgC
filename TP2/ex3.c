#include <stdio.h>
#include <math.h>

int main() {
    int nombre, i;
    int est_premier = 1;
    
    printf("Entrez un nombre pour verifier s'il est premier: ");
    if (scanf("%d", &nombre) != 1) {
        printf("Erreur: veuillez entrer un nombre entier.\n");
        return 1;
    }
    
    if (nombre <= 1) {
        printf("%d n'est pas un nombre premier.\n", nombre);
        return 0;
    }
    
    if (nombre == 2) {
        printf("2 est un nombre premier.\n");
        return 0;
    }
    
    if (nombre % 2 == 0) {
        printf("%d n'est pas un nombre premier (divisible par 2).\n", nombre);
        return 0;
    }
    
    for (i = 3; i <= sqrt(nombre); i += 2) {
        if (nombre % i == 0) {
            est_premier = 0;
            break;
        }
    }
    
    if (est_premier) {
        printf("%d est un nombre premier.\n", nombre);
    } else {
        printf("%d n'est pas un nombre premier (divisible par %d).\n", nombre, i);
    }
    
    return 0;
}

