#include <stdio.h>

#include "defaultBoard.h"
#include "loadFile.h"
#include "displayMenu.h"

int main(void)
{
    int option;
    option = displayMenu();

    switch(option)
    {
        case 1:
        defaultBoard();
            break;
        case 2:
            loadFile();
            break;
        case 3:
            //
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
            // code to loop back to start
            break;


    }
}