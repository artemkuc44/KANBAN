#include <stdio.h>
#include <stdlib.h>

#include "library.h"

int main(void)
{
    system("cls");
    int option;

    while (1) //loops until valid path is taken
    {
        option = displayMenu();

        switch(option)
        {
            case 1:
                loadFile(1);

                break;
            case 2:
                loadFile(0);
                break;
            case 3:
                loadFile(1);
                //editList();
                break;
            case 4:
                //
                break;
            case 5:
                //
                break;
            case 6:
                return 0;
                break;
            default:
                printf("Incorrect input, please try again: ");
                system("cls");
                break;
        }
    }
}
