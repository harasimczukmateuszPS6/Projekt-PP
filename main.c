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
    int status;
};

int main()
{
    char proceed;
    printf("|||WELCOME TO WUNDERTECH DATA TERMINAL|||\n\n");
    printf("Do you want to proceed? (Y/N): \n> ");
    scanf("%c", &proceed);
    if (proceed == 'y' || proceed == 'Y') {
        printf("\nLoading...\n");
    } else {
        printf("\nTERMINATING...");
        return 0;
    }


    return 0;
}
