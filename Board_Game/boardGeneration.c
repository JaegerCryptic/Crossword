char** grid;
short noSymbols;
short gridLength;

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

static void validateGrid()
{
    
}

static char randomSymbol(short noSymbols)
{
    int random = (rand() % noSymbols );
    
    char symbols[] = "!@#$%&";
    
    return symbols[random];
}

void printGrid()
{
    //print grid
    
    for (int i = 0; i < gridLength + 1; i++) 
    {
       
        for (int j = 1; j < gridLength + 1; j++) 
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
            if(count == gridLength)
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

static void fillGrid()
{
     // fill grid symbols
     //static int count = 1; Testing data
     /*static char row = '1';
     static char column = '1';*/
     
    /*  for(int i = 1; i < gridLength + 1; i ++)
    {
            grid[i][0] = column;
            column++;
            //printf("%c\n",grid[i][0]); Test data
    }
     
    for(int i = 0; i < gridLength; i ++)
    {
        for(int j = 1; j < gridLength + 1; j++)
        {
            grid[i][j] = row;
            row++;
        }
    }*/
     
    for(int i = 1; i < gridLength + 1; i++)
    {
        for(int j = 1; j < gridLength + 1; j++)
        {
            grid[i][j] = randomSymbol(noSymbols);
            //printf("%c\n",grid[i][j]);
            //printf("%d", count); Testing data 
            //count++; Testing data
        }
    }
    printGrid();
}

void genGrid()
{
     grid = (char **)malloc((gridLength + 1) * sizeof(char *));
    
    //generate grid with malloc
    
    for(int i = 0; i < gridLength + 1; i++)
    {
            grid[i] = (char *)malloc((gridLength + 1) * sizeof(char *));
    }
    fillGrid();
}

static void gridSize()
{
    //determines size of grid and generates said grid
    
    printf("What size grid would you like?. Must be greater than 1.\n");
    gridLength = toddlerProof(gridLength);
    printf("\n");
    
    genGrid();
}

static void symbolSize()
{
    // determines no of symbols
    printf("How many symbols would you like? The game supports up to 6 symbols and must have a minimum of 2.\n");
    noSymbols = dummyProof(noSymbols);
    gridSize();
}

void boardGenMain()
{
    // responsible for generating the board
    symbolSize();
}