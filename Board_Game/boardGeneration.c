
static char randomSymbol(short inNoSymbols)
{
    int random = (rand() % inNoSymbols ) + 'A';
    return (char)random;
}

static void gridSize(short inNoSymbols)
{
    //determines size of grid and generates said grid
    short totalGrid;
    
    char** grid;
    
    printf("What size grid would you like?\n");
    scanf("%hi", &totalGrid);
    
    grid = (char **)malloc((totalGrid + 1) * sizeof(char *));
    
    //generate grid with malloc
    
    for(int i = 0; i < totalGrid + 1; i++)
    {
            grid[i] = (char *)malloc((totalGrid + 1) * sizeof(char *));
    }
    
    
    
    // fill grid symbols
     //static int count = 1; Testing data
     static char row = '1';
     static char column = '1';
     
      for(int i = 0; i < totalGrid; i ++)
    {
            grid[i][0] = column;
            column++;
            printf("%c\n",grid[i][0]);
    }
     
    for(int i = 0; i < totalGrid; i ++)
    {
        for(int j = 1; j < totalGrid + 1; j++)
        {
            grid[i][j] = row;
            row++;
        }
    }
     
    for(int i = 1; i < totalGrid + 1; i++)
    {
        for(int j = 1; j < totalGrid + 1; j++)
        {
            grid[i][j] = randomSymbol(inNoSymbols);
            //printf("%c\n",grid[i][j]);
            //printf("%d", count); Testing data 
            //count++; Testing data
        }
    }
    
    //print grid
    
    for (int i = 0; i < totalGrid + 1; i++) 
    {
        for (int j = 1; j < totalGrid + 1; j++) 
        {
            static int count = 0;
        
            printf("%c ", grid[i][j]);
            count++;
            if(count == totalGrid)
            {
                printf("\n");
                count = 0;
            }
        }
    }
    //printf("We got here"); Testing data
}

static void symbolSize()
{
    // determines no of symbols
    short noSymbols;
    
    printf("How many symbols would you like? Warning. No more than 26 symbols. More than 6 symbols may result in a unbalanced game.\n");
    scanf("%hi", &noSymbols);
    gridSize(noSymbols);
}

static int startGame()
{
    // determines if new game or old
    short gameSelect; 
    
    printf("Would you like to start a new game(1) or load an old game(2). Please select 1 or 2\n");
    scanf("%hi", &gameSelect);
    
    if(gameSelect == 1)
    {
            // Start new game generation 
            symbolSize();
    } 
    else
    {
            // Start loading of old game I/O sequence
    }
}

void boardGenMain()
{
    // responsible for generating the board
    startGame();
    
}