//Recursive function - function calling itself
//it contains - a base condition and a recursive call
#include<iostream>
#include<stdio.h>
using namespace std;

void fun1(int n){ //prints in decreasing order
    if(n>0){
        printf("%d ",n); //printing in done before the recursive call
        fun1(n-1);
    }
}
/*
tree of fun1(3)
          fun1(3)
         /     \
  \     3     fun1(2)
   \          /     \
    \        2    fun1(1)
     \              /     \
      \            1    fun1(0)
       \                  |
        \V              base condition
      
*/

void fun2(int n){ //prints in increasing order
    if(n>0){
        fun2(n-1);
        printf("%d ",n); //printing is done when the function returns from the recursive call
    }
}
/*
tree of fun2(3)
          fun2(3)        _
         /     \          /\ 
      fun2(2)    3       /
       /     \          / 
    fun2(1)    2       /
     /     \          /
  fun2(0)    1       /
     |
    base condition
*/
int fib(int n){
    if(n<=1) return 1;
    return fib(n-1)*n;
}
int main(){
    int result = fib(4);
    printf("%d\n",result);

    fun1(3);
    printf("\n");
    fun2(3);
    return 0;
}
/*
void fun(int n){
    statements execute when calling time 
    fun(n-1);
    statements execute when returning time
}

Time complexity - O(n)

Types of recursion
1. Tail recursion - when the recursive call is the last statement in the function
2. Head recursion - when the recursive call is the first statement in the function
3. Tree recursion - when a function makes more than one recursive call
4. Indirect recursion - when a function calls another function which in turn calls the first function
5. Nested recursion - when a function calls itself with a parameter that is the result of another call to the same function
*/