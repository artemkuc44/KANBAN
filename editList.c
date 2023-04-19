
#include "library.h"

int deleteItem(node* head){
    node* owner = head;
    char itemName[MAX_NAME];
    char tempItemName[MAX_NAME];

    printf("owner:  %s\n",owner->name);

    //clear input buffer
    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    printf("Enter the name of the item you would like to delete: ");
    fgets(tempItemName, MAX_NAME, stdin);
    tempItemName[strcspn(tempItemName, "\n")] = '\0'; // remove newline character

    strcpy(itemName, "    ");
    strcat(itemName,tempItemName);

    head = head->next;

    while(head->next != NULL && strcmp(head->name,itemName) != 0 && head->name[0] == ' '){
        head = head->next;
    }
    if(strcmp(head->name,itemName) == 0){
        node* temp = owner;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = head->next;
        printf("Item named '%s' deleted\n",head->name+4);
        free(head);
    }else{
        printf("Item named '%s' not found\n",tempItemName);
        printf("Press any key to continue...");
        getchar();

        return -1;
    }
    return 0;

}

int addItem(node* head){
    //char test[4];
    node* owner = head;
    char newItemName[MAX_NAME];

    // clear input buffer
    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    printf("Enter the name of the item you would like to add: ");
    fgets(newItemName, MAX_NAME, stdin);
    newItemName[strcspn(newItemName, "\n")] = '\0'; // remove newline character

    node* new_node = malloc(sizeof(node));
    strcpy(new_node->name, "    "); // add indentation
    strcat(new_node->name, newItemName);
    new_node->next = NULL;

    node* current = owner;
    node* temp;


    //printf("test == %d",strcmp(test,"    "));
    while (current->next != NULL && current->name[0] != ' '){
        current = current->next;
        temp = current->next;
        //memcpy(test,current->next->name,4);
    }
    current->next = new_node;
    new_node->next = temp;//ammends the previously broken link

    return 0;
}


int editItem(node* head){
    node* owner = head;
    char itemName[MAX_NAME];
    char tempItemName[MAX_NAME];
    char newItemName[MAX_NAME];

    printf("owner:  %s\n",owner->name);

    //clear input buffer
    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    printf("Enter the name of the item you would like to edit: ");
    fgets(tempItemName, MAX_NAME, stdin);
    tempItemName[strcspn(tempItemName, "\n")] = '\0'; // remove newline character

    strcpy(itemName, "    ");
    strcat(itemName,tempItemName);

    while(head != NULL && strcmp(head->name,itemName) != 0){
        head = head->next;
    }
    if(head == NULL){
        printf("Item named '%s' not found\n",tempItemName);
        printf("Press any key to continue...");
        getchar();

        return -1;
    }else{
        printf("Item named '%s' found\n",head->name+4);
    }
    //read in the new item name
    printf("Enter the new name for the item: ");

    fgets(tempItemName, MAX_NAME, stdin);
    tempItemName[strcspn(tempItemName, "\n")] = '\0';
    strcpy(newItemName, "    ");
    strcat(newItemName,tempItemName);

    strcpy(head->name, newItemName);
    return 0;
}


int editList(node* head) {
    int option;
    char listName[MAX_NAME];
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
    while (1) //loops until valid path is taken
    {
        option = displayEditListMenu();

        switch(option)
        {
            case 1:
                editItem(head);
                break;
            case 2:
                addItem(head);
                break;
            case 3:
                deleteItem(head);
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
