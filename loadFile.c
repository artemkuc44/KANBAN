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
} item;

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

    item* head = NULL;
    item* current = NULL;

    char line[MAX_NAME] = "";

    while (fgets(line, MAX_NAME, fp)) {
        line[strcspn(line, "\n")] = '\0';//replaces newline that fgets put there

        if (line[0] != '\t') {
            item* new_item = malloc(sizeof(item));
            new_item->device[0] = '\0'; //removes garbage data


            strcpy(new_item->name, line);
            new_item->next = NULL;


            if (head == NULL) {//head will be null during first iteration
                head = new_item;//assigns
            } else {
                current->next = new_item;
            }
            current = new_item;
        } else {
            strcpy(current->device, line);
        }
    }

    fclose(fp);

    //Print

    while (head != NULL) {
        printf("%s%s\n", head->name, head->device);
        head = head->next;


    }

    //Free
    while (head != NULL) {
        item* next = head->next;
        free(head);
        head = next;
    }
}

