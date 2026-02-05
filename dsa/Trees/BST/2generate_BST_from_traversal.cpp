//Similar to binary trees BST cannot be generated only using preorder or postorder traversal
//we need inorder traversal along with either preorder or postorder traversal
//but if preorder or postorder is given we can find inorder as it is sorted order in BST
//so either preorder or postorder is sufficient to generate BST

/*
steps using stack with top pointing to infinity
1. loop through the preorder traversal 
2. create node for each element using *temp
3. use *p to traverse the tree and insert the nodes
4. push the address of the *p into the stack before traversing to next node
5. if p->data > temp->data, insert to left of p
6. if p->data < temp->data && stack.peek()->data > temp->data, insert to right of p, 
    and donot push p to stack as the node is now completed with right child so no need to track the node in stack
7. if p->data < temp->data && stack.peek()->data < temp->data, move *p to stack.pop() address 
8. repeat the steps
The stack should contain only those nodes whose right subtree is NOT yet created.
*/

#include<iostream>
#include<stack>
#include <climits>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
}*root=NULL;

void createBST(int preorder[], int n) { //time complexity O(n)
    stack<Node*> s;

    Node* inf = new Node;
    inf->data = INT_MAX;
    inf->left = inf->right = NULL;
    s.push(inf);

    Node *t; //to create node
    root = new Node;
    root->data = preorder[0];
    root->left = root->right = NULL;
    Node *p = root; //pointer to traverse

    int i = 1;
    while(i<n) {
        if(preorder[i] < p->data) {  //left child
            t = new Node;
            t->data = preorder[i];
            t->left = t->right = NULL;
            p->left = t;
            s.push(p);
            p = t;
            i++;
        }
        else{ //right child or sibling node
            if(preorder[i] > p->data && preorder[i] < s.top()->data) {
                t = new Node;
                t->data = preorder[i];
                t->left = t->right = NULL;
                p->right = t;
                p = t;
                i++;
            }
            else {
                p = s.top();
                s.pop();
            }
        }
    }
}
void inorder(Node* root) {
    if(root) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}
int main(){
    int preorder[] = {8, 3, 1, 6, 4, 7, 10, 14, 13};
    int n = 9;
    createBST(preorder, n);
    inorder(root);
    return 0;
}
