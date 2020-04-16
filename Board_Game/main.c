#include <stdio.h>
#include <boardGeneration.h>

static void startGame()
{
    // determines if new game or old
    short gameSelect;
    
    printf("Would you like to start a new game(1), or load an old game(2). Please select 1 or 2\n");
    
    gameSelect = babyProof(gameSelect);
    
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
