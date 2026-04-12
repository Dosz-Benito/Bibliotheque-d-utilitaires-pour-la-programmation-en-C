#include "exemple.h"
#include "liste.h"
#include <stdio.h>
#include <stdlib.h>
#pragma region "Structures"
struct GestionnaireTaches
{
    Liste *taches;
};
struct Tache
{
    int id;
    char *nom;
    bool statut;
};
enum StatutTache
{
    A_FAIRE,
    EN_COURS,
    TERMINEE
};
enum StatutTache statut_tache = A_FAIRE;
#pragma endregion

#pragma region "Fonctions du gestionnaire de tâches"
GestionnaireTaches *creer_gestionnaire()
{
    GestionnaireTaches *gestionnaire = malloc(sizeof(GestionnaireTaches));
    if (gestionnaire == NULL)
    {
        fprintf(stderr, "Erreur d'allocation mémoire pour le gestionnaire de tâches.\n");
        exit(EXIT_FAILURE);
    }
    gestionnaire->taches = creer_liste(); // Initialiser la liste des tâches à NULL
    if (gestionnaire->taches == NULL)
        return NULL;

    return gestionnaire;
}

void ajouter_tache(GestionnaireTaches *gestionnaire, Tache *tache)
{
    if (gestionnaire == NULL)
    {
        fprintf(stderr, "Gestionnaire invalide (pointeur nul).\n");
        return;
    }
    if (tache == NULL)
    {
        fprintf(stderr, "Tâche invalide (pointeur nul).\n");
        return;
    }
    ajouter_element(gestionnaire->taches, tache);
}

int nombre_taches(GestionnaireTaches *gestionnaire)
{
    if (gestionnaire == NULL)
    {
        fprintf(stderr, "Gestionnaire invalide (pointeur nul).\n");
        return -1;
    }
    return taille_liste(gestionnaire->taches);
}
#pragma endregion

#pragma region "Fonctions de la tâche"
Tache *creer_tache(const int id, const char *nom, StatutTache statut)
{
    Tache *tache = malloc(sizeof(Tache));
    if (tache == NULL)
    {
        perror("Erreur d'allocation de mémoire lors de la création de la tâche");
        return NULL;
    }

    tache->id = id;
    tache->nom = nom;
    tache->statut = statut;
    return tache;
}
#pragma endregion