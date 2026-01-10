/**
 * @file liste.h
 * @author do SANTOS ZOUNON Bénito K. (dosantosbenito81@gmail.com)
 * @brief Ce fichier offre une implémentation complète d'une liste chaînée
 d'objets génériques en C selon le modèle FILO. Il inclut toutes les fonctions de base pour manipuler
 aisément n'importe quel objet dans une liste chaînée. Les fonctionnalités
 exhaustives incluent la création, l'ajout, la suppression, la recherche,
 l'affichage, la fusion, la duplication, Chaque fonction est soigneusement
 conçue pour garantir une gestion efficace de la mémoire et des performances
 optimales. Ce fichier est idéal pour les développeurs cherchant à intégrer sans
 souci des listes chaînées génériques dans leurs projets C.
 * @date 09-01-2026
 * @copyright Copyright (c) 2026
 */
#ifndef LISTE_H
#define LISTE_H
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct ElementListe
{
    void *valeur;
    struct ElementListe *suivant, *precedent;
} ElementListe;

typedef struct
{
    ElementListe *premier, *dernier;
    int taille;
} Liste;

/* Prototypes des fonctions */

/**
 * @brief Crée une liste de taille_liste éléments. Chaque élément est initialisé à NULL.
 *
 * @param taille_liste La taille de la liste
 * @return Liste* La liste créée ou NULL en cas d'erreur
 */
Liste *creer_liste(void);

/**
 * @brief Libère toute la mémoire occupée et mets la liste à NULL.
 *
 * @param liste La liste à supprimer
 * @return La liste qui est maintenant un pointeur nul
 */
Liste *supprimer_liste(Liste *liste);

#endif