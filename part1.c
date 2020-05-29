#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void rand_gen(int *arr, int min, int max)
{
  //function allows a max and min value, within integer range
  //middle of range:
  // mid = (max + min)/2     (19+(-8))/2 = 11/2 = 5.5 = 5
  //max offset from middle:
  // offset = abs(max - mid) |19 - 5| = 14
  //final equation
  // *var = (rand() % (max + offset)) - offset (63 % (19 + 14)) - 14 = 
  int i, mid, offset;
  // srand(time(0));
  
  mid = (max + min) / 2;
  offset = abs(max - mid);
  for(i = 0; i < 4; i++)
    {
      arr[i] = (rand() % (max + offset)) - offset;
    }
}

int main()
{
  time_t t;
  int i, val[4];
  int operator; //designates whether addition or subtraction is performed
  srand(time(0));
  FILE *output, *answers;
  output = fopen("output.txt", "w");
  answers = fopen("answers.txt", "w");
  //fprintf(output, "%d%c", var)

  for(i = 0; i < 20; i++)
    {
      rand_gen(val, -9, 9);
      fprintf(output, "%2d) %d + %d = \t\t%2d) %d + %d = \n", i*2+1, val[0], val[1], i*2+2, val[2], val[3]);
      fprintf(answers, "%2d)%4d\t%2d)%4d\n", i*2+1, val[0] + val[1], i*2+2, val[2] + val[3]);
    }
  fclose(output);
  fclose(answers);
  return 0;
}
