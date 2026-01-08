# Bibliothèque d'utilitaires pour la programmation en C

Cette bibliothèque regroupe des fonctions, structures et types utilitaires destinés à la programmation courante en langage C.
Elle est conçue comme un **socle bas niveau**, avec une attention particulière portée à la rigueur mémoire, à la clarté du code et aux bonnes pratiques du C.

Le code est écrit et documenté en **français**.

---

## Objectifs

* Fournir des utilitaires réutilisables (chaînes, tableaux, listes, conversions, etc.)
* Servir d'exemple dans l'apprentissage au **C bas niveau**
* Encourager une gestion explicite et saine de la mémoire

Ce projet n'a pas vocation à remplacer la libc, mais à accompagner l'apprentissage et la structuration de projets C.

---

## Architecture du projet

```
.
├── include/        # Fichiers headers contenant les utilitaires
├── src/            # Exemples d'utilisation de chaque utilitaire
├── README.md       # Documentation du projet
```

### Règles importantes

* Les fichiers dans `include/` sont **autonomes**.
* Les allocations mémoire sont **explicites** et documentées.
* La responsabilité de libération (`free`) est clairement définie.

---

## Du téléchargement à la démonstration

Exemple simple avec GCC :

```bash
git clone https://github.com/Dosz-Benito/Bibliotheque-d-utilitaires-pour-la-programmation-en-C.git
cd Bibliotheque-d-utilitaires-pour-la-programmation-en-C
```

Pour le développement, une configuration VS Code avec compilation stricte est utilisée.

---

## Conseil d'utilisation

* Inclure uniquement les en-têtes nécessaires :
* Il est possible d'inclure tous les fichiers en une seule fois via
```c
#include "main.h"
```

---

## État du projet

Projet en évolution continue.
Certaines utilitaires peuvent changer au fil de l'apprentissage et des refactorisations.

---

## Licence

Projet libre à vocation volontaire.
Utilisez-le comme bon vous semble, sans garantie.