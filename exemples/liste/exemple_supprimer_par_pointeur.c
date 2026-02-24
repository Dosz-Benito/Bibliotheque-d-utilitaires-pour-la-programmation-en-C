/**
 * Démonstration de `supprimer_element_par_pointeur()`
 * Ce démonstrateur ajoute plusieurs éléments, supprime un élément donné par son pointeur,
 * vérifie le code de retour et la nouvelle taille de la liste.
 */
#include <stdio.h>
#include <stdlib.h>
#include "liste.h"

int main(void)
{
    Liste *liste = creer_liste();
    if (!liste) return 1;

    int *x = malloc(sizeof(int));
    int *y = malloc(sizeof(int));
    if (!x || !y) return 1;
    *x = 10; *y = 20;

    ajouter_element(liste, x);
    ajouter_element(liste, y);
    ajouter_element(liste, NULL); /* valeur NULL possible */

    printf("Taille avant suppression=%d\n", liste->taille);

    /* Suppression de y par pointeur */
    int r = supprimer_element_par_pointeur(liste, y);
    printf("supprimer_element_par_pointeur pour y -> %d (0=succès)\n", r);
    printf("Taille après suppression=%d (attendu 2)\n", liste->taille);

    /* Tentative de suppression d'un pointeur non présent */
    int z;
    r = supprimer_element_par_pointeur(liste, &z);
    printf("suppression d'un pointeur non présent -> %d (attendu 1)\n", r);

    /* Suppression de NULL (présent) */
    r = supprimer_element_par_pointeur(liste, NULL);
    printf("suppression de NULL -> %d (0 si trouvé)\n", r);

    /* Nettoyage : libérer les valeurs restantes puis vider la liste */
    free(x);
    liste = vider_liste(liste);
    free(liste);
    return 0;
}
