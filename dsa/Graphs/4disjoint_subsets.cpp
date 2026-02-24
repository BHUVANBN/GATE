//disjoint subsets - when two or more sets have no common element i.e A ∩ B = ∅
/*lets say U = {1,2,3,4,5,6,7,8,9,10}

each element is a subset of U and itself is a parent of it
it is represented in array as -1(-ve shows its the parent of the subset)

array = [-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1]  //ignore index 0

then A = {3,5,9}, B = {4,7,8,10} are disjoint subsets of U
each subset must have a parent to represent as tree

            3                      4
          /   \                  / | \   
         5     9                7  8  10

each index act as a vertex, and it stores its parent vertex, parent vertex stores the number of vertices in the subset with -ve sign indicating it is the parent         
    array = [-1, -1, -1, -3, -4, 3, -1, 4, 4, 3, 4]   
    indexes   0   1   2   3   4  5   6  7  8  9  10

weighted union - union of two subsets with parent having more number of vertices
               4
            / / \ \
           3 7   8 10
          / \
         5   9

    add the two parents and store it in the parent of larger subset and make parent of smaller-subset as larger-subset parent 
    array = [-1, -1, -1,  4, -7, 3, -1, 4, 4, 3, 4]   //-4-3 = -7 , and parent of 3 is 4
    indexes   0   1   2   3   4  5   6  7  8  9  10

    from this we can easily find the root of any element
*/