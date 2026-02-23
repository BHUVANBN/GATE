///Selection sort- select a position and put the correct element at that position
//select a place and put the correct element at that place (i is used to select the place)
//iterate usring 2 pointers j and k, k points to min element, j is used to iterate 
//at last swap the min element with the element at position i
//for each round/pass elements are sorted from the 0th index and so on 

//intermediate results give smallest element at the start
#include<iostream>
using namespace std;
void SelectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int k = i; //k points to the index of the minimum element
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[k]) {
                k = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[k];
        arr[k] = temp;
    }
}
//numbver of comparisions = n(n-1)/2
//number of swaps = n-1
//time complexity = O(n^2)
//space complexity = O(1)
//adaptive = no, always O(n^2) time complexity
//stable = no
//inplace = yes

//if array is already sorted - best case - O(n^2)
//if array is reverse sorted - worst case - O(n^2)
//if array is random - average case - O(n^2)
int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    SelectionSort(arr, n);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}