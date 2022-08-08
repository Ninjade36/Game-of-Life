#include "game.h"
#include <stdbool.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define EXAMPLE_LOAF {  \
    "......",           \
    "..OO..",           \
    ".O..O.",           \
    "..O.O.",           \
    "...O..",           \
    "......"}

#define EXAMPLE_BEACON {\
    "......",           \
    ".OO...",           \
    ".OO...",           \
    "...OO.",           \
    "...OO.",           \
    "......"}

#define EXAMPLE_GLIDER {\
    "......",           \
    "...O..",           \
    ".O.O..",           \
    "..OO..",           \
    "......",           \
    "......"}

// try all 3 examples! 
// e.g. change EXAMPLE_LOAF TO EXAMPLE_BEACON
// and rebulid
// char board2[SIZE][SIZE + 1] = EXAMPLE_BEACON;
void free_game_state(game_state *tmp);
int main(int argc,char ** argv)
{
    if (argc==1){
        printf("usage error detected");
        return 1;
    }
    bool interactive;
    game_state tmp={};
    bool lod;
    
    lod=load(&tmp,argv[1]); 
    if (lod==false)
    {
        free_game_state(&tmp);
        fprintf(stderr,"The program has failed to load\n");
        return 2;
    }
    if (argc!=1)
    {
    if (argc==2)
    {
    bool interactive = true;
    unsigned gen;
    for (gen = 1; gen <= (tmp.generations); ++gen) {
        update(&tmp);
        if (interactive) {
            // display intermediate boards
            clear();
            display(gen,&tmp);
            sleep(1); // one second
        }
    }
    if (!interactive) // display only final board
        display(gen,&tmp);
    }
    else if (argc>2)
    {
        if (argc==3)
        {
           
        if (isdigit(argv[2][0]))
        {
            int n_gen=atoi(argv[2]);
            printf("%d",n_gen);
            interactive = true;
            tmp.generations=n_gen;
        }
        else{
            interactive=false;
        }
        }
        if (argc==4)
        {
        if (isdigit(argv[2][0]))
        {
            int n_gen=atoi(argv[2]);
            tmp.generations=n_gen;
            interactive=false;
        }
        else{
            int n_gen=atoi(argv[3]);
            tmp.generations=n_gen;
            interactive=false;

        }
        }
        unsigned gen;
    for (gen = 1; gen <= tmp.generations; ++gen) {
        update(&tmp);
        if (interactive) {
            // display intermediate boards
            clear();
            display(gen,&tmp);
            sleep(1); // one second
        }
    } 
    if (!interactive){ // display only final board
        display(gen-1,&tmp);
    }
    }
    }
    else{
    bool interactive = true;
    unsigned gen;
    for (gen = 1; gen <= tmp.generations; ++gen) {
        update(&tmp);
        if (interactive) {
            // display intermediate boards
            clear();
            display(gen,&tmp);
            sleep(1); // one second
        }
    }
    if (!interactive) // display only final board
        display(gen,&tmp);
    }
    
    free_game_state(&tmp);
    return 0;
}
    
