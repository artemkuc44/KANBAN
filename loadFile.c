#include <stdio.h>
#include "loadFile.h"
#include "defaultBoard.h"

int loadFile() {
    char filename[MAX_NAME];
    printf("Enter filename: ");
    scanf("%s", &filename);

    FILE *fp = fopen(filename, "r");
    if (fp == NULL) 
    {
        printf("Error: could not open file %s.\n", filename);
        return -1;
    }
    return 0;

    // code to store file in the same directory as the executable.
    
}