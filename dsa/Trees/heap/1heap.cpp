//Heap is a Complete Binary tree
//height is always logn
//implemented using array
//types - max and min heap
//every node must be greater or equal to its decendents - max heap
//every node must be smaller or equal to its decendents - min heap

/*
insertion in heap:
1.insert the new element in next free space of the array
  2*parentidx = childidx
  parentidx = floor(childidx/2)  //to find parent node 
2.now move the inserted element to satify the max or min heap by comparing with parent
3.if parent is smaller than child then swap
4.repeat until parent is larger than child or root is reached
*/

//Heap is also used as priority queue - O(logn) for both insertion and deletion
#include<iostream> 
using namespace std;
//max heap
struct Heap{
    int *arr;
    int size;
    int count; //to track the last index of the heap
};
void insert(struct Heap *h, int x){
    if(h->count == h->size){
        cout << "Heap is full" << endl;
        return;
    }
    
    // Insert at the end
    int i = h->count;
    h->arr[i] = x;
    h->count++;
    
    // Heapify up (for max heap)
    while(i != 0 && h->arr[(i-1)/2] < h->arr[i]){  //array index 0 contains first node
        swap(h->arr[i], h->arr[(i-1)/2]); //std::swap()
        i = (i-1)/2; //move to parent node
    }
}
//creating heap from the array - it is done inplace without using another array 
struct Heap createHeap(int A[], int n){ //O(nlogn)
    struct Heap h;
    h.arr = A;
    h.size = n;
    h.count = 0;
    for(int i = 0; i < n; i++){
        insert(&h, A[i]);
    }
    return h;
}
void deleteRoot(struct Heap *h){  //in Heap only root is deleted and replaced with last element
    if(h->count <= 0){
        cout << "Heap is empty" << endl;
        return;
    }
    
    // Swap root (max) with last element - max goes to sorted position
    swap(h->arr[0], h->arr[h->count-1]);
    
    // Reduce heap size - max stays at end in sorted position
    h->count--;

    // Restore heap property by comparing with children
    int i = 0; // start from root
    while(true){
        int left = 2*i + 1; //left child
        int right = 2*i + 2; //right child
        int largest = i; //parent initially 0
        
        // Find largest among root and its children
        if(left < h->count && h->arr[left] > h->arr[largest])
            largest = left;
        
        if(right < h->count && h->arr[right] > h->arr[largest])
            largest = right;
        
        // If root is already largest, heap property is satisfied
        if(largest == i)
            break;
        
        // Swap root with largest child
        swap(h->arr[i], h->arr[largest]);
        i = largest; // move to the child position and continue until heap property is satisfied
    }
    //this can create a sorted elements as we delete the largest value everytime - Heap Sort
    //Heap sort takes O(2nlogn) = O(nlogn)
}
//while inserting elements the adjustment is done from leaf to root 
//while deletion the adjustment is done from root to leaf
//heapify is the process of 
void heapify(struct Heap *h, int i){
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;
    
    if(left < h->count && h->arr[left] > h->arr[largest])
        largest = left;
    
    if(right < h->count && h->arr[right] > h->arr[largest])
        largest = right;
    
    if(largest != i){
        swap(h->arr[i], h->arr[largest]);
        heapify(h, largest);
    }
}

int extractMax(struct Heap *h){
    if(h->count <= 0){
        cout << "Heap is empty" << endl;
        return -1;
    }
    
    if(h->count == 1){
        h->count--;
        return h->arr[0];
    }
    
    // Store the maximum value and remove it
    int root = h->arr[0];
    h->arr[0] = h->arr[h->count-1];
    h->count--;
    
    // Heapify the root
    heapify(h, 0);
    
    return root;
}

void printHeap(struct Heap *h){
    for(int i = 0; i < h->count; i++){
        cout << h->arr[i] << " ";
    }
    cout << endl;
}

void printCompleteArray(struct Heap *h){
    for(int i = 0; i < h->size; i++){
        cout << h->arr[i] << " ";
    }
    cout << endl;
}
int main(){
    struct Heap h;
    h.arr = new int[10];
    h.size = 10;
    h.count = 0;

    // Test insertions
    insert(&h, 30);
    insert(&h, 20);
    insert(&h, 50);
    insert(&h, 10);
    insert(&h, 40);
    
    cout << "Heap after insertions: ";
    printHeap(&h);

    // Test creating heap from array
    int arr[] = {1, 2, 3, 4, 5};
    Heap h2 = createHeap(arr, 5);
    cout << "Heap from array: ";
    printHeap(&h2);
    
    //deleting in heap
    deleteRoot(&h2);

    cout << "Heap after deleting root (active heap): ";
    printHeap(&h2);
    
    cout << "Complete array (including sorted): ";
    printCompleteArray(&h2);

    // // Test extraction
    // cout << "Extracted max: " << extractMax(&h) << endl;
    // cout << "Heap after extraction: ";
    // printHeap(&h);
    
    // cout << "Extracted max: " << extractMax(&h) << endl;
    // cout << "Heap after extraction: ";
    // printHeap(&h);

    delete[] h.arr;
    return 0;
}
