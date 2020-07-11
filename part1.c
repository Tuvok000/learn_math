#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void rand_gen(int *var, int min, int max)
{
  //function allows a max and min value, within integer range
  //middle of range:
  // mid = (max + min)/2     (19+(-8))/2 = 11/2 = 5.5 = 5
  //max offset from middle:
  // offset = abs(max - mid) |19 - 5| = 14
  //final equation
  // *var = (rand() % (max + offset)) - offset (63 % (19 + 14)) - 14 = 

  int mid, offset;
  
  mid = (max + min) / 2;
  offset = abs(max - mid);
  *var = (rand() % (max + offset)) - offset;
}

int main()
{
  printf("Welcome to Learn Math Alpha V0.0.1");
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
			  {1, 0, 10}, {1, 0, 25}, {1, 0, 50}, {1, 0, 100}, {1, 0, 250},
			  {2, -10, 10}, {2, -25, 25}, {2, -50, 50}, {2, -100, 100}, {2, -250, 250}};
  unsigned int level;
  level = getc();
  printf("%d, %d, %d, %d\n", level, reference[level][0], reference[level][1], reference[level][2]);
  /*
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
      for(j = 0; j < 2; j++) rand_gen(val[j], -9, 9);
      if(val[1] >= 0)
      {
	fprintf(output, "%2d) %d + %d = \t\t", i*2+1, val[0], val[1]);
      }
      else
      {
  	fprintf(output, "%2d) %d -
fprintf(answers, "%2d)%4d\t", i*2+1, val[0] + val[1]);
    }

  //close both work file and solution file
  fclose(output);
  fclose(answers);
  */
  return 0;
}
