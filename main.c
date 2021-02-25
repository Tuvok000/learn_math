#include <stdio.h>
#include <stdlib.h>
#include "def.h"

#define CAT_RANGE_HIGH 6
#define CAT_RANGE_LOW 1

//category definitions

void addition(int level);
/***************************************
first category, addition
adding 2-4 numbers together
each number 1-4 digits long

variable: level
1 - 2 num, 1 digit

***************************************/

int main()
{
  int category_count;
  long category_select;
  char input[2];
  
  printf("Welcome to Learn Math Alpha V0.0.1\n");
  printf("Select module\n");

  //print categories defined in def.h
  for(category_count = 0; category_count < 6; category_count++)
    {
      printf("%d - %s\n", category_count+1, category[category_count]);
    }

  //wait for user to select a category
  while(1)
    {
      printf("> ");
      scanf("%2s", input);
      fflush(stdin);
      category_select = strtol(input, NULL, 10);
      if(category_select < CAT_RANGE_LOW || category_select > CAT_RANGE_HIGH)
	continue;
      break;
    }
  printf("done\n");
  
  return 0;
}
