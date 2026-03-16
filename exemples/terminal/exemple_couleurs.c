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

    // Affiche "NOIR" suivi de 5 variantes : texte noir normal, gras (souvent gris clair), italique, souligné et clignotant
    printf("NOIR    : " ANSI_NOIR "Texte" ANSI_NORMAL " | " ANSI_NOIR ANSI_GRAS "Texte" ANSI_NORMAL " | " ANSI_NOIR ANSI_ITALIQUE "Texte" ANSI_NORMAL " | " ANSI_NOIR ANSI_SOULIGNE "Texte" ANSI_NORMAL " | " ANSI_NOIR ANSI_CLIGNOTANT "Texte" ANSI_NORMAL "\n");

    // Affiche "ROUGE" suivi de 5 variantes : texte rouge normal, gras, italique, souligné et clignotant
    printf("ROUGE   : " ANSI_ROUGE "Texte" ANSI_NORMAL " | " ANSI_ROUGE ANSI_GRAS "Texte" ANSI_NORMAL " | " ANSI_ROUGE ANSI_ITALIQUE "Texte" ANSI_NORMAL " | " ANSI_ROUGE ANSI_SOULIGNE "Texte" ANSI_NORMAL " | " ANSI_ROUGE ANSI_CLIGNOTANT "Texte" ANSI_NORMAL "\n");

    // Affiche "VERT" suivi de 5 variantes : texte vert normal, gras, italique, souligné et clignotant
    printf("VERT    : " ANSI_VERT "Texte" ANSI_NORMAL " | " ANSI_VERT ANSI_GRAS "Texte" ANSI_NORMAL " | " ANSI_VERT ANSI_ITALIQUE "Texte" ANSI_NORMAL " | " ANSI_VERT ANSI_SOULIGNE "Texte" ANSI_NORMAL " | " ANSI_VERT ANSI_CLIGNOTANT "Texte" ANSI_NORMAL "\n");

    // Affiche "JAUNE" suivi de 5 variantes : texte jaune normal, gras, italique, souligné et clignotant
    printf("JAUNE   : " ANSI_JAUNE "Texte" ANSI_NORMAL " | " ANSI_JAUNE ANSI_GRAS "Texte" ANSI_NORMAL " | " ANSI_JAUNE ANSI_ITALIQUE "Texte" ANSI_NORMAL " | " ANSI_JAUNE ANSI_SOULIGNE "Texte" ANSI_NORMAL " | " ANSI_JAUNE ANSI_CLIGNOTANT "Texte" ANSI_NORMAL "\n");

    // Affiche "BLEU" suivi de 5 variantes : texte bleu normal, gras, italique, souligné et clignotant
    printf("BLEU    : " ANSI_BLEU "Texte" ANSI_NORMAL " | " ANSI_BLEU ANSI_GRAS "Texte" ANSI_NORMAL " | "ANSI_BLEU ANSI_ITALIQUE "Texte"ANSI_NORMAL " | "ANSI_BLEU ANSI_SOULIGNE "Texte"ANSI_NORMAL " | "ANSI_BLEU ANSI_CLIGNOTANT "Texte"ANSI_NORMAL "\n");

    // Affiche "VIOLET" suivi de 5 variantes : texte violet normal, gras, italique, souligné et clignotant
    printf("VIOLET  : " ANSI_VIOLET "Texte" ANSI_NORMAL " | " ANSI_VIOLET ANSI_GRAS "Texte" ANSI_NORMAL " | " ANSI_VIOLET ANSI_ITALIQUE "Texte" ANSI_NORMAL " | " ANSI_VIOLET ANSI_SOULIGNE "Texte" ANSI_NORMAL " | " ANSI_VIOLET ANSI_CLIGNOTANT "Texte" ANSI_NORMAL "\n");

    // Affiche "CYAN" suivi de 5 variantes : texte cyan normal, gras, italique, souligné et clignotant
    printf("CYAN    : " ANSI_CYAN "Texte" ANSI_NORMAL " | " ANSI_CYAN ANSI_GRAS "Texte" ANSI_NORMAL " | " ANSI_CYAN ANSI_ITALIQUE "Texte" ANSI_NORMAL " | " ANSI_CYAN ANSI_SOULIGNE "Texte" ANSI_NORMAL " | " ANSI_CYAN ANSI_CLIGNOTANT "Texte" ANSI_NORMAL "\n");

    // Affiche "BLANC" suivi de 5 variantes : texte blanc normal, gras, italique, souligné et clignotant
    printf("BLANC   : " ANSI_BLANC "Texte" ANSI_NORMAL " | " ANSI_BLANC ANSI_GRAS "Texte" ANSI_NORMAL " | " ANSI_BLANC ANSI_ITALIQUE "Texte" ANSI_NORMAL " | " ANSI_BLANC ANSI_SOULIGNE "Texte" ANSI_NORMAL " | " ANSI_BLANC ANSI_CLIGNOTANT "Texte" ANSI_NORMAL "\n");

    printf("\n");

    // Affiche les 8 couleurs d'arrière-plan ANSI : noir, rouge, vert, jaune, bleu, violet, cyan et blanc
    printf("--- 2. ARRIERE-PLANS (BACKGROUNDS) ---\n\n");
    printf(ANSI_FOND_NOIR "  FOND NOIR  " ANSI_NORMAL " ");
    printf(ANSI_FOND_ROUGE "  FOND ROUGE  " ANSI_NORMAL " ");
    printf(ANSI_FOND_VERT "  FOND VERT  " ANSI_NORMAL " ");
    printf(ANSI_FOND_JAUNE "  FOND JAUNE  " ANSI_NORMAL " ");
    printf(ANSI_FOND_BLEU "  FOND BLEU  " ANSI_NORMAL " ");
    printf(ANSI_FOND_VIOLET "  FOND VIOLET  " ANSI_NORMAL " ");
    printf(ANSI_FOND_CYAN "  FOND CYAN  " ANSI_NORMAL " ");
    printf(ANSI_FOND_BLANC "  FOND BLANC  " ANSI_NORMAL "\n\n");

    // Affiche un poème humoristique sur les segfaults avec des combinaisons complexes de couleurs et styles
    printf("\n--- 3. DÉMONSTRATION SANS LIMITES : L'ODYSSÉE DU DÉBOGAGE ---\n\n");

    // Affiche "Ô mon pointeur errant, vers quel" en gras italique violet sur fond blanc, puis "abîme" en rouge gras, puis "pointes-tu ?" en gras
    printf(ANSI_FOND_VIOLET ANSI_BLANC ANSI_GRAS ANSI_ITALIQUE " Ô mon pointeur errant, vers quel" ANSI_ROUGE ANSI_GRAS " abîme" ANSI_NORMAL ANSI_GRAS " pointes-tu ?" ANSI_NORMAL "\n");

    // Affiche "Tu cherches l'adresse" sur fond bleu, puis "0x0" en jaune souligné, puis "tel un" en rouge
    printf(ANSI_FOND_BLEU " Tu cherches l'adresse" ANSI_NORMAL " " ANSI_JAUNE ANSI_SOULIGNE "0x0" ANSI_NORMAL ", tel un " ANSI_ROUGE "fou corrompu." ANSI_NORMAL "\n\n");

    // Affiche "LE SEGFAULT HURLE," en rouge gras italique souligné
    printf(ANSI_ROUGE ANSI_GRAS ANSI_ITALIQUE ANSI_SOULIGNE "LE SEGFAULT HURLE," ANSI_NORMAL " ");

    // Inverse les couleurs (texte noir sur fond blanc) pour "le noyau s'épouvante,"
    printf(ANSI_INVERSE " le noyau s'épouvante, " ANSI_NORMAL "\n");

    // Affiche "!! DANGER !" en blanc clignotant sur fond rouge avec Gras (alerte maximale)
    printf(ANSI_BLANC ANSI_FOND_ROUGE ANSI_GRAS ANSI_CLIGNOTANT " !! DANGER !! " ANSI_NORMAL " ");

    printf(ANSI_ROUGE ANSI_ITALIQUE "La mémoire fuit comme une passoire béante." ANSI_NORMAL "\n");

    // Affiche "J'ai mis un 'malloc'" en vert gras sur fond jaune, puis "mais j'ai oublié le" en rouge, puis "'free'" en rouge gras inversé
    printf(ANSI_FOND_JAUNE ANSI_VERT ANSI_GRAS " J'ai mis un 'malloc'" ANSI_ROUGE ", mais j'ai oublié le " ANSI_NORMAL "'" ANSI_ROUGE ANSI_GRAS ANSI_INVERSE "free" ANSI_NORMAL "'.\n");

    // Affiche "Et mon CPU chauffe... il est en surchauffe, criii !" en noir italique sur fond blanc
    printf(ANSI_FOND_BLANC ANSI_NOIR ANSI_ITALIQUE " Et mon CPU chauffe... il est en surchauffe, criii ! " ANSI_NORMAL "\n");

    // Affiche "ADIEU MONDE CRUEL," en noir gras italique souligné clignotant sur fond cyan, puis "JE REBOOT MON PC..." en violet italique souligné
    printf(ANSI_FOND_CYAN ANSI_NOIR ANSI_GRAS ANSI_ITALIQUE ANSI_SOULIGNE ANSI_CLIGNOTANT " ADIEU MONDE CRUEL, " ANSI_VIOLET ANSI_ITALIQUE ANSI_SOULIGNE "JE REBOOT MON PC... " ANSI_NORMAL "\n");

    printf(ANSI_GRAS ANSI_FOND_CYAN ANSI_INVERSE "--- Fin de " ANSI_GRAS ANSI_ITALIQUE ANSI_FOND_CYAN ANSI_INVERSE "l'agonie du processeur" ANSI_INVERSE " ---" ANSI_NORMAL "\n");
    return 0;
}