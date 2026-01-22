//linear recursion - when the recursive call is done only once in each function
//tree recursion - when the recursive call is done more than once in each function
#include<stdio.h>
using namespace std;
void fun(int n){
    if(n>0){
        printf("%d ",n);
        fun(n-1); //recursive call
        fun(n-1); //recursive call
    }
}
int main(){
    fun(3); //time complexity - O(2^n), space complexity - O(n) due to function call stack
    return 0;
}
/**
function call tree for fun(3)
                      f(3)
            /-----------|----------------------------------\
           3          f(2)                                f(2)
                /-------|-------------\             /-------|-------------\    
                2     f(1)           f(1)          2     f(1)           f(1)
                    /   |   \      /   |   \           /   |   \      /   |   \ 
                   1   f(0) f(0)  1   f(0) f(0)       1   f(0) f(0)  1   f(0) f(0)
                        |     |        |     |              |     |        |     |
                      base   base     base   base         base   base     base   base
 
 
Time complexity - O(2^n)
Space complexity - O(n)

no pf calls at each level: 
level 0: 1 call
level 1: 2 calls
level 2: 4 calls    
level 3: 8 calls

it is in geometric progression 
Total calls = 1 + 2 + 4 + 8  i.e 2^0 + 2^1 + 2^2 + 2^3
for n value it will be 2^(n+1) - 1 
*/