#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

struct invention {
    char name[101];
    int type;
    int reliability;
    int powerneeded;
    char status[];
};

int main()
{
    printf("|||WELCOME TO WUNDERTECH DATA TERMINAL|||\n\n");
    printf("Do you want to proceed? (Y/N): \n> ");
    return 0;
}
