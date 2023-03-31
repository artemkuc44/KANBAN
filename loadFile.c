#include <stdio.h>
#include <string.h>

#include "loadFile.h"
#include "defaultBoard.h"

int loadFile(int type) {
    char filename[MAX_NAME];
    if(type == 1){
     strcpy(filename,"defaultBoard.txt");
    }
    else{
        printf("Enter filename: ");
        scanf("%s", filename);
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
