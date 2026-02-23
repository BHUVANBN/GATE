//merging two sorted array
//use i for first array and j for second array
//compare elements of both arrays and insert smaller element in third array
//if one array is exhausted, copy remaining elements of other array

#include<iostream>
using namespace std;
//merging two different sorted arrays
//m-way merging - merging m sorted arrays using m iterators
void merge2Arrays(int A[], int B[], int x, int y){
    int i,j,k;
    i=0;
    j=0;
    k=0;
    int C[x+y];
    while(i<x && j<y){
        if(A[i]<B[j]) C[k++]=A[i++];
        else C[k++]=B[j++];
    }
    for(;i<x;i++) C[k++]=A[i];
    for(;j<y;j++) C[k++]=B[j];
}
//merging two sorted sub-array in one array
//this is used in merge sort
void merge1Array(int A[], int low, int high, int mid){
    int i = low;
    int j = mid+1;
    int k = low;
    int B[high+1];
    while(i<=mid && j<=high){
        if(A[i]<A[j]) B[k++]=A[i++];
        else B[k++]=A[j++];
    }
    for(;i<=mid;i++) B[k++]=A[i];
    for(;j<=high;j++) B[k++]=A[j];

    for(int i=low;i<=high;i++) A[i]=B[i];
}
//merge sort - divide and conquer
//here each element is a subarray, so each element is merged with its adjacent element(2-way merging) recursively
/*eg:iterative version
    8  3  7  4  9  2  6  5
     \/    \/    \/    \/
     3,8   4,7   2,9   5,6
        \  /       \  /
       3,4,7,8    2,5,6,9
             \    /
         2,3,4,5,6,7,8,9

time complexity = O(n log n) //tree height = log n
space complexity = O(n)
*/
void mergeSortIterative(int A[], int n){
    int low, mid, high;
    int i;
    for(i = 2; i<=n; i*=2 ){  //logn rounds, eg: for n=8, 2,4,8 -> it says number os elements to be merged at each round
        for(int j = 0; j+i-1<n; j=j+i){
            low = j;
            high = j+i-1;
            mid = (low+high)/2;
            merge1Array(A, low, high, mid);
        }
    }
    if(i/2<n){ //for odd number of items
        merge1Array(A, 0, n-1, i/2-1);
    }
} 
//in recursive merge sort we divide array into two halves and sort them recursively
void mergeSortRecursive(int A[], int low, int high){
    if(low<high){//if there are more than one element in subarray
        int mid = (low+high)/2;
        mergeSortRecursive(A, low, mid);
        mergeSortRecursive(A, mid+1, high);
        merge1Array(A, low, high, mid);
    }
}
int main(){
    int A[] = {11, 13, 45, 7, 23, 21, 15};
    int n = sizeof(A)/sizeof(A[0]);
    //mergeSortIterative(A, n);
    mergeSortRecursive(A, 0, n-1);
    for(int i = 0; i<n; i++) cout<<A[i]<<" ";
    return 0;
}