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
    10. Sum
    11. Average
    12. Reverse
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
int sum(struct Array arr){ //sum of all elements, time complexity O(n)
    int sum = 0;
    for(int i=0; i<arr.length; i++){
        sum +=arr.A[i];
    }
    return sum;
}
int average(struct Array arr){ //average of all elements, time complexity O(n)
    return sum(arr)/arr.length;
}
//reversing array can be done using auxiliary array or by swapping elements
//using auxiliary array - time complexity O(n), space complexity O(n)
int reverseAuxiliary(struct Array *arr){
    int *B = new int[arr->length];
    int i,j;
    for(i=arr->length-1, j=0; i>=0; i--, j++){ //copying elements in reverse order
        B[j] = arr->A[i];
    }
    for(i=0; i<arr->length; i++){ //copying back to original array
        arr->A[i] = B[i];
    }
    delete[] B; //free allocated memory
    return 0;
}
//using swapping - time complexity O(n), space complexity O(1)
//swapping elements from start and end, eg: swap first and last, second and second last and so on
int reverseSwap(struct Array *arr){
    int i, j;
    for(i=0, j=arr->length-1; i<j; i++, j--){
        int temp = arr->A[i];
        arr->A[i] =  arr->A[j];
        arr->A[j] = temp;
    }
    return 0;
}
//Left shift - shifts all elements to left, first element comes out and last position is 0
//Right shift - shifts all elements to right, last element comes out and first position is 0
//Left rotate - shifts all elements to left, first element goes to last position    
//Right rotate - shifts all elements to right, last element goes to first position
//used in circular arrays, scrolling ads, image viewers etc.

//inserting in sorted array - insert element at correct position to keep array sorted
int insertSorted(struct Array *arr, int x){ //time complexity O(n)
    if(arr->length == arr->size){ //check if array is full
        return 0;
    }
    int i = arr->length - 1;
    while(i>=0 && arr->A[i]>x){ //find position to insert
        arr->A[i+1] = arr->A[i]; //shift elements to right
        i--;
    }
    arr->A[i+1] = x; //insert element
    arr->length++;
    return 1; //success
}
//check if array is sorted
int isSorted(struct Array arr){ //time complexity O(n)
    for(int i=0; i<arr.length-1; i++){
        if(arr.A[i]>arr.A[i+1]){
            return 0; //not sorted
        }
    }
    return 1; //sorted
}
//rearrange - move negative elements to left and positive to right
int rearrange(struct Array *arr){ //time complexity O(n)
    int i=0, j=arr->length-1;
    while(i<j){
        while(arr->A[i]<0) i++;
        while(arr->A[j]>=0) j--;
        if(i<j){
            int temp = arr->A[i];
            arr->A[i] = arr->A[j];
            arr->A[j] = temp;
        }
    }
    return 0;
}
//Merging - merge two sorted arrays into a third sorted array
Struct Array* mergeArray(struct Array arr1, struct Array arr2){ //time complexity O(n+m)
    Struct Array *arr3 = new Struct Array;
    arr3->A = new int[arr1.length + arr2.length];
    int i=0, j=0, k=0;
    while(i<arr1.length && j<arr2.length){
        if(arr1.A[i]<arr2.A[j]){
            arr3->A[k++] = arr1.A[i++];
        }
        else{
            arr3->A[k++] = arr2.A[j++];
        }
    }
    for(; i<arr1.length; i++){
        arr3->A[k++] = arr1.A[i];
    }
    for(; j<arr2.length; j++){
        arr3->A[k++] = arr2.A[j];
    }
    arr3->length = k;
    arr3->size = arr1.size + arr2.size;
    return arr3;
}
int main(){
    // struct Array arr;
    // int n, i;

    // cout<<"Enter size of array: ";
    // cin>>arr.size;
    // arr.A = new int[arr.size];
    // arr.length = 0;

    // cout<<"Enter number of elements to insert: ";
    // cin>>n;

    // cout<<"Enter elements: ";
    // for(i=0; i<n; i++){
    //     cin>>arr.A[i];
    // }
    // arr.length = n;

    // //operations on array
    // display(arr);
    // append(&arr, 10);
    // insert(&arr, 2, 15);
    // del(&arr, 1);
    // display(arr);
    // printf("Linear Search result: %d\n", LinearSearch(arr, 15));
    // printf("Binary Search result: %d\n", BinarySearch(arr, 15));
    // printf("Binary Search Recursive result: %d\n", BinarySearchRecursive(arr, 0, arr.length-1, 15));
    // printf("Get element at index 2: %d\n", get(arr, 2));
    // set(&arr, 2, 20);
    // printf("Max element: %d\n", Max(arr));
    // printf("Min element: %d\n", Min(arr));
    // printf("Sum of elements: %d\n", sum(arr));
    // printf("Average of elements: %d\n", average(arr));
    // reverseSwap(&arr);
    // cout<<"Array after reversing: ";
    // display(arr);
    
    //merging two sorted arrays
    struct Array arr1 = {{2,4,6,8,10}, 10, 5};
    struct Array arr2 = {{1,3,5,7,9}, 10, 5};
    struct Array *arr3 = mergeArray(arr1, arr2);
    cout<<"Merged array: ";
    display(*arr3);

    //delete[] arr.A; // Free allocated memory
    return 0;
}
