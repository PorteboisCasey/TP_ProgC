#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_DESCRIPTION 100

typedef enum {
    EN_ATTENTE,
    EN_COURS,
    TERMINEE
} StatusTache;

typedef struct Tache {
    int id;
    char description[MAX_DESCRIPTION];
    int priorite;
    StatusTache status;
} Tache;

typedef struct NoeudArbre {
    Tache tache;
    struct NoeudArbre *gauche;
    struct NoeudArbre *droite;
} NoeudArbre;

typedef struct NoeudListe {
    Tache tache;
    struct NoeudListe *suivant;
} NoeudListe;

typedef struct {
    NoeudListe *tete;
    NoeudListe *queue;
} FileTaches;

typedef struct {
    NoeudListe *sommet;
} PileHistorique;

int id_courant = 1;

NoeudArbre* creer_noeud_arbre(Tache tache) {
    NoeudArbre *nouveau = (NoeudArbre*) malloc(sizeof(NoeudArbre));
    if (nouveau == NULL) {
        printf("Erreur: allocation memoire echouee\n");
        exit(EXIT_FAILURE);
    }
    nouveau->tache = tache;
    nouveau->gauche = NULL;
    nouveau->droite = NULL;
    return nouveau;
}

NoeudListe* creer_noeud_liste(Tache tache) {
    NoeudListe *nouveau = (NoeudListe*) malloc(sizeof(NoeudListe));
    if (nouveau == NULL) {
        printf("Erreur: allocation memoire echouee\n");
        exit(EXIT_FAILURE);
    }
    nouveau->tache = tache;
    nouveau->suivant = NULL;
    return nouveau;
}

FileTaches* creer_file() {
    FileTaches *f = (FileTaches*) malloc(sizeof(FileTaches));
    if (f == NULL) {
        printf("Erreur: allocation memoire echouee\n");
        exit(EXIT_FAILURE);
    }
    f->tete = NULL;
    f->queue = NULL;
    return f;
}

PileHistorique* creer_pile() {
    PileHistorique *p = (PileHistorique*) malloc(sizeof(PileHistorique));
    if (p == NULL) {
        printf("Erreur: allocation memoire echouee\n");
        exit(EXIT_FAILURE);
    }
    p->sommet = NULL;
    return p;
}

bool file_est_vide(FileTaches *f) {
    return f->tete == NULL;
}

bool pile_est_vide(PileHistorique *p) {
    return p->sommet == NULL;
}

NoeudArbre* inserer_dans_arbre(NoeudArbre *racine, Tache tache) {
    if (racine == NULL) {
        return creer_noeud_arbre(tache);
    }
    
    if (tache.priorite < racine->tache.priorite) {
        racine->gauche = inserer_dans_arbre(racine->gauche, tache);
    } else {
        racine->droite = inserer_dans_arbre(racine->droite, tache);
    }
    
    return racine;
}

void enfiler_tache(FileTaches *f, Tache tache) {
    NoeudListe *nouveau = creer_noeud_liste(tache);
    
    if (file_est_vide(f)) {
        f->tete = nouveau;
        f->queue = nouveau;
    } else {
        f->queue->suivant = nouveau;
        f->queue = nouveau;
    }
}

void empiler_tache(PileHistorique *p, Tache tache) {
    NoeudListe *nouveau = creer_noeud_liste(tache);
    nouveau->suivant = p->sommet;
    p->sommet = nouveau;
}

Tache defiler_tache(FileTaches *f) {
    if (file_est_vide(f)) {
        Tache tache_vide = {0};
        return tache_vide;
    }
    
    NoeudListe *temp = f->tete;
    Tache tache = temp->tache;
    
    f->tete = f->tete->suivant;
    
    if (f->tete == NULL) {
        f->queue = NULL;
    }
    
    free(temp);
    return tache;
}

void ajouter_tache(NoeudArbre **racine, FileTaches *file) {
    Tache nouvelle_tache;
    
    nouvelle_tache.id = id_courant++;
    nouvelle_tache.status = EN_ATTENTE;
    
    printf("Description de la tache: ");
    while (getchar() != '\n');
    fgets(nouvelle_tache.description, MAX_DESCRIPTION, stdin);
    
    size_t len = strlen(nouvelle_tache.description);
    if (len > 0 && nouvelle_tache.description[len - 1] == '\n') {
        nouvelle_tache.description[len - 1] = '\0';
    }
    
    printf("Priorite (1-10, 1 etant la plus elevee): ");
    if (scanf("%d", &nouvelle_tache.priorite) != 1 || 
        nouvelle_tache.priorite < 1 || nouvelle_tache.priorite > 10) {
        printf("Priorite invalide, fixee a 5 par defaut\n");
        nouvelle_tache.priorite = 5;
    }
    
    *racine = inserer_dans_arbre(*racine, nouvelle_tache);
    enfiler_tache(file, nouvelle_tache);
    
    printf("Tache ajoutee avec succes (ID: %d)\n", nouvelle_tache.id);
}

void parcours_infixe_arbre(NoeudArbre *racine) {
    if (racine != NULL) {
        parcours_infixe_arbre(racine->gauche);
        
        printf("ID: %d | Priorite: %d | Status: ", 
               racine->tache.id, racine->tache.priorite);
        
        switch (racine->tache.status) {
            case EN_ATTENTE: printf("En attente"); break;
            case EN_COURS: printf("En cours"); break;
            case TERMINEE: printf("Terminee"); break;
        }
        
        printf(" | Description: %s\n", racine->tache.description);
        
        parcours_infixe_arbre(racine->droite);
    }
}

NoeudArbre* trouver_tache_par_id(NoeudArbre *racine, int id) {
    if (racine == NULL) {
        return NULL;
    }
    
    if (racine->tache.id == id) {
        return racine;
    }
    
    NoeudArbre *trouve = trouver_tache_par_id(racine->gauche, id);
    if (trouve != NULL) {
        return trouve;
    }
    
    return trouver_tache_par_id(racine->droite, id);
}

void traiter_tache_par_priorite(NoeudArbre *racine, PileHistorique *historique) {
    if (racine == NULL) {
        printf("Pas de taches a traiter\n");
        return;
    }
    
    void parcourir_priorite(NoeudArbre *noeud) {
        if (noeud == NULL) return;
        
        parcourir_priorite(noeud->gauche);
        
        if (noeud->tache.status == EN_ATTENTE) {
            printf("Traitement de la tache prioritaire:\n");
            printf("ID: %d | Priorite: %d | Description: %s\n",
                   noeud->tache.id, noeud->tache.priorite, noeud->tache.description);
            
            printf("Marquer comme:\n");
            printf("1. En cours\n");
            printf("2. Terminee\n");
            printf("3. Ignorer\n");
            printf("Votre choix: ");
            
            int choix;
            if (scanf("%d", &choix) != 1 || choix < 1 || choix > 3) {
                printf("Choix invalide, tache ignoree\n");
                return;
            }
            
            if (choix == 1) {
                noeud->tache.status = EN_COURS;
                printf("Tache %d marquee comme 'En cours'\n", noeud->tache.id);
            } else if (choix == 2) {
                noeud->tache.status = TERMINEE;
                empiler_tache(historique, noeud->tache);
                printf("Tache %d marquee comme 'Terminee' et ajoutee a l'historique\n", noeud->tache.id);
            }
            
            return;
        }
        
        parcourir_priorite(noeud->droite);
    }
    
    parcourir_priorite(racine);
}

void marquer_tache_terminee(NoeudArbre *racine, PileHistorique *historique) {
    if (racine == NULL) {
        printf("Pas de taches a traiter\n");
        return;
    }
    
    int id;
    printf("Entrez l'ID de la tache a marquer comme terminee: ");
    if (scanf("%d", &id) != 1) {
        printf("ID invalide\n");
        return;
    }
    
    NoeudArbre *noeud = trouver_tache_par_id(racine, id);
    
    if (noeud == NULL) {
        printf("Tache avec ID %d non trouvee\n", id);
        return;
    }
    
    if (noeud->tache.status == TERMINEE) {
        printf("Cette tache est deja marquee comme terminee\n");
        return;
    }
    
    noeud->tache.status = TERMINEE;
    empiler_tache(historique, noeud->tache);
    printf("Tache %d marquee comme 'Terminee' et ajoutee a l'historique\n", noeud->tache.id);
}

void afficher_historique(PileHistorique *historique) {
    if (pile_est_vide(historique)) {
        printf("L'historique est vide\n");
        return;
    }
    
    printf("\n=== HISTORIQUE DES TACHES TERMINEES ===\n");
    printf("(Ordre: la plus recente en haut)\n\n");
    
    NoeudListe *courant = historique->sommet;
    int compteur = 1;
    
    while (courant != NULL) {
        printf("%d. ID: %d | Priorite: %d | Description: %s\n",
               compteur++, courant->tache.id, courant->tache.priorite, 
               courant->tache.description);
        courant = courant->suivant;
    }
}

void liberer_arbre(NoeudArbre *racine) {
    if (racine != NULL) {
        liberer_arbre(racine->gauche);
        liberer_arbre(racine->droite);
        free(racine);
    }
}

void liberer_file(FileTaches *f) {
    while (!file_est_vide(f)) {
        defiler_tache(f);
    }
    free(f);
}

void liberer_pile(PileHistorique *p) {
    NoeudListe *courant = p->sommet;
    NoeudListe *suivant;
    
    while (courant != NULL) {
        suivant = courant->suivant;
        free(courant);
        courant = suivant;
    }
    
    free(p);
}

int main() {
    NoeudArbre *arbre_taches = NULL;
    FileTaches *file_taches = creer_file();
    PileHistorique *historique = creer_pile();
    int choix;
    
    while (1) {
        printf("\n=== SYSTEME DE GESTION DE TACHES ===\n");
        printf("1. Ajouter une nouvelle tache\n");
        printf("2. Afficher toutes les taches\n");
        printf("3. Traiter la tache prioritaire\n");
        printf("4. Marquer une tache comme terminee\n");
        printf("5. Afficher l'historique des taches terminees\n");
        printf("6. Quitter\n");
        printf("Votre choix: ");
        
        if (scanf("%d", &choix) != 1) {
            printf("Erreur: choix invalide\n");
            while (getchar() != '\n');
            continue;
        }
        
        switch (choix) {
            case 1:
                ajouter_tache(&arbre_taches, file_taches);
                break;
                
            case 2:
                if (arbre_taches == NULL) {
                    printf("Aucune tache enregistree\n");
                } else {
                    printf("\n=== LISTE DES TACHES ===\n");
                    parcours_infixe_arbre(arbre_taches);
                }
                break;
                
            case 3:
                traiter_tache_par_priorite(arbre_taches, historique);
                break;
                
            case 4:
                marquer_tache_terminee(arbre_taches, historique);
                break;
                
            case 5:
                afficher_historique(historique);
                break;
                
            case 6:
                liberer_arbre(arbre_taches);
                liberer_file(file_taches);
                liberer_pile(historique);
                printf("Au revoir!\n");
                return 0;
                
            default:
                printf("Choix invalide!\n");
        }
    }
    
    return 0;
}

