/**
 * Démonstration de `creer_liste()`
 * Ce fichier montre la création d'une liste vide et l'état initial attendu.
 * Résultat attendu : la liste est non nulle, `taille` == 0, `premier` et `dernier` == NULL.
 */
#include <stdio.h>
#include <stdlib.h>
#include "liste.h"

int main(void)
{
    Liste *liste = creer_liste();
    if (liste == NULL)
    {
        fprintf_s(stderr, "Erreur : creer_liste() a retourné NULL\n");
        return 1;
    }

    printf("Liste créée : adresse=%p\n", liste);
    printf("Taille de la liste : %d ; Valeur attendue : 0\n", liste->taille);
    printf("Le premier élément de la liste est %p ; Valeur attendue : %p\n", liste->premier, NULL);
    printf("Le dernier élément de la liste est %p ; Valeur attendue : %p\n", liste->dernier, NULL);

    // Libération de la structure liste
    // On appelle vider_liste juste au cas où la liste ne serait pas vide (cas anormal)
    vider_liste(liste);
    free(liste);
    return 0;
}
