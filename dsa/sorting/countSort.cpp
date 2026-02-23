//Count Sort - Index based sorting
//fastest sorting algorithm but requires more space 

//size of count array = max element in array
//count array index act as element and value act as frequency of that element
//initialize count array with 0
//count frequency of each element
//now traverse the count array and put its index in array with value times and make value 0
//place elements in sorted order

//time complexity = O(n)
//space complexity = O(n)

#include<iostream>
using namespace std;

void countSort(int A[], int n){
    int max = A[0];
    for(int i = 1; i < n; i++) // Find max
        if(A[i] > max)
            max = A[i];
    int *count = new int[max + 1];// Allocate count array
    for(int i = 0; i <= max; i++) count[i] = 0;
    for(int i = 0; i < n; i++) // Count frequency
        count[A[i]]++;
    int j = 0;
    int i = 0;
    while(j< max+1){
        if(count[j]>0){
            A[i++] = j;
            count[j]--;
        }
        else j++;
    }
    delete[] count;
}

int main(){
    int A[] = {5, 3, 8, 3, 1, 0, 5};
    int n = sizeof(A)/sizeof(A[0]);
    countSort(A, n);
    for(int i = 0; i < n; i++)
        cout << A[i] << " ";
    return 0;
}