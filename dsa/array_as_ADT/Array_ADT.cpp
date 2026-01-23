//Array ADT Implementation - array with basic operations
/*
properties -
    1. Array space
    2. Array size - maximum number of elements array can hold
    3. Array length - current number of elements in the array
operations - 
    1. Traversal
    2. Insertion
    3. Deletion
    4. Searching
    5. Sorting
    6. get
    7. set
    8. Min
    9. Max
    10. Reverse
*/
#include <iostream>
#include<stdio.h>
using namespace std;

struct Array { //array with its properties
    int *A;
    int size;
    int length;
};

int display(struct Array arr){ //traversal, time complexity O(n)
    int i;
    cout<<"Elements in the array are: ";
    for(i=0; i<arr.length; i++){
        cout<<arr.A[i]<<" ";
    }
    cout<<endl;
    return 0;
}

void append(struct Array *arr, int x){ //insertion at end, time complexity O(1)
    if(arr->length < arr->size){
        arr->A[arr->length++] = x;
    }
}

void insert(struct Array *arr,int index, int value){ //insertion at given index, time complexity O(n)
    if(index<0 || index>arr->length){
        return;
    }
    for(int i = arr->length; i>index; i--){
        arr->A[i] = arr->A[i-1];
    }
    arr->A[index] = value;
    arr->length++;
}

void del(struct Array *arr, int index){ //deletion at given index, time complexity O(n)
    if(index<0 || index>=arr->length){
        return;
    }
    for(int i = index; i<arr->length-1; i++){
        arr->A[i] = arr->A[i+1];
    }
    arr->length--;
}

int LinearSearch(struct Array arr, int key){ //linear search, time complexity O(n)
    for(int i=0; i<arr.length; i++){
        if(arr.A[i] == key){
            return i;
        }

    }
    return -1;
}
/*
Optimisned Linear Search - 
transposition - the element found is swapped with previous element to reduce search time for future searches of same element
Move to head - the element found is moved to first position to reduce search time for future searches of same element
*/

int BinarySearch(struct Array arr, int key){ //binary search applies on sorted array, time complexity O(log n)
    int l=0; //lower bound
    int h=arr.length-1; //upper bound
    int mid;
    while(l<=h){ //when element not found, l will cross h
        mid = (l+h)/2;
        if(arr.A[mid] == key){
            return mid; // function exits when element is found
        }
        else if(arr.A[mid] < key){
            l = mid + 1;
        }
        else{
            h = mid - 1;
        }
    }
    return -1; //element not found
}
int BinarySearchRecursive(struct Array arr, int l, int h, int key){ //binary search using recursion
    int mid;
    if(l<=h){
        mid = (l+h)/2;
        if(arr.A[mid] == key){
            return mid;
        }
        else if(arr.A[mid] < key){
            return BinarySearchRecursive(arr, mid+1, h, key);
        }
        else{
            return BinarySearchRecursive(arr, l, mid-1, key);
        }
    }
    return -1; //element not found
}
int get(struct Array arr, int index){ //get value at given index, time complexity O(1)
    if(index>=0 && index<arr.length){
        return arr.A[index];
    }
    return -1; //invalid index
}
int set(struct Array *arr, int index, int value){ //set value at given index or replace, time complexity O(1)
    if(index>=0 && index<arr->length){
        arr->A[index] = value;
        return 1; //success
    }
    return 0; //invalid index
}
int Max(struct Array arr){ //find max element, time complexity O(n)
    int max = arr.A[0];
    for(int i=1; i<arr.length; i++){
        if(arr.A[i]>max){
            max = arr.A[i];
        }
    }
    return max;
}
int Min(struct Array arr){ //find min element, time complexity O(n)
    int min = arr.A[0];
    for(int i=1; i<arr.length; i++){
        if(arr.A[i]<min){
            min = arr.A[i];
        }
    }
    return min;
}
int main(){
    struct Array arr;
    int n, i;

    cout<<"Enter size of array: ";
    cin>>arr.size;
    arr.A = new int[arr.size];
    arr.length = 0;

    cout<<"Enter number of elements to insert: ";
    cin>>n;

    cout<<"Enter elements: ";
    for(i=0; i<n; i++){
        cin>>arr.A[i];
    }
    arr.length = n;

    //operations on array
    display(arr);
    append(&arr, 10);
    insert(&arr, 2, 15);
    del(&arr, 1);
    display(arr);
    printf("Linear Search result: %d\n", LinearSearch(arr, 15));
    printf("Binary Search result: %d\n", BinarySearch(arr, 15));
    printf("Binary Search Recursive result: %d\n", BinarySearchRecursive(arr, 0, arr.length-1, 15));

    delete[] arr.A; // Free allocated memory
    return 0;
}
