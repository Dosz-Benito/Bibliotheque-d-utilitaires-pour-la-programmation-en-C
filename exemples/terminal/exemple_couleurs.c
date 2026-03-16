/**
 * @file test_complet_couleurs.c
 * @brief Test exhaustif de la palette ANSI.
 * * Ce fichier affiche systématiquement chaque couleur avec ses variantes
 * de style, suivies des arrière-plans et de combinaisons complexes.
 */

#include <stdio.h>
#include <stdlib.h>
#include "couleurs_ansi.h"

int main(void) {
    // --- SECTION 1 : COULEURS ET VARIANTES DE STYLE ---
    printf("--- 1. COULEURS DE TEXTE ET VARIANTES ---\n");
    printf("Format : <Normal> | <Gras> | <Italique> | <Souligne> | <Clignotant>\n\n");

    // NOIR (Souvent gris en mode Gras)
    printf("NOIR    : " ANSI_NOIR "Texte" ANSI_NORMAL " | " ANSI_NOIR_GRAS "Texte" ANSI_NORMAL " | " ANSI_NOIR_ITALIQUE "Texte" ANSI_NORMAL " | " ANSI_NOIR_SOULIGNE "Texte" ANSI_NORMAL " | " ANSI_NOIR_CLIGNOTANT "Texte" ANSI_NORMAL "\n");

    // ROUGE
    printf("ROUGE   : " ANSI_ROUGE "Texte" ANSI_NORMAL " | " ANSI_ROUGE_GRAS "Texte" ANSI_NORMAL " | " ANSI_ROUGE_ITALIQUE "Texte" ANSI_NORMAL " | " ANSI_ROUGE_SOULIGNE "Texte" ANSI_NORMAL " | " ANSI_ROUGE_CLIGNOTANT "Texte" ANSI_NORMAL "\n");

    // VERT
    printf("VERT    : " ANSI_VERT "Texte" ANSI_NORMAL " | " ANSI_VERT_GRAS "Texte" ANSI_NORMAL " | " ANSI_VERT_ITALIQUE "Texte" ANSI_NORMAL " | " ANSI_VERT_SOULIGNE "Texte" ANSI_NORMAL " | " ANSI_VERT_CLIGNOTANT "Texte" ANSI_NORMAL "\n");

    // JAUNE
    printf("JAUNE   : " ANSI_JAUNE "Texte" ANSI_NORMAL " | " ANSI_JAUNE_GRAS "Texte" ANSI_NORMAL " | " ANSI_JAUNE_ITALIQUE "Texte" ANSI_NORMAL " | " ANSI_JAUNE_SOULIGNE "Texte" ANSI_NORMAL " | " ANSI_JAUNE_CLIGNOTANT "Texte" ANSI_NORMAL "\n");

    // BLEU
    printf("BLEU    : " ANSI_BLEU "Texte" ANSI_NORMAL " | " ANSI_BLEU_GRAS "Texte" ANSI_NORMAL " | " ANSI_BLEU_ITALIQUE "Texte" ANSI_NORMAL " | " ANSI_BLEU_SOULIGNE "Texte" ANSI_NORMAL " | " ANSI_BLEU_CLIGNOTANT "Texte" ANSI_NORMAL "\n");

    // VIOLET
    printf("VIOLET  : " ANSI_VIOLET "Texte" ANSI_NORMAL " | " ANSI_VIOLET_GRAS "Texte" ANSI_NORMAL " | " ANSI_VIOLET_ITALIQUE "Texte" ANSI_NORMAL " | " ANSI_VIOLET_SOULIGNE "Texte" ANSI_NORMAL " | " ANSI_VIOLET_CLIGNOTANT "Texte" ANSI_NORMAL "\n");

    // CYAN
    printf("CYAN    : " ANSI_CYAN "Texte" ANSI_NORMAL " | " ANSI_CYAN_GRAS "Texte" ANSI_NORMAL " | " ANSI_CYAN_ITALIQUE "Texte" ANSI_NORMAL " | " ANSI_CYAN_SOULIGNE "Texte" ANSI_NORMAL " | " ANSI_CYAN_CLIGNOTANT "Texte" ANSI_NORMAL "\n");

    // BLANC
    printf("BLANC   : " ANSI_BLANC "Texte" ANSI_NORMAL " | " ANSI_BLANC_GRAS "Texte" ANSI_NORMAL " | " ANSI_BLANC_ITALIQUE "Texte" ANSI_NORMAL " | " ANSI_BLANC_SOULIGNE "Texte" ANSI_NORMAL " | " ANSI_BLANC_CLIGNOTANT "Texte" ANSI_NORMAL "\n");

    printf("\n");

    // --- SECTION 2 : ARRIÈRE-PLANS ---
    printf("--- 2. ARRIERE-PLANS (BACKGROUNDS) ---\n\n");
    printf(ANSI_BG_NOIR "  BG NOIR  " ANSI_NORMAL " ");
    printf(ANSI_BG_ROUGE "  BG ROUGE  " ANSI_NORMAL " ");
    printf(ANSI_BG_VERT "  BG VERT  " ANSI_NORMAL " ");
    printf(ANSI_BG_JAUNE "  BG JAUNE  " ANSI_NORMAL " ");
    printf(ANSI_BG_BLEU "  BG BLEU  " ANSI_NORMAL " ");
    printf(ANSI_BG_VIOLET "  BG VIOLET  " ANSI_NORMAL " ");
    printf(ANSI_BG_CYAN "  BG CYAN  " ANSI_NORMAL " ");
    printf(ANSI_BG_BLANC "  BG BLANC  " ANSI_NORMAL "\n\n");


    // --- SECTION 3 : COMBINAISONS COMPLEXES ---
    printf("--- 3. COMBINAISONS COMPLEXES ---\n\n");

    printf(ANSI_BG_ROUGE ANSI_JAUNE_GRAS " ATTENTION : Erreur Critique detectee ! " ANSI_NORMAL "\n\n");

    printf(ANSI_BG_VERT ANSI_NOIR " INFO " ANSI_NORMAL " " ANSI_VERT_ITALIQUE "L'element a ete ajoute avec succes." ANSI_NORMAL "\n\n");

    printf(ANSI_CYAN_SOULIGNE "Lien :" ANSI_NORMAL " " ANSI_BLEU_ITALIQUE "https://github.com/votre-depot" ANSI_NORMAL "\n\n");

    printf(ANSI_BG_VIOLET ANSI_BLANC_GRAS ANSI_CLIGNOTANT " FLASH INFO " ANSI_NORMAL 
           " <- Si ca clignote, votre terminal est " ANSI_CYAN ANSI_GRAS ANSI_ITALIQUE "100%% compatible" ANSI_NORMAL ".\n\n");

    printf("Tableau de debug :\n");
    printf(ANSI_BG_NOIR ANSI_BLANC_GRAS "| ID | NOM       | STATUT    |" ANSI_NORMAL "\n");
    printf("| 01 | " ANSI_JAUNE "Data_01" ANSI_NORMAL "   | " ANSI_VERT "OK        " ANSI_NORMAL "|\n");
    printf("| 02 | " ANSI_JAUNE "Data_02" ANSI_NORMAL "   | " ANSI_ROUGE_GRAS "ECHEC     " ANSI_NORMAL "|\n");
    return 0;
}