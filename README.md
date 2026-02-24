# Bibliothèque d'utilitaires pour la programmation en C
Cette bibliothèque regroupe des fonctions, structures et types utilitaires destinés à la programmation courante en langage C. Elle sert de socle bas niveau pour l'apprentissage et le prototypage, avec une attention particulière portée à la gestion mémoire et à la clarté du code.
Le code et la documentation sont en français.

---
**Objectifs**
- **Réutilisables** : fournir des utilitaires pour chaînes, tableaux, listes, conversions, etc.
- **Pédagogiques** : offrir des exemples concrets pour l'apprentissage du C bas niveau.
- **Fiabilité mémoire** : encourager une gestion explicite et saine de la mémoire.
Ce projet n'a pas pour objectif de remplacer la libc, mais d'aider à structurer des projets C et apprendre de bonnes pratiques.

---
**Architecture du projet**

 - **include/** : en-têtes publics (`*.h`) des utilitaires
 - **src/** : implémentations sources (`*.c`)
 - **exemples/** : programmes d'exemple montrant l'utilisation des utilitaires
 - **tests/** : petits programmes de test
Les en-têtes sont conçus pour être autonomes et la responsabilité de libération des ressources est documentée dans chaque fonction.

---
**Modifications récentes**

 - Ajout dans l'exemple `exemples/liste/main.c` d'une démonstration de suppression par index via la fonction `supprimer_element_par_index()` : l'exemple supprime maintenant explicitement l'élément à l'index 0 et affiche le code de retour et la taille de la liste après suppression.
 - Aucune nouvelle dépendance externe ajoutée.
Si d'autres modifications de code ont été apportées depuis la dernière version, elles doivent être ajoutées ici au fil du temps. Cette section vise à conserver une trace lisible des évolutions importantes.

---
**API et fonctionnalités importantes**

 - Listes chaînées génériques (`include/liste.h`) : création, ajout, suppression par pointeur, suppression par index, vidage.
Consultez les en-têtes de `include/` pour la liste complète des fonctions et leurs contrats (préconditions, responsabilités de libération, codes de retour).

---
**Compilation et exécution des exemples**

Un exemple rapide pour compiler et exécuter l'exemple de la liste (depuis la racine du projet) avec `gcc` :
- Exemple complet
```bash
. .\commandes.ps1; # Charger les fonctions de commandes.ps1
Executer-Exemple -Projet liste
```
- Exemple spécifique
```bash
. .\commandes.ps1; # Charger les fonctions de commandes.ps1
Executer-Exemple -Projet liste -Fonction ajouter_element
```
---
**Exemples et démonstrations**

 - `exemples/liste/` : plusieurs démonstrations pour la liste chaînée
	 - `main.c` : exemple complet — création, ajout d'éléments (types variés), suppression par pointeur, suppression par index (nouveau), vidage.
	 - `exemple_supprimer_par_index.c` : démonstration dédiée à `supprimer_element_par_index()`.

---
**Changements de configuration / dépendances**

 - Aucune dépendance externe (bibliothèques tierces) n'a été ajoutée.
 - Le projet est conçu pour être compilé avec un compilateur C moderne compatible C17 (`gcc` recommandé sur les environnements de développement). Pour Windows, une toolchain MinGW/Winlibs est utilisée dans les tâches fournies.

---
**Contributions et bonnes pratiques**

 - Ouvrez une issue pour proposer une amélioration ou signaler un bug.
 - Respectez les conventions de nommage et la responsabilité de libération mémoire dans chaque fonction.

---
**Licence**
Projet libre à vocation volontaire.
Utilisez-le comme bon vous semble, sans garantie.