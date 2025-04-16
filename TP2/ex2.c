#include <stdio.h>

int main() {
    int nombre_notes = 0;
    float note, somme = 0, moyenne;
    
    printf("Entrez les notes (terminez avec un nombre negatif):\n");
    
    while (1) {
        printf("Note %d: ", nombre_notes + 1);
        if (scanf("%f", &note) != 1) {
            printf("Erreur de saisie. Veuillez entrer un nombre.\n");
            while (getchar() != '\n');
            continue;
        }
        
        if (note < 0) {
            break;
        }
        
        if (note > 20) {
            printf("La note doit etre entre 0 et 20.\n");
            continue;
        }
        
        somme += note;
        nombre_notes++;
    }
    
    if (nombre_notes == 0) {
        printf("Aucune note n'a ete saisie.\n");
    } else {
        moyenne = somme / nombre_notes;
        printf("Moyenne de %d notes: %.2f\n", nombre_notes, moyenne);
    }
    
    return 0;
}

