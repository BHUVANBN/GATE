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

class Array { //array with its properties
    private: 
        int *A;
        //int A[10]; //static array declaration for merging example
        int size;
        int length;
    public:
        Array(){
            size = 10;
            length = 0;
            A = new int[size];
        }
        Array(int sz){ //constructor to initialize array
            size = sz;
            length = 0;
            A = new int[size];
        }
        Array(const Array &other){ //copy constructor
            size = other.size;
            length = other.length;
            A = new int[size];
            for(int i = 0; i < length; i++){
                A[i] = other.A[i];
            }
        }
        ~Array(){ //destructor to free memory
            delete[] A;
        } 
        int display(); //traversal
        void append(int x); //insertion at end
        void insert(int index, int value); //insertion at given index
        void del(int index); //deletion at given index
        int LinearSearch(int key); //linear search
        int BinarySearch(int key); //binary search
        int get(int index); //get value at given index
        void set(int index, int value); //set value at given index or replace
        int Max(); //find max element
        int Min(); //find min element
        int sum(); //sum of all elements
        float average(); //average of all elements
        int reverseAuxiliary(); //reverse using auxiliary array
        int BinarySearchRecursive(int l, int h, int key); //binary search using recursion
        void reverseSwap(); //reverse the array
        int insertSorted(int x); //insert in sorted array
        int isSorted(); //check if array is sorted
        void rearrange(); //rearrange negative and positive elements
        Array* mergeArray(Array arr2); //merge two sorted arrays
        Array* unionArray(Array arr2); //union of two arrays
        Array* intersectionArray(Array arr2); //intersection of two arrays
        Array* differenceArray(Array arr2); //difference of two arrays

    };

int Array::display(){ //traversal, time complexity O(n)
    int i;
    cout<<"Elements in the array are: ";
    for(i=0; i<length; i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
    return 0;
}

void Array::append(int x){ //insertion at end, time complexity O(1)
    if(length < size){
        A[length++] = x;
    }
}

void Array::insert(int index, int value){ //insertion at given index, time complexity O(n)
    if(index<0 || index>length){
        return;
    }
    for(int i = length; i>index; i--){
        A[i] = A[i-1];
    }
    A[index] = value;
    length++;
}

void Array::del(int index){ //deletion at given index, time complexity O(n)
    if(index<0 || index>=length){
        return;
    }
    for(int i = index; i<length-1; i++){
        A[i] = A[i+1];
    }
    length--;
}

int Array::LinearSearch(int key){ //linear search, time complexity O(n)
    for(int i=0; i<length; i++){
        if(A[i] == key){
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

int Array::BinarySearch(int key){ //binary search applies on sorted array, time complexity O(log n)
    int l=0; //lower bound
    int h=length-1; //upper bound
    int mid;
    while(l<=h){ //when element not found, l will cross h
        mid = (l+h)/2;
        if(A[mid] == key){
            return mid; // function exits when element is found
        }
        else if(A[mid] < key){
            l = mid + 1;
        }
        else{
            h = mid - 1;
        }
    }
    return -1; //element not found
}
int Array::BinarySearchRecursive(int l, int h, int key){ //binary search using recursion
    int mid;
    if(l<=h){
        mid = (l+h)/2;
        if(A[mid] == key){
            return mid;
        }
        else if(A[mid] < key){
            return BinarySearchRecursive(mid+1, h, key);
        }
        else{
            return BinarySearchRecursive(l, mid-1, key);
        }
    }
    return -1; //element not found
}
int Array::get(int index){ //get value at given index, time complexity O(1)
    if(index>=0 && index<length){
        return A[index];
    }
    return -1; //invalid index
}
void Array::set(int index, int value){ //set value at given index or replace, time complexity O(1)
    if(index>=0 && index<length){
        A[index] = value;
    }
}
int Array::Max(){ //find max element, time complexity O(n)
    if(length == 0){
        cout << "Array is empty!" << endl;
        return -1;
    }
    int max = A[0];
    for(int i=1; i<length; i++){
        if(A[i]>max){
            max = A[i];
        }
    }
    return max;
}
int Array::Min(){ //find min element, time complexity O(n)
    if(length == 0){
        cout << "Array is empty!" << endl;
        return -1;
    }
    int min = A[0];
    for(int i=1; i<length; i++){
        if(A[i]<min){
            min = A[i];
        }
    }
    return min;
}
int Array::sum(){ //sum of all elements, time complexity O(n)
    int sum = 0;
    for(int i=0; i<length; i++){
        sum +=A[i];
    }
    return sum;
}
float Array::average(){ //average of all elements, time complexity O(n)
    if(length == 0){
        cout << "Array is empty!" << endl;
        return -1;
    }
    return sum()/length;
}
//reversing array can be done using auxiliary array or by swapping elements
//using auxiliary array - time complexity O(n), space complexity O(n)
int Array::reverseAuxiliary(){ //reverse using auxiliary array - time complexity O(n), space complexity O(n)
    if(length == 0){
        return 0;
    }
    int *B = new int[length];
    int i,j;
    for(i=length-1, j=0; i>=0; i--, j++){ //copying elements in reverse order
        B[j] = A[i];
    }
    for(i=0; i<length; i++){ //copying back to original array
        A[i] = B[i];
    }
    delete[] B; //free allocated memory
    return 0;
}
//using swapping - time complexity O(n), space complexity O(1)
//swapping elements from start and end, eg: swap first and last, second and second last and so on
void Array::reverseSwap(){ //reverse using swapping - time complexity O(n), space complexity O(1)
    if(length == 0){
        return;
    }
    int i, j;
    for(i=0, j=length-1; i<j; i++, j--){
        int temp = A[i];
        A[i] =  A[j];
        A[j] = temp;
    }
}
//Left shift - shifts all elements to left, first element comes out and last position is 0
//Right shift - shifts all elements to right, last element comes out and first position is 0
//Left rotate - shifts all elements to left, first element goes to last position    
//Right rotate - shifts all elements to right, last element goes to first position
//used in circular arrays, scrolling ads, image viewers etc.

//inserting in sorted array - insert element at correct position to keep array sorted
int Array::insertSorted(int x){ //insert in sorted array - time complexity O(n)
    if(length == size){ //check if array is full
        return 0;
    }
    int i = length - 1;
    while(i>=0 && A[i]>x){ //find position to insert
        A[i+1] = A[i]; //shift elements to right
        i--;
    }
    A[i+1] = x; //insert element
    length++;
    return 1; //success
}
//check if array is sorted
int Array::isSorted(){ //check if array is sorted - time complexity O(n)
    for(int i=0; i<length-1; i++){
        if(A[i]>A[i+1]){
            return 0; //not sorted
        }
    }
    return 1; //sorted
}
//rearrange - move negative elements to left and positive to right
void Array::rearrange(){ //rearrange negative elements to left and positive to right - time complexity O(n)
    int i=0, j=length-1;
    while(i<j){
        while(A[i]<0) i++;
        while(A[j]>=0) j--;
        if(i<j){
            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }
}
//Merging - merge two sorted arrays into a third sorted array
Array* Array::mergeArray(Array arr2){ //merge two sorted arrays - time complexity O(n+m)
    Array *arr3 = new Array(size + arr2.size);
    arr3->length = 0;

    int i=0, j=0, k=0;
    while(i<length && j<arr2.length){
        if(A[i]<arr2.A[j]){
            arr3->A[k++] = A[i++];
        }
        else{
            arr3->A[k++] = arr2.A[j++];
        }
    }
    for(; i<length; i++){
        arr3->A[k++] = A[i];
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
Array* Array::unionArray(Array arr2){ //union of two arrays
    Array *arr3 = new Array(size + arr2.size);
    arr3->length = 0;
    int i=0, j=0, k=0;
    while(i<length && j<arr2.length){
        if(A[i]<arr2.A[j]){
            arr3->A[k++] = A[i++];
        }
        else if(arr2.A[j]<A[i]){
            arr3->A[k++] = arr2.A[j++];
        }
        else{
            arr3->A[k++] = A[i++];
            j++;
        }
    }
    for(; i<length; i++){
        arr3->A[k++] = A[i];
    }
    for(; j<arr2.length; j++){
        arr3->A[k++] = arr2.A[j];
    }
    arr3->length = k;
    return arr3;
}
Array* Array::intersectionArray(Array arr2){ //intersection of two arrays
    Array *arr3 = new Array((size < arr2.size) ? size : arr2.size);
    arr3->length = 0;
    int i=0, j=0, k=0;
    while(i<length && j<arr2.length){
        if(A[i]<arr2.A[j]){
            i++;
        }
        else if(arr2.A[j]<A[i]){
            j++;
        }
        else{
            arr3->A[k++] = A[i++];
            j++;
        }
    }
    arr3->length = k;
    return arr3;
}
Array* Array::differenceArray(Array arr2){ //difference of two arrays
    Array *arr3 = new Array(size);
    arr3->length = 0;
    int i=0, j=0, k=0;
    while(i<length && j<arr2.length){
        if(A[i]<arr2.A[j]){
            arr3->A[k++] = A[i++];
        }
        else if(arr2.A[j]<A[i]){
            j++;
        }
        else{
            i++;
            j++;
        }
    }
    for(; i<length; i++){
        arr3->A[k++] = A[i];   
    }
    arr3->length = k;
    return arr3;
}

int main(){
    //Menu driven program using OOP approach
    Array arr;
    int n, i;
    printf("Enter size of array: ");
    scanf("%d", &n);
    Array arr1(n); //using parameterized constructor
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements of array: ");
    for(i=0; i<n; i++){
        int val;
        scanf("%d", &val);
        arr1.append(val);
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
                arr1.append(x);
                arr1.display();
                break;
            }
        case 2:
            {
                int index, value;
                printf("Enter index and value to insert: ");
                scanf("%d %d", &index, &value);
                arr1.insert(index, value);
                arr1.display();
                break;
            }
        case 3:
            {
                int index;
                printf("Enter index to delete: ");
                scanf("%d", &index);
                arr1.del(index);
                arr1.display();
                break;
            }
        case 4:
            {
                int key;    
                printf("Enter element to search: ");
                scanf("%d", &key);
                int result = arr1.LinearSearch(key);
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
                int result = arr1.BinarySearch(key);
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
                int value = arr1.get(index);
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
                arr1.set(index, value);
                printf("Element set successfully\n");
                break;
            }
        case 8:
            {
                int max = arr1.Max();
                printf("Maximum element is %d\n", max);
                break;
            }
        case 9:
            {
                int min = arr1.Min();
                printf("Minimum element is %d\n", min);
                break;
            }
        case 10:
            {
                int total = arr1.sum();
                printf("Sum of elements is %d\n", total);
                break;
            }
        case 11:
            {
                int avg = arr1.average();
                printf("Average of elements is %d\n", avg);
                break;
            }
        case 12:
            {
                arr1.reverseAuxiliary();
                printf("Array reversed using auxiliary array\n");
                arr1.display();
                break;
            }
        case 13:
            {
                arr1.reverseSwap();
                printf("Array reversed using swapping\n");
                arr1.display();
                break;
            }
        case 14:
            {
                int x;
                printf("Enter element to insert in sorted array: ");
                scanf("%d", &x);
                if(arr1.insertSorted(x)){
                    printf("Element inserted successfully\n");
                } else {
                    printf("Array is full\n");
                }
                arr1.display();
                break;
            }
        case 15:
            {
                if(arr1.isSorted()){
                    printf("Array is sorted\n");
                } else {
                    printf("Array is not sorted\n");
                }
                break;
            }
        case 16:
            {
                arr1.rearrange();
                printf("Array rearranged\n");
                arr1.display();
                break;
            }
        case 17:
            {
                int size2;
                printf("Enter size of second array: ");
                scanf("%d", &size2);
                Array arr2(size2);
                printf("Enter number of elements in second array: ");
                scanf("%d", &n);
                printf("Enter elements of second array: ");
                for(int i=0; i<n; i++){
                    int val;
                    scanf("%d", &val);
                    arr2.append(val);
                }
                Array *arr3 = arr1.mergeArray(arr2);
                printf("Merged array: \n");
                arr3->display();
                delete arr3;
                break;
            }
        case 18:
            {
                int size2;
                printf("Enter size of second array: ");
                scanf("%d", &size2);
                Array arr2(size2);
                printf("Enter number of elements in second array: ");
                scanf("%d", &n);
                printf("Enter elements of second array: ");
                for(int i=0; i<n; i++){
                    int val;
                    scanf("%d", &val);
                    arr2.append(val);
                }
                Array *arr4 = arr1.unionArray(arr2);
                printf("Union of arrays: \n");
                arr4->display();
                delete arr4;
                break;
            }
        case 19:
            {
                int size2;
                printf("Enter size of second array: ");
                scanf("%d", &size2);
                Array arr2(size2);
                printf("Enter number of elements in second array: ");
                scanf("%d", &n);
                printf("Enter elements of second array: ");
                for(int i=0; i<n; i++){   
                    int val;
                    scanf("%d", &val);
                    arr2.append(val);
                }
                Array *arr5 = arr1.intersectionArray(arr2);
                printf("Intersection of arrays: \n");
                arr5->display();
                delete arr5;
                break;
            }
        case 20:
            {
                int size2;
                printf("Enter size of second array: ");
                scanf("%d", &size2);
                Array arr2(size2);
                printf("Enter number of elements in second array: ");
                scanf("%d", &n);
                printf("Enter elements of second array: ");
                for(int i=0; i<n; i++){   
                    int val;
                    scanf("%d", &val);
                    arr2.append(val);
                }
                Array *arr6 = arr1.differenceArray(arr2);    
                printf("Difference of arrays (arr1 - arr2): \n");
                arr6->display();
                delete arr6;
                break;
            }
        default:
            printf("Invalid choice\n");
    }
    
    return 0;
}
