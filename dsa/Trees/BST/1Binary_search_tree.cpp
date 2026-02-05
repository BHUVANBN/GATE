/*
Binary Search Tree
Properties:
1. Left child is smaller than parent node
2. Right child is greater than parent node
3. No duplicates
4. inorder traversal is sorted
5. Number of BST for n nodes is Catalan number i.e (2n)Cn/(n+1) trees
6. BST is represented by linked list

                    30
                   /  \
                  20   40
                 /  \    \
                10   25   50

Searching in BST:
1. Start from root
2. If root is null, return null
3. If root->data is equal to key, return root
4. If root->data is greater than key, search in left subtree
5. If root->data is less than key, search in right subtree
6. If key is not found, return null
Time complexity: O(logn) //order of height 

Insertion in BST: using tail pointer
1. Create a new node
2. If root is null, return new node
3. If root->data is equal to key, node cannot be inserted
4. create *tail , move *node to root
5. if root->data is greater than key, move tail to root, and *node to root->left
6. if root->data is less than key, move tail to root->right, and *node to root->right
7. if *node == NULL, insert node at tail->right if tail->data is less than key, else insert at tail->left
8. return root
Time complexity: O(nlogn) //order of height for each node n
*/

#include<iostream>
using namespace std;

class Node{
    public:
        Node* left;
        int data;
        Node* right;
};
class BST{
    public:
        Node* root;
        Node* node; //for traversal
        Node* tail; //follows the *node pointer for insertion 
    public:
        BST(){
            root = NULL;
            node = NULL;
            tail = NULL;
        }
        void insert(int key){
            Node *t = new Node;
            t->data = key;
            t->left = t->right = NULL;
            if(root == NULL){
                root = t;
                tail = t;
                return;
            }
            node = root;
            while(node != NULL){
                tail = node;  //move tail to node
                if(key < node->data) node = node->left; //move node to left
                else if(key > node->data) node = node->right; //move node to right
                else return;
            }
            //now node is null at where the new node should be inserted
            if(key < tail->data) tail->left = t; //insert at tail->left
            else tail->right = t; //insert at tail->right
        }
        Node* RecursiveInsert(Node *p,int key){
            if(p == NULL){
                Node *t = new Node;
                t->data = key;
                t->left = t->right = NULL;
                p = t;
                return p;
            }
            if(key < p->data) p->left = RecursiveInsert(p->left, key);
            else p->right = RecursiveInsert(p->right, key);
            return p;
        }
        void inorder(Node *p){
            if(p){
                inorder(p->left);
                cout<<p->data<<" ";
                inorder(p->right);   
            }
        }
        Node* search(int key){
            Node *node = root;
            while(node != NULL){
                if(key < node->data) node = node->left;
                else if(key > node->data) node = node->right;
                else return node; //if key == node->data, returns the node which is equal to key
            }
            return NULL;
        }
        //delete node and make parent link as null
        //if single child exists for the deleted node replace the place of deleted node
        //if two children exist for the deleted node replace the place of deleted node with inorder successor or inorder predecessor
        //inorder successor - left most node of the right subtree
        //inorder predecessor - right most node of left subtree
        //based on the height the node is selected from inorder succesor and inorder predecessor
        //time complexiity - O(logn)
        int height(Node *p){
            if(p==NULL) return 0;
            int x = height(p->left);
            int y = height(p->right);
            return x>y?x+1:y+1;
        }
        Node* deleteNode(Node* p, int key) {
            if (p == NULL)
                return NULL;
            if (key < p->data)
                p->left = deleteNode(p->left, key); //traverse until key is found
            else if (key > p->data)
                p->right = deleteNode(p->right, key); //traverse until key is found
            else { //when key == p->data
                // Case 1: leaf node
                if (p->left == NULL && p->right == NULL) {
                    delete p;
                    return NULL; //returns to the parent node and assigns to left or right 
                }
                // Case 2: single child
                else if (p->left == NULL) {
                    Node* temp = p->right;
                    delete p;
                    return temp; //returns to the parent node and assigns to left or right 
                }
                else if (p->right == NULL) {
                    Node* temp = p->left;
                    delete p;
                    return temp; //returns to the parent node and assigns to left or right 
                }
                // Case 3: two children
                else {
                    if (height(p->left) > height(p->right)) {
                        // inorder predecessor
                        Node* temp = p->left;
                        while (temp->right)
                            temp = temp->right; //finds the right nost node of left subtree

                        p->data = temp->data; //replace data with inorder predecessor, donot disturb the tree structure
                        p->left = deleteNode(p->left, temp->data);
                    }
                    else {
                        // inorder successor
                        Node* temp = p->right;
                        while (temp->left)
                            temp = temp->left; 

                        p->data = temp->data;
                        p->right = deleteNode(p->right, temp->data);
                    }
                }
            }
            return p;
        }

};
int main(){
   BST tree;
   tree.insert(100);
   tree.insert(50);
   tree.insert(70);
   tree.insert(200);

   tree.inorder(tree.root);
   cout<<endl;
   tree.RecursiveInsert(tree.root, 150);
   tree.inorder(tree.root);
   cout<<endl;
   
   Node* found = tree.search(170); //found contains the address of the node 
   if(found) cout << "\nNode found: " << found->data << endl;
   else cout << "\nNode not found" << endl;
   
   tree.deleteNode(tree.root, 100);
   tree.inorder(tree.root);
   cout<<endl;
   
   return 0;
}