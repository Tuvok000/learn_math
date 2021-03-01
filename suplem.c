#include "def.h"

//extern char category[][17];

int num_input(int low, int high)
{
  //need to fix the stdin flush issue
  //function reads in stream, but doesn't clear it
  //mul
  int i;
  char input[4] = {'\0'};
  long num = 0;
  
  while(1)
    {
      printf("> ");
      scanf("%4s", input);
      fflush(stdin);
      num = strtol(input, NULL, 10);
      if(num < low || num > high)
	continue;
      break;
    }
  return (int)num;
}
  
