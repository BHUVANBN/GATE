#include<stdio.h>
// Function to calculate sum of series 1 + x/1! + x^2/2! + x^3/3! + .... + x^n/n!
// e^x = 1 + x/1! + x^2/2! + x^3/3! + ....
// it is used to calculate exponential value of x, with n terms
// time complexity - O(n^2)
// space complexity - O(n) due to function call stack
double ts(int x, int n){
    static double power=1, fact = 1;
    if(n==0) return 1;
    double res = ts(x,n-1);
    power = power * x;
    fact = fact * n;
    return  res + power/fact;
}
/*
we can reduce the time complexity to O(n) by taking common terms of x and n in each recursive call
eg: e^x =  1 + x/1! + x^2/2! + x^3/3! + ....
            = 1 + x/1! (1 + x/2 (1 + x/3 (1 + ... )))
*/

//using loop
double ts_loop(int x, int n){
    double sum = 1;
    for(;n>0;n--){
        sum = 1+sum * x/n;
    }
    return sum;
}
//recursive approach
double ts_optimized(int x, int n){
    static double res = 1;
    if(n==0) return res;
    res = 1 + res * x/n;
    return ts_optimized(x,n-1);
}
int main(){
    int x,n;
    printf("Enter the value of x and n: ");
    scanf("%d %d",&x,&n);
    printf("The sum of the series is: %lf\n",ts(x,n));
    printf("The sum of the series using loop is: %lf\n",ts_loop(x,n));
    printf("The sum of the series using optimized recursion is: %lf\n",ts_optimized(x,n));
    return 0;
}