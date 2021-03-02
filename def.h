#ifndef DEF_H
#define DEF_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static char category[][17] = {"Addition", "Subtraction",
		       "Add + Sub Mixed", "Multiplication",
		       "Division", "Mult + Div Mixed"};

/*--------------------*
Function Definitions
/*--------------------*/

int num_input(int low, int high);
void addition(int level, int num, int *arr);












#endif
