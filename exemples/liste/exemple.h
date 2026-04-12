#ifndef EXEMPLE_H
#define EXEMPLE_H
#pragma region "Structures"
typedef struct GestionnaireTaches GestionnaireTaches;
typedef struct Tache Tache;
typedef enum StatutTache StatutTache;
#pragma endregion

#pragma region "Fonctions du gestionnaire de tâches"
GestionnaireTaches *creer_gestionnaire();
void ajouter_tache(GestionnaireTaches *gestionnaire, Tache *tache);
int nombre_taches(GestionnaireTaches *gestionnaire);
#pragma endregion

#pragma region "Fonctions de la tâche"
Tache *creer_tache(const int id, const char *nom, StatutTache statut);
#pragma endregion

#endif // EXEMPLE_H