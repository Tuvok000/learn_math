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

void addition_gen(int dig, int num, int *arr)
{
/*--------------------------------------------*
Level: decides max number of digits per number
num: how many numbers (max 4)
arr: stores numbers to be passed back
*--------------------------------------------*/
  int i;
  int digit_max = 0;

  //generates the max number for a given set of digits
  for(i = 0; i < dig; i++)
  {
    digit_max += 9 * pow(10, i);
  }

  //generate amount of numbers given dig
  for(i = 0; i < num; i++)
  { 
    arr[i] = rand() % digit_max;
  }
}

void addition_main(int page_count)
{
/*-------------------------------------------------------*
gets input from user about how hard they want the math
problems to be, then repeatedly calls the addition_gen
function to generate the numbers
fills up an array, then writes a tex document with array
values
tex document is processed separately to create the final
math document
page_count specifies how many pages to create
20 problems per page, max 20 pages
*-------------------------------------------------------*/

  int page_num, j;
  char file_name[23] = {'\0'}; //"Addition Page xx of xx"

/*** Verify that page_count is <= 20 ***/

  FILE *fp;
  fp = fopen("Addition Workbook", "w");

  //generate page name for file open and close
  for(page_num = 0; page_num < page_count; page_num++)
  {
    //use if new files are needed for every page
    //snprintf(file_name, 22, "Addition Page %2d of %2d", i + 1, page_count);

  }
}
  
