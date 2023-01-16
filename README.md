# Data Structures
* AVL Tree
* Singly linked list
* Binary Heap (Minimum)

<br>

## AVL Tree
---
| Operation               | Description                             |
|-------------------------|-----------------------------------------|
| tree_make()             | Generate an empty tree                  |
| tree_destroy(Tree*)     |  Free memory allocated for a given tree |
| tree_insert(Tree*, int) | Insert a key to the given tree          |
| tree_inorder()          | Print Tree values in - order            |
| tree_print()            | Prints Tree structure to the console    |

Example:
~~~C
Tree *tree = tree_make(); //Generate an empty tree
tree_insert(tree,4); //insert some values
tree_insert(tree,7);
tree_insert(tree,10);
tree_insert(tree,1);
tree_insert(tree,19);
tree_inorder(tree); //print values in order to the console (4,7,10)
printf("\n");
tree_print(tree); //print tree to console
tree_destroy(tree); //free memory
~~~
Output:
~~~
1->4->7->10->19->

          07          
    04          10    
 01    xx    xx    19 
 ~~~

<br>

## Singly Linked List
---
| Operation                    | Description                             |
|------------------------------|-----------------------------------------|
| list_make()                  | Generate an empty list                  |
| list_destroy(List*)          |  Free memory allocated for a given list |
| list_length(List*)           | Return current length of list           |
| list_retrieve(List*,int)     | Retrieve element at index int           |
| list_insert(List*,void*,int) | Insert data at index int                |
| list_delete(List*,int)       | Delete element at position int          |
| list_print(List*)            | Prints list elements                    |

Example:
~~~C
Tree *tree = tree_make(); //Generate an empty tree
tree_insert(tree,4); //insert some values
tree_insert(tree,7);
tree_insert(tree,10);
tree_insert(tree,1);
tree_insert(tree,19);
tree_inorder(tree); //print values in order to the console (4,7,10)
printf("\n");
tree_print(tree); //print tree to console
tree_destroy(tree); //free memory