#include <stdio.h>
#include <stdlib.h>

typedef struct Noeud {
    int valeur;
    struct Noeud *suivant;
} Noeud;

Noeud* creer_noeud(int valeur) {
    Noeud *nouveau = (Noeud*) malloc(sizeof(Noeud));
    if (nouveau == NULL) {
        printf("Erreur: allocation memoire echouee\n");
        exit(EXIT_FAILURE);
    }
    nouveau->valeur = valeur;
    nouveau->suivant = NULL;
    return nouveau;
}

void inserer_debut(Noeud **tete, int valeur) {
    Noeud *nouveau = creer_noeud(valeur);
    nouveau->suivant = *tete;
    *tete = nouveau;
    printf("Valeur %d inseree en debut de liste\n", valeur);
}

void inserer_fin(Noeud **tete, int valeur) {
    Noeud *nouveau = creer_noeud(valeur);
    
    if (*tete == NULL) {
        *tete = nouveau;
        printf("Valeur %d inseree dans la liste vide\n", valeur);
        return;
    }
    
    Noeud *courant = *tete;
    while (courant->suivant != NULL) {
        courant = courant->suivant;
    }
    
    courant->suivant = nouveau;
    printf("Valeur %d inseree en fin de liste\n", valeur);
}

int supprimer_valeur(Noeud **tete, int valeur) {
    if (*tete == NULL) {
        printf("La liste est vide\n");
        return 0;
    }
    
    if ((*tete)->valeur == valeur) {
        Noeud *temp = *tete;
        *tete = (*tete)->suivant;
        free(temp);
        printf("Valeur %d supprimee avec succes\n", valeur);
        return 1;
    }
    
    Noeud *courant = *tete;
    while (courant->suivant != NULL && courant->suivant->valeur != valeur) {
        courant = courant->suivant;
    }
    
    if (courant->suivant == NULL) {
        printf("Valeur %d non trouvee dans la liste\n", valeur);
        return 0;
    }
    
    Noeud *temp = courant->suivant;
    courant->suivant = temp->suivant;
    free(temp);
    printf("Valeur %d supprimee avec succes\n", valeur);
    return 1;
}

Noeud* rechercher_valeur(Noeud *tete, int valeur) {
    Noeud *courant = tete;
    int position = 0;
    
    while (courant != NULL) {
        if (courant->valeur == valeur) {
            printf("Valeur %d trouvee a la position %d\n", valeur, position);
            return courant;
        }
        courant = courant->suivant;
        position++;
    }
    
    printf("Valeur %d non trouvee dans la liste\n", valeur);
    return NULL;
}

void afficher_liste(Noeud *tete) {
    if (tete == NULL) {
        printf("La liste est vide\n");
        return;
    }
    
    printf("Liste: ");
    Noeud *courant = tete;
    while (courant != NULL) {
        printf("%d", courant->valeur);
        if (courant->suivant != NULL) {
            printf(" -> ");
        }
        courant = courant->suivant;
    }
    printf("\n");
}

void liberer_liste(Noeud **tete) {
    Noeud *courant = *tete;
    Noeud *suivant;
    
    while (courant != NULL) {
        suivant = courant->suivant;
        free(courant);
        courant = suivant;
    }
    
    *tete = NULL;
    printf("Liste liberee avec succes\n");
}

int compter_elements(Noeud *tete) {
    int compteur = 0;
    Noeud *courant = tete;
    
    while (courant != NULL) {
        compteur++;
        courant = courant->suivant;
    }
    
    return compteur;
}

int main() {
    Noeud *liste = NULL;
    int choix, valeur;
    
    while (1) {
        printf("\n=== GESTION DE LISTE CHAINEE ===\n");
        printf("1. Inserer au debut\n");
        printf("2. Inserer a la fin\n");
        printf("3. Supprimer une valeur\n");
        printf("4. Rechercher une valeur\n");
        printf("5. Afficher la liste\n");
        printf("6. Nombre d'elements\n");
        printf("7. Liberer la liste\n");
        printf("8. Quitter\n");
        printf("Votre choix: ");
        
        if (scanf("%d", &choix) != 1) {
            printf("Erreur: choix invalide\n");
            while (getchar() != '\n');
            continue;
        }
        
        switch (choix) {
            case 1:
                printf("Entrez la valeur a inserer: ");
                if (scanf("%d", &valeur) != 1) {
                    printf("Erreur: valeur invalide\n");
                    while (getchar() != '\n');
                    break;
                }
                inserer_debut(&liste, valeur);
                break;
                
            case 2:
                printf("Entrez la valeur a inserer: ");
                if (scanf("%d", &valeur) != 1) {
                    printf("Erreur: valeur invalide\n");
                    while (getchar() != '\n');
                    break;
                }
                inserer_fin(&liste, valeur);
                break;
                
            case 3:
                printf("Entrez la valeur a supprimer: ");
                if (scanf("%d", &valeur) != 1) {
                    printf("Erreur: valeur invalide\n");
                    while (getchar() != '\n');
                    break;
                }
                supprimer_valeur(&liste, valeur);
                break;
                
            case 4:
                printf("Entrez la valeur a rechercher: ");
                if (scanf("%d", &valeur) != 1) {
                    printf("Erreur: valeur invalide\n");
                    while (getchar() != '\n');
                    break;
                }
                rechercher_valeur(liste, valeur);
                break;
                
            case 5:
                afficher_liste(liste);
                break;
                
            case 6:
                printf("Nombre d'elements dans la liste: %d\n", compter_elements(liste));
                break;
                
            case 7:
                liberer_liste(&liste);
                break;
                
            case 8:
                liberer_liste(&liste);
                printf("Au revoir!\n");
                return 0;
                
            default:
                printf("Choix invalide!\n");
        }
    }
    
    return 0;
}

