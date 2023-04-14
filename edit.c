
#include "library.h"
node* editItem(node* head){
    node* owner = head;
    char itemName[MAX_NAME];
    char tempItemName[MAX_NAME];
    char newItemName[MAX_NAME];

    printf("owner:  %s\n",owner->name);

    // clear input buffer
    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    printf("Edit the name of the item you would like to edit: ");
    fgets(tempItemName, MAX_NAME, stdin);
    tempItemName[strcspn(tempItemName, "\n")] = '\0'; // remove newline character

    strcpy(itemName, "    ");
    strcat(itemName,tempItemName);

    // find the node to edit
    while(strcmp(head->name,itemName) != 0){
        head = head->next;
    }
    printf("Device named: '%s' found\n",head->name+4);//+4 to not print the formatting spaces

    //read in the new item name
    printf("Enter the new name for the item: ");

    fgets(tempItemName, MAX_NAME, stdin);
    tempItemName[strcspn(tempItemName, "\n")] = '\0';
    strcpy(newItemName, "    ");
    strcat(newItemName,tempItemName);

    strcpy(head->name, newItemName);
    return owner;
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
        option = displayEditMenu();

        switch(option)
        {
            case 1:
                editItem(head);
                break;

            case 2:
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
