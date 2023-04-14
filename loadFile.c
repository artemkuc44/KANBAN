#include "library.h"
void printBoard(node* head){
    while (head != NULL) {
//        if (head->name[0] == ' ') {
//            printf("Device Name: %s\n", head->name);
//        } else {
//            printf("Person Name: %s\n", head->name);
//        }
        printf("%s\n",head->name);
        head = head->next;
    }

}

node* loadFile(int type) {

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

    node* head = NULL;
    node* ptr = NULL;

    char line[MAX_NAME] = "";

    while (fgets(line, MAX_NAME, fp)) {
        line[strcspn(line, "\n")] = '\0';

        node* new_node = malloc(sizeof(node));

        strcpy(new_node->name, line);
        new_node->next = NULL;//marks end of list

        if (head == NULL) {
            head = new_node;
        } else {
            ptr->next = new_node;
        }
        ptr = new_node;

    }
    fclose(fp);

    printf("\n'%s' data:\n\n",filename);
    node* start = head;
    printBoard(start);


    return start;//returns pointer to start of linked list


}
