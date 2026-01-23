//static variable in recursion is a variable that retains its value between function calls.
#include<stdio.h>
using namespace std;
//local variable - for every function call, a new copy of the variable is created and destroyed when the function returns.
//static variable - only one copy of the variable is created and retains its value between function calls.
int fun(int n){ //no static variable
    if(n>0){
        return fun(n-1)+n;
    }
    return 0;
}
/*
function call tree for fun(3)
           fun(3)
          /     \
     fun(2)     3+3=6
      /   \
  fun(1)   2+1=3
   /   \
fun(0)   1+0 =1
    |
    0

n is created in each function call and destroyed when the function returns.
Time complexity - O(n)
*/

//int sum = 0; //global variable (not recommended) - result will be same as static variable
int fun_static(int n){ //with static variable
    static int sum = 0; //static variable retains its value between function calls
    if(n>0){
        sum ++;
        return fun_static(n-1) + sum;
    }
    return 0;
}
/*
function call tree for fun_static(3)
        fun_static(3)        sum = 0->1->2->3(last value retained)
          /          \
     fun_static(2)    3+6=9
      /           \
  fun_static(1)    3+3=6
   /           \
fun_static(0)   3+0=3 
    |
    0

sum is created only once and retains its value between function calls.
Time complexity - O(n)
*/
int main(){
    int result1 = fun(3);
    printf("Sum without static variable: %d\n",result1);
    int result2 = fun_static(3);
    printf("Sum with static variable: %d\n",result2);
    return 0;
}
