/**
 * @file exemple_rechercher_index_par_adresse.c
 * @brief Exemple d'utilisation de la fonction rechercher_index_par_adresse
 * 
 * Ce programme démontre comment rechercher l'index d'un élément dans une liste
 * en utilisant son adresse. La fonction retourne l'index de la première occurrence
 * de la valeur si elle existe, ou -1 si la valeur n'est pas trouvée.
 */

#include <stdio.h>
#include <stdlib.h>
#include "liste.h"

int main(void)
{
    printf("\033[1;34m=== Exemple: Recherche d'index par adresse ===\033[0m\n\n");

    // Création d'une liste
    Liste *liste = creer_liste();
    if (liste == NULL)
    {
        fprintf_s(stderr, "Erreur lors de la création de la liste.\n");
        return EXIT_FAILURE;
    }

    printf("\033[33mLa fonction de recherche d'index par adresse retournera l'index du premier élément trouvé ou -1 si aucun élément n'est trouvé.\033[0m\n\n");

    // Ajout d'éléments à la liste
    int a = 10, b = 20, c = 30, d = 40, e = 50;

    ajouter_element(liste, &a);
    ajouter_element(liste, &b);
    ajouter_element(liste, &c);
    ajouter_element(liste, &d);

    printf("Liste créée avec les éléments: %d, %d, %d, %d\n", a, b, c, d);

    // Recherche de l'index de chaque élément
    printf("L'élément %d est à l'index: %d\n", a, rechercher_index_par_adresse(liste, &a));
    printf("L'élément %d est à l'index: %d\n", b, rechercher_index_par_adresse(liste, &b));
    printf("L'élément %d est à l'index: %d\n", c, rechercher_index_par_adresse(liste, &c));
    printf("L'élément %d est à l'index: %d\n", d, rechercher_index_par_adresse(liste, &d));

    // Recherche d'un élément qui n'est pas dans la liste
    printf("On teste la fonction sur un élément qui n'est pas dans la liste (e = %d):\n", e);
    int retour = rechercher_index_par_adresse(liste, &e);
    printf("%sL'élément %d est à l'index: %d\033[0m\n", retour == -1 ? "\033[32m" : "\033[31m", e, retour);

    printf("\n\033[1;34m=== Fin de l'exemple ===\033[0m\n");
    liste = vider_liste(liste);
    free(liste);
    return EXIT_SUCCESS;
}
