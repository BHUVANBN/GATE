// Algorithm Strategies - 
// 1. Divide and Conquer
// 2. Greedy Algorithms
// 3. Dynamic Programming
// 4. Backtracking

/*Divide and Conquer 
Problem --> Subproblems -->Solve independently --> Combine results 
subproblems are smaller instances of the same problem

Algorithm DAC(P){
    if (P is simple) return solution of P
    else {
        divide P into subproblems P1, P2, ..., Pk
        for i = 1 to k do
            solve Pi recursively by calling DAC(Pi)
        combine the solutions (DAC(P1), DAC(P2), ..., DAC(Pk)) 
    }
}

Eg: 
Binary Search on sorted list
    Algorithm BinarySearch(A, target, low, high){
        if (low > high) {
            return -1 // target not found
        }    
        mid = (low + high) / 2
        if (A[mid] == target) return mid
        else if (A[mid] < target) 
            return BinarySearch(A, target, mid + 1, high) // search in right half
        else 
            return BinarySearch(A, target, low, mid - 1) // search in left half    
    }

Merging - combining 2 sorted lists into a single sorted list
Algorithm Merge(A,B,m,n){
    int i = 0, j = 0, k = 0
    while (i < m && j < n) {
        if (A[i] <= B[j]) {
            C[k++] = A[i++]
        } else {
            C[k++] = B[j++]
        }
    }
    while (i < m) {
        C[k++] = A[i++]
    }
    while (j < n) {
        C[k++] = B[j++]
    }
}
Algorithm Merge_from_single_list(A,low, mid, high){
    int i = low, j = mid + 1, k = low
    while (i <= mid && j <= high) {
        if (A[i] <= A[j]) {
            B[k++] = A[i++]
        } else {
            B[k++] = A[j++]
        }
    }
    while (i <= mid) {
        B[k++] = A[i++]
    }
    while (j <= high) {
        B[k++] = A[j++]
    }
    for (i = low; i <= high; i++) {
        A[i] = B[i] // copy back to original array
    }
}


Merge Sort
    Algorithm MergeSort(A, low, high){
        if (low < high) {
            mid = (low + high) / 2
            MergeSort(A, low, mid) // sort left half
            MergeSort(A, mid + 1, high) // sort right half
            Merge(A, low, mid, high) // merge sorted halves
        }
    }
*/