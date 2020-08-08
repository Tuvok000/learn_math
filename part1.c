#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int rand_gen(int min, int max)
{
  return min + rand() % (max + 1 - min);
}



int num_input(int length)
{
  /********************************************
  Function will take in how many digits to read
  (up to 6), and output a single number
  ********************************************/
  
  //make sure the input is between 1 and 6 inclusive
  if (length > 6) length = 6;
  if (length < 1) length = 1;
  
  int digit[6] = {0};//stores up to 6 digits
  int i;//generic variable for use in for loops
  unsigned int input = 0;//stores input from getchar()
  int count = 0; //keeps track of values entered to later multiply my powers of 10
  int output = 0;
  
  for(i = 0; i < length; i++)
    {
      while(1)
	{
	  input = getc(stdin);
	  if (input >= '0' && input <= '9')
	    {
	      digit[i] = input - '0';//convert ascii number value to actual number value
	      count++;
	      break;
	    }
	  //user presed enter without entering at least one number
	  else if ((input == '\r' || input == '\n') && i == 0)
	    {
	      printf("Must enter at least one value\n");
	    }
	  //user pressed enter with at least one number entered
	  else if ((input == '\r' || input == '\n') && count > 0)
	    {
	      i = length;
	      break;
	    }
	  //user entered an input other than numbers
	  else
	    {
	      printf("Incorrect input detected, enter number 0-9\n");
	    }
	}
    }

  //multiplies the individual digits to create a single number
  //ex: x*10^2 + y*10^1 + z*10^0
  for(i = 0; i < count; i++)
    {
      output += digit[i] * pow(10, count - i - 1);
    }
  return output;
}
        

int main()
{
  printf("Welcome to Learn Math Alpha V0.0.1\n");
  printf("Select difficulty\n");
  
  //later on, expand this section to automatically space values instead of hardcoded strings
  printf("| Difficulty | Operators | Value From | Value To |\n");
  printf("+------------+-----------+------------+----------+\n");
  printf("| 1          | +         | 0          | 10       |\n");
  printf("| 2          | +         | 0          | 25       |\n");
  printf("| 3          | +         | 0          | 50       |\n");
  printf("| 4          | +         | 0          | 100      |\n");
  printf("| 5          | +         | 0          | 250      |\n");
  printf("+------------+-----------+------------+----------+\n");
  printf("| 6          | -         | 0          | 10       |\n");
  printf("| 7          | -         | 0          | 25       |\n");
  printf("| 8          | -         | 0          | 50       |\n");
  printf("| 9          | -         | 0          | 100      |\n");
  printf("| 10         | -         | 0          | 250      |\n");
  printf("+------------+-----------+------------+----------+\n");
  printf("| 11         | +/-       | -10        | 10       |\n");
  printf("| 12         | +/-       | -25        | 20       |\n");
  printf("| 13         | +/-       | -50        | 50       |\n");
  printf("| 14         | +/-       | -100       | 100      |\n");
  printf("| 15         | +/-       | -250       | 250      |\n");
  printf("+------------+-----------+------------+----------+\n");

  //reference array for above diagram
  int reference[15][3] = {{0, 0, 10}, {0, 0, 25}, {0, 0, 50}, {0, 0, 100}, {0, 0, 250},
			  {1, -10, 0}, {1, -25, 0}, {1, -50, 0}, {1, -100, 0}, {1, -250, 0},
			  {0, -10, 10}, {0, -25, 25}, {0, -50, 50}, {0, -100, 100}, {0, -250, 250}};
  unsigned int level;
  //function to input and validate character input
  printf("Select a level\n-> ");
  level = num_input(2);
  level--;
  //printf("%d, %d, %d, %d\n", level, reference[level][0], reference[level][1], reference[level][2]);
  
  time_t t;
  int i, j, val[2];
  int operator; //0 - add, 1 - minus, 2 - add/minus (rand)
  srand(time(0));
  FILE *output, *answers;
  output = fopen("output.txt", "w");
  answers = fopen("answers.txt", "w");
  //fprintf(output, "%d%c", var)

  for(i = 0; i < 20; i++)
    {
	//add check for second value to modify the sign
      for(j = 0; j < 2; j++)
	{ 
	  val[j] = rand_gen(reference[level][1], reference[level][2]);
	}
      
      if(val[1] >= 0)
      {
	fprintf(output, "%2d) %d + %d = \t\t\n", i + 1, val[0], val[1]);
      }
      else
      {
  	fprintf(output, "%2d) %d - %d = \t\t\n", i + 1, val[0], abs(val[1]));
      }
      
      fprintf(answers, "%2d)%4d\t\n", i + 1, val[0] + val[1]);
    }

  //close both work file and solution file
  fclose(output);
  fclose(answers);

  return 0;
}
