#include <stdio.h>
#include <stdlib.h>

typedef struct Noeud {
    int valeur;
    struct Noeud *gauche;
    struct Noeud *droite;
} Noeud;

Noeud* creer_noeud(int valeur) {
    Noeud *nouveau = (Noeud*) malloc(sizeof(Noeud));
    if (nouveau == NULL) {
        printf("Erreur: allocation memoire echouee\n");
        exit(EXIT_FAILURE);
    }
    nouveau->valeur = valeur;
    nouveau->gauche = NULL;
    nouveau->droite = NULL;
    return nouveau;
}

Noeud* inserer(Noeud *racine, int valeur) {
    if (racine == NULL) {
        return creer_noeud(valeur);
    }
    
    if (valeur < racine->valeur) {
        racine->gauche = inserer(racine->gauche, valeur);
    } else if (valeur > racine->valeur) {
        racine->droite = inserer(racine->droite, valeur);
    } else {
        printf("La valeur %d existe deja dans l'arbre\n", valeur);
    }
    
    return racine;
}

Noeud* trouver_min(Noeud *racine) {
    Noeud *courant = racine;
    while (courant && courant->gauche != NULL) {
        courant = courant->gauche;
    }
    return courant;
}

Noeud* supprimer(Noeud *racine, int valeur) {
    if (racine == NULL) {
        printf("La valeur %d n'existe pas dans l'arbre\n", valeur);
        return NULL;
    }
    
    if (valeur < racine->valeur) {
        racine->gauche = supprimer(racine->gauche, valeur);
    } else if (valeur > racine->valeur) {
        racine->droite = supprimer(racine->droite, valeur);
    } else {
        if (racine->gauche == NULL) {
            Noeud *temp = racine->droite;
            free(racine);
            printf("Valeur %d supprimee avec succes\n", valeur);
            return temp;
        } else if (racine->droite == NULL) {
            Noeud *temp = racine->gauche;
            free(racine);
            printf("Valeur %d supprimee avec succes\n", valeur);
            return temp;
        }
        
        Noeud *temp = trouver_min(racine->droite);
        racine->valeur = temp->valeur;
        racine->droite = supprimer(racine->droite, temp->valeur);
    }
    
    return racine;
}

Noeud* rechercher(Noeud *racine, int valeur) {
    if (racine == NULL || racine->valeur == valeur) {
        return racine;
    }
    
    if (valeur < racine->valeur) {
        return rechercher(racine->gauche, valeur);
    } else {
        return rechercher(racine->droite, valeur);
    }
}

void parcours_infixe(Noeud *racine) {
    if (racine != NULL) {
        parcours_infixe(racine->gauche);
        printf("%d ", racine->valeur);
        parcours_infixe(racine->droite);
    }
}

void parcours_prefixe(Noeud *racine) {
    if (racine != NULL) {
        printf("%d ", racine->valeur);
        parcours_prefixe(racine->gauche);
        parcours_prefixe(racine->droite);
    }
}

void parcours_postfixe(Noeud *racine) {
    if (racine != NULL) {
        parcours_postfixe(racine->gauche);
        parcours_postfixe(racine->droite);
        printf("%d ", racine->valeur);
    }
}

int hauteur_arbre(Noeud *racine) {
    if (racine == NULL) {
        return -1;
    }
    
    int hauteur_gauche = hauteur_arbre(racine->gauche);
    int hauteur_droite = hauteur_arbre(racine->droite);
    
    return 1 + (hauteur_gauche > hauteur_droite ? hauteur_gauche : hauteur_droite);
}

int compter_noeuds(Noeud *racine) {
    if (racine == NULL) {
        return 0;
    }
    
    return 1 + compter_noeuds(racine->gauche) + compter_noeuds(racine->droite);
}

void liberer_arbre(Noeud *racine) {
    if (racine != NULL) {
        liberer_arbre(racine->gauche);
        liberer_arbre(racine->droite);
        free(racine);
    }
}

void afficher_arbre(Noeud *racine, int espace) {
    if (racine == NULL) {
        return;
    }
    
    espace += 10;
    
    afficher_arbre(racine->droite, espace);
    
    printf("\n");
    for (int i = 10; i < espace; i++) {
        printf(" ");
    }
    printf("%d\n", racine->valeur);
    
    afficher_arbre(racine->gauche, espace);
}

int main() {
    Noeud *racine = NULL;
    int choix, valeur;
    
    while (1) {
        printf("\n=== GESTION D'ARBRE BINAIRE DE RECHERCHE ===\n");
        printf("1. Inserer une valeur\n");
        printf("2. Supprimer une valeur\n");
        printf("3. Rechercher une valeur\n");
        printf("4. Parcours infixe (gauche-racine-droite)\n");
        printf("5. Parcours prefixe (racine-gauche-droite)\n");
        printf("6. Parcours postfixe (gauche-droite-racine)\n");
        printf("7. Afficher l'arbre (structure visuelle)\n");
        printf("8. Hauteur de l'arbre\n");
        printf("9. Nombre de noeuds\n");
        printf("10. Quitter\n");
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
                racine = inserer(racine, valeur);
                printf("Valeur %d inseree\n", valeur);
                break;
                
            case 2:
                printf("Entrez la valeur a supprimer: ");
                if (scanf("%d", &valeur) != 1) {
                    printf("Erreur: valeur invalide\n");
                    while (getchar() != '\n');
                    break;
                }
                racine = supprimer(racine, valeur);
                break;
                
            case 3:
                printf("Entrez la valeur a rechercher: ");
                if (scanf("%d", &valeur) != 1) {
                    printf("Erreur: valeur invalide\n");
                    while (getchar() != '\n');
                    break;
                }
                
                Noeud *resultat = rechercher(racine, valeur);
                if (resultat) {
                    printf("Valeur %d trouvee dans l'arbre\n", valeur);
                } else {
                    printf("Valeur %d non trouvee dans l'arbre\n", valeur);
                }
                break;
                
            case 4:
                if (racine == NULL) {
                    printf("L'arbre est vide\n");
                } else {
                    printf("Parcours infixe: ");
                    parcours_infixe(racine);
                    printf("\n");
                }
                break;
                
            case 5:
                if (racine == NULL) {
                    printf("L'arbre est vide\n");
                } else {
                    printf("Parcours prefixe: ");
                    parcours_prefixe(racine);
                    printf("\n");
                }
                break;
                
            case 6:
                if (racine == NULL) {
                    printf("L'arbre est vide\n");
                } else {
                    printf("Parcours postfixe: ");
                    parcours_postfixe(racine);
                    printf("\n");
                }
                break;
                
            case 7:
                if (racine == NULL) {
                    printf("L'arbre est vide\n");
                } else {
                    printf("Structure de l'arbre:\n");
                    afficher_arbre(racine, 0);
                }
                break;
                
            case 8:
                printf("Hauteur de l'arbre: %d\n", hauteur_arbre(racine));
                break;
                
            case 9:
                printf("Nombre de noeuds: %d\n", compter_noeuds(racine));
                break;
                
            case 10:
                liberer_arbre(racine);
                printf("Arbre libere. Au revoir!\n");
                return 0;
                
            default:
                printf("Choix invalide!\n");
        }
    }
    
    return 0;
}

