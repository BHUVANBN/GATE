//Array cannot be passed by value to functions in C++, 
//instead we pass the address of first element of array, so its pointer passing
#include<iostream>
using namespace std;

//function taking array as parameter 
void printArray(int arr[], int size){ //arr is pointer to first element of array, use *arr or arr[] both are same
    //arr[] this is pointer to array only
    for(int i=0; i<size; i++){ //for each loop cannot be used because it is pointer not array
        cout<<arr[i]<<" "; //accessing array elements using pointer
    }
    cout<<endl;
}
//function returning Array
int* getArray(){
    int *arr; //pointer to int
    arr = (int*)malloc(5 * sizeof(int)); //dynamically allocating memory for array using malloc
    return arr; //returning pointer to array
}
int main(){
    int myArray[] = {1, 2, 3, 4, 5};
    printf("%d\n",sizeof(myArray)); //in bytes
    int size = sizeof(myArray)/sizeof(myArray[0]);
    printArray(myArray, size); //passing array to function, actually passing address of first element

    int *newArray = getArray(); //getting array from function

    return 0;
}