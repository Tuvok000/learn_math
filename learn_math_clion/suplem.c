#include "def.h"

//extern char category[][17];

int num_input(int low, int high)
{
    /********************************************************
  //need to fix the stdin flush issue
  //function reads in stream, but doesn't clear it
  //the function will process 4 characters at a time
  //then process the remainder of the stream
  **********************************************************/
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

int basics_format_string_gen(char *format_string, int length, int sign)
{
/*---------------------------------------------------*
 *Generates the string used by latexpdf to create the document
format_string: pointer to string being manipulated
length: number of numbers to be handled by the string (individual %d values)
sign: 1-4, selects the +, -, x, / math symbol for the problems
returns how many characters are in the generated format string
*---------------------------------------------------*/

    int i = 0;
    int total_length = 0;
    char digit[] = "%d";
    char string_begin[] = "%d.) $";
    char string_end[] = "=$";
    char sign_temp[1];
    //generate format string using string concatenation
    //if mixed symbols, use rand function with mod

    //add start of string to external string pointer (func input)
    strncat(format_string, string_begin, 5);
    total_length += 5;

    //generate format string
    while(1) {
        //copy the %d value to the string
        strncat(format_string, digit, 2);
        total_length += 2;
        i++;
        //if amount %d values meets target, end while loop
        if (i == length) break;
        //generate sign and store it into variable
        //unsure how char and char array relate, search it up
        sign_temp[0] = sign_selector(sign);
        //copy sign to format string
        strncat(format_string, sign_temp, 1);
        total_length++;
    }
    //copy string end to
    strncat(format_string, string_end, 2);

    //return the character length of string returned
}

char sign_selector(int sign)
{
    char sign_return = '\0';
    switch (sign)
    {
        case 1:
            sign_return = '+';
            break;
        case 2:
            sign_return = '-';
            break;
        case 3:
            sign_return = 'x';
            break;
        case 4:
            sign_return = '/';
            break;
        case 5://mixed addition subtraction
            //question mark operator, 0 = +, 1 = -
            sign_return = rand() & 1 ? "+" : "-";
            break;
        case 6:
            //question mark operator, 0 = *, 1 = /
            sign_return = rand() & 1 ? "x" : "/";
            break;
        default:
            printf("\n*******Error*******\nError: sign_selector\n\n");
    }
    return sign_return;
}

void problem_gen(int dig, int num, int *arr, int sign)
{
/*--------------------------------------------*
dig: decides max number of digits per number (max 4)
num: how many numbers (max 4)
arr: stores numbers to be passed back
sign: 1-4, selects the +, -, x, / math symbol for the problems
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

void problem_main(int category, int page_count, int level)
{
/*-------------------------------------------------------*
gets input from user about how hard they want the math
problems to be, then repeatedly calls the addition_gen
function to generate the numbers
fills up an array, then writes a tex document with array
values
tex document is processed separately to create the final
math document
category decides the workbook name based on the sign
page_count specifies how many pages to create
20 problems per page, max 20 pages
*-------------------------------------------------------*/

    int page_num, prob_count, i, j;
    //char file_name[23] = {'\0'}; //"Problem Page xx of xx"
    int num_buf[4] = {'\0'};

/*** Verify that page_count is <= 20 ***/
    //open work book based on the category selected
    //create a function to do this later and use string copy to programatically generate the names
    FILE *fp;
    switch(category)
    {
        case 1: //addition
            fp = fopen("Addition_Workbook.tex", "w");
            break;

        case 2:
            fp = fopen("Subtraction_Workbook.tex", "w");
            break;

        case 3:
            fp = fopen("Multiplication_Workbook.tex", "w");
            break;

        case 4:
            fp = fopen("Division_Workbook.tex", "w");
            break;

        case 5:
            fp = fopen("Add_and_Subt_Workbook.tex", "w");
            break;

        case 6:
            fp = fopen("Mult_and_Div_Workbook.tex", "w");
            break;

        default:
            printf("\n*******Error*******\nError: Func; Problem Main, category selection\n\n")
    }

    if(fp == NULL) printf("Error opening file, category %d", category);


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
            addition_gen(problem_gen_ref[level][0], problem_gen_ref[level][1], num_buf);
            //use one of three format strings depending on the number of variables requested
            switch(problem_gen_ref[level][1])
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

void problem_format_string(int count, int category, char *string)
{
    /***************************************************************
     * generates the format string used by problem_main()
     * count: how many numbers per problem
     * category: addition, subtraction, mult., etc
     * string: pointer for final string output
     **************************************************************/
}
  