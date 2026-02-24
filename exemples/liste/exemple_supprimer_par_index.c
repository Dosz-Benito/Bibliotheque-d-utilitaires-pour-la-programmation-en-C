/**
 * Démonstration de `supprimer_element_par_index()`
 * ATTENTION : l'implémentation actuelle a des limites pour l'index 0.
 * Ce démonstrateur supprime un élément d'un index non nul (ici index 2) pour éviter
 * un comportement non défini potentiel. On teste aussi la gestion d'un index invalide.
 */
#include <stdio.h>
#include <stdlib.h>
#include "liste.h"

int main(void)
{
    Liste *liste = creer_liste();
    if (!liste) return 1;

    /* Ajout de 5 entiers */
    for (int i = 0; i < 5; ++i)
    {
        int a = i + 1;
        ajouter_element(liste, &a);
    }

    printf("Taille avant suppression=%d (attendu 5)\n", liste->taille);

    /* Suppression de l'élément à l'index 2 (troisième élément) */
    int rc = supprimer_element_par_index(liste, 2);
    printf("La suppression de l'élément d'index 2 (troisème élément) a retourné %d : %s\n", rc, rc == 0 ? "succès" : "échec");
    printf("Taille après suppression=%d (attendu 4)\n", liste->taille);

    printf("Parcours après suppression :\n");
    for (ElementListe *e = liste->premier; e != NULL; e = e->suivant)
    {
        if (e->valeur)
            printf(" %d", *(int *)e->valeur);
        else
            printf(" (NULL)");
    }
    printf("\n");

    /* Test d'un index invalide */
    printf("On tente de supprimer un élément avec un index invalide (-1)\n");
    rc = supprimer_element_par_index(liste, -1);
    printf("La suppression de l'élément d'index -1 a retourné %d : %s\n", rc, rc == 0 ? "succès" : "échec");

    liste = vider_liste(liste);
    free(liste);
    printf("Fin de la démonstration de supprimer_element_par_index().\n");
    return 0;
}
