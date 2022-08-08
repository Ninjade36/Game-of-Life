#include "game.h"
#include <stdio.h>
/* this function is not declared in game.h since it is
   internal to game.c; it is even defined as static -- 
   so the linker won't allow using it outside of game.c */
static unsigned count_neighbors(game_state *tmp,unsigned i, unsigned j)
{   
    int count=0;
    int ni[3];
    int nj[3];
    if (i==0)
    {
        ni[0]=tmp->n_rows-1;
        ni[1]=i;
        ni[2]=i+1;
    }
    else if (i==tmp->n_rows-1)
    {
        ni[0]=i-1;
        ni[1]=i;
        ni[2]=0;
    }
    else{
        ni[0]=i-1;
        ni[1]=i;
        ni[2]=i+1;
    }
    if (j==0)
    {
        nj[0]=tmp->n_cols-1;
        nj[1]=j;
        nj[2]=j+1;
    }
    else if (j==tmp->n_cols-1)
    {
        nj[0]=j-1;
        nj[1]=j;
        nj[2]=0;
    }
    else{
        nj[0]=j-1;
        nj[1]=j;
        nj[2]=j+1;
    }
    
    for (int ii = 0; ii < 3; ii++)
    {
        for (int jj = 0; jj < 3; jj++)
        {
            if (tmp->board[ni[ii]][nj[jj]]=='O')
            {
                {
                count++;
                }
            }
        }  
    }
    if (tmp->board[i][j]=='O')
    {
        return count-1;
    }
    return count;
    
}

void update(game_state *tmp)
{
    // unsigned n_neighbors[tmp->n_rows][tmp->n_cols];

    for (int i = 0; i < tmp->n_rows; ++i) {
        for (int j = 0; j < tmp->n_cols; ++j) {
            tmp->n_neighbors[i][j] = count_neighbors(tmp,i,j);
        }
    }

    for (unsigned i = 0; i < tmp->n_rows; ++i) {
        for (unsigned j = 0; j < tmp->n_cols; ++j) {
            unsigned nn = tmp->n_neighbors[i][j];
            if (nn < 2 || nn > 3)
                tmp->board[i][j] = DEAD;
            else if (nn==3)
                tmp->board[i][j] = ALIVE;
            
            // when nn == 2, the previous value is retained
        }
    }
}
