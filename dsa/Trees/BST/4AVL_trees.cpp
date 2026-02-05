//AVL - height balanced BST
//height is balanced by balance factor(bf) = height of left subtree - height of right subtree
//bf = -1, 0, 1
//for each node balance factor is calculated
//if bf > 1 or bf < -1, then tree is unbalanced, then to balance it rotation is done
/*

BALANCED TREES (bf = -1, 0, 1 for all nodes):

Tree 1: Balanced Tree
        A(bf:0)
       /       \
    B(bf:0)    C(bf:0)
   /    \         /  \
 D(bf:0) E(bf:0) F(bf:0) G(bf:0)

Balance factors:
- A: height(L)=2, height(R)=2, bf=0
- B: height(L)=1, height(R)=1, bf=0  
- C: height(L)=1, height(R)=1, bf=0
- D: height(L)=0, height(R)=0, bf=0
- E: height(L)=0, height(R)=0, bf=0
- F: height(L)=0, height(R)=0, bf=0
- G: height(L)=0, height(R)=0, bf=0

Tree 2: Balanced Tree (different structure)
        M(bf:1)
       /    \
    N(bf:0)  Q(bf:0)
   /    \     
 O(bf:0) P(bf:0)

Balance factors:
- M: height(L)=2, height(R)=1, bf=1
- N: height(L)=1, height(R)=1, bf=0
- Q: height(L)=0, height(R)=0, bf=0
- O: height(L)=0, height(R)=0, bf=0
- P: height(L)=0, height(R)=0, bf=0


IMBALANCED TREES (bf > 1 or bf < -1 for some nodes):

Tree 3: Left-Left Imbalanced Tree
        X(bf:2)  ← IMBALANCED
       /       
    Y(bf:1)    
   /       
 Z(bf:0)    

Balance factors:
- X: height(L)=2, height(R)=0, bf=2 (IMBALANCED - needs right rotation)
- Y: height(L)=1, height(R)=0, bf=1
- Z: height(L)=0, height(R)=0, bf=0

Tree 4: Right-Right Imbalanced Tree
    A(bf:-2)  ← IMBALANCED
       \       
        B(bf:-1)    
           \       
            C(bf:0)    

Balance factors:
- A: height(L)=0, height(R)=2, bf=-2 (IMBALANCED - needs left rotation)
- B: height(L)=0, height(R)=1, bf=-1
- C: height(L)=0, height(R)=0, bf=0

Tree 5: Left-Right Imbalanced Tree
        P(bf:2)  ← IMBALANCED
       /       
    Q(bf:-1)    
       \       
        R(bf:0)    

Balance factors:
- P: height(L)=2, height(R)=0, bf=2 (IMBALANCED - needs LR rotation)
- Q: height(L)=0, height(R)=1, bf=-1
- R: height(L)=0, height(R)=0, bf=0

Tree 6: Right-Left Imbalanced Tree
    K(bf:-2)  ← IMBALANCED
       \       
        L(bf:1)    
       /       
    M(bf:0)    

Balance factors:
- K: height(L)=0, height(R)=2, bf=-2 (IMBALANCED - needs RL rotation)
- L: height(L)=1, height(R)=0, bf=1
- M: height(L)=0, height(R)=0, bf=0

*/

/*
Rotations - Always done with 3 nodes, even in large trees
LL Rotation - caused by LL imbalance, single right rotation
LR Rotation - caused by LR imbalance, double rotation (left then right)
RR Rotation - caused by RR imbalance, single left rotation
RL Rotation - caused by RL imbalance, double rotation (right then left)

1.LL Rotation
    Initial             After insert                   After LL Rotation
        A                   A                            B
       /                   /                            / \
      B       ->          B            ->              C   A
                         /                            
                        C                            
                    inserted in left's left           Rotated around A
                    of root node which now has        Single right rotation
                    bf = 2(imbalance)                 now at same position of imbalanced node (now B) bf = 0

2. LR Rotation
    Initial             After insert                   After LR Rotation
        A                   A                                  A        C
       /                   /                                  /        / \
      B       ->          B            ->                    C    ->  B   A
       \                   \                                /
        C                   C                              B
                    inserted in left's right place    Double rotation: left on B, then right on A
                    of root node which now has        now at same position of imbalanced node (now C) bf = 0
                    bf = 2(imbalance)                 

3. RR Rotation
    Initial             After insert                   After RR Rotation
    A                       A                                        B
     \                       \                                      / \
      B       ->              B            ->                      A   C
                               \                            
                                C                            
                    inserted in right's right place    Single left rotation
                    of root node which now has         now at same position of imbalanced node (now B) bf = 0
                    bf = -2(imbalance)               

4. RL Rotation
    Initial             After insert                   After RL Rotation
    A                       A                            A          C
     \                       \                            \        / \
      B       ->              B            ->              C  ->  A   B
     /                       /                              \
    C                       C                                B
                    inserted in right's left place     Double rotation: right on B, then left on A
                    of root node which now has         now at same position of imbalanced node (now C) bf = 0
                    bf = -2(imbalance)                


*/
/*
eg: LL Rotation

BEFORE INSERTION:
        50(1)
       /     \
    30(1)     70(0)
   /   \       / \
 20(1) 40(0) 60(0) 80(0)
 /
10(0)

AFTER INSERTION (insert 5):
        50(2) ← IMBALANCED
       /     \
    30(2)     70(0)
   /   \       / \
 20(2) 40(0) 60(0) 80(0)
 /
10(1)
/
5(0)

IMBALANCE POINT: Node 50 (bf=2) and Node 30 (bf=2)

AFTER ROTATION:
                30(0)
               /    \
IMBALANCED-> 20(2)   50(0)
            /       /   \
          10(1)   40(0)  70(0)
         /              / \
        5(0)          60(0) 80(0)

SECOND ROTATION (LL at node 20):
            30(-1)
           /      \
         10(0)     50(-1)
        /  \       /    \
       5(0) 20(0) 40(0)  70(0)
                           / \
                        60(0) 80(0)
*/


/*
Height and Node of AVL tree
Take height = 1 for single node in AVL tree
if height is given:
   minimum nodes = N(h-2)+N(h-1)+1    //fibonacci series is always balanced
   |   height   | 1 | 2 | 3 | 4 | 5 | 6 | 7 |
   |  minNodes  | 1 | 2 | 4 | 7 |12 |20 |33 |
   maximum nodes = 2^height - 1

if nodes is given:
   minimum height = log2(n+1)
   maximum height = look into the table eg: from 12-19 nodes maxheight is 5
*/
