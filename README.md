# Data Structures
* AVL Tree
* B Tree
<br>

## AVL Tree
---
| Operation              | Description                    | Complexity |
|------------------------|--------------------------------|------------|
| tree_make()            | Generate an empty Tree         | O(1)       |
| tree_destroy(Tree*)    | Free memory allocated for Tree | O(n)       |
| tree_insert(Tree*,int) | Insert int to Tree             | O(logn)    |
| tree_min(Tree*)        | Return minimum value in Tree   | O(logn)    |
| tree_max(Tree*)        | Return maximum value in Tree   | O(logn)    |
| tree_inorder(Tree*)    | In order traversal of the Tree | O(n)       |
| tree_print(Tree*)      | Prints the tree structure      | O(n)       |

Example:
~~~C
Tree *tree = tree_make(); //Generate an empty tree
tree_insert(tree,4); //insert some values
tree_insert(tree,7);
tree_insert(tree,10);
tree_insert(tree,1);
tree_insert(tree,19);
tree_inorder(tree); //print values in order to the console 
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

## B - Tree
---
