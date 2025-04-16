#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Noeud {
    int valeur;
    struct Noeud *suivant;
} Noeud;

typedef struct {
    Noeud *sommet;
} Pile;

typedef struct {
    Noeud *tete;
    Noeud *queue;
} File;

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

Pile* creer_pile() {
    Pile *p = (Pile*) malloc(sizeof(Pile));
    if (p == NULL) {
        printf("Erreur: allocation memoire echouee\n");
        exit(EXIT_FAILURE);
    }
    p->sommet = NULL;
    return p;
}

File* creer_file() {
    File *f = (File*) malloc(sizeof(File));
    if (f == NULL) {
        printf("Erreur: allocation memoire echouee\n");
        exit(EXIT_FAILURE);
    }
    f->tete = NULL;
    f->queue = NULL;
    return f;
}

bool pile_est_vide(Pile *p) {
    return p->sommet == NULL;
}

bool file_est_vide(File *f) {
    return f->tete == NULL;
}

void empiler(Pile *p, int valeur) {
    Noeud *nouveau = creer_noeud(valeur);
    nouveau->suivant = p->sommet;
    p->sommet = nouveau;
    printf("Valeur %d ajoutee a la pile\n", valeur);
}

int depiler(Pile *p) {
    if (pile_est_vide(p)) {
        printf("Erreur: la pile est vide\n");
        return -1;
    }
    
    Noeud *temp = p->sommet;
    int valeur = temp->valeur;
    p->sommet = p->sommet->suivant;
    free(temp);
    return valeur;
}

int sommet_pile(Pile *p) {
    if (pile_est_vide(p)) {
        printf("Erreur: la pile est vide\n");
        return -1;
    }
    return p->sommet->valeur;
}

void enfiler(File *f, int valeur) {
    Noeud *nouveau = creer_noeud(valeur);
    
    if (file_est_vide(f)) {
        f->tete = nouveau;
        f->queue = nouveau;
    } else {
        f->queue->suivant = nouveau;
        f->queue = nouveau;
    }
    printf("Valeur %d ajoutee a la file\n", valeur);
}

int defiler(File *f) {
    if (file_est_vide(f)) {
        printf("Erreur: la file est vide\n");
        return -1;
    }
    
    Noeud *temp = f->tete;
    int valeur = temp->valeur;
    
    f->tete = f->tete->suivant;
    
    if (f->tete == NULL) {
        f->queue = NULL;
    }
    
    free(temp);
    return valeur;
}

int tete_file(File *f) {
    if (file_est_vide(f)) {
        printf("Erreur: la file est vide\n");
        return -1;
    }
    return f->tete->valeur;
}

void afficher_pile(Pile *p) {
    if (pile_est_vide(p)) {
        printf("La pile est vide\n");
        return;
    }
    
    printf("Contenu de la pile (du sommet vers la base):\n");
    Noeud *courant = p->sommet;
    while (courant != NULL) {
        printf("| %d |\n", courant->valeur);
        courant = courant->suivant;
    }
    printf("-----\n");
}

void afficher_file(File *f) {
    if (file_est_vide(f)) {
        printf("La file est vide\n");
        return;
    }
    
    printf("Contenu de la file (de la tete vers la queue):\n");
    printf("TÊTE -> ");
    Noeud *courant = f->tete;
    while (courant != NULL) {
        printf("%d ", courant->valeur);
        if (courant->suivant != NULL) {
            printf("-> ");
        }
        courant = courant->suivant;
    }
    printf("<- QUEUE\n");
}

void liberer_pile(Pile *p) {
    while (!pile_est_vide(p)) {
        depiler(p);
    }
    free(p);
}

void liberer_file(File *f) {
    while (!file_est_vide(f)) {
        defiler(f);
    }
    free(f);
}

void menu_pile(Pile *p) {
    int choix, valeur;
    
    while (1) {
        printf("\n=== OPERATIONS SUR LA PILE ===\n");
        printf("1. Empiler (push)\n");
        printf("2. Depiler (pop)\n");
        printf("3. Consulter le sommet (peek)\n");
        printf("4. Verifier si la pile est vide\n");
        printf("5. Afficher la pile\n");
        printf("6. Retour au menu principal\n");
        printf("Votre choix: ");
        
        if (scanf("%d", &choix) != 1) {
            printf("Erreur: choix invalide\n");
            while (getchar() != '\n');
            continue;
        }
        
        switch (choix) {
            case 1:
                printf("Entrez la valeur a empiler: ");
                if (scanf("%d", &valeur) != 1) {
                    printf("Erreur: valeur invalide\n");
                    while (getchar() != '\n');
                    break;
                }
                empiler(p, valeur);
                break;
                
            case 2:
                valeur = depiler(p);
                if (valeur != -1) {
                    printf("Valeur depilee: %d\n", valeur);
                }
                break;
                
            case 3:
                valeur = sommet_pile(p);
                if (valeur != -1) {
                    printf("Valeur au sommet: %d\n", valeur);
                }
                break;
                
            case 4:
                if (pile_est_vide(p)) {
                    printf("La pile est vide\n");
                } else {
                    printf("La pile n'est pas vide\n");
                }
                break;
                
            case 5:
                afficher_pile(p);
                break;
                
            case 6:
                return;
                
            default:
                printf("Choix invalide!\n");
        }
    }
}

void menu_file(File *f) {
    int choix, valeur;
    
    while (1) {
        printf("\n=== OPERATIONS SUR LA FILE ===\n");
        printf("1. Enfiler (enqueue)\n");
        printf("2. Defiler (dequeue)\n");
        printf("3. Consulter la tete (peek)\n");
        printf("4. Verifier si la file est vide\n");
        printf("5. Afficher la file\n");
        printf("6. Retour au menu principal\n");
        printf("Votre choix: ");
        
        if (scanf("%d", &choix) != 1) {
            printf("Erreur: choix invalide\n");
            while (getchar() != '\n');
            continue;
        }
        
        switch (choix) {
            case 1:
                printf("Entrez la valeur a enfiler: ");
                if (scanf("%d", &valeur) != 1) {
                    printf("Erreur: valeur invalide\n");
                    while (getchar() != '\n');
                    break;
                }
                enfiler(f, valeur);
                break;
                
            case 2:
                valeur = defiler(f);
                if (valeur != -1) {
                    printf("Valeur defilee: %d\n", valeur);
                }
                break;
                
            case 3:
                valeur = tete_file(f);
                if (valeur != -1) {
                    printf("Valeur en tete: %d\n", valeur);
                }
                break;
                
            case 4:
                if (file_est_vide(f)) {
                    printf("La file est vide\n");
                } else {
                    printf("La file n'est pas vide\n");
                }
                break;
                
            case 5:
                afficher_file(f);
                break;
                
            case 6:
                return;
                
            default:
                printf("Choix invalide!\n");
        }
    }
}

int main() {
    Pile *pile = creer_pile();
    File *file = creer_file();
    int choix;
    
    while (1) {
        printf("\n=== MENU PRINCIPAL ===\n");
        printf("1. Operations sur la pile (LIFO)\n");
        printf("2. Operations sur la file (FIFO)\n");
        printf("3. Quitter\n");
        printf("Votre choix: ");
        
        if (scanf("%d", &choix) != 1) {
            printf("Erreur: choix invalide\n");
            while (getchar() != '\n');
            continue;
        }
        
        switch (choix) {
            case 1:
                menu_pile(pile);
                break;
                
            case 2:
                menu_file(file);
                break;
                
            case 3:
                liberer_pile(pile);
                liberer_file(file);
                printf("Au revoir!\n");
                return 0;
                
            default:
                printf("Choix invalide!\n");
        }
    }
    
    return 0;
}

