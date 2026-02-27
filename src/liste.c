/**
 * @file liste.c
 * @author do SANTOS ZOUNON Bénito K. (dosantosbenito81@gmail.com)
 * @brief Implémentation complète d'une liste chaînée d'objets génériques en C selon le modèle FILO.
 * @date 09-01-2026
 * @copyright Copyright (c) 2026
 */

#include "liste.h"
#include <stdlib.h>
#include <stdio.h>

#pragma region "Structures"
struct ElementListe
{
    void *valeur;
    ElementListe *suivant, *precedent;
};

struct Liste
{
    ElementListe *premier, *dernier;
    int taille;
};
#pragma endregion

#pragma region "Fonctions de base d'une liste"
Liste *creer_liste(void)
{
    Liste *liste = malloc(sizeof(Liste));
    if (liste == NULL)
    {
        perror("Erreur d'allocation de mémoire lors de la création de la liste");
        return NULL;
    }
    liste->premier = NULL;
    liste->dernier = NULL;
    liste->taille = 0;
    return liste;
}

int taille_liste(const Liste *liste)
{
    if (liste == NULL)
        return -1;
    return liste->taille;
}

Liste *vider_liste(Liste *liste)
{
    if (liste == NULL)
        return NULL;
    ElementListe *element_actuel = liste->dernier;
    ElementListe *element_precedent = NULL;
    while (element_actuel != NULL)
    {
        element_precedent = element_actuel->precedent;
        free(element_actuel);
        element_actuel = element_precedent;
    }

    liste->premier = NULL;
    liste->dernier = NULL;
    liste->taille = 0;
    return liste;
}
#pragma endregion

#pragma region "Fonctions d'ajout"
bool ajouter_element(Liste *liste, void *element)
{
    ElementListe *element_liste = malloc(sizeof(ElementListe));

    if (element_liste == NULL)
    {
        perror("Erreur d'allocation de mémoire");
        return false;
    }

    // On configure element_liste
    element_liste->precedent = element_liste->suivant = NULL;
    element_liste->valeur = element;

    // On lie le nouvel élément à la liste
    if (liste->taille == 0)
    {
        liste->premier = liste->dernier = element_liste;
    }
    else
    {
        element_liste->precedent = liste->dernier;
        liste->dernier->suivant = element_liste;
        liste->dernier = element_liste;
    }
    liste->taille += 1;
    return true;
}
#pragma endregion

#pragma region "Fonctions de suppression"
int supprimer_element_par_pointeur(Liste *liste, void *element)
{
    if (liste == NULL)
        return -1;

    ElementListe *element_actuel = liste->premier;
    while (element_actuel != NULL)
    {
        if (element_actuel->valeur == element)
        {
            if (element_actuel->precedent == NULL)
                liste->premier = element_actuel->suivant;
            else
                element_actuel->precedent->suivant = element_actuel->suivant;

            if (element_actuel->suivant == NULL)
                liste->dernier = element_actuel->precedent;
            else
                element_actuel->suivant->precedent = element_actuel->precedent;

            liste->taille -= 1;
            free(element_actuel);
            return 0;
        }
        element_actuel = element_actuel->suivant;
    }
    return 1;
}

int supprimer_element_par_index(Liste *liste, int index)
{
    if (liste == NULL)
        return -1;

    if (index < 0 || index >= liste->taille)
        return 1;

    /* Trouver l'élément à l'index demandé */
    ElementListe *element_actuel = liste->premier;
    for (int i = 0; i < index; i++)
        element_actuel = element_actuel->suivant;

    /* Détacher l'élément en mettant à jour les voisins */
    if (element_actuel->precedent)
        element_actuel->precedent->suivant = element_actuel->suivant;
    else
        liste->premier = element_actuel->suivant;

    if (element_actuel->suivant)
        element_actuel->suivant->precedent = element_actuel->precedent;
    else
        liste->dernier = element_actuel->precedent;

    liste->taille -= 1;
    free(element_actuel);
    return 0;
}
#pragma endregion

#pragma region "Fonctions de recherche"
int rechercher_index_par_adresse(Liste *liste, void *element)
{
    if (liste == NULL)
        return -2;
    int index = 0;
    for (ElementListe *element_actuel = liste->premier; element_actuel != NULL; element_actuel = element_actuel->suivant)
    {
        if (element_actuel->valeur == element)
            return index;
        index += 1;
    }
    return -1;
}
void *rechercher_element_par_index(Liste *liste, int index)
{
    if (liste == NULL || index < 0 || index >= liste->taille)
    return NULL;

    int i = 0;
    ElementListe *resultat = NULL;
    for (resultat = liste->premier; i < index; resultat = resultat->suivant)
    i++;
    return resultat->valeur;
}
#pragma endregion

#pragma region "Fonctions de parcours"
void parcourir_liste(const Liste * liste, void (*fonction_parcours)(void *valeur))
{
    if (liste == NULL) return;

    for(ElementListe * element_actuel = liste->premier; element_actuel != NULL; element_actuel = element_actuel->suivant)
        fonction_parcours(element_actuel->valeur);
}
#pragma endregion