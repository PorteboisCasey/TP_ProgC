#include <stdio.h>

#define NB_ETUDIANTS 5
#define TAILLE_MAX 100

int main() {
    // Tableaux pour stocker les informations
    char noms[NB_ETUDIANTS][TAILLE_MAX] = {
        "Dupont", "Martin", "Bernard", "Petit", "Robert"
    };
    char prenoms[NB_ETUDIANTS][TAILLE_MAX] = {
        "Marie", "Pierre", "Sophie", "Jean", "Louise"
    };
    char adresses[NB_ETUDIANTS][TAILLE_MAX] = {
        "20 rue de la Paix, Paris",
        "15 avenue des Champs-Élysées, Paris",
        "8 place Bellecour, Lyon",
        "45 rue du Vieux-Port, Marseille",
        "12 rue des Carmes, Orléans"
    };
    
    // Notes des étudiants
    float notes_prog[NB_ETUDIANTS] = {16.5, 14.0, 15.5, 13.0, 17.5};
    float notes_sys[NB_ETUDIANTS] = {15.0, 16.5, 14.0, 15.5, 16.0};
    
    // Affichage des informations
    printf("Liste des étudiants et leurs informations:\n\n");
    
    for (int i = 0; i < NB_ETUDIANTS; i++) {
        printf("Étudiant %d:\n", i + 1);
        printf("Nom: %s\n", noms[i]);
        printf("Prénom: %s\n", prenoms[i]);
        printf("Adresse: %s\n", adresses[i]);
        printf("Note en Programmation C: %.1f\n", notes_prog[i]);
        printf("Note en Système d'exploitation: %.1f\n", notes_sys[i]);
        printf("\n");
    }
    
    return 0;
}

