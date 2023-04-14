#include "library.h"


item* loadFile(int type) {
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
        return 0;
    }

    item* head = NULL;
    item* current = NULL;

    char line[MAX_NAME] = "";

    while (fgets(line, MAX_NAME, fp)) {
        line[strcspn(line, "\n")] = '\0';//replaces newline that fgets put there


        item* new_item = malloc(sizeof(item));

        strcpy(new_item->name, line);
        new_item->next = NULL;

        if (head == NULL) {//head will be null during first iteration
            head = new_item;//creates start of list
        } else {
            current->next = new_item;
        }
        current = new_item;//needed in else{


    }
    fclose(fp);

    printf("\n'%s' data:\n\n",filename);
    int count = 0;
    while (head != NULL) {

        printf("%s\n", head->name);
        count ++;

        head = head->next;
    }
    printf("%d",count);

    //Free
    while (head != NULL) {
        item* next = head->next;
        free(head);
        head = next;
    }
    return head;
}