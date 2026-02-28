/**
 * Démonstration de l'**ajout d'éléments** dans une liste.
 *
 * Fonctions illustrées ici :
 *  - creer_liste()
 *  - ajouter_element()
 *  - rechercher_index_par_adresse()
 *  - rechercher_element_par_index()
 *
 * On montre comment :
 *  - remplir la liste avec plusieurs valeurs,
 *  - retrouver la position (index) d'un element a partir de son adresse,
 *  - retrouver un element a partir de son index.
 */
#include <stdio.h>
#include <stdlib.h>
#include "liste.h"

/* Variable globale pour le parcours avec compteur d'index */
static int _index_courant;

static void afficher_element(void *valeur)
{
    printf("  - element[%d] -> %d\n", _index_courant, *(int *)valeur);
    _index_courant++;
}

static void afficher_liste(const Liste *liste, const char *titre)
{
    printf("%s :\n", titre);
    _index_courant = 0;
    parcourir_liste(liste, afficher_element);
    printf("\n");
}

int main(void)
{
    printf("=== Exemple 2 : ajout d'elements et recherches ===\n\n");

    Liste *liste = creer_liste();
    if (!liste)
    {
        fprintf_s(stderr, "Erreur : impossible de creer la liste\n");
        return EXIT_FAILURE;
    }

    int a = 10, b = 20, c = 30, d = 40, e = 50;

    printf("Ajout des valeurs %d, %d, %d, %d, %d dans la liste...\n", a, b, c, d, e);
    ajouter_element(liste, &a);
    ajouter_element(liste, &b);
    ajouter_element(liste, &c);
    ajouter_element(liste, &d);
    ajouter_element(liste, &e);

    printf("La liste contient maintenant %d elements.\n\n", taille_liste(liste));

    /* Parcours simple en utilisant la fonction generique parcourir_liste() */
    afficher_liste(liste, "Parcours de la liste (par chainage)");

    /* Recherche de l'index a partir de l'adresse */
    printf("Recherche de l'index d'éléments par leur adresse :\n");
    printf("  adresse de a -> index %d\n", rechercher_index_par_adresse(liste, &a));
    printf("  adresse de c -> index %d\n", rechercher_index_par_adresse(liste, &c));
    printf("  adresse de e -> index %d\n", rechercher_index_par_adresse(liste, &e));

    int x = 999;
    printf("  adresse de x (non present) -> index %d (attendu -1)\n",
           rechercher_index_par_adresse(liste, &x));
    printf("\n");

    /* Recherche d'un element a partir de son index */
    printf("Recherche d'elements par index :\n");
    for (int i = 0; i < taille_liste(liste); ++i)
    {
        int *val = (int *)rechercher_element_par_index(liste, i);
        if (val)
            printf("  element a l'index %d -> %d\n", i, *val);
    }

    printf("\nTest de cas limites pour rechercher_element_par_index() :\n");
    printf("  index -1 -> %p (attendu NULL)\n", rechercher_element_par_index(liste, -1));
    printf("  index %d (== taille) -> %p (attendu NULL)\n",
           taille_liste(liste), rechercher_element_par_index(liste, taille_liste(liste)));

    /* Ici les valeurs sont sur la pile, donc on ne les free pas.
       On vide simplement la liste puis on libere la structure. */
    liste = vider_liste(liste);
    free(liste);

    printf("\nFin de l'exemple 2.\n");
    return EXIT_SUCCESS;
}

