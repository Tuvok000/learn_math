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
  time_t t;
  int i, j, val[2];
  int operator; //designates whether addition or subtraction is performed
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
  return 0;
}
