#include<iostream>
using namespace std;
//Parameter Passing in C++
//1. Pass by Value - actual parameters are copied to formal parameters, used when we do not want to modify actual parameters and return single value
//2. Pass by Address  - address of actual parameters are copied to formal parameters using pointers, used when we want to modify actual parameters
//3. Pass by Reference - address of actual parameters are copied to formal parameters using pointers

//Pass by Value
void swapByValue(int a, int b){
    int temp = a;
    a = b;
    b = temp;
}
void swapByAddress(int *a, int *b){ //pointers can take address of actual parameters, a function accessing variables using poiners indirectly
    int temp = *a;      //dereferencing pointers to get actual values
    *a = *b;
    *b = temp;
}
void swapByReference(int &a, int &b){ //references are aliases to actual parameters, a function accessing variables directly, only in C++
    int temp = a;
    a = b;
    b = temp;
}   
int main(){
    
    printf("Pass by Value\n");
    int a = 5;
    int b = 10;
    cout<<"Before Swap: a = "<<a<<", b = "<<b<<endl;
    swapByValue(a,b);
    cout<<"After Swap using Pass by Value: a = "<<a<<", b = "<<b<<endl; //values remain unchanged - swap happened only in function scope
    
    printf("\nPass by Address\n");
    int x = 15;
    int y = 20;
    cout<<"Before Swap: x = "<<x<<", y = "<<y<<endl;
    swapByAddress(&x,&y);
    cout<<"After Swap using Pass by Address: x = "<<x<<", y = "<<y<<endl; //values are changed - swap happened in main function scope
    
    printf("\nPass by Reference\n");
    int p = 25;
    int q = 30;
    cout<<"Before Swap: p = "<<p<<", q = "<<q<<endl;
    swapByReference(p,q);
    cout<<"After Swap using Pass by Reference: p = "<<p<<", q = "<<q<<endl; //values are changed - swap happened in main function scope

    return 0;
}
