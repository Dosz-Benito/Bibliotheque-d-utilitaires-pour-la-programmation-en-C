/**
 * Demonstration de `rechercher_element_par_index()`
 * 
 * Ce fichier illustre l'utilisation de la fonction rechercher_element_par_index()
 * qui permet de rechercher un element dans une structure de donnees en utilisant son index.
 * 
 * La fonction rechercher_element_par_index() possede la signature suivante :
 * void *rechercher_element_par_index(Liste *liste, int index);
 * 
 * Parametres :
 *   - liste : un pointeur vers la Liste dans laquelle rechercher l'element
 *   - index : l'index de l'element a rechercher (zero-based, le premier element a l'index 0)
 * 
 * Comportement :
 *   - Si la liste est NULL, la fonction retourne NULL
 *   - Si l'index est negatif, la fonction retourne NULL
 *   - Si l'index est superieur ou egal a la taille de la liste, la fonction retourne NULL
 *   - Sinon, la fonction retourne un pointeur vers l'element a l'index specifie
 * 
 * Ce fichier contient plusieurs cas de test :
 *   1. Recherche dans une liste normale avec plusieurs elements
 *   2. Recherche du premier element (index 0)
 *   3. Recherche du dernier element
 *   4. Recherche avec un index negatif (cas limite)
 *   5. Recherche avec un index hors limites (cas limite)
 *   6. Recherche dans une liste vide (cas limite)
 *   7. Recherche avec une liste NULL (cas limite)
 */

#include <stdio.h>
#include <stdlib.h>
#include "liste.h"

int main(void)
{
    printf("=====================================================\n");
    printf("   Demonstration de rechercher_element_par_index()\n");
    printf("=====================================================\n\n");

    /* ============================================================
     * CREATION D'UNE LISTE DE DEMONSTRATION
     * ============================================================ */
    printf("--- Creation d'une liste avec plusieurs elements ---\n\n");

    Liste *liste = creer_liste();
    if (liste == NULL)
    {
        fprintf_s(stderr, "Erreur : impossible de creer la liste\n");
        return 1;
    }

    /* Ajout de quelques elements (nombres decimaux) pour les tests */
    /* On stocke les valeurs dans des variables locales et on ajoute leurs adresses */
    int val1 = 10;
    int val2 = 20;
    int val3 = 30;
    int val4 = 40;
    int val5 = 50;

    ajouter_element(liste, &val1);
    ajouter_element(liste, &val2);
    ajouter_element(liste, &val3);
    ajouter_element(liste, &val4);
    ajouter_element(liste, &val5);

    printf("Liste creee avec %d elements\n", liste->taille);
    printf("Contenu de la liste :\n");
    for (int i = 0; i < liste->taille; i++)
    {
        void *elem = rechercher_element_par_index(liste, i);
        if (elem != NULL)
        {
            printf("  [%d] : %d\n", i, *(int *)elem);
        }
    }
    printf("\n");

    /* ============================================================
     * CAS DE TEST 1 : Recherche normale au milieu de la liste
     * ============================================================ */
    printf("--- CAS 1: Recherche normale (index au milieu) ---\n");
    printf("Recherche de l'element a l'index 2...\n");

    void *resultat = rechercher_element_par_index(liste, 2);

    if (resultat != NULL)
    {
        printf("  Resultat trouve : %d\n", *(int *)resultat);
        printf("  Resultat attendu : 30\n");
    }
    else
    {
        printf("  ERREUR: Aucun element trouve (attendu: 30)\n");
    }
    printf("\n");

    /* ============================================================
     * CAS DE TEST 2 : Recherche du premier element (index 0)
     * ============================================================ */
    printf("--- CAS 2: Recherche du premier element (index 0) ---\n");
    printf("Recherche de l'element a l'index 0...\n");
    
    resultat = rechercher_element_par_index(liste, 0);
    
    if (resultat != NULL)
    {
        printf("  Resultat trouve : %d\n", *(int *)resultat);
        printf("  Resultat attendu : 10\n");
    }
    else
    {
        printf("  ERREUR: Aucun element trouve (attendu: 10)\n");
    }
    printf("\n");

    /* ============================================================
     * CAS DE TEST 3 : Recherche du dernier element
     * ============================================================ */
    printf("--- CAS 3: Recherche du dernier element ---\n");
    printf("Recherche de l'element a l'index %d (dernier)...\n", liste->taille - 1);
    
    resultat = rechercher_element_par_index(liste, liste->taille - 1);
    
    if (resultat != NULL)
    {
        printf("  Resultat trouve : %d\n", *(int *)resultat);
        printf("  Resultat attendu : 50\n");
    }
    else
    {
        printf("  ERREUR: Aucun element trouve (attendu: 50)\n");
    }
    printf("\n");

    /* ============================================================
     * CAS DE TEST 4 : Index negatif (cas limite)
     * ============================================================ */
    printf("--- CAS 4: Index negatif (cas limite) ---\n");
    printf("Recherche de l'element a l'index -1...\n");
    
    resultat = rechercher_element_par_index(liste, -1);
    
    if (resultat == NULL)
    {
        printf("  Resultat : NULL (comportement attendu)\n");
        printf("  La fonction retourne NULL pour un index negatif\n");
    }
    else
    {
        printf("  ERREUR: Resultat inattendu : %d\n", *(int *)resultat);
    }
    printf("\n");

    /* ============================================================
     * CAS DE TEST 5 : Index hors limites (cas limite)
     * ============================================================ */
    printf("--- CAS 5: Index hors limites (cas limite) ---\n");
    printf("Recherche de l'element a l'index %d (taille de la liste)...\n", liste->taille);
    
    resultat = rechercher_element_par_index(liste, liste->taille);
    
    if (resultat == NULL)
    {
        printf("  Resultat : NULL (comportement attendu)\n");
        printf("  La fonction retourne NULL pour un index >= taille\n");
    }
    else
    {
        printf("  ERREUR: Resultat inattendu : %d\n", *(int *)resultat);
    }
    printf("\n");

    /* ============================================================
     * CAS DE TEST 6 : Index trop grand (cas limite)
     * ============================================================ */
    printf("--- CAS 6: Index tres grand (cas limite) ---\n");
    printf("Recherche de l'element a l'index 100...\n");
    
    resultat = rechercher_element_par_index(liste, 100);
    
    if (resultat == NULL)
    {
        printf("  Resultat : NULL (comportement attendu)\n");
        printf("  La fonction retourne NULL pour un index trop grand\n");
    }
    else
    {
        printf("  ERREUR: Resultat inattendu : %d\n", *(int *)resultat);
    }
    printf("\n");

    /* ============================================================
     * CAS DE TEST 7 : Liste vide (cas limite)
     * ============================================================ */
    printf("--- CAS 7: Liste vide (cas limite) ---\n");
    
    Liste *liste_vide = creer_liste();
    printf("Creation d'une liste vide...\n");
    printf("Recherche de l'element a l'index 0 dans une liste vide...\n");
    
    resultat = rechercher_element_par_index(liste_vide, 0);
    
    if (resultat == NULL)
    {
        printf("  Resultat : NULL (comportement attendu)\n");
        printf("  La fonction retourne NULL pour une liste vide\n");
    }
    else
    {
        printf("  ERREUR: Resultat inattendu : %d\n", *(int *)resultat);
    }
    
    /* Liberation de la liste vide */
    free(liste_vide);
    printf("\n");

    /* ============================================================
     * CAS DE TEST 8 : Liste NULL (cas limite)
     * ============================================================ */
    printf("--- CAS 8: Liste NULL (cas limite) ---\n");
    printf("Recherche de l'element a l'index 0 avec une liste NULL...\n");
    
    resultat = rechercher_element_par_index(NULL, 0);
    
    if (resultat == NULL)
    {
        printf("  Resultat : NULL (comportement attendu)\n");
        printf("  La fonction retourne NULL pour une liste NULL\n");
    }
    else
    {
        printf("  ERREUR: Resultat inattendu : %d\n", *(int *)resultat);
    }
    printf("\n");

    /* ============================================================
     * CAS DE TEST 9 : Recherche avec tous les index valides
     * ============================================================ */
    printf("--- CAS 9: Parcours complet de la liste ---\n");
    printf("Recuperation de tous les elements par leur index :\n");
    
    for (int i = 0; i < liste->taille; i++)
    {
        void *elem = rechercher_element_par_index(liste, i);
        if (elem != NULL)
        {
            printf("  Index %d -> %d\n", i, *(int *)elem);
        }
    }
    printf("\n");

    /* ============================================================
     * LIBERATION DE LA MEMOIRE
     * ============================================================ */
    printf("--- Nettoyage de la memoire ---\n");
    
    vider_liste(liste);
    free(liste);
    
    printf("\n=====================================================\n");
    printf("           Fin de la demonstration\n");
    printf("=====================================================\n");

    return 0;
}
