
# TicTacToe


Durée :

• 6h de développement

• Travail en groupe (2 à 3 étudiants)

Objectifs :

• Développer un jeu Tic Tac Toe en C/C++ (terminal) et utiliser Git/GitHub pour gérer le
projet.





## Arborescence  

```plaintext
TicTacToe/
├── include/ → fichier header (.h)
└── src/ → fichier .cpp
```
## Installation

Git clone :

```bash
  git clone https://github.com/jarebYT/tictactoe.git
```
Compilation : 

```bash
g++ -I include src/*.cpp -o tictactoe
```

-I car nous avons mis les .h dans un dossier include, et le src/*.cpp car les fichiers cpp sont dans un dossier src.






## Bonus

- Github Actions pour tester la compil à chaque push sur la main et dev, ainsi que sur les pr.
- Jouer contre l'IA


## Equipe

- Asly, Rôle : Affichage du résultat
- Florian, Rôle : Grille 3x3
- Alexandre, Rôle : Joueur, Validation de la saisie, Git Leader
- Sonny, Rôle : Organisation, Détection de victoire / égalité, Github Actions
