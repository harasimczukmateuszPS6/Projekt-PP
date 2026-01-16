#define MAX 500

int optionMenu() {


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

                case 6: {
                    saveFile(tab, number);
                    break;
                }

                case 7: {
                    loadFile(tab, &number);
                    break;
                }

                case 8: {
                    optionsList();
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
}
