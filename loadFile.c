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
    }

    FILE* fp = fopen(filename, "r");
    if (!fp) {
        printf("Error could not open file %s\n", filename);
        return;
    }

    Item* head = NULL;
    Item* current = NULL;

    char line[MAX_NAME] = "";//assigning to "" removes junk code
    char name[MAX_NAME] = "";//^^
    char device[MAX_NAME] = "";//^^

    while (fgets(line, MAX_NAME, fp)) {
        line[strcspn(line, "\n")] = '\0';//remove newline strcspn used to find index

        if (line[0] != '\t') {

            Item* new_item = malloc(sizeof(Item));//allocates memory for new_item variable
            if (new_item == NULL) {
                printf("Error out of memory\n");
                break;
            }
            strcpy(new_item->name, name);
            new_item->next = NULL;
            if (head == NULL) {
                head = new_item;
            } else {
                current->next = new_item;
            }
            current = new_item;
            strcpy(name, line);//copies to name array

            device[0] = ' ';//clears device string
        } else {//continuation of device adds to current item
            strcpy(device, line);//copies to device array
            strcat(current->device, "\n");
            strcat(current->device, device);
        }
    }

    fclose(fp);

    //Print and traverse
    current = head;
    while (current != NULL) {
        printf("%s\n%s\n", current->name, current->device);
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










