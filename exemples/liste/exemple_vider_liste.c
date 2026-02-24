/**
 * Démonstration de `vider_liste()`
 * Ce programme crée une liste, y ajoute quelques éléments alloués dynamiquement,
 * libère ces valeurs, appelle `vider_liste()` et vérifie que la structure est vide.
 * Remarque : `vider_liste()` libère les noeuds de la liste mais ne libère pas
 * la mémoire pointée par `valeur` — il faut la libérer soi-même.
 */
#include <stdio.h>
#include <stdlib.h>
#include "liste.h"

int main(void)
{
    Liste *liste = creer_liste();
    if (liste == NULL)
        return 1;

    int *p1 = malloc(sizeof(int));
    int *p2 = malloc(sizeof(int));
    if (!p1 || !p2) return 1;
    *p1 = 1; *p2 = 2;

    ajouter_element(liste, p1);
    ajouter_element(liste, p2);

    printf("Avant vider_liste : taille=%d, premier=%p, dernier=%p\n", liste->taille, (void*)liste->premier, (void*)liste->dernier);

    /* libération des données stockées (nécessaire car vider_liste n'y touche pas) */
    free(p1);
    free(p2);

    liste = vider_liste(liste);

    printf("Après vider_liste : taille=%d (attendu 0), premier=%p (attendu NULL), dernier=%p (attendu NULL)\n",
           liste->taille, (void*)liste->premier, (void*)liste->dernier);

    free(liste);
    return 0;
}
