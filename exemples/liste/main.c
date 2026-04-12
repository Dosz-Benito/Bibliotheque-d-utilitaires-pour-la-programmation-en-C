#include <stdio.h>
#include <stdlib.h>
#include "exemple.h"

int main(int argc, char const *argv[])
{
    printf("Bienvenue !\n");
    printf("Ceci est une démonstration du fonctionnement de la liste chaînée en C : un gestionnaire de tâches.\n");
    GestionnaireTaches *gestionnaire = creer_gestionnaire();
    printf("Voici les commandes disponibles :\n");
    printf("1. Ajouter une tâche\n");
    printf("2. Afficher les tâches\n");
    printf("3. Supprimer une tâche\n");
    printf("4. Quitter\n");
    printf("Veuillez choisir une option : ");
    int option = fgetc(stdin) - '0'; // Convertir le caractère en entier
    switch (option)
    {
    case 1:
        printf("Choix: Ajouter une tâche\n");
        printf("Entrez le nom de la tâche : ");
        char * nom_tache = malloc(100 * sizeof(char));
        fgets(nom_tache, 100, stdin);
        // ajouter_tache(gestionnaire, creer_tache(nombre_taches(gestionnaire), nom_tache, statut_tache));
        break;

    default:
        printf("Option %d invalide.\n", option);
        break;
    }
    return 0;
}
