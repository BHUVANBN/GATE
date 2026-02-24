//insertion sort is done on sorted array, designed for linked list
//insertion of element is done in the correct place after sifting elements
//from the last element compare the element with the previous elements and shift the elements to the right until the correct position is found
//if the element is smalled than the key insert the key in index(element)+1 
//for linkedlist insertion is O(1) but finding the position is O(n)

//the array is divided into two parts - sorted and unsorted
//initially the sorted part has only one element (element at index 0)
//the insertion is done in the correct position in the sorted part from unsorted part

//number of rounds = n-1 
//number of comparisons = n(n-1)/2
//number of swaps = n(n-1)/2
//time complexity = O(n^2) when array is reverse sorted
//space complexity = O(1)
//adaptive = yes by its nature
//stable = yes
//inplace = yes
#include <iostream>
using namespace std;
void insertionSort(int arr[], int n) {
    for(int i = 1; i < n; i++) { //for rounds
        int j = i-1;
        int x = arr[i];
        while(arr[j]>x && j>=0) {
            arr[j+1] = arr[j]; //shift elements to the right
            j--;
        }
        arr[j+1] = x; //insert element at correct position
    }
}
//best case = O(n) when array is already sorted
//worst case = O(n^2) when array is reverse sorted
//average case = O(n^2)

int main() {
    int arr[] = {5, 2, 4, 6, 1, 3};
    int n = 6;
    insertionSort(arr, n);
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}

//Bubble sort vs Insertion sort
/*
                    Bubble Sort              Insertion Sort

Min Comparisons        n−1 (optimized)       n−1
Max Comparisons        n(n−1)/2              n(n−1)/2

Min Swaps              0                     0
Max Swaps              n(n−1)/2              n(n−1)/2 (if swap-based)
                                               but only n−1 shifts (shift-based)
Adaptive               Yes (with flag)       Yes (naturally)
Stable                 Yes                   Yes
In-place               Yes                   Yes
Suitable for LL        No                    Yes
*/