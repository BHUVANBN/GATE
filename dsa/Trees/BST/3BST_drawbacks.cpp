/*
Drawbacks of BST

eg:  construct BST for
    1)  40, 20, 30, 60, 50, 10, 70

                    40
                   /  \
                 20    60
                /  \   / \
               10  30 50  70
   height - 2

   2)  10, 20, 30, 40, 50, 60, 70
                    
                    10
                      \
                      20
                        \
                        30
                          \
                          40
                            \
                            59
                              \
                              60
                                \
                                70
    height - 6
    
    even though the elements are same height is varied, so no control over height of BST
    So, BST is not suitable for all cases.
    
    to overcome this AVL trees are used
    AVL trees are height balanced BST
*/