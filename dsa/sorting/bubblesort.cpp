//consecutive elements are compared and swapped accordingly
//there are n-1 rounds
//for each round n-1 comparision is made
//every round sorts the last element

//intermediate results give largest element at the end

#include<iostream>
using namespace std;
void BubbleSort(int arr[], int n) {
    int swapped;
    for (int i = 0; i < n - 1; i++) {       //for n-1 rounds
        swapped = 0;
        for (int j = 0; j < n - i - 1; j++) {   //for n-1 comparisions
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }
        if (swapped == 0) {  //if the elements are already in sorted order exit the loop after round 1
            break;
        }
    }   
}
//numbver of comparisions = n(n-1)/2
//number of swaps = n(n-1)/2
//time complexity = O(n^2)
//space complexity = O(1)
//adaptive = yes by adding a flag to check if any swaps were made
//stable = yes
//inplace = yes

//if array is already sorted - best case - O(n)
//if array is reverse sorted - worst case - O(n^2)
//if array is random - average case - O(n^2)

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    BubbleSort(arr, n);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}