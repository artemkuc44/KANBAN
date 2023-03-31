#include <stdio.h>
#include <stdlib.h>

#include "defaultBoard.h"
#include "loadFile.h"
#include "displayMenu.h"

int main(void)
{
    system("cls");
    int option;

    while (1) //loops until valid path is taken
    {
<<<<<<< Updated upstream
        option = displayMenu();
=======
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
            return -1;
            break;
        default:
            break;
>>>>>>> Stashed changes

        switch(option)
        {
            case 1:
                //defaultBoard();
                loadFile(1);

                break;
            case 2:
                loadFile(0);
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
                system("cls");
                break;
        }
    }
}
