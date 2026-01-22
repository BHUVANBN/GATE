// Nested Recursion - a recursive function takes itself as an argument
#include<stdio.h>
using namespace std;
int fun(int n){
    if(n>100){
        return n-10;
    }
    return fun(fun(n+11)); //nested recursive call
}
int main(){
    printf("%d\n", fun(95)); //time complexity - O(n), space complexity - O(n) due to function call stack
    return 0;
}
/*
function call tree for fun(95)

          fun(95)
             |
       fun(fun(106))
             |
          fun(96)
             |
       fun(fun(107))
             |
          fun(97)
             |
       fun(fun(108))
             |
          fun(98)
             |
       fun(fun(109))
             |
          fun(99)
             |
       fun(fun(110))
             |
          fun(100)
             |
       fun(fun(111))
             |
          fun(101)
             |
       91  <--- base condition met here and returns back up the call stack
*/