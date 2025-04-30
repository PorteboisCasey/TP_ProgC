#include <stdio.h>
#include <string.h>

#define NB_ETUDIANTS 5
#define TAILLE_MAX 100

// Définition de la structure Etudiant
struct Etudiant {
    char nom[TAILLE_MAX];
    char prenom[TAILLE_MAX];
    char adresse[TAILLE_MAX];
    float note_prog;
    float note_sys;
};

int main() {
    // Tableau de structures
    struct Etudiant etudiants[NB_ETUDIANTS];
    
    // Initialisation des données
    strcpy(etudiants[0].nom, "Dupont");
    strcpy(etudiants[0].prenom, "Marie");
    strcpy(etudiants[0].adresse, "20 rue de la Paix, Paris");
    etudiants[0].note_prog = 16.5;
    etudiants[0].note_sys = 15.0;
    
    strcpy(etudiants[1].nom, "Martin");
    strcpy(etudiants[1].prenom, "Pierre");
    strcpy(etudiants[1].adresse, "15 avenue des Champs-Élysées, Paris");
    etudiants[1].note_prog = 14.0;
    etudiants[1].note_sys = 16.5;
    
    strcpy(etudiants[2].nom, "Bernard");
    strcpy(etudiants[2].prenom, "Sophie");
    strcpy(etudiants[2].adresse, "8 place Bellecour, Lyon");
    etudiants[2].note_prog = 15.5;
    etudiants[2].note_sys = 14.0;
    
    strcpy(etudiants[3].nom, "Petit");
    strcpy(etudiants[3].prenom, "Jean");
    strcpy(etudiants[3].adresse, "45 rue du Vieux-Port, Marseille");
    etudiants[3].note_prog = 13.0;
    etudiants[3].note_sys = 15.5;
    
    strcpy(etudiants[4].nom, "Robert");
    strcpy(etudiants[4].prenom, "Louise");
    strcpy(etudiants[4].adresse, "12 rue des Carmes, Orléans");
    etudiants[4].note_prog = 17.5;
    etudiants[4].note_sys = 16.0;
    
    // Affichage des informations
    printf("Liste des étudiants et leurs informations:\n\n");
    
    for (int i = 0; i < NB_ETUDIANTS; i++) {
        printf("Étudiant %d:\n", i + 1);
        printf("Nom: %s\n", etudiants[i].nom);
        printf("Prénom: %s\n", etudiants[i].prenom);
        printf("Adresse: %s\n", etudiants[i].adresse);
        printf("Note en Programmation C: %.1f\n", etudiants[i].note_prog);
        printf("Note en Système d'exploitation: %.1f\n", etudiants[i].note_sys);
        printf("\n");
    }
    
    return 0;
}

