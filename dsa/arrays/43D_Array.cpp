//2D array - for implementing matrix, table etc.
//in real memory is allocated in a single contiguous block but we can visualize it in rows and columns and access elements using row and column indices.
#include<stdio.h>

int main(){
    //static 2D array
    int arr[3][4] = {  {1,2,3,4},  //creation of 2D array in stack
                       {5,6,7,8},
                       {9,10,11,12}  }; //declaration and initialization of 
    
    //using array of pointers
    int* ptrs[3]; //created in stack
    for(int i=0;i<3;i++){    
        ptrs[i] = new int[4]; //allocation of dynamic array for each row
        //each pointer in ptrs points to a dynamic array of size 4
        //to access element at row i and column j, we can use ptrs[i][j]
        //ptrs[i] = (int *)malloc(4 * sizeof(int)); //allocation of dynamic array for each row in C
    }

    //using double pointer
    int** dptr; //pointer to pointer , created in stack
    dptr = new int*[3]; //allocation of array of pointers for 3 rows
    //dptr = (int **)malloc(3 * sizeof(int*)); //allocation of array of pointers for 3 rows in C
    for(int i=0;i<3;i++){
        dptr[i] = new int[4]; //allocation of dynamic array for each row
        //dptr[i] = (int *)malloc(4 * sizeof(int)); //allocation of dynamic array for each row in C
    }

    //accessing elements of static 2D array
    printf("Static 2D Array elements: \n");
    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    
    return 0;
}