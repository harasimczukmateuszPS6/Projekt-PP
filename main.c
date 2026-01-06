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
        printf("\nLoading...\n\n");
    } else {
        printf("\nTERMINATING...");
        return 0;
    }
    printf("1 - Register new invention.\n");
    printf("0 - Terminate program.\n");
    printf("\nChoose your option:\n");

    int option;
    do {
        printf("> ");
        scanf("%d", &option);
        switch (option) {
            case 1: {
                break;
            }
            case 0: {
                printf("TERMINATING...");
                break;
            }
            default: {
                printf("Unknown option. Try again.\n");
                break;
            }
        }
    } while(option != 0);


    return 0;
}
