//Array - A collection of elements of the same data type stored in contiguous memory locations.
//scalar variable - single value
//vector variable - multiple values on 1 Dimension. eg: array
//matrix variable - multiple values on 2 Dimensions ( rows and columns). eg: 2D array
//tensor variable - multiple values on more than 2 Dimensions. eg: 3D array

#include<stdio.h>
int main(){
    int arr1[5]; //declaration of array of size 5, has garbage values
    int arr2[5] = {1,2,3,4,5}; //declaration and initialization of array
    int arr3[5] = {1,2}; //declaration and partial initialization of array, rest elements are initialized to 0
    int arr4[5] = {0}; //declaration and initialization of all elements to 0
    int arr5[] = {1,2,3,4,5,6,7}; //declaration and initialization of array without size, size is determined by number of elements
    
    //accessing array elements
    printf("accessing element via index: %d \n", arr2[0]); //accessing first element
    printf("accessing element via index: %d \n", 4[arr2]); //it can also be accessed like this, accessing first element
    printf("accessing element via pointer: %d \n", *(arr2 + 4)); //accessing last element
    //traversing array
    printf("arr2 elements with their addresses: \n");
    for(int i=0;i<5;i++){
        printf("%d %u \n", arr2[i], &arr2[i]);
    }
    printf("\n");
    return 0;
}