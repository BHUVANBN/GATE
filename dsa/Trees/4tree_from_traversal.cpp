//generating tree from given traversals
//it is not possible to generate single tree from only one traversal, or preorder and postorder
//we need preorder and inorder or postorder and inorder to generate tree

/*
eg: preorder: A B D E C F
    inorder: D B E A C F 
    
    select first element of preorder as root                                                    
    find root in inorder and divide into left and right subtree(i.e D B E and C F)

              A
            /   \ 
        D B E   C F 

    select second element of preorder as root of left subtree 
    find root in inorder and if group of nodes exists, divide into left and right subtree(i.e D and E) 
    
              A
            /   \ 
           B     C F
          / \   
         D   E   
              
    continue this process until all nodes are traversed
    
              A
            /   \ 
           B     C 
          / \     \
         D   E     F

Time complexity: O(n^2) as we search for root in inorder for each node of preorder
*/