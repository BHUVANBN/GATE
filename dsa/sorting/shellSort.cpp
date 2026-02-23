//Shell sort - gap based insertion sorting
//gap is initially n/2 and then gap is reduced by half
//gap is reduced until it becomes 1
//gap based sorting is used to sort the array
//this reduces the number of swaps significantly

//time complexity = O(nlog n) or O(n^3/2) 
//space complexity = O(1)
//adaptive
//in-place
#include <iostream>
using namespace std;

void shellSort(int A[], int n){
    // Start with a large gap, then reduce it
    for(int gap = n/2; gap > 0; gap /= 2){
        // Perform gapped insertion sort
        for(int i = gap; i < n; i++){
            int temp = A[i];
            int j = i;
            while(j >= gap && A[j - gap] > temp){
                A[j] = A[j - gap];
                j -= gap;
            }
            A[j] = temp;
        }
    }
}

int main(){
    int A[] = {23, 12, 1, 8, 34, 54, 2, 3};
    int n = sizeof(A)/sizeof(A[0]);
    shellSort(A, n);
    for(int i = 0; i < n; i++)
        cout << A[i] << " ";
    return 0;
}