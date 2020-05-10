#include <stdio.h>
#include <boardGeneration.h>

short gameProof()
{
	short userVal; 
    while(1)
    {
        if(scanf("%hi", &userVal) == 0)
        {
            while(getchar() != '\n');   
        }
        else if(userVal == 1 || userVal == 2)
        {
            return userVal;
        }
        error();
    }
}

static void startGame()
{
    // determines if new game or old
    
    printf("Would you like to start a new game(1), or load an old game(2). Please select 1 or 2\n");
    
	short gameSelect = gameProof();
    
    if(gameSelect == 1)
    {
        // Start new game generation 
        boardGenMain();
    } 
    else
    {
        // Start loading of old game I/O sequence
    }
}

int main(int argc, char **argv)
{
    startGame();
	return 0;
}
