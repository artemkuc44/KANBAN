//
// Created by akuca on 13/04/2023.
//

#ifndef ASSIGNMENT3_LIBRARY_H
#define ASSIGNMENT3_LIBRARY_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_NAME 50

typedef struct node {
    char name[MAX_NAME];
    struct node* next;
} node;


void printBoard(node * head);
node* loadFile(int type);

int editItem(node * head);
int addItem(node * head);
int deleteItem(node * head);

int editList(node* head);
int displayMenu();
int displayEditMenu();

#endif //ASSIGNMENT3_LIBRARY_H

