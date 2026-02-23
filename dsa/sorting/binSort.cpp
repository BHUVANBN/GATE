//bin sort or bucket sort
//used when data is uniformly distributed
//auxiliary array of size max element in array is used
//this auxilary array stores the pointers initially null
//traverse the array and place the element at the index of auxiliary array as nodes
//auxiliary array stores the linked list of nodes
//traverse the auxiliary array and place the elements in sorted order

//time complexity = O(n)
//space complexity = O(n)

#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

// Insert node into sorted linked list
void insert(Node* &head, int value){
    Node* temp = new Node;
    temp->data = value;
    temp->next = NULL;

    if(head == NULL || value < head->data){
        temp->next = head;
        head = temp;
    }
    else{
        Node* p = head;
        while(p->next != NULL && p->next->data < value)
            p = p->next;

        temp->next = p->next;
        p->next = temp;
    }
}

// Delete first node from list
int remove(Node* &head){
    Node* temp = head;
    int x = temp->data;
    head = head->next;
    delete temp;
    return x;
}

void binSort(int A[], int n){

    // Find max
    int max = A[0];
    for(int i = 1; i < n; i++)
        if(A[i] > max)
            max = A[i];

    // Create auxiliary array of pointers
    Node** bins = new Node*[max+1];

    for(int i = 0; i <= max; i++)
        bins[i] = NULL;

    // Insert elements into bins
    for(int i = 0; i < n; i++)
        insert(bins[A[i]], A[i]);

    // Collect elements back
    int i = 0;
    int j = 0;

    while(j <= max){
        while(bins[j] != NULL){
            A[i++] = remove(bins[j]);
        }
        j++;
    }

    delete[] bins;
}

int main(){
    int A[] = {6, 3, 9, 4, 2, 5, 3};
    int n = sizeof(A)/sizeof(A[0]);

    binSort(A, n);

    for(int i = 0; i < n; i++)
        cout << A[i] << " ";

    return 0;
}