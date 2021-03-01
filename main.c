#include "def.h"

#define CAT_RANGE_HIGH 6
#define CAT_RANGE_LOW 1

extern char category[][17];

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
  int i;
  printf("Welcome to Learn Math Alpha V0.0.1\n");
  printf("Select module\n");

  //print categories defined in def.h
  for(i = 0; i < 6; i++)
    {
      printf("%d - %s\n", i+1, category[i]);
    }

  //wait for user to select a category
  i = num_input(CAT_RANGE_LOW, CAT_RANGE_HIGH);
  printf("%d done\n", i);
  
  return 0;
}
