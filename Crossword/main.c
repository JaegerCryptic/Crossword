#include <stdio.h>

int myFunction()
{
    int value1, value2, min, max;
    scanf("%d%d", &value1, &value2);
    for(int i = 1; i <= value1 && i <= value2; i++)
        {
            if(value1 % i == 0 && value2 %i ==0)
                max = i;
        }
    min = (value1 * value2) / max;
    return min;
}

int main(int argc, char **argv)
{
  int temp = myFunction();
  printf("\n%d", temp);
   
	return 0;
}
