/*
BST - Search trees with 2 children each node(1 key)
      grows downwards as new node is added

B-tree - height balanced trees
rules for balancing height
- all leaf nodes are at same level
- every node must have minimum children of ceil(degree/2), eg:2-3 tree must have minimum 2 children i.e ceil(3/2) = 2

2-3 trees - Search trees with 2 or 3 children each node(2 keys)
properties:
    degree of 2-3 trees is 3
    they are height balanced - B-tree of degree 3
    no duplicates
    all leaf nodes are at same level
    minimum 2 children per node
    grows upwards
    
                      |k1|k2|
                      /  |  \
                   |||  |||  |||
                    l    m    n
conditions:
    k1 < k2
    l < k1
    k1 < m < k2
    k2 < n   

inserting node steps:
    If the tree is empty, create a 2-node root with the key.
    Start from the root and traverse to the appropriate leaf as in a BST.
    Always perform insertion at a leaf node.
    If the leaf is a 2-node, insert the key in sorted order and stop.
    If the leaf is a 3-node, temporarily insert the key to form an overflow node.
    Sort the three keys in the overflow node.
    Promote the middle key to the parent node.
    Split the node into two 2-nodes using the remaining keys.
    Attach the two new nodes as children of the parent.
    If the parent becomes a 3-node, stop.
    If the parent overflows, repeat the split process upward.
    If the root overflows, create a new root with the promoted key.
    Increase the tree height by one.

    eg: 20,30,40,50,60,10,15,70,80

        insert(20)          insert(30)         insert(40)                insert(50)                  insert(60)                  

         |20||               |20|30|           |20|30| 40                  |30||                       |30|| 
                                                                          /     \                     /     \
                                            no space for 40           |20||      |40|50|         |20||       |40|50| 60
                                             split the node                                     
                                            promote 30 as root                                     no space for 60
                                                                                                    split the node
                                                 |30||                                             promote 50 as root
                                                /     \
                                            |20||     |40||                                              |30|50|                                           
                                                                                                        /   |   \
                                                                                                   |20|| |40||   |60||
    _________________________________________________________________________________________________________________________________________
        
            insert(10)                      insert(15)                              insert(70)                     insert(80)
                                                        
            |30|50|                         |30|50|                                  |30||                          |30||                             
            /   |   \                       /   |   \                                /     \                        /     \ 
        |20|| |40||   |60||           |10|20| |40||   |60||                      |15||       |50||              |15||       |50||
                                        15                                      /   \       /   \              /   \       /   \ 
    shift the 20 and insert 10           no space for 15                      |10||  |20|| |40|| |60|70|     |10||  |20|| |40|| |60|70| 80      
                                split the node and make 15 root                    
            |30|50|              again no space for 15 in root                                                  no space for 80
            /   |   \           split again and make 30(center node) root                                  split the node and make 70 root
    |10|20| |40||   |60||
                                            |30||                                                                   |30|| 
                                            /     \                                                                 /     \
                                        |15||       |50||                                                       |15||       |50|70|
                                        /   \       /   \                                                      /   \       /   |   \
                                    |10||  |20|| |40|| |60||                                             |10||  |20|| |40|| |60||  |80||
    _________________________________________________________________________________________________________________________________________

Deleting node steps:
    Locate the node containing the key to be deleted.
    If the key is in an internal node, replace it with its inorder successor.
    Move the key to a leaf node for deletion.
    Delete the key from the leaf node.
    If the leaf remains a valid 2-node or 3-node, stop.
    If the leaf becomes empty (underflow), rebalancing is required.
    If a sibling is a 3-node, borrow a key from the sibling via the parent.
    Adjust parent and child keys after borrowing.
    If siblings are 2-nodes, merge the leaf with a sibling and a parent key.
    Reduce the parent node’s key count after merging.
    If the parent remains valid, stop.
    If the parent underflows, repeat the rebalancing process upward.
    If the root becomes empty, replace it with its only child.
    Decrease the tree height by one.

    case 1: when the key is in leaf node with more than one key - simply delete it and if other value in in place of k2 bring that value to k1
    case 2: when the key is in leaf node with only one key - delete it and if sibling has more than one key, borrow from sibling though parent, so the parent is now child and sibling is promoted as parent
    case 3: when the key is in leaf node with only one key and sibling has only one key - merge with sibling and the parent key gets adjusted

Height and Node of 2-3 tree
    Take height = 0 for single node in 2-3 tree
    if height is given:
        minimum nodes = 2^(h+1)  - 1   //same as BST max nodes
        maximum nodes = (3^(h+1) - 1)/3-1

    if nodes is given:
        minimum height = log2(n-1)-1
        maximum height = log3(n(3-1)+1)-1

Uses of B-tree
- used in DBMS
*/


