//here sorting decimal numbers requires array with size 10 (0-9 bins)
//similarly sorting binary numbers requires array with size 2 (0-1 bins)
//check ones place of each number and drop it in the bin
// now take out the elements from the bin and drop them in the array
// repeat the process for tens place and then hundreds place and so on (i.e largest numbers digits)

//time complexity = O(nk) //n is number of elements and k is number of digits
//space complexity = O(n+k)
#include <iostream>
using namespace std;

// Get maximum element
int getMax(int A[], int n){
    int max = A[0];
    for(int i = 1; i < n; i++)
        if(A[i] > max)
            max = A[i];
    return max;
}

// Stable counting sort based on digit (exp = 1, 10, 100...)
void countSort(int A[], int n, int exp){
    int output[n];      // temporary array
    int count[10] = {0}; // digits 0-9

    // Count occurrences of current digit
    for(int i = 0; i < n; i++)
        count[(A[i] / exp) % 10]++;

    // Prefix sum (cumulative count)
    for(int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Build output array (right to left for stability)
    for(int i = n - 1; i >= 0; i--){
        int digit = (A[i] / exp) % 10;
        output[count[digit] - 1] = A[i];
        count[digit]--;
    }

    // Copy back
    for(int i = 0; i < n; i++)
        A[i] = output[i];
}

// Main radix sort
void radixSort(int A[], int n){
    int max = getMax(A, n);

    for(int exp = 1; max / exp > 0; exp *= 10)
        countSort(A, n, exp);
}

int main(){
    int A[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(A)/sizeof(A[0]);
    radixSort(A, n);
    for(int i = 0; i < n; i++)
        cout << A[i] << " ";
    return 0;
}