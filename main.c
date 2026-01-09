#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX 500

struct invention {
    char name[101];
    int type;
    int reliability;
    int energydemand;
    int status;
};

int nameCheck(char *name) {
    for(int i = 0; name[i]; i++) {
        if (!isalpha(name[i]) && name[i] != '_' && name[i] != '-')
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
        scanf("%s", name);
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

    printf("Energy demand (0 - 100): \n");
    tab[*number].energydemand = valueCheck();

    printf("Invention status: \n");
    printf("1 - prototype\n2 - testing\n3 - admissible\n4 - forbidden\n5 - unstable\n\n");
    tab[*number].status = typeCheck();


    (*number)++;
    printf("Invention added to database.\n");

}

int invFind(struct invention tab[], int number) {
    char name[101];
    scanf("%s", name);
    for(int i = 0; i < number; i++) {
        if(strcmp(tab[i].name, name) == 0)
            return i;
    }
    return -1;
}


void invPrint(struct invention tab[], int number) {

    printf("%s:\n", tab[number].name);
    if(tab[number].type == 1)
        printf("Type: mechanical\n");
    else if(tab[number].type == 2)
            printf("Type: chemical\n");
        else if(tab[number].type == 3)
                printf("Type: energetic\n");
            else if(tab[number].type == 4)
                    printf("Type: quantum\n");
                else if(tab[number].type == 5)
                        printf("Type: steam\n");
    printf("Reliability: %d%%\n", tab[number].reliability);
    printf("Energy demand: %d%%\n", tab[number].energydemand);
    if(tab[number].status == 1)
        printf("Status: prototype\n");
    else if(tab[number].status == 2)
            printf("Status: testing\n");
        else if(tab[number].status == 3)
                printf("Status: admissible\n");
            else if(tab[number].status == 4)
                    printf("Status: forbidden\n");
                else if(tab[number].status == 5)
                        printf("Status: unstable\n");


}

void invList(struct invention tab[], int number) {

    printf("\nALL REGISTERED INVENTIONS:\n\n");
    for (int i = 0; i < number; i++) {
        printf("%d. ", i + 1);
        invPrint(tab, i);
    }
}

void invMod(struct invention tab[], int number) {

    printf("Invention type: \n");
    printf("1 - mechanical\n2 - chemical\n3 - energetic\n4 - quantum\n5 - steam\n\n");
    tab[number].type = typeCheck();

    printf("Reliability level (0 - 100): \n");
    tab[number].reliability = valueCheck();

    printf("Energy demand (0 - 100): \n");
    tab[number].energydemand = valueCheck();

    printf("Invention status: \n");
    printf("1 - prototype\n2 - testing\n3 - admissible\n4 - forbidden\n5 - unstable\n\n");
    tab[number].status = typeCheck();

    printf("\nData modified successfully!\n\n");
}

void invDel(struct invention tab[], int *number) {
    int rNumber = invFind(tab, *number);
    if(rNumber == -1) {
        printf("Invention not found!\n");
        return;
    }
    for(int i = rNumber; i < *number - 1; i++) {
        tab[i] = tab[i + 1];
    }
    (*number)--;
    printf("\nData removed successfully!\n\n");
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
    printf("2 - Show the list.\n");
    printf("3 - Search for invention.\n");
    printf("4 - Modify invention data.\n");
    printf("5 - Remove invention data.\n");
    printf("0 - Terminate program.\n");

    struct invention tab[MAX];
    int number = 0;
    int option;
    do {
        printf("\nChoose your option: \n> ");
        while (scanf("%d", &option) != 1) {
            printf("Invalid input! Enter a number:\n> ");
            while (getchar() != '\n');
        }
        switch (option) {
            case 1: {
                newInvention(tab, &number);
                break;
            }
            case 2: {
                invList(tab, number);
                break;
            }
            case 3: {
                printf("Search:\n> ");
                int sNumber = invFind(tab, number);
                if(sNumber == -1) {
                    printf("Invention not found!\n");
                } else
                    invPrint(tab, sNumber);

                break;
            }
            case 4: {
                printf("Enter invention name:\n> ");
                int mNumber = invFind(tab, number);
                if(mNumber == -1) {
                    printf("Invention not found!\n");
                } else
                    invMod(tab, mNumber);

                break;
            }

            case 5: {
                printf("Enter invention name:\n> ");
                invDel(tab, &number);
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
