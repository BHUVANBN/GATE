#include<stdio.h>
//recursive approach
int fib(int n){ //time complexity - O(2^n)
    if (n<=1)return n;
    return fib(n-1) + fib(n-2);
}
//iterative approach
int fib_iter(int n){ //time complexity - O(n)
    if(n<=1) return 1;
    int a=0,b=1,c;
    for(int i=2;i<=n;i++){
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}
//Excessive recursion - when the same subproblems are solved multiple times
//eg: fib(5) = fib(4) + fib(3)
//solution - keep an array to store the results of subproblems - memoization
int fib_memo(int n, int memo[]){ //time complexity - O(n)
    if(n<=1) return n;
    if(memo[n]!=-1) return memo[n];
    memo[n] = fib_memo(n-1,memo) + fib_memo(n-2,memo);
    return memo[n];
}

int main (){
    int n;
    printf("Enter the value of n: ");
    scanf("%d",&n);
    printf("The %dth Fibonacci number is: %d\n",n,fib(n));
    printf("The %dth Fibonacci number using iterative approach is: %d\n",n,fib_iter(n));

    int memo[n+1];
    for(int i=0;i<=n;i++) memo[i]=-1;
    printf("The %dth Fibonacci number using memoization approach is: %d\n",n,fib_memo(n,memo));

    return 0;
}