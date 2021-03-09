#ifndef DEF_H
#define DEF_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

static char category[][17] = {"Addition", "Subtraction",
		       "Add + Sub Mixed", "Multiplication",
		       "Division", "Mult + Div Mixed"};

static char addition_tex_open[] = "\\documentclass{amsart}\n\\begin{document}\n\\begin{tabular}{r@{ }p{4.5cm}r@{ }l}\n";
static char addition_gen_ref[10][2] = {{1, 2}, {2, 2}, {3, 2},
									   {1, 3}, {2, 3}, {3, 3}, 
									   {1, 4}, {2, 4}, {3, 4}, {4, 4}};
static char addition_format_string[3][20] = {
	"%d.)&$%d+%d=$", "%d.)&$%d+%d+%d=$", "%d.)&$%d+%d+%d+%d=$"};
}
/*--------------------*
Function Definitions
/*--------------------*/

int num_input(int low, int high);
void addition_gen(int dig, int num, int *arr);
void addition_main(int page_count, int level);


#endif
