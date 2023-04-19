#include "library.h"
int addName(node **head) {
    char newName[MAX_NAME];
    printf("Enter the name to add to the start of the list:");

    int c;
    while ((c = getchar()) != '\n' && c != EOF); // clear input buffer
    fgets(newName, MAX_NAME, stdin);
    newName[strcspn(newName, "\n")] = '\0'; // remove newline character

    node *new_node = malloc(sizeof(node));
    if (new_node == NULL) {
        printf("Error: unable to allocate memory for new node\n");
        return -1; // return an error code to indicate failure
    }

    strcpy(new_node->name, newName);
    new_node->next = *head;
    *head = new_node;

    printf("new_node->name = %s\n", new_node->name);
    printf("new_node->next->name = %s\n", new_node->next->name);
    printf("head->name = %s\n", (*head)->name);
    printf("head->next->name = %s\n", (*head)->next->name);

    return 0;
}

int editName(node * head){
    char listName[MAX_NAME];
    char newListName[MAX_NAME];
    printf("Enter the name for the list that needs to be edited:");
    scanf("%s",listName);
    strcat(listName,":");
    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    while(head != NULL && strcmp(head->name,listName) != 0){
        head = head->next;
    }
    if(head == NULL){
        printf("List named '%s' not found\n",listName);
        printf("Press any key to continue...");
        getchar();

        return -1;
    }else{
        printf("List named '%s' found\n",head->name);
    }
    printf("Enter the new name for the list:");

    fgets(newListName, MAX_NAME, stdin);
    newListName[strcspn(newListName, "\n")] = '\0'; // remove newline character

    strcat(newListName,":");
    strcpy(head->name,newListName);
    return 0;
}

int editBoard(node ** head){
    int option;
    while (1) //loops until valid path is taken
    {
        option = displayEditBoardMenu();

        switch(option)
        {
            case 1:
                editName(*head);
                break;
            case 2:
                addName(head);
                printf("head->name = %s\n",(*head)->name);
                break;
            case 3:
                break;
            case 4:
                return 0;
            default:
                printf("Incorrect input, please try again: ");
                int c;
                while ((c = getchar()) != '\n' && c != EOF);
                break;
        }
    }
}