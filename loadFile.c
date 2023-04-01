#include <stdio.h>
#include <string.h>

#include "loadFile.h"
#include "defaultBoard.h"
#include <stdio.h>

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

int loadFile(int type) {
    char filename[MAX_NAME];
    if(type == 1){
     strcpy(filename,"defaultBoard.txt");
    }
    else{
        printf("Enter filename: ");
        scanf("%s", filename);
        copyFile(filename);//copies file loaded file to defaultBoard.txt ie.loaded board becomes base board
    }


    FILE *fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("Error: could not open file %s\n", filename);
        return -1;
    }
    else{

        char line[50];
        while (fgets(line, 50, fp) != NULL) {
            printf("%s", line);
        }
        fclose(fp);
        return 0;
    }

    // code to store file in the same directory as the executable.

}

