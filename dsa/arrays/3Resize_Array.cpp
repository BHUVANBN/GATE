//Resize array is done only using pointers and dynamic memory allocation
#include<stdio.h>
#include<iostream>
using namespace std;
int main(){
    int *p = (int*)malloc(5 * sizeof(int)); //allocation of dynamic array of size 5
    for(int i=0;i<5;i++){
        p[i] = i+1; //initialization of dynamic array
    }
    printf("Original Array elements: \n");
    for(int i=0;i<5;i++){
        printf("%d ", p[i]);
    }
    printf("\n");

    //resizing array to size 10
    int *q = (int*)malloc(10 * sizeof(int)); //reallocation of dynamic array to size 10
    for(int i=0;i<5;i++){
        q[i] = p[i]; //copying old elements to new array
    }
    free(p); //deallocation of old array
    p = q; //pointing p to new array
    q=NULL; //setting q to NULL
    printf("Resized Array elements: \n");    
    for(int i=0;i<10;i++){
        printf("%d ", p[i]);
    }
    printf("\n");
    free(p); //deallocation of new array
    return 0;
}