/**
 * @file couleurs_ansi.h
 * @author do SANTOS ZOUNON Bénito K. (dosantosbenito81@gmail.com)
 * @brief Ce fichier définit une palette complète de codes d'échappement ANSI
 * pour les couleurs de texte, les styles (gras, italique, souligné, clignotant)
 * et les arrière-plans. Il permet aux développeurs d'ajouter facilement des effets
 * de couleur et de style à leurs sorties console en C.
 *
 * ? Astuce : Appliquez dans l'ordre les couleurs de fond, les couleurs de texte puis les styles (gras, italique, etc.)
 * ? pour garantir que tous les effets sont correctement rendus.

 * @date 2026-03-16
 *
 * @copyright Copyright (c) 2026
 *
 */
#ifndef COULEURS_ANSI_H
#define COULEURS_ANSI_H

/* Réinitialisation */
#define ANSI_NORMAL             "\033[0m"

/* --- Styles Seuls (sans couleur imposée) --- */
#define ANSI_GRAS               "\033[1m"
#define ANSI_ITALIQUE           "\033[3m"
#define ANSI_SOULIGNE           "\033[4m"
#define ANSI_CLIGNOTANT         "\033[5m"
#define ANSI_INVERSE            "\033[7m"

/* Couleurs de texte */
#define ANSI_NOIR               "\033[0;30m"
#define ANSI_ROUGE              "\033[0;31m"
#define ANSI_VERT               "\033[0;32m"
#define ANSI_JAUNE              "\033[0;33m"
#define ANSI_BLEU               "\033[0;34m"
#define ANSI_VIOLET             "\033[0;35m"
#define ANSI_CYAN               "\033[0;36m"
#define ANSI_BLANC              "\033[0;37m"

/* Couleurs d'arrière-plan */
#define ANSI_FOND_NOIR          "\033[40m"
#define ANSI_FOND_ROUGE         "\033[41m"
#define ANSI_FOND_VERT          "\033[42m"
#define ANSI_FOND_JAUNE         "\033[43m"
#define ANSI_FOND_BLEU          "\033[44m"
#define ANSI_FOND_VIOLET        "\033[45m"
#define ANSI_FOND_CYAN          "\033[46m"
#define ANSI_FOND_BLANC         "\033[47m"

#endif