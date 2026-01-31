//Tree is a collection of nodes(vertices) and edges
//for n nodes there are n-1 edges
/*
                       level       height
            A            1           0
          / | \
         /  |  \
        B   C   D        2           1
       / \     / \
      E   F   G   H      3           2
      |      /|\
      I     J K L        4           3
*/
//subtree is a tree with a node as root

//Terminologies:
//Root- node with no parent
//Parent- node with child
//Child- node with parent
//Sibling- nodes with same parent
//Leaf/external node- node with no child
//internal node- node with child
//descendants- nodes that are below a node
//Ancestors- nodes from that node to root node
//degree of a node - number of children of a node
//Height of a node - number of edges from that node to the deepest node
//Height of a tree - height of root node
//levels - each row is numbered from 1 in root and so on
//forest - collection of trees

//Binary Tree - tree where each node has at most 2 children i.e 0,1,2 children
/* 
            A
           / \ 
          B   C
         / \  |
        D   E F

    left skewed binary tree     right skewed binary tree
            A                             A
           /                               \
          B                                 B
         /                                   \
        C                                     C                     


unlabelled nodes - empty nodes 
    number of binary trees for n nodes
       T(n) = (2n)Cn/n+1
    max height = n-1, and number of trees with max height = 2^(n-1)
    eg: for n = 3 T(3) = (2*3)C3/3+1 = 5
    
            O    O      O      O      O                                                                       
           /    /      / \      \      \              
          O    O      O   O      O      O                  
         /      \               /        \         
        O        O             O          O                            

labelled node - named nodes
    number of binary trees for n nodes
        T(n) = (2n)Cn/n+1 * n!


Height and nodes
if height is given - 
    minimum nodes = height + 1
    maximum nodes = each level contains 2^(h-1) nodes, so sum of all nodes = 2^(h+1) - 1
    range: h + 1   <= n <=     2^(h+1) - 1
if nodes are given - 
    minimum height = log2(n+1) - 1   //from maximum nodes formula
    maximum height = n-1
    range: log2(n+1) - 1   <= h <=     n-1


relation between internal and external nodes
    number of nodes with degree-0 = number of nodes with degree-2 +1

*/

/*
Strict binary tree - binary tree where each node has either 0 or 2 children

Height and nodes
if height is given - 
    minimum nodes = 2*height + 1
    maximum nodes = each level contains 2^(h-1) nodes, so sum of all nodes = 2^(h+1) - 1
    range: 2h + 1   <= n <=     2^(h+1) - 1
if nodes are given - 
    minimum height = log2(n+1) - 1   //from maximum nodes formula
    maximum height = (n-1)/2
    range: log2(n+1) - 1   <= h <=     (n-1)/2

relation between internal and external nodes
    external nodes = internal nodes+1
*/

/*
n-ary trees - tree where each node has at most n children. eg - 3-ary tree has atmost 3 children i.e 0,1,2,3 children
strict n-ary tree - n-ary tree where each node has either 0 or n children. eg - 3-ary tree has 0 or 3 children i.e 0,3 children

Height and nodes
if height is given - 
    minimum nodes = m*height + 1 //m - number of children in m-ary trees
    maximum nodes = each level contains m^(h-1) nodes, so sum of all nodes = (m^(h+1) - 1)/m-1
    range: m*h + 1   <= n <=     (m^(h+1) - 1)/m-1
if nodes are given - 
    minimum height = logm(n(m-1)+1) - 1   //from maximum nodes formula
    maximum height = (n-1)/m
    range: logm(n(m-1)+1) - 1   <= h <=     (n-1)/m

relation between internal and external nodes
    external nodes = (m-1)*internal nodes+1

*/

//full binary tree/perfect binary tree - maximum number of nodes at each level
//                 - if is is represented by array complete array must be filled
//Complete binary tree - binary tree where each level is filled except last level from left to right
//                     - if it is represented by array there must not be any gap in between
//                     - a complete binary tree is full binary tree upto h-1 height, and in the last level elements are filled from laft to right without any gap

//Representation of tree
//1. Linked representation
//2. Array representation - index starts from 1

/*
Array representation
for any node i its left child is 2*i and right child is 2*i+1  
for any node i its parent is floor(i/2)

Linked representation
node =  | *leftchild | data | *rightchild |
*leftchild points to left child
*rightchild points to right child
no child is denoted by NULL

                        | *lc | A | *rc |
                          /           \
                | *lc | B | *rc |     | null | C | null |
                   /          \              
     | null | D | null | | null | E | null | 

for n nodes n+1 null pointers

*/


