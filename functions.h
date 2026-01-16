#include "typedefs.h"
#define MAX 500


int nameCheck(char *name) {
    for(int i = 0; name[i]; i++) {
        if (!isalpha(name[i]) && name[i] != '_' && name[i] != '-')
            return 0;
    }
    return 1;
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

int valueCheck(int min, int max) {
    int n;
    printf("> ");
    while(scanf("%d", &n) != 1 || n < min || n > max) {
            printf("Invalid value! Try again: \n> ");
            while (getchar() != '\n');
    }
    while (getchar() != '\n');
    return n;

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
    tab[*number].type = valueCheck(1, 5);

    printf("Reliability level (0 - 100): \n");
    tab[*number].reliability = valueCheck(0, 100);

    printf("Energy demand (0 - 100): \n");
    tab[*number].energydemand = valueCheck(0, 100);

    printf("Invention status: \n");
    printf("1 - prototype\n2 - testing\n3 - admissible\n4 - forbidden\n5 - unstable\n\n");
    tab[*number].status = valueCheck(1, 5);


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
    printf("Type: %s\n", typeNames[tab[number].type]);
    printf("Reliability: %d%%\n", tab[number].reliability);
    printf("Energy demand: %d%%\n", tab[number].energydemand);
    printf("Status: %s\n", statusNames[tab[number].status]);


}

int invCompare(const void *a, const void *b) {
    const struct invention *x = (const struct invention*)a;
    const struct invention *y = (const struct invention*)b;
    return strcmp(x->name, y->name);
}

void invList(struct invention tab[], int number) {

    qsort(tab, number, sizeof(struct invention), invCompare);

    printf("\nALL REGISTERED INVENTIONS:\n\n");
    for (int i = 0; i < number; i++) {
        printf("%d. ", i + 1);
        invPrint(tab, i);
    }
}

void invMod(struct invention tab[], int number) {

    printf("Invention type: \n");
    printf("1 - mechanical\n2 - chemical\n3 - energetic\n4 - quantum\n5 - steam\n\n");
    tab[number].type = valueCheck(1, 5);

    printf("Reliability level (0 - 100): \n");
    tab[number].reliability = valueCheck(0, 100);

    printf("Energy demand (0 - 100): \n");
    tab[number].energydemand = valueCheck(0, 100);

    printf("Invention status: \n");
    printf("1 - prototype\n2 - testing\n3 - admissible\n4 - forbidden\n5 - unstable\n\n");
    tab[number].status = valueCheck(1, 5);

    printf("\nData modified successfully!\n\n");
}

void invDel(struct invention tab[], int *number) {
    int rNumber = invFind(tab, *number);
    if(rNumber == -1) {
        printf("Invention not found!\n");
        return;
    }
    if(tab[rNumber].status == 4 || tab[rNumber].status == 5) {
        printf("Failed to remove data!\n");
        return;
    }
    for(int i = rNumber; i < *number - 1; i++) {
        tab[i] = tab[i + 1];
    }
    (*number)--;
    printf("\nData removed successfully!\n\n");
}

void optionsList() {
    printf("1 - Register new invention.\n");
    printf("2 - Show the list.\n");
    printf("3 - Search for invention.\n");
    printf("4 - Modify invention data.\n");
    printf("5 - Remove invention data.\n");
    printf("6 - Save list to a file.\n");
    printf("7 - Show this again.\n");
    printf("0 - Terminate program.\n");
}

void saveFile(struct invention tab[], int number) {
    FILE *f = fopen("inventions.txt", "w");
    if (!f) {
        printf("Cannot open file for writing!\n");
        return;
    }

    for (int i = 0; i < number; i++) {
        fprintf(f, "%d. %s;%d;%d;%d;%d\n",
                number,
                tab[i].name,
                tab[i].type,
                tab[i].reliability,
                tab[i].energydemand,
                tab[i].status);
    }

    fclose(f);
    printf("\nData saved to file.\n");
}


