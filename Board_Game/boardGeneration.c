void error()
{
    printf("Entered value was invalid. Please try again\n");
}

short toddlerProof(short userVal)
{
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

short dummyProof(short userVal)
{
    while(1)
    {
        if(scanf("%hi", &userVal) == 0)
        {
            while(getchar() != '\n');   
        }
        else if(userVal >= 2 && userVal <= 6)
        {
            return userVal;
        }
        error();
    }
}

short babyProof(short userVal)
{
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

static char randomSymbol(short inNoSymbols)
{
    int random = (rand() % inNoSymbols );
    
    char symbols[] = "!@#$%&";
    
    return symbols[random];
}

static void gridSize(short inNoSymbols)
{
    //determines size of grid and generates said grid
    short totalGrid;
    
    char** grid;
    
    printf("What size grid would you like?. Must be greater than 1.\n");
    totalGrid = toddlerProof(totalGrid);
    printf("\n");
    
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
     
      for(int i = 1; i < totalGrid + 1; i ++)
    {
            grid[i][0] = column;
            column++;
            //printf("%c\n",grid[i][0]); Test data
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
            static int topDone = 0;
            if(topDone == 0 || count > 0)
            {
                printf("    %c", grid[i][j]);
            } 
            else
            {
                printf("   %c", grid[i][j]);
            }
            count++;
            if(count == totalGrid)
            {
                topDone++;
                printf("\n");
                count = 0;
                if(topDone >= 1)
                {
                    printf("%c",grid[0][topDone]);
                }
               
            }
        }
    }
    //printf("We got here"); Testing data
}

static void symbolSize()
{
    // determines no of symbols
    short noSymbols;
    
    printf("How many symbols would you like? Warning. The game supports up to 6 symbols.\n");
    noSymbols = dummyProof(noSymbols);
    gridSize(noSymbols);
}

static int startGame()
{
    // determines if new game or old
    short gameSelect;
    
    printf("Would you like to start a new game(1), or load an old game(2). Please select 1 or 2\n");
    
    gameSelect = babyProof(gameSelect);
    
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