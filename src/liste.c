/**
 * @file liste.c
 * @author do SANTOS ZOUNON Bénito K. (dosantosbenito81@gmail.com)
 * @brief Implémentation complète d'une liste chaînée d'objets génériques en C selon le modèle FILO.
 * @date 09-01-2026
 * @copyright Copyright (c) 2026
 */

#include "liste.h"

Liste *creer_liste(void)
{
    Liste *liste = malloc(sizeof(Liste));
    if (liste == NULL)
    {
        perror("Erreur d'allocation de mémoire");
        return NULL;
    }
    liste->premier = NULL;
    liste->dernier = NULL;
    liste->taille = 0;
    return liste;
}

Liste *supprimer_liste(Liste *liste)
{
    if (liste == NULL)
        return NULL;
    ElementListe *element_actuel = liste->dernier;
    ElementListe *element_precedent = NULL;
    while (element_actuel != NULL)
    {
        element_precedent = NULL;
        element_precedent = element_actuel->precedent;
        free(element_actuel);
        element_actuel = element_precedent;
    }
    free(liste);
    liste = NULL;
    return liste;
}
