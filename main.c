#include <stdio.h>
#include <stdlib.h>
#include "def.h"


int main()
{
  int i;

  
  printf("Welcome to Learn Math Alpha V0.0.1\n");
  printf("Select module\n");

  //print categories defined in def.h
  for(i = 0; i < 4; i++)
    {
      printf("%d - %s\n", i+1, category[i]);
    }

  //wait for user to select a category
  printf("> ");
  getchar("
  
  return 0;
}
