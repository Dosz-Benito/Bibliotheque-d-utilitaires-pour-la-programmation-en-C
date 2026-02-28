# Bibliothèque d'utilitaires pour la programmation en C
Cette bibliothèque regroupe des fonctions, structures et types utilitaires destinés à la programmation courante en langage C.
Elle est conçue comme un **socle bas niveau**, avec une attention particulière portée à la rigueur mémoire, à la clarté du code et aux bonnes pratiques du C.
Le code est écrit et documenté en **français**.


## Objectifs

* Fournir des utilitaires réutilisables (chaînes, tableaux, listes, conversions, gestions d'entrées utilisateur, etc.)
* Servir d'exemple dans l'apprentissage du **C**
* Faciliter le développement de projets en C en offrant des prérequis essentiels
* Encourager une gestion explicite et saine de la mémoire

Ce projet n'a pas vocation à remplacer la libc, mais à accompagner l'apprentissage et la structuration de projets C.


## Architecture du projet

```
.
├── include/        # Fichiers headers contenant les déclarations des utilitaires
├── src/            # Fichiers sources contenant les implémentation des utilitaires
├── exemples/       # Exemples d'utilisation de chaque utilitaire
├── README.md       # Documentation du projet
```

### Règles importantes

* Les fichiers dans `include/` sont **autonomes**.
* Les allocations mémoire sont **explicites** et documentées.
* La responsabilité de libération (`free`) est clairement définie.


## Téléchargement
Vous pouvez cloner ce projet depuis GitHub avec la commande suivante :
```bash
git clone https://github.com/Dosz-Benito/Bibliotheque-d-utilitaires-pour-la-programmation-en-C.git
cd Bibliotheque-d-utilitaires-pour-la-programmation-en-C
```

## Compilation et exécution des exemples
Un exemple rapide pour compiler et exécuter l'exemple de la liste (depuis la racine du projet) avec gcc :
* Exemple complet
```bash
. .\commandes.ps1; # Charger les fonctions de commandes.ps1
Executer-Exemple -Projet liste
```
* Exemple spécifique (ajout d'un élément à une liste)
```bash
. .\commandes.ps1; # Charger les fonctions de commandes.ps1
Executer-Exemple -Projet liste -Exemple ajout_element # Les exemples disponibles sont : ajout_element, creation_suppression_liste, suppression_elements
```
Pour le développement, une configuration VS Code avec des options strictes de compilation est utilisée.


## Conseil d'utilisation

* Inclure uniquement les en-têtes nécessaires :
* Pour la compilation de vos projets, utilisez la commande minimale suivante :
```bash
gcc chemin/vers/vos/fichiers.c src/*.c -Iinclude -o executable.exe
.\executable.exe
```

## Dépendances
Aucune dépendance externe (bibliothèques tierces) n'a été ajoutée.
Le projet est conçu pour être compilé avec un compilateur C moderne compatible C17 (gcc recommandé sur les environnements de développement).


## Licence
Projet libre à vocation volontaire. Utilisez-le comme bon vous semble, sans garantie.