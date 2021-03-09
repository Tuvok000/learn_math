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
      //this may cause some problems in the future
      //clears input buffer before and after input
      //while ((getchar()) != '\n');
      printf("> ");
      scanf("%4s", input);
      //while ((getchar()) != '\n');
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
dig: decides max number of digits per number (max 4)
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

void addition_main(int page_count, int level)
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

  int page_num, prob_count, i, j;
  //char file_name[23] = {'\0'}; //"Addition Page xx of xx"
  int num_buf[4] = {'\0'};

/*** Verify that page_count is <= 20 ***/

  FILE *fp;
  fp = fopen("Addition_Workbook.tex", "w");

  //print the start of the document
  fprintf(fp, "\\documentclass{article}\n\\begin{document}\n");

  //generate page name for file open and close
  for(page_num = 0; page_num < page_count; page_num++)
  {
    //open tabular environment for every page
    fprintf(fp, "\\begin{tabular}{ccc}\n");
    //print out 20 problems for the page
    for(prob_count = 0; prob_count < 20; prob_count++)
    {
      //generate the values used for the problems
      addition_gen(addition_gen_ref[level][0], addition_gen_ref[level][1], num_buf);
      //use one of three format strings depending on the number of variables requested
      switch(addition_gen_ref[level][1])
      {
        case 2://2 variables
          fprintf(fp, addition_format_string[0], prob_count + 1, num_buf[0], num_buf[1]);
          break;

        case 3://3 variables
          fprintf(fp, addition_format_string[1], prob_count + 1, num_buf[0], num_buf[1], num_buf[2]);
          break;

        case 4://4 variables
          fprintf(fp, addition_format_string[2], prob_count + 1, num_buf[0], num_buf[1], num_buf[2], num_buf[3]);
          break;

        default://something done fucked up, should never come here
          printf("Things really fucked up in addition\n");
          break;
      }
      //if second problem listed, create 2 new lines
      if(prob_count % 2 == 1)
      {
        fprintf(fp, "\\\\\\\\\n");
      }
      else//insert a 5 cm space into the second column 
      {
        fprintf(fp, "& \\hspace{3cm} &");
      }
    }
    //end the tabular environment, create a new page
    //the loop will reopen a tabular environment for each new page
    fprintf(fp, "\\end{tabular}\n\\newpage\n");
  }
  fprintf(fp, "\\end{document}");
  fclose(fp);
}
  
