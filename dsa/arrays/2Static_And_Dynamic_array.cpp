#include<stdio.h>
#include<iostream>
using namespace std;

int main(){
    //Static array - size is fixed at compile time
    int staticArr[5] = {1,2,3,4,5};
    printf("Static Array elements: \n");
    for(int i=0;i<5;i++){
        printf("%d ", staticArr[i]);
    }
    printf("\n");

    //Dynamic array - size can be changed at runtime
    int n;
    printf("Enter size of dynamic array: ");
    scanf("%d", &n);
    int* dynamicArr = new int[n]; //allocation of dynamic array in c++ using new keyword
    for(int i=0;i<n;i++){
        dynamicArr[i] = i+1; //initialization of dynamic array
    }
    printf("Dynamic Array elements in C++   : \n");
    for(int i=0;i<n;i++){
        printf("%d ", dynamicArr[i]);
    }
    printf("\n");
    delete[] dynamicArr; //deallocation of dynamic array

    //dynamic array in C using malloc and free
    int* cDynamicArr = (int*)malloc(n * sizeof(int)); //allocation of dynamic array in C using malloc
    for(int i=0;i<n;i++){
        cDynamicArr[i] = i+2; //initialization of dynamic array
    }
    printf("Dynamic Array elements in C: \n");
    for(int i=0;i<n;i++){
        printf("%d ", cDynamicArr[i]);
    }
    free(cDynamicArr); //deallocation of dynamic array in C
    
    return 0;
}