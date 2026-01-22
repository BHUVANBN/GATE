#include<stdio.h>
#include<iostream>
using namespace std;
int sum(int n){
    if(n<=0) return 0;
    return n+sum(n-1);
}
int factorial(int n){
    if(n<=0) return 1;
    return n*factorial(n-1);
}
int main(){
    printf("sum of %d natural no: %d\n", 5, sum(5)); //output - 15
    printf("factorial of %d: %d\n", 5, factorial(5)); //output - 120
    return 0;
}
/*
formula for sum of first n natural numbers = n(n+1)/2
time complexity - O(n)
space complexity - O(n) due to function call stack

we can implement using loops with O(1) space complexity
*/