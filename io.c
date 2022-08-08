#include "game.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

// clear terminal screen
void clear()
{
    printf("\e[2J\e[H"); // magic!
}

// display board and current generation 
void display(unsigned gen,game_state *tmp)
{
    printf("Game generation %u\n", gen);
    for (unsigned i = 0; i < tmp->n_rows; ++i) {
        puts(tmp->board[i]);
    }
    fflush(stdout); // make sure it gets displayed
}

// returns true if load was successful
bool load(game_state *gs, char const *filename)
{
    assert(gs && filename);
    int rows,cols;
    int countc=0,countr=0;
    char word;
    int num=0;
    // int c;
    FILE *fp=fopen(filename,"r");
    if (!fp)
    {
        perror(__func__);
        fprintf(stderr,"Cannot open '%s' !\n",filename); 
        return false;
    }
    bool flagr=false,flagc=false;
    while (word!='\n')
    {
        fscanf(fp,"%d",&num);
        
            if (!flagr)
            {
                flagr=true;
                rows=num;
            }
            else if (!flagc) 
            {
                flagc=true;
                cols=num;
            }
             
        word=fgetc(fp);
        
    }
    gs->n_cols=cols;
    gs->n_rows=rows;
    gs->generations=5;
    gs->board=malloc(rows*(sizeof(char*)));
    gs->n_neighbors=malloc(rows*(sizeof(unsigned *)));
    for ( int k = 0; k < rows; k++)
    {
        gs->board[k]=malloc(cols+1);
        gs->n_neighbors[k]=malloc((cols+1)*sizeof(unsigned));
    }
    word=fgetc(fp);
    countc=0;
    countr=0;
    int countcheck=0;
    while (word!=EOF)
    {
           
        if (word=='.' || word=='O')
        {
            if (countr>=rows)
        {
            printf("invaild file format\n");
            fclose(fp);
            return false;
        }
            gs->board[countr][countc]=word;
            countc++;
            countcheck++;
        }
        word=fgetc(fp);
        
        if (countc==cols)
        {   
            if (word!='\n')
            {
                
                printf("invaild file format\n");
                fclose(fp);
                return false;
            }
            countc=0;
            countr++;
        }
        if (countcheck>(cols*rows) || countr>rows)
        {
            
            printf("invaild file format\n");
            fclose(fp);
            return false;
        }
    
    }
    if (countcheck!=(rows*cols) || countr!=rows)
    {
        
        printf("invaild file format\n");
        fclose(fp);
        return false;
    }
    
    fclose(fp);
    return true;
}
void free_game_state(game_state *tmp){
    if (tmp->board==NULL)
    {
        if (tmp->n_neighbors==NULL)
        {
            return;
        }
        for (int j = 0; j < tmp->n_rows;j++)
        {
            unsigned *curneigh=tmp->n_neighbors[j];
            free(curneigh);
        }
        unsigned **curtmpneigh=tmp->n_neighbors;
        free(curtmpneigh);
        return;
    }
    else if (tmp->n_neighbors==NULL)
    {
        for (int j = 0; j < tmp->n_rows;j++)
        {
            char *curboard=tmp->board[j];
            free(curboard);
        }
        char **curtmpboard=tmp->board;
        free(curtmpboard);
        return;
    }
    for ( int i = 0; i < tmp->n_rows; i++)
    {
        char *curboard=tmp->board[i];
        unsigned *curneigh=tmp->n_neighbors[i];
        free(curboard);
        free(curneigh);
    }
    char **curtmpboard=tmp->board;
    unsigned **curtmpneigh=tmp->n_neighbors;
    free(curtmpboard);
    free(curtmpneigh);
    
}











//printf("countcheck:%d, cols:%d rows:%d countr:%d countc:%d ",countcheck,cols,rows,countr,countc);