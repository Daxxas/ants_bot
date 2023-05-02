# Convention de nommage

## Organisation du projet
Tous le code du projet se trouve dans src.

A l'intérieur, les dossiers sont organisés sous cette forme:
- BT/ : Tous les fichiers liés au Behavior Tree. Les classes sont nommées BT_*.h
- AI/ : Toutes les nodes du Behavior Tree. Les classes préfixés par A_* sont des nodes d'actions, les classes préfixés par I_* sont des nodes d'inputs.
- AI/Scout : Les nodes liés aux décisions de type "Scout". Une seule maintenant (A_MoveToBestDirection), mais durant le développement beaucoup de nodes étaient liés à ce comportement.
- AI/Soldier : Les nodes liés aux décisions de type "Soldier". Pour comprendre le fonctionnement, voir l'image si dessous.

![Behavior Tree](./IAFourmis.drawio.png)

## Convention
- Les variables sont en camelCase
- Les pointeurs sont préfixés de p_ pour éviter d'oublier de les libérer