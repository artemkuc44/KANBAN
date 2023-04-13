#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "library.h"
#define MAX_NAME 20


void copyFile(const char* name) {
    // Open the input file for reading
    FILE* input = fopen(name, "r");
    if (input == NULL) {
        printf("Error: failed to open input file %s\n", name);
        return;
    }

    // Open the output file for writing
    FILE* output = fopen("defaultBoard.txt", "w");
    if (output == NULL) {
        printf("Error: failed to open output file defaultBoard.txt\n");
        fclose(input);
        return;
    }

    // Read from input file and write to output file until EOF is reached
    int c;
    while ((c = fgetc(input)) != EOF) {
        fputc(c, output);
    }

    // Close the files
    fclose(input);
    fclose(output);
}




typedef struct item {
    char name[MAX_NAME];
    char device[MAX_NAME];
    struct item* next;
} Item;

void loadFile(int type) {
    char filename[MAX_NAME];
    if (type == 1) {
        strcpy(filename, "defaultBoard.txt");
    } else {
        printf("Enter filename: ");
        scanf("%s", filename);
    }

    FILE* fp = fopen(filename, "r");
    if (!fp) {
        printf("Error could not open file %s\n", filename);
        return;
    }

    Item* head = NULL;
    Item* current = NULL;

    char line[MAX_NAME] = "";


    while (fgets(line, MAX_NAME, fp)) {
        line[strcspn(line, "\n")] = '\0';

        if (line[0] != '\t') {
            // Allocate memory for a new item
            Item* new_item = malloc(sizeof(Item));
            if (new_item == NULL) {
                printf("Error out of memory\n");
                break;
            }
            // Set the name and device fields of the new item
            strcpy(new_item->name, line);
            new_item->device[0] = '\0'; // Initialize the device field to an empty string
            new_item->next = NULL;


            if (head == NULL) {//head will be null during first iteration
                head = new_item;//assigns
            } else {
                current->next = new_item;
            }
            current = new_item;
        } else {
            //Append the device line to the current item's device field
            strcat(current->device, line);
            strcat(current->device, "\n");
        }
    }

    fclose(fp);

    // Print the items in the list
    current = head;
    while (current != NULL) {
        printf("%s%s\n", current->name, current->device);
        current = current->next;
    }

    // Free the memory allocated for the items in the list
    current = head;
    while (current != NULL) {
        Item* next = current->next;
        free(current);
        current = next;
    }
}

