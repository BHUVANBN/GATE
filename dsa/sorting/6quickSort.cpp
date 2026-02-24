//quick sort - an element is in sorted position if the elements to its left are smaller and elements to its right are larger
//pivot - element which is in its sorted position
//select 1st element as pivot
//iterate from left to right (using i) and find elements greater than pivot
//iterate from right to left (using j) and find elements smaller than pivot
//swap those elements
//do this until i < j
//now swap the pivot with element at j
//repeat for left and right parts of array (recursively)

//each round is called partitioning procedure

//number of partitions = n
//number of comparisons = n(n-1)/2
//number of swaps = n-1
//time complexity = O(n^2) when array is sorted or reverse sorted
//space complexity = O(log n)

//best case = O(n log n) when pivot is always middle element
//worst case = O(n^2) when pivot is always first or last element
//average case = O(n log n)

//randomised quick sort - pivot is chosen randomly
//other names - partition-exchange sort, selection-exchange sort, divide-and-conquer sort
#include<iostream>
using namespace std;

int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low;
    int j = high;
    
    while (i < j) {
        while (arr[i] <= pivot && i <= high - 1) {
            i++;
        }
        while (arr[j] > pivot && j >= low + 1) {
            j--;
        }
        if (i < j) {
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[low], arr[j]);
    return j;
}
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
