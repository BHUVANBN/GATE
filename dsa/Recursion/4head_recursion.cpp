//Head recursion - when the recursive call is the first statement in the function
#include<stdio.h>
using namespace std;
void head_recursion(int n){
    if(n>0){
        head_recursion(n-1); //recursive call is the first statement
        printf("%d ",n);
    }
}
int main(){ 
    head_recursion(3); //time complexity - O(n), space complexity - O(n) due to function call stack
    //it cannot be done by while loop easily
    return 0;
}

/*  
function call tree for head_recursion(3)
          head_recursion(3)
          /        \
     head_recursion(2)   print 3
       /        \
  head_recursion(1)   print 2
    /        \
head_recursion(0)   print 1
     |
  base condition
Time complexity - O(n)
*/