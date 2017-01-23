Version 1.0

Premier Proto du jeu, sortie pour la Global Game Jam.

Contexte de developpement :

SFML Imposée, Projet uniquement développé par un groupe de 3 developpeurs d'Epitech en début de deuxieme année.


Contenus 1.0:

- Menu principal avec deux options:
		- Lancer le jeu
		- Quitter le jeu

- Musique Menu & Level, une seule musique.

- Gestion de l'ajout de niveaux dans le dossier /src/map, SANS gestion d'erreurs

- Gestion de l'ajout de texture de mur dans le dossier /src/wall, SANS gestion d'erreurs

- Moteur physique fonctionnel.

- Creation de vagues de bombes tombant rapidement sur le joueur.

- Selection aléatoire des niveaux dans le dossier /src/map

- Possibilité de niveau " Bonus " avec une marre de lave qui monte et tue le joueur au contact.

- Gestion du score:
		- 100 points à chaque niveau terminé
		- 150 points à chaque niveau bonus terminé

- Sauvegarde du HighScore ( NON SECURISER )

- Gestion des touches:
	Deplacement avec flèche gauche/droites
	Saut avec la flèche du haut
	Echap pour quitter
	A pour se suicider

BUGS Connus :

- Problème de hitbox en cas de bloc unique en plateforme.

- Impossible de sauter s'il n'y a pas de plateforme à la première ligne en partant du bas.
