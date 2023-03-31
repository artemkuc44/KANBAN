#include <stdio.h> 
#include "displayMenu.h"

int displayMenu() {
    int option;

    // Display menu with 6 options.
    printf("\nMenu:\n");
    printf("1. Display board\n");
    printf("2. Load board from a file\n");
    printf("3. Edit list\n");
    printf("4. Edit Board\n");
    printf("5. Save board to a file\n");
    printf("6. Quit\n");
    printf("Enter your choice (1-6): ");
    scanf("%d", &option);
//    while(option<1 || option>6)
//    {
//        printf("Incorrect input, please try again: ");
//        scanf("%d", &option);
//    }

    return option;
}
