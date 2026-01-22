//Tail recursion - when the recursive call is the last statement in the function
#include<stdio.h>
using namespace std;

void tail_recursion(int n){
    if(n>0){
        printf("%d ",n);
        tail_recursion(n-1); //recursive call is the last statement
    }
}
int main(){ 
    printf("Using tail recursion:\n");
    tail_recursion(3); //time complexity - O(n), space complexity - O(n) due to function call stack
    //it is also done by while loop
    printf("\nUsing while loop:\n");
    int n =3;
    while(n>0){   //time complexity - O(n), space complexity - O(1)
        printf("%d ",n);
        n--;
    }
    return 0;
}
/*
function call tree for tail_recursion(3)
          tail_recursion(3)
          /        \
       print 3   tail_recursion(2)
                 /        \
              print 2   tail_recursion(1)
                        /        \
                     print 1   tail_recursion(0)
                                |
                             base condition
Time complexity - O(n)
*/