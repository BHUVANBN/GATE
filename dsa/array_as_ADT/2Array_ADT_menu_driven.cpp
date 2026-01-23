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
    //int A[10]; //static array declaration for merging example
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
    if(arr.length == 0){
        cout << "Array is empty!" << endl;
        return -1;
    }
    int max = arr.A[0];
    for(int i=1; i<arr.length; i++){
        if(arr.A[i]>max){
            max = arr.A[i];
        }
    }
    return max;
}
int Min(struct Array arr){ //find min element, time complexity O(n)
    if(arr.length == 0){
        cout << "Array is empty!" << endl;
        return -1;
    }
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
    if(arr.length == 0){
        cout << "Array is empty!" << endl;
        return -1;
    }
    return sum(arr)/arr.length;
}
//reversing array can be done using auxiliary array or by swapping elements
//using auxiliary array - time complexity O(n), space complexity O(n)
int reverseAuxiliary(struct Array *arr){
    if(arr->length == 0){
        return 0;
    }
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
    if(arr->length == 0){
        return 0;
    }
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
struct Array* mergeArray(struct Array arr1, struct Array arr2){ //time complexity O(n+m)
    struct Array *arr3 = new struct Array;
    arr3->size = arr1.size + arr2.size;
    arr3->A = new int[arr3->size];

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
    return arr3;
}
//Set operations on arrays -
//Union - combine elements of both arrays without duplicates
//Intersection - common elements in both arrays
//Difference - elements in first array not in second array
struct Array* unionArray(struct Array arr1, struct Array arr2){
    struct Array *arr3 = new struct Array;
    arr3->size = arr1.size + arr2.size;
    arr3->A = new int[arr3->size];
    int i=0, j=0, k=0;
    while(i<arr1.length && j<arr2.length){
        if(arr1.A[i]<arr2.A[j]){
            arr3->A[k++] = arr1.A[i++];
        }
        else if(arr2.A[j]<arr1.A[i]){
            arr3->A[k++] = arr2.A[j++];
        }
        else{
            arr3->A[k++] = arr1.A[i++];
            j++;
        }
    }
    for(; i<arr1.length; i++){
        arr3->A[k++] = arr1.A[i];
    }
    for(; j<arr2.length; j++){
        arr3->A[k++] = arr2.A[j];
    }
    arr3->length = k;
    return arr3;
}
struct Array* intersectionArray(struct Array arr1, struct Array arr2){
    struct Array *arr3 = new struct Array;
    arr3->size = (arr1.size < arr2.size) ? arr1.size : arr2.size;
    arr3->A = new int[arr3->size];
    int i=0, j=0, k=0;
    while(i<arr1.length && j<arr2.length){
        if(arr1.A[i]<arr2.A[j]){
            i++;
        }
        else if(arr2.A[j]<arr1.A[i]){
            j++;
        }
        else{
            arr3->A[k++] = arr1.A[i++];
            j++;
        }
    }
    arr3->length = k;
    return arr3;
}
struct Array* differenceArray(struct Array arr1, struct Array arr2){
    struct Array *arr3 = new struct Array;
    arr3->size = arr1.size;
    arr3->A = new int[arr3->size];
    int i=0, j=0, k=0;
    while(i<arr1.length && j<arr2.length){
        if(arr1.A[i]<arr2.A[j]){
            arr3->A[k++] = arr1.A[i++];
        }
        else if(arr2.A[j]<arr1.A[i]){
            j++;
        }
        else{
            i++;
            j++;
        }
    }
    for(; i<arr1.length; i++){
        arr3->A[k++] = arr1.A[i];   
    }
    arr3->length = k;
    return arr3;
}

int main(){
    //Menu driven program can be implemented here to test all functions
    struct Array arr;
    int n, i;
    printf("Enter size of array: ");
    scanf("%d", &arr.size);
    arr.A = new int[arr.size];
    arr.length = 0;
    printf("Enter number of elements: ");
    scanf("%d", &arr.length);
    printf("Enter elements of array: ");
    for(i=0; i<arr.length; i++){
        scanf("%d", &arr.A[i]);
    }

    printf("Menu\n");
    printf("1.  Append\n2.  Insert\n3.  Delete\n4.  Linear Search\n5.  Binary Search\n6.  Get\n7.  Set\n8.  Max\n9.  Min\n10. Sum\n11. Average\n12. Reverse (Auxiliary)\n13. Reverse (Swap)\n14. Insert in Sorted Array\n15. Check if Sorted\n16. Rearrange\n17. Merge Two Arrays\n18. Union of Two Arrays\n19. Intersection of Two Arrays\n20. Difference of Two Arrays\n  ");
    printf("Enter the choice: ");
    int choice;
    scanf("%d", &choice);
    //Implement switch case for each choice to call respective functions
    switch(choice){
        case 1:
            {
                int x;
                printf("Enter element to append: ");
                scanf("%d", &x);
                append(&arr, x);
                display(arr);
                break;
            }
        case 2:
            {
                int index, value;
                printf("Enter index and value to insert: ");
                scanf("%d %d", &index, &value);
                insert(&arr, index, value);
                display(arr);
                break;
            }
        case 3:
            {
                int index;
                printf("Enter index to delete: ");
                scanf("%d", &index);
                del(&arr, index);
                display(arr);
                break;
            }
        case 4:
            {
                int key;    
                printf("Enter element to search: ");
                scanf("%d", &key);
                int result = LinearSearch(arr, key);
                if(result != -1){
                    printf("Element found at index %d\n", result);
                } else {
                    printf("Element not found\n");
                }
                break;
            }
        case 5:
            {
                int key;    
                printf("Enter element to search: ");
                scanf("%d", &key);
                int result = BinarySearch(arr, key);
                if(result != -1){
                    printf("Element found at index %d\n", result);
                } else {
                    printf("Element not found\n");
                }
                break;
            }
        case 6:
            {
                int index;    
                printf("Enter index to get value: ");
                scanf("%d", &index);
                int value = get(arr, index);
                if(value != -1){
                    printf("Element at index %d is %d\n", index, value);
                } else {
                    printf("Invalid index\n");
                }
                break;
            }
        case 7:
            {
                int index, value;    
                printf("Enter index and value to set: ");
                scanf("%d %d", &index, &value);
                if(set(&arr, index, value)){
                    printf("Element set successfully\n");
                } else {
                    printf("Invalid index\n");
                }
                break;
            }
        case 8:
            {
                int max = Max(arr);
                printf("Maximum element is %d\n", max);
                break;
            }
        case 9:
            {
                int min = Min(arr);
                printf("Minimum element is %d\n", min);
                break;
            }
        case 10:
            {
                int total = sum(arr);
                printf("Sum of elements is %d\n", total);
                break;
            }
        case 11:
            {
                int avg = average(arr);
                printf("Average of elements is %d\n", avg);
                break;
            }
        case 12:
            {
                reverseAuxiliary(&arr);
                printf("Array reversed using auxiliary array\n");
                display(arr);
                break;
            }
        case 13:
            {
                reverseSwap(&arr);
                printf("Array reversed using swapping\n");
                display(arr);
                break;
            }
        case 14:
            {
                int x;
                printf("Enter element to insert in sorted array: ");
                scanf("%d", &x);
                if(insertSorted(&arr, x)){
                    printf("Element inserted successfully\n");
                } else {
                    printf("Array is full\n");
                }
                display(arr);
                break;
            }
        case 15:
            {
                if(isSorted(arr)){
                    printf("Array is sorted\n");
                } else {
                    printf("Array is not sorted\n");
                }
                break;
            }
        case 16:
            {
                rearrange(&arr);
                printf("Array rearranged\n");
                display(arr);
                break;
            }
        case 17:
            {
                struct Array arr2;
                printf("Enter size of second array: ");
                scanf("%d", &arr2.size);
                arr2.A = new int[arr2.size];
                printf("Enter number of elements in second array: ");
                scanf("%d", &arr2.length);
                printf("Enter elements of second array: ");
                for(int i=0; i<arr2.length; i++){
                    scanf("%d", &arr2.A[i]);
                }
                struct Array *arr3 = mergeArray(arr, arr2);
                printf("Merged array: \n");
                display(*arr3);
                delete[] arr2.A;
                delete[] arr3->A;
                delete arr3;
                break;
            }
        case 18:
            {
                struct Array arr2;
                printf("Enter size of second array: ");
                scanf("%d", &arr2.size);
                arr2.A = new int[arr2.size];
                printf("Enter number of elements in second array: ");
                scanf("%d", &arr2.length);
                printf("Enter elements of second array: ");
                for(int i=0; i<arr2.length; i++){
                    scanf("%d", &arr2.A[i]);
                }
                struct Array *arr4 = unionArray(arr, arr2);
                printf("Union of arrays: \n");
                display(*arr4);
                delete[] arr2.A;
                delete[] arr4->A;
                delete arr4;
                break;
            }
        case 19:
            {
                struct Array arr2;
                printf("Enter size of second array: ");
                scanf("%d", &arr2.size);
                arr2.A = new int[arr2.size];
                printf("Enter number of elements in second array: ");
                scanf("%d", &arr2.length);
                printf("Enter elements of second array: ");
                for(int i=0; i<arr2.length; i++){   
                    scanf("%d", &arr2.A[i]);
                }
                struct Array *arr5 = intersectionArray(arr, arr2);
                printf("Intersection of arrays: \n");
                display(*arr5);
                delete[] arr2.A;
                delete[] arr5->A;
                delete arr5;
                break;
            }
        case 20:
            {
                struct Array arr2;
                printf("Enter size of second array: ");
                scanf("%d", &arr2.size);
                arr2.A = new int[arr2.size];
                printf("Enter number of elements in second array: ");
                scanf("%d", &arr2.length);
                printf("Enter elements of second array: ");
                for(int i=0; i<arr2.length; i++){   
                    scanf("%d", &arr2.A[i]);
                }
                struct Array *arr6 = differenceArray(arr, arr2);    
                printf("Difference of arrays (arr1 - arr2): \n");
                display(*arr6);
                delete[] arr2.A;
                delete[] arr6->A;
                delete arr6;
                break;
            }
        default:
            printf("Invalid choice\n");
    }

    // Clean up dynamically allocated memory
    delete[] arr.A;
    
    return 0;
}
