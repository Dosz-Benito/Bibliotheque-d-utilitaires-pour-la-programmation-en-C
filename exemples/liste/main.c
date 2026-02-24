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
#include <string.h>
#include <time.h>
#include "liste.h"

/**
 * @brief Fonction principale démontrant l'utilisation de la bibliothèque de listes chaînées génériques.
 *
 * Cette fonction illustre les opérations de base sur une liste chaînée :
 * - La création d'une liste vide
 * - L'ajout d'un nombre aléatoire (1-100) d'éléments à la liste
 * - Le vidage de la liste et libération de la mémoire
 *
 * @return Code de retour (int) : 0 en cas de succès, 1 en cas d'erreur
 */
int main(void)
{
    // Création d'une liste vide
    Liste *liste = creer_liste();
    if (liste == NULL)
    {
        perror("Erreur lors de la création de la liste");
        return 1;
    }
    printf("Une nouvelle liste de %d élément est créée\n", liste->taille);

    printf("Choix d'un nombre aléatoire d'éléments à ajouter...\n");

    // Initialisation du générateur de nombres aléatoires
    // La génération aléatoire est uniquement utilisée ici à des fins de démonstration.
    srand(time(NULL));

    int nb = rand() % 100 + 1; // Nombre aléatoire d'éléments entre 1 et 100

    // Ajout d'éléments à la liste
    printf("On ajoute %d nombre%s à la liste.\n", nb, nb > 1 ? "s" : "");
    for (int i = 1; i <= nb; i++)
    {
        // Allocation de mémoire pour chaque valeur
        int *valeur = malloc(sizeof(int));
        if (valeur == NULL)
        {
            printf("Erreur d'allocation de mémoire pour le nombre %d: %s", i, strerror(errno));
            // Nettoyage de la liste avant de quitter
            liste = vider_liste(liste);
            free(liste);
            liste = NULL;
            return 1;
        }
        *valeur = i;

        // Ajout de l'élément à la liste
        if (!ajouter_element(liste, valeur))
        {
            printf("Erreur lors de l'ajout du nombre %d à la liste: %s", i, strerror(errno));
            free(valeur);
            valeur = NULL;

            // Nettoyage de la liste avant de quitter
            liste = vider_liste(liste);
            free(liste);
            liste = NULL;
            return 1;
        }
    }

    printf("On ajoute quelques autres types d'éléments (NULL, char, char*, float) pour démontrer la nature générique de la liste\n");
    ajouter_element(liste, NULL);
    ajouter_element(liste, "Une chaîne de caractères");
    float *pi = malloc(sizeof(float));
    // Les erreurs ne sont pas gérées ici pour préserver la simplicité de l'exemple
    if (pi == NULL)
    {
        printf("Erreur d'allocation de mémoire pour le nombre pi: %s", strerror(errno));
        // Nettoyage de la liste avant de quitter
        liste = vider_liste(liste);
        free(liste);
        liste = NULL;
        return EXIT_FAILURE;
    }
    *pi = 3.1415f;
    ajouter_element(liste, pi);
    char *caractere = malloc(sizeof(char));
    if (caractere == NULL)
    {
        printf("Erreur d'allocation de mémoire pour le caractère: %s", strerror(errno));
        // Nettoyage de la liste avant de quitter
        liste = vider_liste(liste);
        free(liste);
        liste = NULL;
        return EXIT_FAILURE;
    }
        *caractere = 'A';
        ajouter_element(liste, caractere);

    // Affichage de la taille de la liste
    printf("La liste a %d élément%s.\n", liste->taille, liste->taille > 1 ? "s" : "");

    // On supprime un élément spécifique (par pointeur)
    // On supprime correctement le nombre pi de la liste
    printf("On supprime le nombre pi (%f) de la liste.\n", *pi);
    switch (supprimer_element_par_pointeur(liste, pi))
    {
    case 0:
        printf("L'élément %f a été supprimé avec succès.\n", *pi);
        break;
    case 1:
        printf("L'élément %f est introuvable dans la liste.\n", *pi);
        break;
    case -1:
        printf("La liste est un pointeur nul.\n");
        break;
    }

    printf("On supprime également NULL et le caractère '%c' de la liste.\n", *caractere);
    // Absence de gestion des erreurs pour préserver la simplicité de l'exemple
    supprimer_element_par_pointeur(liste, caractere);
    supprimer_element_par_pointeur(liste, NULL);
    printf("La liste a maintenant %d élément%s.\n", liste->taille, liste->taille > 1 ? "s" : "");

    /* Démonstration de la suppression par index */
    if (liste->taille > 0)
    {
        int index_a_supprimer = 0; // supprimer le premier élément (index 0)
        printf("Suppression de l'élément à l'index %d...\n", index_a_supprimer);
        switch (supprimer_element_par_index(liste, index_a_supprimer))
        {
        case 0:
            printf("L'élément à l'index %d a été supprimé avec succès.\n", index_a_supprimer);
            break;
        case 1:
            printf("Index %d invalide ou liste nulle.\n", index_a_supprimer);
            break;
        case -1:
            printf("Erreur lors de la suppression par index.\n");
            break;
        }
        printf("La liste a maintenant %d élément%s après suppression par index.\n", liste->taille, liste->taille > 1 ? "s" : "");
    }

    // Vidage de la liste et libération de la mémoire
    printf("On vide la liste...\n");
    liste = vider_liste(liste);

    // Vérification que le vidage s'est bien passée
    // Une liste correctement vidée doit avoir :
    // - premier = NULL (aucun élément au début)
    // - dernier = NULL (aucun élément à la fin)
    // - taille = 0 (la taille de la liste est remise à zéro)
    if (liste->premier == NULL && liste->dernier == NULL && liste->taille == 0)
        printf("Le vidage de la liste s'est bien passé\n");
    else
        printf("Le vidage de la liste s'est mal passé\n");

    // Libération de la mémoire
    free(pi);
    free(caractere);
    // Libération de la variable liste elle-même
    free(liste);
    liste = NULL;

    return 0;
}