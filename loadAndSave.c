#include "library.h"
void printBoard(node* head){
    while (head != NULL) {
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

    node* head = NULL;//pointer to he first node of the linked list
    node* ptr = NULL;//pointer used to traverse/create the linked list

    char line[MAX_NAME] = "";

    while (fgets(line, MAX_NAME, fp)){//fgets returns null when end of file is reached
        line[strcspn(line, "\n")] = '\0';

        node* new_node = malloc(sizeof(node));//allocates memory for a new node

        strcpy(new_node->name, line);//copies the read in line to name variable in the new node
        new_node->next = NULL;//marks end of list

        if (head == NULL) {//head==NULL when list is empty
            head = new_node;//assigns head to new_node (the start node)
        } else {//else when list isnt empty
            ptr->next = new_node;//pushes ptr->next to the new_node, marking end of the list.(ptr->next) always null
        }
        ptr = new_node;//pushes current ptr to new node also (needed for next iteration)
    }
    fclose(fp);

    printf("\n'%s' data:\n\n",filename);
    node* start = head;//returns the start pointer of the linked list(= to head)
    printBoard(start);


    return start;//returns pointer to start of linked list


}
void saveBoard(node * head){
    char filename[MAX_NAME];
    printf("Enter the name of the file you would like to save the board to:");
    scanf("%s",filename);
    FILE *fp = fopen(filename, "w");
    if (!fp) {
        printf("Error could not open file %s\n", filename);
        return;
    }

    node* current = head;
    while (current != NULL) {
        fprintf(fp, "%s\n", current->name);
        current = current->next;
    }

    fclose(fp);

    printf("\nSuccessfully saved to '%s'\n",filename);
}

void ascii1(){
    printf("\n"
           "                           _  __      _      _   _      ____      _      _   _     \n"
           "                          |\"|/ /  U  /\"\\  u | \\ |\"|  U | __\")uU  /\"\\  u | \\ |\"|    \n"
           "                          | ' /    \\/ _ \\/ <|  \\| |>  \\|  _ \\/ \\/ _ \\/ <|  \\| |>   \n"
           "                        U/| . \\\\u  / ___ \\ U| |\\  |u   | |_) | / ___ \\ U| |\\  |u   \n"
           "                          |_|\\_\\  /_/   \\_\\ |_| \\_|    |____/ /_/   \\_\\ |_| \\_|    \n"
           "                        ,-,>> \\\\,-.\\\\    >> ||   \\\\,-._|| \\\\_  \\\\    >> ||   \\\\,-. \n"
           "                         \\.)   (_/(__)  (__)(_\")  (_/(__) (__)(__)  (__)(_\")  (_/  \n");
}
void ascii2(){
    printf(" __");
    printf("\n");
    printf("'. \\");
    printf("\n");
    printf(" '- \\");
    printf("\n");
    printf("  / /_         .---.");
    printf("\n");
    printf(" / | \\\\,.\\/--.//    )");
    printf("\n");
    printf(" |  \\/        )/  /");
    printf("\n");
    printf("  \\  ' ^ ^    /    )____.----..  6");
    printf("\n");
    printf("   '.____.    .___/            \\._)");
    printf("\n");
    printf("      .\\/.");
    printf("\n");
    printf("       '\\                       /");
    printf("\n");
    printf("       _/ \\/    ).        )    (");
    printf("\n");
    printf("      /#  .!    |        /\\    /");
    printf("\n");
    printf("      \\  C// #  /'-----''/ #  /");
    printf("\n");
    printf("   .   'C/ |    |    |   |    |");
    printf("\n");
    printf("   \\), .. .'OOO-'. ..'OOO'OOO-'. ..\\(,");
}