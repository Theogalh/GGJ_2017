Version 1.0

Premier Proto du jeu, sortie pour la Global Game Jam.

Contexte de developpement :

SFML Impos�e, Projet uniquement d�velopp� par un groupe de 3 developpeurs d'Epitech en d�but de deuxieme ann�e.


Contenus 1.0:

- Menu principal avec deux options:
		- Lancer le jeu
		- Quitter le jeu

- Musique Menu & Level, une seule musique.

- Gestion de l'ajout de niveaux dans le dossier /src/map, SANS gestion d'erreurs

- Gestion de l'ajout de texture de mur dans le dossier /src/wall, SANS gestion d'erreurs

- Moteur physique fonctionnel.

- Creation de vagues de bombes tombant rapidement sur le joueur.

- Selection al�atoire des niveaux dans le dossier /src/map

- Possibilit� de niveau " Bonus " avec une marre de lave qui monte et tue le joueur au contact.

- Gestion du score:
		- 100 points � chaque niveau termin�
		- 150 points � chaque niveau bonus termin�

- Sauvegarde du HighScore ( NON SECURISER )

- Gestion des touches:
	Deplacement avec fl�che gauche/droites
	Saut avec la fl�che du haut
	Echap pour quitter
	A pour se suicider

BUGS Connus :

- Probl�me de hitbox en cas de bloc unique en plateforme.

- Impossible de sauter s'il n'y a pas de plateforme a la premi�re lige en partant du bas.