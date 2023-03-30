//
// Created by rebec on 30/03/2023.
//

#ifndef ASSIGNMENT3_DEFAULTBOARD_H
#define ASSIGNMENT3_DEFAULTBOARD_H

#define MAX_NAME 20

// Default board.
typedef struct
{
    char name[MAX_NAME];
    char item[MAX_NAME];
} Person_t;

int defaultBoard(void);

#endif //ASSIGNMENT3_DEFAULTBOARD_H
