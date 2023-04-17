#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define EMPTY ' '

struct board
{
    char field[3][3];
};

struct player
{
    // x i y są jako ostatnie podane koordynaty
    // przez danego gracza.
    int x, y, id;
    char icon;
};

// Prototypy funkcji
void printboard(struct board * brd);
bool initialize(struct board * brd);
bool playerinit(struct player * pl, int id, char icon);
bool getplayerinput(struct player * pl);
char checkifwin(struct board * brd);

// Inicjalizacja planszy i wypełnienie jej pustymi wartościami
bool initialize(struct board * brd)
{
    if (brd == NULL) return false;
    
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            brd -> field[i][j] = EMPTY;
    
    return true;
}


// Wyświetlanie planszy w konsoli
void printboard(struct board * brd)
{
    for (int i = 0; i < 3; i++)
    {
        printf(" %c | %c | %c ", brd -> field[i][0], brd -> field[i][1], brd -> field[i][2]);
        if (i < 2) printf("\n---+---+---\n");
    }
    
    
    printf("\n");
}


// Inicjalizacja gracza
bool playerinit(struct player * pl, int id, char icon)
{
    if (pl == NULL) return false;
    pl -> id = id;
    pl -> icon = icon;
    return true;
}


bool getplayerinput(struct player * pl)
{
    if (pl == NULL) return false;
    
    printf("\n---gra gracz: %d---\n", pl -> id);
    printf("podaj wspolrzedne punktu: \n");
    
    while (!scanf("%d %d", &pl -> x, &pl -> y) || (pl -> x < 0 || pl -> y < 0 || pl -> x > 2 || pl -> y > 2))
    {
        while ((getchar()) != '\n') { }
        printf("niepoprawne dane, podaj wspolrzedne punktu: \n");
    }

    
    return true;
}


char checkifwin(struct board * brd)
{
    if (brd -> field[0][0] == brd -> field[0][1] && brd -> field[0][1] == brd -> field[0][2]) return brd -> field[0][0];
    if (brd -> field[1][0] == brd -> field[1][1] && brd -> field[1][1] == brd -> field[1][2]) return brd -> field[1][0];
    if (brd -> field[2][0] == brd -> field[2][1] && brd -> field[2][1] == brd -> field[2][2]) return brd -> field[2][0];
    
    if (brd -> field[0][0] == brd -> field[1][0] && brd -> field[1][0] == brd -> field[2][0]) return brd -> field[0][0];
    if (brd -> field[0][1] == brd -> field[1][1] && brd -> field[1][1] == brd -> field[2][1]) return brd -> field[0][1];
    if (brd -> field[0][2] == brd -> field[1][2] && brd -> field[1][2] == brd -> field[2][2]) return brd -> field[0][2];
    
    if (brd -> field[0][0] == brd -> field[1][1] && brd -> field[1][1] == brd -> field[2][2]) return brd -> field[0][0];
    if (brd -> field[0][2] == brd -> field[1][1] && brd -> field[1][1] == brd -> field[2][0]) return brd -> field[0][2];
    
    // Zwraca puste jak nikt nie wygrał
    return EMPTY;
}


int main(void)
{
    int turn = 0;
    struct player player1;
    struct player player2;
    playerinit(&player1, 1, 'X');
    playerinit(&player2, 2, 'O');
    
    // Różne ziarno z każdą grą
    srand((unsigned) time(NULL));
    
    struct board mainboard;
    initialize(&mainboard);
    
    // Główna pętla gry, będzie się wykonywać, aż minie 9 rund,
    // lub ktoś wygra, bądź zrezygnue z gry.
    while (turn < 9)
    {
        char won = EMPTY;
        
        while (getplayerinput(&player1) && mainboard.field[player1.x][player1.y] != EMPTY)
        {
            while ((getchar()) != '\n') { }
            printf("pole jest juz zajete, podaj wspolrzedne innego punktu: \n");
        }
        mainboard.field[player1.x][player1.y] = player1.icon;
        printboard(&mainboard);
             
        if (checkifwin(&mainboard) != EMPTY) {printf("wygral gracz: %d\n", player1.id); return 0; }
        
            
        while (getplayerinput(&player2) && mainboard.field[player2.x][player2.y] != EMPTY)
        {
            while ((getchar()) != '\n') { }
            printf("pole jest juz zajete, podaj wspolrzedne innego punktu: \n");
        }
        mainboard.field[player2.x][player2.y] = player2.icon;
        printboard(&mainboard);
        
        if (checkifwin(&mainboard) != EMPTY) {printf("wygral gracz: %d\n", player2.id); return 0; }
        
        turn ++;
    }
    
    printf("remis!\n");
    return 0;
}
