#include "def.h"

//extern char category[][17];

int num_input(int low, int high)
{
  //need to fix the stdin flush issue
  //function reads in stream, but doesn't clear it
  //the function will process 4 characters at a time
  //then process the remainder of the stream
  
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

void addition(int level, int num, int *arr)
{
/*--------------------------------------------*
Level: decides max number of digits per number
num: how many numbers (max 4)
arr: stores numbers to be passed back
*--------------------------------------------*/
  int i;
  for(i = 0; i < num; i++)
    {
      arr[i] = 
  
