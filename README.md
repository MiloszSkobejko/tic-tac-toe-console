# Tic-Tac-Toe Console Game

This is one of my first projects and C programs that I created back in late 2020 when I started college. I'm uploading it now to archive it on GitHub. Please note that this repository will not be further modified or changed, and it will remain for view-only purposes.

## Introduction

Tic-tac-toe is a classic game played on a grid of 3x3 squares. The objective of the game is to be the first player to form a horizontal, vertical, or diagonal line with their markers on the grid. It's a simple yet entertaining game that can be enjoyed by people of all ages.

This project implements a console-based version of the tic-tac-toe game using the C programming language. The game allows two players to take turns entering their moves until a winner is determined or the game ends in a draw. It provides a basic user interface and utilizes basic logic to handle player inputs and validate moves.

## Controls and coordinates:

```
0,0 | 1,0 | 2,0
----+-----+----
0,1 | 1,1 | 2,1
----+-----+----
0,2 | 1,2 | 2,2
```

## Requirements

To compile and run this program, you need to have a C compiler installed on your system. This program has been tested and developed using [GCC](https://gcc.gnu.org/), but it should work with other C compilers as well.

## Usage

1. Clone this repository to your local machine or download the source code as a ZIP file.
2. Open a terminal or command prompt and navigate to the project directory.
3. Compile the source code using the following command:

   ```bash
   gcc main.c -o tic-tac-toe
   ```
4. Run the program by executing the generated binary:
  * On Unix/Linux systems:
  ```
  ./tic-tac-toe
  ```
  * On Windows systems:
  ```
  tic-tac-toe.exe
  ```
5. Follow the on-screen instructions to play the tic-tac-toe game.

## Features
* Interactive console-based gameplay.
* Two players can take turns entering their moves.
* The game detects and announces the winner if a player forms a line of three markers.
* The game detects and announces a draw if all the squares on the grid are filled.
* Basic input validation to ensure only valid moves are accepted.
* The game can be replayed once it ends.

## Limitations
This version of the tic-tac-toe game has a few limitations:

* It doesn't include any AI or computer opponent. It can only be played between two human players.
* The input validation is basic and may not handle all possible edge cases.
