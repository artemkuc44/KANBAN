////
//// Created by akuca on 02/04/2023.
////
//#include <stdio.h>
//
//#include "edit.h"
//
//#include <string.h>
//
//int editList(void) {
//    char listName[50], itemName[100], newItemName[100];
//
//    FILE *file = fopen("defaultBoard.txt", "w");
//    if (file == NULL) {
//        printf("Error opening file\n");
//        return -1;
//    }
//
//    printf("Enter the name of the list to edit: ");
//    scanf("%s", listName);
//
//    char line[100];
//    int listFound = 0;
//    while (fgets(line, sizeof(line), file)) {
//        if (strstr(line, listName) != NULL) {
//            listFound = 1;
//            break;
//        }
//    }
//
//    if (listFound == 0) {
//        printf("List not found\n");
//        fclose(file); //Close the file before returning
//        return -1;
//    }
//
//    printf("Enter the name of the item to edit: ");
//    getchar(); //Consume the newline character left in the input buffer
//    fgets(itemName, sizeof(itemName), stdin);
//    strtok(itemName, "\n"); //Remove the newline character
//
//    printf("Enter the new name of the item: ");
//    fgets(newItemName, sizeof(newItemName), stdin);
//    strtok(newItemName, "\n"); //Remove the newline character
//
//
//    int itemFound = 0;
//    while (fgets(line, sizeof(line), file)) {
//        if (strstr(line, itemName) != NULL) {
//            itemFound = 1;
//            fseek(file, -strlen(line), SEEK_CUR);
//            fprintf(file, "\t%s\n", newItemName);
//            break;
//        }
//    }
//    if (!itemFound) {
//        printf("Item not found in list\n");
//        fclose(file); //Close the file before returning
//        return -1;
//    }
//
//
//    fclose(file);
//
//    return 0;
//}
//
//
//
