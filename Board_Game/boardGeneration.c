#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdint.h>

void colCascade(short *noSymbolsPtr, char **grid, int *scorePtr, int index)
{
	
}

void rowCascade(short *noSymbolsPtr, char **grid, int *scorePtr, int index)
{
	
}

bool swapAlgorithm(short *noSymbolsPtr, char **grid, int *scorePtr, short gridLength)
{
	for(int i = 1; i < gridLength; i++)
		{
			for(int j = 1; j < gridLength; i++)
				{
					if(grid[i][j] == grid[i + 1][j] && grid[i + 1][j] == grid[i + 2][j]) rowCascade(noSymbolsPtr, grid, scorePtr, i);
					else if(grid[i][j] == grid[i][j + 1] && grid[i][j + 1] == grid[i][j + 2]) colCascade(noSymbolsPtr, grid, scorePtr, j);
				}
		}
		return 1;
} 

void swapOperation(char **grid, int *parametersPtr, short gridLength)
{
	int toggle = 0;
	int row1 = parametersPtr[0], row2 = parametersPtr[2], col1 = parametersPtr[1], col2 = parametersPtr[3];
	char temp = grid[row1][col1];
	
	grid[row1][col1] = grid[row2][col2];
	grid[row2][col2] = temp;
		
	for(int i = 1; i < gridLength - 1; i++)
		{
			for(int j = 1; j < gridLength - 1 ; j++)
				{
					if((grid[i][j] == grid[i + 1][j] && grid[i][j] == grid[i + 2][j]) 
						|| (grid[i][j] == grid[i][j + 1] && grid[i][j] == grid[i][j + 2])) toggle = 1;
				}
		}
		if(toggle == 0)
			{
				//revert logic
				int row1 = parametersPtr[0], row2 = parametersPtr[2], col1 = parametersPtr[1], col2 = parametersPtr[3];
				char temp = grid[row1][col1];
	
				grid[row1][col1] = grid[row2][col2];
				grid[row2][col2] = temp;
				printf("No swap possible\n");
			}
}

bool rangeCheck(int *parametersPtr ,short gridLength)
{
	return parametersPtr[0] >= 1 && parametersPtr[0] <= gridLength && parametersPtr[1] >= 1 && parametersPtr[1] <= gridLength
								 && parametersPtr[2] >= 1 && parametersPtr[2] <= gridLength && parametersPtr[3] >= 1
								 && parametersPtr[3] <= gridLength;
}

bool adjacentCheck(int *parametersPtr)
{
	return (parametersPtr[0] == parametersPtr[2] && abs(parametersPtr[1] - parametersPtr[3]) == 1)
			|| (parametersPtr[1] == parametersPtr[3] && abs(parametersPtr[0] - parametersPtr[2]) == 1);
}

void error()
{
    printf("Entered value was invalid. Please try again\n");
}

short gridProof()
{
	short userVal;
    while(1)
    {
        if(scanf("%hi", &userVal) == 0)
        {
            while(getchar() != '\n');   
        }
        else if(userVal >= 2)
        {
            return userVal;
        }
        error();
    }
}

short symbolProof()
{
	short userVal;
    while(1)
    {
        if(scanf("%hi", &userVal) == 0)
        {
            while(getchar() != '\n');   
        }
        else if(userVal >= 2 && userVal <= 13)
        {
            return userVal;
        }
        error();
    }
}

void printGrid(char **grid, short gridLength)
{
    //print grid
    
    for (int i = 1; i <= gridLength; i++) 
    {
        for (int j = 1; j <= gridLength; j++) 
        {
            printf(" %c", grid[i][j]);
        }
		printf("\n");
    }
}

bool checkRow(char **grid, int row, int column)
{
    return column > 2 && grid[row][column] == grid[row][column - 1]
                      && grid[row][column] == grid[row][column - 2];
} 

bool checkColumn(char **grid, int row, int column)
{
    return row > 2 && grid[row][column] == grid[row - 1][column]
                   && grid[row][column] == grid[row - 2][column];
}


char **genGrid(short gridLength, char *symbols, short noSymbols)
{   
    char **grid = (char **)malloc((gridLength + 1) * sizeof(char *));
    
    //generate grid with malloc
    
    for(int i = 1; i <= gridLength; i++)
    {
            grid[i] = (char *)malloc((gridLength + 1) * sizeof(char *));
            
            for(int j = 1; j <= gridLength; j++)
            {
                grid[i][j] = symbols[rand() % noSymbols];
                
                while(checkRow(grid, i, j) || checkColumn(grid, i, j))
                {
                    grid[i][j] = symbols[rand() % noSymbols];
                }
            }
    }
    return grid;
}

static short gridSize()
{
    //determines size of grid and generates said grid
    printf("What size grid would you like?. Must be greater than 1.\n");
    short gridLength = gridProof();
    printf("\n");
	return gridLength;
}

static short symbolSize()
{
    // determines no of symbols
    printf("How many symbols would you like? The game supports up to 13 symbols and must have a minimum of 2.\n");
    short noSymbols = symbolProof();
    return noSymbols;
   
}

static int swapHandling(char *commandPtr, int *parametersPtr, short gridLength)
{
	int j = 0;
	for(int i = 0; commandPtr[i] != '\0'; i++)
	{
		if(isdigit(commandPtr[i]) != 0)
		{
			parametersPtr[j] = commandPtr[i] - '0';
			j++;
		}
	}
	if(parametersPtr[0] == gridLength + 1 || parametersPtr[1] == gridLength + 1 || parametersPtr[2] == gridLength + 1 || parametersPtr[3] == gridLength + 1)
	{
		printf("You have not entered the columns and rows to be swapped correctly.\n");
		return 0;
	}
	
	return 1;
}  

int boardGenMain()
{
    // responsible for generating the board
    char symbols[] = "!@#$%^&*()-+";
    short noSymbols = symbolSize();
    short gridLength = gridSize();
    char **grid = genGrid(gridLength, symbols, noSymbols);
	char command[10];
	int parameters[4] = {gridLength + 1};
	printGrid(grid, gridLength);
	
	printf("\nCommands:\n" 
           "Save(s)\n" 
		   "Exit(e)\n" 
		   "Swap(sw row column x row column) eg. sw 12 22\n");
	while(1)
	{
		if(fgets(command, 10, stdin) == 0)
		{
			while(getchar() != '\n');
		}
		else if(command[0] == 's' && command[1] != 'w')
		{

		}
		else if(command[0] == 's' && command[1] == 'w')
		{
			// check range and input is valid
			if(swapHandling(command, parameters, gridLength) && rangeCheck(parameters, gridLength) && adjacentCheck(parameters))
			{
				swapOperation(grid, parameters, gridLength);
				
			}else printf("Values for columns and rows are not adjacent.\n");
		}
		else if(command[0] == 'e') return 0;
	}
}