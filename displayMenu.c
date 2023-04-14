#include <stdio.h> 
#include "library.h"
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

    return option;
}
int displayEditMenu() {
    int opt;

    // Display menu with 6 options.
    printf("\nMenu:\n");
    printf("1. Edit an item\n");
    printf("2. Add a new item\n");
    printf("3. Delete an item\n");
    printf("4. Return to main menu\n");
    printf("Enter your choice (1-4): ");
    scanf("%d", &opt);

    return opt;
}




