#include<iostream>
using namespace std;

class Node{
    public:
    Node *left;
    int data;
    int height;
    Node *right;
}*root=NULL;

class AVL{
    public:
        int getBalanceFactor(Node* node){
            return getHeight(node->left) - getHeight(node->right);
        }
        // If bf = -ve → right subtree is taller → RR or RL
        //   bf(p) = -2 and bf(p->right) = -1  → RR rotation
        //   bf(p) = -2 and bf(p->right) = +1  → RL rotation
            
        // If bf = +ve → left subtree is taller → LL or LR
        //   bf(p) = +2 and bf(p->left)  = +1  → LL rotation
        //   bf(p) = +2 and bf(p->left)  = -1  → LR rotation

        int getHeight(Node* node){
            return node ? node->height : 0;
        }
        Node* LLRotation(Node *p){
            //make p->left as root node, p->left->right as p->left
            /*
                    p               pl
                   / \             /  \
                  pl  O    ->     O    p
                 /  \                 / \
                O    plr            plr  O

            */
            Node *pl = p->left; //p's left child
            Node *plr = pl->right; //p's left child's right child
            
            pl->right = p;
            p->left = plr;
            
            p->height = max(getHeight(p->left), getHeight(p->right)) + 1;
            pl->height = max(getHeight(pl->left), getHeight(pl->right)) + 1;
            
            if(root == p){ //if rotation is performed in root 
                root = pl;  //change the root
            }
            return pl;
        }
        Node* LRRotation(Node *p){
            //make p->left->right as root node, 
            //then plr's right child is p, 
            //pl's right child is plr->left 
            //and p's left child is plr->right
            /*
                    p                     plr
                   / \                   /   \
                  pl  O                 pl    p  
                 / \           ->      / \   / \
                O   plr               O  Xl Xr  O
                   / \
                  Xl  Xr
   
            */
            Node *plr = p->left->right;
            Node *pl = p->left;
            Node *plrLeft = plr->left;
            Node *plrRight = plr->right;

            plr->right = p;
            plr->left = pl;
            p->left = plrRight;
            pl->right = plrLeft;
            
            p->height = max(getHeight(p->left), getHeight(p->right)) + 1;
            pl->height = max(getHeight(pl->left), getHeight(pl->right)) + 1;
            plr->height = max(getHeight(plr->left), getHeight(plr->right)) + 1;
            
            if(root == p){
                root = plr;
            }
            return plr;
        }
        
        Node* RRRotation(Node *p){
            //make p->right as root node, p->right->left as p->right
            /*
                    p                   pr
                   / \                 /  \
                  O   pr      ->      p    O
                     / \             / \
                    prl O           O  prl

            */
            Node *pr = p->right; //p's right child
            Node *prl = pr->left; //p's right child's left child
            
            pr->left = p;
            p->right = prl;
            
            p->height = max(getHeight(p->left), getHeight(p->right)) + 1;
            pr->height = max(getHeight(pr->left), getHeight(pr->right)) + 1;
            
            if(root == p){ //if rotation is performed in root 
                root = pr;  //change the root
            }
            return pr;
        }
        
        Node* RLRotation(Node *p){
            //make p->right->left as root node,
            //then prl's left child is p,
            //pr's left child is prl->right
            //and p's right child is prl->left
            /*
                    p                     prl
                   / \                   /   \
                  O   pr                p     pr  
                     / \      ->       / \   / \
                    prl  O            O  Xl Xr  O
                   / \
                  Xl  Xr
   
            */
            Node *prl = p->right->left;
            Node *pr = p->right;
            Node *prlLeft = prl->left;
            Node *prlRight = prl->right;

            prl->left = p;
            prl->right = pr;
            p->right = prlLeft;
            pr->left = prlRight;
            
            p->height = max(getHeight(p->left), getHeight(p->right)) + 1;
            pr->height = max(getHeight(pr->left), getHeight(pr->right)) + 1;
            prl->height = max(getHeight(prl->left), getHeight(prl->right)) + 1;
            
            if(root == p){
                root = prl;
            }
            return prl;
        }
        Node* Insert(Node* p, int key){
            if(p == NULL){
                Node *t = new Node;
                t->data = key;
                t->height = 1;  //leaf node height = 1 
                t->left = t->right = NULL;
                p = t;
                return p;
            }
            if(key < p->data) p->left = Insert(p->left, key);
            else p->right = Insert(p->right, key);
            p->height = max(getHeight(p->left), getHeight(p->right)) + 1;

            //rotations
            int bf = getBalanceFactor(p);
            if (bf == 2 && getBalanceFactor(p->left) >= 0){
                //LL rotation
                return LLRotation(p);
            }
            else if (bf == 2 && getBalanceFactor(p->left) < 0){
                //LR rotation
                return LRRotation(p);
            }
            else if (bf == -2 && getBalanceFactor(p->right) <= 0){
                //RR rotation
                return RRRotation(p);
            }
            else if (bf == -2 && getBalanceFactor(p->right) > 0){
                //RL rotation
                return RLRotation(p);
            }
            return p;
        }   
        void inorder(Node *p){
            if(p){
                inorder(p->left);
                cout<<p->data<<" ";
                inorder(p->right);   
            }
        } 
        void preorder(Node *p){
            if(p){
                cout<<p->data<<" ";
                preorder(p->left);
                preorder(p->right);   
            }
        } 
        // After deletion, an AVL tree may become imbalanced
        // To rebalance, rotations are applied based on balance factors
        //
        // NOTE (Deletion vs Insertion):
        // In deletion, child balance factor CAN BE 0
        // This is the key difference most people miss.

        /*
            Case 1: L1 Rotation
            -------------------
            bf(p) = +2  (left subtree heavy)
            bf(p->left) = +1
            → Perform LL Rotation

            Case 2: L0 Rotation
            -------------------
            bf(p) = +2
            bf(p->left) = 0
            → Perform LL Rotation
            (Special deletion case)

            Case 3: L-1 Rotation
            --------------------
            bf(p) = +2
            bf(p->left) = -1
            → Perform LR Rotation


            Case 4: R-1 Rotation
            --------------------
            bf(p) = -2  (right subtree heavy)
            bf(p->right) = -1
            → Perform RR Rotation

            Case 5: R0 Rotation
            -------------------
            bf(p) = -2
            bf(p->right) = 0
            → Perform RR Rotation
            (Special deletion case)

            Case 6: R1 Rotation
            -------------------
            bf(p) = -2
            bf(p->right) = +1
            → Perform RL Rotation
        */
        Node* deleteNode(Node* p, int key){
            if(p == NULL) return NULL;

            // 1. BST delete
            if(key < p->data){
                p->left = deleteNode(p->left, key);
            }
            else if(key > p->data){
                p->right = deleteNode(p->right, key);
            }
            else{
                // node found
                if(p->left == NULL && p->right == NULL){
                    delete p;
                    return NULL;
                }
                else if(p->left && !p->right){
                    Node* temp = p->left;
                    delete p;
                    return temp;
                }
                else if(!p->left && p->right){
                    Node* temp = p->right;
                    delete p;
                    return temp;
                }
                else{
                    // two children → inorder predecessor
                    Node* q = p->left;
                    while(q->right) q = q->right;
                    p->data = q->data;
                    p->left = deleteNode(p->left, q->data);
                }
            }

            // 2. Update height
            p->height = max(getHeight(p->left), getHeight(p->right)) + 1;

            // 3. Balance
            int bf = getBalanceFactor(p);

            // L1 and L0
            if(bf == 2 && getBalanceFactor(p->left) >= 0)
                return LLRotation(p);

            // L-1
            if(bf == 2 && getBalanceFactor(p->left) < 0)
                return LRRotation(p);

            // R-1 and R0
            if(bf == -2 && getBalanceFactor(p->right) <= 0)
                return RRRotation(p);

            // R1
            if(bf == -2 && getBalanceFactor(p->right) > 0)
                return RLRotation(p);

            return p;
        }
 
};
int main(){
    AVL avl;
    root = avl.Insert(root, 10);
    root = avl.Insert(root, 20);
    root = avl.Insert(root, 30);
    root = avl.Insert(root, 40);
    root = avl.Insert(root, 50);
    root = avl.Insert(root, 25);

    avl.inorder(root);
    cout<<endl;
    avl.preorder(root);

    root = avl.deleteNode(root, 30);
    cout<<endl;
    avl.inorder(root);
    cout<<endl;
    avl.preorder(root);

    return 0;
}