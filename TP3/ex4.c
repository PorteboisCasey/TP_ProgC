#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TAILLE_MAX 100

void afficher_tableau(int tableau[], int taille) {
    int i;
    
    if (taille <= 0) {
        printf("Le tableau est vide.\n");
        return;
    }
    
    printf("Contenu du tableau: [");
    for (i = 0; i < taille; i++) {
        printf("%d", tableau[i]);
        if (i < taille - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

void tri_bulle(int tableau[], int taille) {
    int i, j, temp;
    bool echange;
    
    if (taille <= 1) {
        return;
    }
    
    for (i = 0; i < taille - 1; i++) {
        echange = false;
        for (j = 0; j < taille - i - 1; j++) {
            if (tableau[j] > tableau[j + 1]) {
                temp = tableau[j];
                tableau[j] = tableau[j + 1];
                tableau[j + 1] = temp;
                echange = true;
            }
        }
        if (!echange) {
            break;
        }
    }
}

int recherche_binaire(int tableau[], int taille, int valeur) {
    int debut = 0;
    int fin = taille - 1;
    int milieu;
    
    if (taille <= 0) {
        return -1;
    }
    
    while (debut <= fin) {
        milieu = debut + (fin - debut) / 2;
        
        if (tableau[milieu] == valeur) {
            return milieu;
        }
        
        if (tableau[milieu] < valeur) {
            debut = milieu + 1;
        } else {
            fin = milieu - 1;
        }
    }
    
    return -1;
}

int main() {
    int tableau[TAILLE_MAX];
    int taille = 0;
    int choix, valeur, resultat;
    bool tableau_trie = false;
    
    while (1) {
        printf("\n==== MENU OPERATIONS SUR TABLEAU ====\n");
        printf("1. Saisir un nouveau tableau\n");
        printf("2. Afficher le tableau\n");
        printf("3. Trier le tableau (tri a bulles)\n");
        printf("4. Rechercher une valeur (recherche binaire)\n");
        printf("5. Quitter\n");
        printf("Votre choix: ");
        
        if (scanf("%d", &choix) != 1) {
            printf("Erreur: saisie invalide.\n");
            while (getchar() != '\n');
            continue;
        }
        
        switch (choix) {
            case 1:
                printf("Entrez la taille du tableau (max %d): ", TAILLE_MAX);
                if (scanf("%d", &taille) != 1 || taille <= 0 || taille > TAILLE_MAX) {
                    printf("Erreur: taille invalide.\n");
                    taille = 0;
                    break;
                }
                
                printf("Entrez les %d elements du tableau:\n", taille);
                for (int i = 0; i < taille; i++) {
                    printf("Element %d: ", i + 1);
                    if (scanf("%d", &tableau[i]) != 1) {
                        printf("Erreur: valeur invalide.\n");
                        i--;
                        while (getchar() != '\n');
                    }
                }
                printf("Tableau saisi avec succes.\n");
                tableau_trie = false;
                break;
                
            case 2:
                afficher_tableau(tableau, taille);
                break;
                
            case 3:
                if (taille <= 0) {
                    printf("Erreur: le tableau est vide.\n");
                    break;
                }
                
                tri_bulle(tableau, taille);
                printf("Tableau trie avec succes.\n");
                afficher_tableau(tableau, taille);
                tableau_trie = true;
                break;
                
            case 4:
                if (taille <= 0) {
                    printf("Erreur: le tableau est vide.\n");
                    break;
                }
                
                if (!tableau_trie) {
                    printf("Attention: le tableau n'est pas trie. Tri en cours...\n");
                    tri_bulle(tableau, taille);
                    tableau_trie = true;
                    afficher_tableau(tableau, taille);
                }
                
                printf("Entrez la valeur a rechercher: ");
                if (scanf("%d", &valeur) != 1) {
                    printf("Erreur: valeur invalide.\n");
                    while (getchar() != '\n');
                    break;
                }
                
                resultat = recherche_binaire(tableau, taille, valeur);
                if (resultat != -1) {
                    printf("La valeur %d a ete trouvee a l'indice %d.\n", valeur, resultat);
                } else {
                    printf("La valeur %d n'a pas ete trouvee dans le tableau.\n", valeur);
                }
                break;
                
            case 5:
                printf("Au revoir!\n");
                return 0;
                
            default:
                printf("Choix invalide. Veuillez reessayer.\n");
        }
    }
    
    return 0;
}

