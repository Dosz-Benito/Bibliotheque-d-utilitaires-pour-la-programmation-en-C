/**
 * @file liste.c
 * @author do SANTOS ZOUNON Bénito K. (dosantosbenito81@gmail.com)
 * @brief Ce fichier illustre un exemple simple d'utilisation de la bibliothèque de listes chaînées génériques.
 * @date 09/01/2026
 * 
 * @copyright Copyright (c) 2026
 * 
 */
#include <stdio.h>
#include <errno.h>
#include "../include/liste.h"

int main(int argc, const char **argv)
{
    // Création d'une liste
    Liste * liste = creer_liste();
    printf("Une nouvelle liste de %d element est créée\n", liste->taille);

    // Suppression de la liste
    printf("On supprime la liste...\n");
    liste = supprimer_liste(liste);

    if (liste == NULL)
        printf("La suppression de la liste s'est bien passée");
    else
        perror("La suppression de la liste s'est mal passée");

    return 0;
}