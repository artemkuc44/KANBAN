#include <stdio.h>
#include <stdlib.h>

#include "library.h"

int main(void)
{
    node* start = NULL;
    system("cls");
    int option;

    while (1) //loops until valid path is taken
    {
        option = displayMenu();
        switch(option)
        {
            case 1:
                if(start == NULL){
                    start = loadFile(option);
                }
                else{
                    printBoard(start);
                }
                break;
            case 2:
                start = loadFile(option);
                break;
            case 3:
                if(start == NULL){
                    start = loadFile(1);

                }
                editList(start);
                printBoard(start);
                break;
            case 4:
                if(start == NULL){
                    start = loadFile(1);
                }
                editBoard(&start);
                printf("start->name = %s\n",start->name);
                printBoard(start);
                break;
            case 5:
                //
                break;
            case 6:
                return 0;
                break;
            default:
                printf("Incorrect input, please try again: ");
                int c;
                while ((c = getchar()) != '\n' && c != EOF);
                break;
        }
    }
}
