#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "loadFile.h"
#include "defaultBoard.h"
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
        //copyFile(filename);
    }

    FILE* fp = fopen(filename, "r");
    if (!fp) {
        printf("Error could not open file %s\n", filename);
        return;
    }

    Item* head = NULL;
    Item* current = NULL;

    char line[MAX_NAME];
    char name[MAX_NAME] = "";
    char device[MAX_NAME] = "";

    while (fgets(line, MAX_NAME, fp)) {
        if (line[0] != '\t') {
            // new name, create new item and add to list
            Item* item = malloc(sizeof(Item));
            if (item == NULL) {
                printf("Error out of memory\n");
                break;
            }
            strcpy(item->name, name);
            item->next = NULL;
            if (head == NULL) {
                head = item;
            } else {
                current->next = item;
            }
            current = item;

            //reset name and device strings
            strcpy(name, line);
            name[strcspn(name, "\n")] = '\0';
            device[0] = '\0';
        } else {
            //continuation of device, append to current item
            strcpy(device, line);
            device[strcspn(device, "\n")] = '\0';
            strcat(current->device, "\n");
            strcat(current->device, device);
        }
    }

    fclose(fp);

    //Print and traverse
    current = head;
    while (current != NULL) {
        printf("%s:\n%s\n", current->name, current->device);
        current = current->next;
    }

    //Free memory
    current = head;
    while (current != NULL) {
        Item* next = current->next;
        free(current);
        current = next;
    }
}








