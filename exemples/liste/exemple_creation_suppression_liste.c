/**
 * Démonstration de la **création** et de la **suppression** d'une liste.
 *
 * Fonctions illustrées ici :
 *  - creer_liste()
 *  - ajouter_element()   (pour remplir un peu la liste)
 *  - vider_liste()
 *
 * L'objectif est de montrer le cycle de vie complet de la structure Liste :
 *   création -> utilisation -> vidage -> libération.
 */
#include <stdio.h>
#include <stdlib.h>
#include "liste.h"

int main(void)
{
    printf("=== Exemple 1 : creation et suppression d'une liste ===\n\n");

    /* Création d'une liste vide */
    Liste *liste = creer_liste();
    if (liste == NULL)
    {
        fprintf_s(stderr, "Erreur : creer_liste() a retourne NULL\n");
        return EXIT_FAILURE;
    }

    printf("Liste creee : adresse=%p\n", (void *)liste);
    printf("Etat initial -> taille=%d (attendu : 0)\n", taille_liste(liste));

    /* On ajoute quelques valeurs pour montrer que la liste sert vraiment a quelque chose */
    int *v1 = malloc(sizeof *v1);
    int *v2 = malloc(sizeof *v2);
    if (!v1 || !v2)
    {
        fprintf_s(stderr, "Erreur d'allocation pour les valeurs\n");
        free(v1);
        free(v2);
        free(liste);
        return EXIT_FAILURE;
    }
    *v1 = 42;
    *v2 = 99;

    ajouter_element(liste, v1);
    ajouter_element(liste, v2);

    printf("Apres ajout de deux elements, taille=%d (attendu : 2)\n", taille_liste(liste));

    /* On libère les valeurs stockées (vider_liste ne libère que les noeuds) */
    free(v1);
    free(v2);

    /* Vidage complet de la liste : tous les noeuds sont liberes,
       la structure Liste reste valide mais vide. */
    liste = vider_liste(liste);

    printf("Apres vider_liste -> taille=%d (attendu : 0)\n", taille_liste(liste));

    /* Enfin, on libère la structure Liste elle‑meme */
    free(liste);
    liste = NULL;

    printf("\nFin de l'exemple 1.\n");
    return EXIT_SUCCESS;
}

