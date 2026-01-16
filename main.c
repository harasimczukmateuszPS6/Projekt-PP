#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "functions.h"
#include "switch.h"

#define MAX 500


int main()
{
    char proceed;
    printf("|||WELCOME TO WUNDERTECH DATA TERMINAL|||\n\n");
    printf("Do you want to proceed? (Y/N): \n> ");
    scanf("%c", &proceed);
    if (proceed == 'y' || proceed == 'Y') {
        printf("\nLoading...\n\n");
    } else {
        printf("\nTERMINATING...");
        return 0;
    }
    optionsList();

    optionMenu();

    return 0;
}
