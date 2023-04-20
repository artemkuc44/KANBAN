#include "library.h"
int deleteList(node **head){
    char name[MAX_NAME];
    printf("Enter the name to delete:");
    int c;
    while ((c = getchar()) != '\n' && c != EOF); // clear input buffer
    fgets(name, MAX_NAME, stdin);
    name[strcspn(name, "\n")] = '\0'; // remove newline character
    strcat(name, ":");

    node *previous;
    node *current = *head;

    //Special case deleting the first node, required as when doing so the pointer to the start of the linked list need to be updated
    if (strcmp(current->name, name) == 0) {
        *head = (*head)->next;//moves the head to the next node
        free(current);//frees previous head

        while (*head != NULL && (*head)->name[0] == ' ') {//while not end of list and the node name begins with a space(item name)
            node *temp = *head;//creates temporary node points to the address of head
            *head = temp->next;//moves head to the next node address
            free(temp);//frees memory pointed to by temp
        }
        return 0;
    }
    //traverses the list while not end and name isnt found
    while (current != NULL && strcmp(current->name, name) != 0) {
        previous = current;
        current = current->next;
    }
    if (current == NULL) {
        printf("Name not found in list\n");
        return -1;
    }
    //"deletes" the list name
    previous->next = current->next;
    free(current);

    //"deletes" the list items
    while (previous->next != NULL && previous->next->name[0] == ' ') {
        node *temp = previous->next;//creates temp pointer to previous->next address (current)
        previous->next = temp->next;//assigns current address to the next node
        free(temp);//frees pointer to current address
    }

    return 0;
}


int addName(node **head) {
    char newName[MAX_NAME];
    printf("Enter the name to add:");

    int c;
    while ((c = getchar()) != '\n' && c != EOF); // clear input buffer
    fgets(newName, MAX_NAME, stdin);
    newName[strcspn(newName, "\n")] = '\0'; // remove newline character
    strcat(newName,":");
    node *new_node = malloc(sizeof(node));
    if (new_node == NULL) {
        printf("Error: unable to allocate memory for new node\n");
        return -1; // return an error code to indicate failure
    }

    strcpy(new_node->name, newName);
    new_node->next = *head;
    *head = new_node;



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
                break;
            case 3:
                deleteList(head);
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