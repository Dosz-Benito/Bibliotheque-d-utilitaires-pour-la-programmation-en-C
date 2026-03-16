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
    printf("NOIR    : " ANSI_NOIR "Texte" ANSI_NORMAL " | " ANSI_NOIR ANSI_GRAS "Texte" ANSI_NORMAL " | " ANSI_NOIR ANSI_ITALIQUE "Texte" ANSI_NORMAL " | " ANSI_NOIR ANSI_SOULIGNE "Texte" ANSI_NORMAL " | " ANSI_NOIR ANSI_CLIGNOTANT "Texte" ANSI_NORMAL "\n");

    // ROUGE
    printf("ROUGE   : " ANSI_ROUGE "Texte" ANSI_NORMAL " | " ANSI_ROUGE ANSI_GRAS "Texte" ANSI_NORMAL " | " ANSI_ROUGE ANSI_ITALIQUE "Texte" ANSI_NORMAL " | " ANSI_ROUGE ANSI_SOULIGNE "Texte" ANSI_NORMAL " | " ANSI_ROUGE ANSI_CLIGNOTANT "Texte" ANSI_NORMAL "\n");

    // VERT
    printf("VERT    : " ANSI_VERT "Texte" ANSI_NORMAL " | " ANSI_VERT ANSI_GRAS "Texte" ANSI_NORMAL " | " ANSI_VERT ANSI_ITALIQUE "Texte" ANSI_NORMAL " | " ANSI_VERT ANSI_SOULIGNE "Texte" ANSI_NORMAL " | " ANSI_VERT ANSI_CLIGNOTANT "Texte" ANSI_NORMAL "\n");

    // JAUNE
    printf("JAUNE   : " ANSI_JAUNE "Texte" ANSI_NORMAL " | " ANSI_JAUNE ANSI_GRAS "Texte" ANSI_NORMAL " | " ANSI_JAUNE ANSI_ITALIQUE "Texte" ANSI_NORMAL " | " ANSI_JAUNE ANSI_SOULIGNE "Texte" ANSI_NORMAL " | " ANSI_JAUNE ANSI_CLIGNOTANT "Texte" ANSI_NORMAL "\n");

    // BLEU
    printf("BLEU    : " ANSI_BLEU "Texte" ANSI_NORMAL " | " ANSI_BLEU ANSI_GRAS "Texte" ANSI_NORMAL " | "ANSI_BLEU ANSI_ITALIQUE "Texte"ANSI_NORMAL " | "ANSI_BLEU ANSI_SOULIGNE "Texte"ANSI_NORMAL " | "ANSI_BLEU ANSI_CLIGNOTANT "Texte"ANSI_NORMAL "\n");

    // VIOLET
    printf("VIOLET  : " ANSI_VIOLET "Texte" ANSI_NORMAL " | " ANSI_VIOLET ANSI_GRAS "Texte" ANSI_NORMAL " | " ANSI_VIOLET ANSI_ITALIQUE "Texte" ANSI_NORMAL " | " ANSI_VIOLET ANSI_SOULIGNE "Texte" ANSI_NORMAL " | " ANSI_VIOLET ANSI_CLIGNOTANT "Texte" ANSI_NORMAL "\n");

    // CYAN
    printf("CYAN    : " ANSI_CYAN "Texte" ANSI_NORMAL " | " ANSI_CYAN ANSI_GRAS "Texte" ANSI_NORMAL " | " ANSI_CYAN ANSI_ITALIQUE "Texte" ANSI_NORMAL " | " ANSI_CYAN ANSI_SOULIGNE "Texte" ANSI_NORMAL " | " ANSI_CYAN ANSI_CLIGNOTANT "Texte" ANSI_NORMAL "\n");

    // BLANC
    printf("BLANC   : " ANSI_BLANC "Texte" ANSI_NORMAL " | " ANSI_BLANC ANSI_GRAS "Texte" ANSI_NORMAL " | " ANSI_BLANC ANSI_ITALIQUE "Texte" ANSI_NORMAL " | " ANSI_BLANC ANSI_SOULIGNE "Texte" ANSI_NORMAL " | " ANSI_BLANC ANSI_CLIGNOTANT "Texte" ANSI_NORMAL "\n");

    printf("\n");

    // --- SECTION 2 : ARRIÈRE-PLANS ---
    printf("--- 2. ARRIERE-PLANS (BACKGROUNDS) ---\n\n");
    printf(ANSI_FOND_NOIR "  FOND NOIR  " ANSI_NORMAL " ");
    printf(ANSI_FOND_ROUGE "  FOND ROUGE  " ANSI_NORMAL " ");
    printf(ANSI_FOND_VERT "  FOND VERT  " ANSI_NORMAL " ");
    printf(ANSI_FOND_JAUNE "  FOND JAUNE  " ANSI_NORMAL " ");
    printf(ANSI_FOND_BLEU "  FOND BLEU  " ANSI_NORMAL " ");
    printf(ANSI_FOND_VIOLET "  FOND VIOLET  " ANSI_NORMAL " ");
    printf(ANSI_FOND_CYAN "  FOND CYAN  " ANSI_NORMAL " ");
    printf(ANSI_FOND_BLANC "  FOND BLANC  " ANSI_NORMAL "\n\n");


    // --- SECTION 3 : COMBINAISONS COMPLEXES ---
    printf("--- 3. COMBINAISONS COMPLEXES ---\n\n");

    printf(ANSI_FOND_ROUGE ANSI_JAUNE ANSI_GRAS " ATTENTION : Erreur Critique detectee ! " ANSI_NORMAL "\n\n");

    printf(ANSI_FOND_VERT ANSI_NOIR " INFO " ANSI_NORMAL " " ANSI_VERT ANSI_ITALIQUE "L'element a ete ajoute avec succes." ANSI_NORMAL "\n\n");

    printf(ANSI_CYAN ANSI_SOULIGNE "Lien :" ANSI_NORMAL " " ANSI_BLEU ANSI_ITALIQUE "https://github.com/votre-depot" ANSI_NORMAL "\n\n");

    printf(ANSI_BLANC ANSI_FOND_VIOLET ANSI_GRAS ANSI_CLIGNOTANT " FLASH INFO " ANSI_NORMAL 
           " <- Si ca clignote, votre terminal est " ANSI_CYAN ANSI_GRAS ANSI_ITALIQUE ANSI_INVERSE "100%% compatible" ANSI_NORMAL ".\n\n");

    printf("Tableau de debug :\n");
    printf(ANSI_FOND_NOIR ANSI_BLANC ANSI_GRAS "| ID | NOM       | STATUT    |" ANSI_NORMAL "\n");
    printf("| 01 | " ANSI_JAUNE "Info_01" ANSI_NORMAL "   | " ANSI_VERT "OK        " ANSI_NORMAL "|\n");
    printf("| 02 | " ANSI_JAUNE "Info_02" ANSI_NORMAL "   | " ANSI_ROUGE ANSI_GRAS "ECHEC     " ANSI_NORMAL "|\n");
    return 0;
}