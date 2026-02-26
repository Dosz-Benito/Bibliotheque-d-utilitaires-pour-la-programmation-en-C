/**
 * Démonstration de la **suppression d'éléments** dans une liste.
 *
 * Fonctions illustrées ici :
 *  - creer_liste()
 *  - ajouter_element()
 *  - supprimer_element_par_pointeur()
 *  - supprimer_element_par_index()
 *  - vider_liste()
 *
 * On ajoute quelques valeurs, puis on les retire :
 *  - d'abord en ciblant les elements par leur pointeur,
 *  - puis en supprimant par index.
 */
#include <stdio.h>
#include <stdlib.h>
#include "liste.h"

static void afficher_liste_ints(const Liste *liste, const char *titre)
{
    printf("%s (taille=%d) : ", titre, liste->taille);
    for (ElementListe *e = liste->premier; e != NULL; e = e->suivant)
    {
        if (e->valeur)
            printf(" %d", *(int *)e->valeur);
        else
            printf(" (NULL)");
    }
    printf("\n");
}

int main(void)
{
    printf("=== Exemple 3 : suppression d'elements ===\n\n");

    Liste *liste = creer_liste();
    if (!liste)
    {
        fprintf(stderr, "Erreur : impossible de creer la liste\n");
        return EXIT_FAILURE;
    }

    /* Pour faciliter le nettoyage, on stocke les valeurs dans un tableau alloue. */
    int *vals = malloc(5 * sizeof *vals);
    if (!vals)
    {
        free(liste);
        return EXIT_FAILURE;
    }

    for (int i = 0; i < 5; ++i)
    {
        vals[i] = (i + 1) * 10; /* 10, 20, 30, 40, 50 */
        ajouter_element(liste, &vals[i]);
    }

    /* On ajoute aussi un element NULL pour montrer que c'est accepte. */
    ajouter_element(liste, NULL);

    afficher_liste_ints(liste, "Liste initiale");

    /* --- Suppression par pointeur --- */
    printf("\nSuppression par pointeur : suppression de la valeur 30 puis de NULL.\n");

    int rc = supprimer_element_par_pointeur(liste, &vals[2]); /* valeur 30 */
    printf("  supprimer_element_par_pointeur(&vals[2]) -> %d (0=succes)\n", rc);
    rc = supprimer_element_par_pointeur(liste, NULL);
    printf("  supprimer_element_par_pointeur(NULL) -> %d (0=succes si NULL etait present)\n", rc);

    afficher_liste_ints(liste, "Apres suppression par pointeur");

    /* Tentative de suppression d'un pointeur inexistant */
    int x = 999;
    rc = supprimer_element_par_pointeur(liste, &x);
    printf("  suppression d'un pointeur non present -> %d (attendu 1)\n", rc);

    /* --- Suppression par index --- */
    printf("\nSuppression par index :\n");
    afficher_liste_ints(liste, "Etat avant suppression par index");

    if (liste->taille > 0)
    {
        int index_a_supprimer = 0;
        rc = supprimer_element_par_index(liste, index_a_supprimer);
        printf("  supprimer_element_par_index(%d) -> %d (0=succes)\n",
               index_a_supprimer, rc);
    }

    if (liste->taille > 1)
    {
        int index_a_supprimer = 1; /* apres une premiere suppression */
        rc = supprimer_element_par_index(liste, index_a_supprimer);
        printf("  supprimer_element_par_index(%d) -> %d (0=succes)\n",
               index_a_supprimer, rc);
    }

    afficher_liste_ints(liste, "Apres suppression par index");

    /* Tests d'index invalides */
    printf("\nTests d'index invalides :\n");
    rc = supprimer_element_par_index(liste, -1);
    printf("  index -1 -> %d (attendu 1)\n", rc);
    rc = supprimer_element_par_index(liste, liste->taille);
    printf("  index == taille (%d) -> %d (attendu 1)\n", liste->taille, rc);

    /* Nettoyage complet */
    liste = vider_liste(liste);
    free(liste);
    free(vals);

    printf("\nFin de l'exemple 3.\n");
    return EXIT_SUCCESS;
}

