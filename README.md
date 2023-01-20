# Data Structures
* AVL Tree
* B Tree
<br>

## AVL Tree
---
| Operation                 | Description                    | Complexity |
|---------------------------|--------------------------------|------------|
| avltree_make()            | Generate an empty Tree         | O(1)       |
| avltree_destroy(Tree*)    | Free memory allocated for Tree | O(n)       |
| avltree_insert(Tree*,int) | Insert int to Tree             | O(logn)    |
| avltree_min(Tree*)        | Return minimum value in Tree   | O(logn)    |
| avltree_max(Tree*)        | Return maximum value in Tree   | O(logn)    |
| avltree_inorder(Tree*)    | In order traversal of the Tree | O(n)       |
| avltree_print(Tree*)      | Prints the tree structure      | O(n)       |

Example:
~~~C
AVLTree *tree = avltree_make(); //Generate an empty tree
avltree_insert(tree,4); //insert some values
avltree_insert(tree,7);
avltree_insert(tree,10);
avltree_insert(tree,1);
avltree_insert(tree,19);
avltree_inorder(tree); //print values in order to the console 
printf("\n");
avltree_print(tree); //print tree to console
avltree_destroy(tree); //free memory
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
