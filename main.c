#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX 100

struct invention {
    char name[101];
    int type;
    int reliability;
    int powerneeded;
    int status;
};

int nameCheck(char *name) {
    for(int i = 0; name[i]; i++) {
        if(!isalpha(name[i]))
            return 0;
    }
    return 1;
}

int typeCheck() {
    int n;
    while(1) {
        printf("> ");
        scanf("%d", &n);
        if(n == 1 || n == 2 || n == 3 || n == 4 || n == 5)
            return n;
        printf("Invalid entry! Try again: \n");
    }
}

void enterName(char *name) {
    while(1) {
        printf("\n> ");
        scanf("%100s", name);
        if(nameCheck(name))
            return;
        printf("Invalid entry! Try again:\n");
    }
}

int valueCheck() {
    int n;
    while(1) {
        printf("> ");
        scanf("%d", &n);
        if(n >= 0 && n <= 100)
            return n;
        printf("Invalid value! Try again: \n");
    }
}

void newInvention(struct invention tab[], int *number) {
    if(*number >= MAX) {
        printf("No memory left!\n");
        return;
    }

    printf("Enter name: \n");
    enterName(tab[*number].name);

    printf("Invention type: \n");
    printf("1 - mechanical\n2 - chemical\n3 - energetic\n4 - quantum\n5 - steam\n\n");
    tab[*number].type = typeCheck();

    printf("Reliability level (0 - 100): \n");
    tab[*number].reliability = valueCheck();


    (*number)++;
    printf("Invention added to database.\n");

}

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

    struct invention tab[MAX];
    int number = 0;
    int option;
    do {
        printf("> ");
        scanf("%d", &option);
        switch (option) {
            case 1: {
                newInvention(tab, &number);
                break;
            }
            case 2: {
                break;
            }
            case 3: {
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
