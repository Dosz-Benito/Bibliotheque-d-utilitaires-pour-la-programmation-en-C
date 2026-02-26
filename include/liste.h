/**
 * @file liste.h
 * @author do SANTOS ZOUNON Bénito K. (dosantosbenito81@gmail.com)
 * @brief Ce fichier offre une implémentation complète d'une liste chaînée
 d'objets génériques en C selon le modèle FILO. Il inclut toutes les fonctions de base pour manipuler
 aisément n'importe quel objet dans une liste chaînée. Les fonctionnalités
 exhaustives incluent la création, l'ajout, le vidage, la suppression, la recherche,
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
 * @brief Libère toute la mémoire occupée par les éléments de la liste.
 * Cette fonction libère uniquement la mémoire des éléments de la liste,
 * la mémoire utilisée par la liste elle-même doit être libérée séparément.
 *
 * @param liste La liste à vider
 * @return La liste qui est maintenant un pointeur nul
 */
Liste *vider_liste(Liste *liste);

/**
 * @brief Ajoute un nouvel élément à la fin de la liste.
 *
 * @param liste La liste à laquelle ajouter l'élément
 * @param element L'élément à ajouter
 * @return true si l'ajout a réussi, false sinon
 */
bool ajouter_element(Liste *liste, void *element);

/**
 * @brief Trouve le premier élément de la liste qui pointe vers la même adresse qui l'élément fourni et le supprime de la liste.
 *
 * @param liste La liste de laquelle supprimer l'élément
 * @param element L'élément à supprimer
 * @return 0 si la suppression a réussi, 1 si l'élément est introuvable, -1 si la liste est un pointeur nul
 */
int supprimer_element_par_pointeur(Liste *liste, void *element);

/**
 * @brief Supprime l'élément à l'index spécifié de la liste. L'index est basé sur zéro, c'est-à-dire que le premier élément de la liste a un index de 0, le deuxième élément a un index de 1, et ainsi de suite. Si l'index est invalide (par exemple, négatif ou supérieur ou égal à la taille de la liste), la fonction retourne une erreur.
 *
 *
 * @param liste La liste de laquelle supprimer l'élément
 * @param index L'index de l'élément à supprimer
 * @return 0 si la suppression a réussi, 1 si l'index est invalide ou si la liste est un pointeur nul, -1 en cas d'autre erreur
 */
int supprimer_element_par_index(Liste *liste, int index);

/**
 * @brief Recherche l'élément correspondant à l'index spécifié dans la liste.
 * 
 *
 * @param liste La liste dans laquelle rechercher l'élément
 * @param index L'index de l'élément à rechercher
 * @return L'élément à l'index spécifié, NULL si l'index est invalide ou si la liste est un pointeur nul
 */
void * rechercher_element_par_index(Liste *liste, int index);
#endif