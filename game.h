#include <stdbool.h>
#define MAXSIZE 10
// #define N_GENERATIONS_DEAFULT 5

#ifndef GAME_STATE
#define GAME_STATE
#define MAXSIZE 10
// #define N_GENERATIONS_DEAFULT 5

#define ALIVE 'O'
#define DEAD  '.'
// this is a declaration, not a definition,
// of the global variable board
// SIZE + 1 since each row is nul-terminated
// extern char board[SIZE][SIZE + 1];

typedef struct game_state {
    unsigned **n_neighbors;
    char **board;
    int generations;
    int n_cols;
    int n_rows;
    
}game_state;

void clear();
void display(unsigned gen,game_state *tmp);
void update(game_state *tmp);
bool load(struct game_state *gs, char const *filename);
void free_game_state(game_state *tmp);

#endif