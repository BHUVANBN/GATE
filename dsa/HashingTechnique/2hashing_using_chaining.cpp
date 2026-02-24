/*Chaining - each index contains linked list of keys, the index is given by hash function, 
    hash table is the array of linked list's head pointers
    loading factor = n / size of hash table
    loading factor says how much elements are stored in hash table per index
    time complexity = O(1 + loading factor)
*/
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
Node* search(struct Node *p, int key){ //time complexity - O(n)
    while(p){
        if(p->data == key){
            return p;
        }
        p = p->next;
    }
    return NULL;
}
int hashFunction(int value){
    return value % 10;
}
void hashTableInsert(Node* hashTable[], int value){
    int index = hashFunction(value); //hash function- x%size of hash table
    insert(hashTable[index], value);
}

int main(){
    Node* hashTable[10];
    for(int i = 0; i < 10; i++)
        hashTable[i] = NULL;
    hashTableInsert(hashTable,12);
    hashTableInsert(hashTable,34);
    hashTableInsert(hashTable,52);
    hashTableInsert(hashTable,78);
    hashTableInsert(hashTable,90);

    Node* node = search(hashTable[hashFunction(53)], 53);
    if(node)
        cout<<"Element found"<<endl;
    else
        cout<<"Element not found"<<endl;
    return 0;
}