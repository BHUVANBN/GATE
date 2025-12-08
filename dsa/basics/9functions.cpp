//functions is a piece of code that performs a specific task
#include<iostream>
#include<cstring>
using namespace std;
//monolithic program - all code in main function
//modular program/procedural program - code is divided into functions

int add(int a , int b){ //function definition, a and b are formal parameters
    return a + b;
}
int main(){
    int res=add(5, 10); //function call , 5, 10 are actual parameters
    printf("Sum: %d\n", res);
    
    return 0;
}