#  Autumn 2023 Software engineering project 1 Kanban board

## Assignment 3 - 2 person group project

Software Engineering Project 3 – Kanban 

The project consists of 5 c files (main,2\*edit files -board and list,a file with the display menus and a load and save file), and a header file making the c files contents accessible within the main. 

The header file contains the struct of the linked list, the list names and item names are stored in one linked list. 

How do you load a board? 

This is done within the loadAndSave file, the loadFile function takes as an argument a type, if the function is called with type 1 it loads the default board (from the notes), and returns the start pointer of the linked list. The load file may also be called with a different type, this allows the user to enter the file from which they would like to load the board to the linked list. 

The file is read in line by line using fgets, a new node is created and the new\_node->name is assigned to the name read in from the line. 

If the list is empty head is assigned to the new node, marking the start of the list and then a pointer is also assigned to this node(needed for the next iteration), If head is not NULL, it means that there are already nodes in the list, so it sets the next pointer of the current node (pointed to by ptr) to new\_node, thus adding the new node to the end of the list. It then updates the ptr pointer to point to new\_node also. The function then returns the head pointer, making the linked list accessible globally. 

How did you edit lists and items? 

Lists and items are edited in the editBoard.c and editList.c files.  

For editing the list, the user is firstly asked for a list name, and finds it. 

deleteItem(node\* head): This function deletes a specific item from the named. It asks the user for the name of the item to be deleted, searches that list for that item, and deletes it if it is found. 

addItem(node\* head): This function adds a new item to the linked list. It prompts the user for the name of the item to be added, creates a new node for the item, and adds it to the start of the list. 

editItem(node\* head): This function edits the name of a specific item from the named list. It prompts the user for the name of the item to be edited, searches the named list for that item, and then prompts the user for the new name of the item. 

For editing the board: 

DeleteList: function takes a pointer to a pointer to the head node of the list as a parameter. It prompts the user to enter the name of the list to be deleted, and then traverses the list to find that node. If the node is found, it removes the node from the list and frees its memory. If the node had items associated with it, it also removes those items from the list. Point by reference is needed to update the linked list globally.  

The addName function takes a pointer to a pointer to the head node of the list as a parameter. It prompts the user to enter the name of the new node, creates a new node with that name, and adds it to the beginning of the linked list. 

The editName function takes a pointer to the head node of the list as a parameter. It prompts the user to enter the name of the node to be edited, and then traverses the list to find that node. If the node is found, it prompts the user to enter a new name for the node and updates the node's name field with the new name. 

The editBoard function takes a pointer to a pointer to the head node of the list as a parameter. It displays a menu of options for editing the list and prompts the user to choose an option. It then calls the appropriate function based on the user's choice. If the user chooses to exit the menu, the function returns 0. 

How do you save a board? 

When the user decides to save the board, the function saveBoard() takes in the start pointer of the linked list and iterates through each node, writing the contents of its name variable to a file, one line at a time, using the fprintf() function. If the inputted filename isn’t found it creates a new file, storing the list in it. 

What is the ascii art about? 

The project includes 2 ascii arts, 1 acts as a logo and printf out “KANBAN”. the 2nd ascii is an image of an elephant. 
