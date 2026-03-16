/**
 * @file couleurs_ansi.h
 * @author do SANTOS ZOUNON Bénito K. (dosantosbenito81@gmail.com)
 * @brief Ce fichier définit une palette complète de codes d'échappement ANSI
 * pour les couleurs de texte, les styles (gras, italique, souligné, clignotant)
 * et les arrière-plans. Il permet aux développeurs d'ajouter facilement des effets
 * de couleur et de style à leurs sorties console en C.
 * 
 * ? Astuce : Appliquez d'abord les styles (gras, italique, etc.) avant d'appliquer
 * ? la couleur pour garantir que les effets sont correctement rendus.

 * @date 2026-03-16
 * 
 * @copyright Copyright (c) 2026
 * 
 */
#ifndef COULEURS_ANSI_H
#define COULEURS_ANSI_H

/* Réinitialisation */
#define ANSI_NORMAL              "\033[0m"

/* --- Styles Seuls (sans couleur imposée) --- */
#define ANSI_GRAS               "\033[1m"
#define ANSI_ITALIQUE           "\033[3m"
#define ANSI_SOULIGNE           "\033[4m"
#define ANSI_CLIGNOTANT         "\033[5m"
#define ANSI_INVERSE            "\033[7m"

/* --- NOIR --- */
#define ANSI_NOIR               "\033[0;30m"
#define ANSI_NOIR_GRAS          "\033[1;30m"
#define ANSI_NOIR_ITALIQUE      "\033[3;30m"
#define ANSI_NOIR_SOULIGNE      "\033[4;30m"
#define ANSI_NOIR_CLIGNOTANT    "\033[5;30m"

/* --- ROUGE --- */
#define ANSI_ROUGE              "\033[0;31m"
#define ANSI_ROUGE_GRAS         "\033[1;31m"
#define ANSI_ROUGE_ITALIQUE     "\033[3;31m"
#define ANSI_ROUGE_SOULIGNE     "\033[4;31m"
#define ANSI_ROUGE_CLIGNOTANT   "\033[5;31m"

/* --- VERT --- */
#define ANSI_VERT               "\033[0;32m"
#define ANSI_VERT_GRAS          "\033[1;32m"
#define ANSI_VERT_ITALIQUE      "\033[3;32m"
#define ANSI_VERT_SOULIGNE      "\033[4;32m"
#define ANSI_VERT_CLIGNOTANT    "\033[5;32m"

/* --- JAUNE --- */
#define ANSI_JAUNE              "\033[0;33m"
#define ANSI_JAUNE_GRAS         "\033[1;33m"
#define ANSI_JAUNE_ITALIQUE     "\033[3;33m"
#define ANSI_JAUNE_SOULIGNE     "\033[4;33m"
#define ANSI_JAUNE_CLIGNOTANT   "\033[5;33m"

/* --- BLEU --- */
#define ANSI_BLEU               "\033[0;34m"
#define ANSI_BLEU_GRAS          "\033[1;34m"
#define ANSI_BLEU_ITALIQUE      "\033[3;34m"
#define ANSI_BLEU_SOULIGNE      "\033[4;34m"
#define ANSI_BLEU_CLIGNOTANT    "\033[5;34m"

/* --- VIOLET (MAGENTA) --- */
#define ANSI_VIOLET             "\033[0;35m"
#define ANSI_VIOLET_GRAS        "\033[1;35m"
#define ANSI_VIOLET_ITALIQUE    "\033[3;35m"
#define ANSI_VIOLET_SOULIGNE    "\033[4;35m"
#define ANSI_VIOLET_CLIGNOTANT  "\033[5;35m"

/* --- CYAN --- */
#define ANSI_CYAN               "\033[0;36m"
#define ANSI_CYAN_GRAS          "\033[1;36m"
#define ANSI_CYAN_ITALIQUE      "\033[3;36m"
#define ANSI_CYAN_SOULIGNE      "\033[4;36m"
#define ANSI_CYAN_CLIGNOTANT    "\033[5;36m"

/* --- BLANC --- */
#define ANSI_BLANC              "\033[0;37m"
#define ANSI_BLANC_GRAS         "\033[1;37m"
#define ANSI_BLANC_ITALIQUE     "\033[3;37m"
#define ANSI_BLANC_SOULIGNE     "\033[4;37m"
#define ANSI_BLANC_CLIGNOTANT   "\033[5;37m"

/* --- ARRIÈRE-PLANS (BACKGROUNDS) --- */
#define ANSI_BG_NOIR            "\033[40m"
#define ANSI_BG_ROUGE           "\033[41m"
#define ANSI_BG_VERT            "\033[42m"
#define ANSI_BG_JAUNE           "\033[43m"
#define ANSI_BG_BLEU            "\033[44m"
#define ANSI_BG_VIOLET          "\033[45m"
#define ANSI_BG_CYAN            "\033[46m"
#define ANSI_BG_BLANC           "\033[47m"

#endif