/**
 * Démonstration de `ajouter_element()`
 * Ce fichier illustre l'ajout d'éléments de types différents (int alloué dynamiquement, littéral chaîne, NULL)
 * et l'itération sur la liste pour vérifier les valeurs ajoutées.
 */
#include <stdio.h>
#include <stdlib.h>
#include "liste.h"

int main(void)
{
    printf("La fonction ajouter_element() permet d'ajouter des éléments de n'importe quel type à la liste.\n");
    printf("Démonstration : \n\n\n");

    Liste *liste = creer_liste();
    if (liste == NULL)
        return 1;

    printf("On crée une liste vide et on y ajoute quelques éléments de types différents.\n");

    // Ajout de deux entiers
    int a = 10;
    int b = 20;
    ajouter_element(liste, &a);
    ajouter_element(liste, &b);

    /* Ajout d'une chaîne littérale (ne doit pas être free() plus tard) */
    ajouter_element(liste, "Bonjour");

    /* Ajout d'une chaîne littérale (ne doit pas être free() plus tard) */
    ajouter_element(liste, "N'est-ce pas un programme incroyable avec des fonctionnalités de ouf !!");

    /* Ajout d'un pointeur NULL */
    ajouter_element(liste, NULL);

    printf("Après différents ajouts, la taille de la liste est de %d éléments (Valeur attendue : 5)\n", liste->taille);

    printf("Parcours de la liste (affichage des contenus) :\n");
    int index = 0;
    for (ElementListe *e = liste->premier; e != NULL; e = e->suivant)
    {
        printf(" - Élément [%d] : ", index++);
        if (e->valeur == NULL)
        {
            printf("(NULL)");
        }
        else if (e->valeur == &a)
        {
            printf("%d", *(int *)e->valeur);
        }
        else if (e->valeur == &b)
        {
            printf("%d", *(int *)e->valeur);
        }
        else
        {
            printf("%s", (char *)e->valeur);
        }
        printf("\n");
    }

    liste = vider_liste(liste);
    free(liste);
    printf("\n\n");
    printf("Fin de la démonstration de ajouter_element().\n");
    return 0;
}
