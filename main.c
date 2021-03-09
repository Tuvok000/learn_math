#include "def.h"

#define CAT_RANGE_HIGH 6
#define CAT_RANGE_LOW 1

extern char category[][17];

int main()
{
  int i;
  int page_count;
  int level;

  srand(time(NULL));
  
  printf("Welcome to Learn Math Alpha V0.0.1\n");
  printf("Select module\n");

  //print categories defined in def.h
  for(i = 0; i < 6; i++)
    {
      printf("%d - %s\n", i+1, category[i]);
    }

  //wait for user to select a category
  i = num_input(CAT_RANGE_LOW, CAT_RANGE_HIGH);
  
  switch(i)
  {
    //addition case, calls addition_main(int) function
    case 1:
      printf("Please enter number of pages to generate\n(1-20) ");
      page_count = num_input(1, 20);
      printf("Please enter Level\n(1-10) \n");
      level = num_input(1, 10);
      //subtract 1 frob level for easier processing
      addition_main(page_count, --level);
      break;
    default:
      printf("stuff gone wrong\n");
      break;    
  }

  printf("%d done\n", i);
  
  return 0;
}
