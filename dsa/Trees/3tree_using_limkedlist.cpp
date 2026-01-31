//Tree using linked list
//take a queue and store the address of the mode created,
//then pop the adress and ask if left child exists, if yes create it and push the address into queue
//then ask if right child exists, if yes create it and push the address into queue
//continue this process until queue is empty

#include<iostream>
using namespace std;

//Node class
class Node{
    public:
        Node *lchild;
        int data;
        Node *rchild;
};
//Queue for tracking nodes created

//  **Q ----> *Node ---->| *lchild |data| *rchild |
class Queue{
    private:
    int size;
    int front;
    int rear;
    Node **Q;   //node type pointer,node is already a pointer so **Q is pointer to node pointer
    public:
    Queue(){
        front = rear = -1; 
        size = 10; 
        Q = new Node*[size];
    }
    Queue(int size){
        this->size = size;
        front = rear = -1;
        Q = new Node*[size];
    }
    void enqueue(Node *x){
        if(rear == size-1) cout<<"queue is full";
        else{
            rear++;
            Q[rear] = x;
        }
    }
    Node* dequeue(){
        Node *x = NULL;
        if(front == rear) cout<<"queue is empty";
        else{
            front++;
            x = Q[front];
        }
        return x;
    }
    void display(){
        for(int i = front+1; i<=rear; i++){
            cout<<Q[i]<<" ";
        }
        cout<<endl;
    }
    int isEmpty(){
        return front == rear;
    }
};
//tree class , tree is group of nodes in a tree structure
class Tree{
    public:
    Node *root;
    Tree(){root = NULL;}

    void createTree(){
        Node *t,*p;  //*t for creating a node, *p for tracking nodes created
        Queue *q = new Queue(100);  //queue for tracking nodes created

        int x;
        cout<<"Enter root value: ";
        cin>>x;
        root = new Node;
        root->data = x;
        root->lchild = root->rchild = NULL; //create root node with left and right child as null
        q->enqueue(root);  //push root node into queue to track nodes created

        while(!q->isEmpty()){  //until queue is empty i.e for all created nodes without children
            p = q->dequeue();  //pop node from queue
            cout<<"Enter the left child of "<<p->data<<": ";
            cin>>x;
            if(x!=-1){
                t = new Node;
                t->data = x;
                t->lchild = t->rchild = NULL;
                p->lchild = t;
                q->enqueue(t);
            }
            cout<<"Enter the right child of "<<p->data<<": ";
            cin>>x;
            if(x!=-1){
                t = new Node;
                t->data = x;
                t->lchild = t->rchild = NULL;
                p->rchild = t;
                q->enqueue(t);
            }
        }
    }
    //tree traversals
    void preOrder(Node *p){
        if(p){
            cout<<p->data<<" ";
            preOrder(p->lchild);
            preOrder(p->rchild);
        }
    }
    void inOrder(Node *p){
        if(p){
            inOrder(p->lchild);
            cout<<p->data<<" ";
            inOrder(p->rchild);
        }
    }
    void postOrder(Node *p){
        if(p){
            postOrder(p->lchild);
            postOrder(p->rchild);
            cout<<p->data<<" ";
        }
    }
    void levelOrder(Node *p){ //using queue to store nodes traversed so that we can access them later
        Queue q(100);
        cout<<p->data<<" "; //root node
        q.enqueue(p);       //push root node into queue to track nodes traveresed
        while(!q.isEmpty()){
            p = q.dequeue(); //pop node from queue
            if(p->lchild){   //if left child exists
                cout<<p->lchild->data<<" ";
                q.enqueue(p->lchild); //push left child into queue to track nodes traveresed
            }
            if(p->rchild){   //if right child exists
                cout<<p->rchild->data<<" ";
                q.enqueue(p->rchild); //push right child into queue to track nodes traveresed
            }
        }
    }
    //iterative tree traversals
    //using stack to store nodes traversed so that we can access them later
   
    //tree properties
    //height of tree is maximum level of tree
    int height(Node *p){
        int x = 0, y = 0;
        if(p == NULL){
            return 0;
        }
        x = height(p->lchild);
        y = height(p->rchild);
        if(x > y){
            return x + 1;
        } else {
            return y + 1;
        }
    }
    
    int count(Node *p){
        if(p){
            return count(p->lchild) + count(p->rchild) + 1; //1 is added for root node (current node)
        } else {
            return 0; //0 is returned for null node
        }
    }
    
    int countLeaf(Node *p){
        if(p == NULL){
            return 0;
        }
        if(p->lchild == NULL && p->rchild == NULL){
            return 1;
        }
        return countLeaf(p->lchild) + countLeaf(p->rchild);
    }
    
    int countInternal(Node *p){
        if(p == NULL || (p->lchild == NULL && p->rchild == NULL)){
            return 0;
        }
        return countInternal(p->lchild) + countInternal(p->rchild) + 1;
    }
    
    int countDegree1(Node *p){
        if(p == NULL){
            return 0;
        }
        int count = 0;
        if((p->lchild != NULL && p->rchild == NULL) || (p->lchild == NULL && p->rchild != NULL)){
            count = 1;
        }
        return count + countDegree1(p->lchild) + countDegree1(p->rchild);
    }
    
    int countDegree2(Node *p){
        if(p == NULL){
            return 0;
        }
        int count = 0;
        if(p->lchild != NULL && p->rchild != NULL){
            count = 1;
        }
        return count + countDegree2(p->lchild) + countDegree2(p->rchild);
    }
    
    int sum(Node *p){
        if(p){
            return sum(p->lchild) + sum(p->rchild) + p->data;
        } else {
            return 0;
        }
    }
    
    void destroy(Node *p){
        if(p){
            destroy(p->lchild);
            destroy(p->rchild);
            delete p;
        }
    }
};

int main(){
    Tree t;
    
    cout<<"Create tree (enter -1 for no child):"<<endl;
    t.createTree();
    
    cout<<"\nTree Traversals:"<<endl;
    cout<<"Preorder: ";
    t.preOrder(t.root);
    cout<<endl;
    
    cout<<"Inorder: ";
    t.inOrder(t.root);
    cout<<endl;
    
    cout<<"Postorder: ";
    t.postOrder(t.root);
    cout<<endl;
    
    cout<<"Levelorder: ";
    t.levelOrder(t.root);
    cout<<endl;
    
    cout<<"\nTree Properties:"<<endl;
    cout<<"Height: "<<t.height(t.root)<<endl;
    cout<<"Total nodes: "<<t.count(t.root)<<endl;
    cout<<"Leaf nodes: "<<t.countLeaf(t.root)<<endl;
    cout<<"Internal nodes: "<<t.countInternal(t.root)<<endl;
    cout<<"Nodes with degree 1: "<<t.countDegree1(t.root)<<endl;
    cout<<"Nodes with degree 2: "<<t.countDegree2(t.root)<<endl;
    cout<<"Sum of all nodes: "<<t.sum(t.root)<<endl;
    
    return 0;
}