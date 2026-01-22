// Indirect Recursion - When a function calls another function, and that other function calls the first one again, it's called indirect recursion.
#include<stdio.h>
using namespace std;
void funA(int n); //function prototype
void funB(int n){
    if(n>0){
        printf("%d ",n);
        funA(n-1); //calling funA
    }
}
void funA(int n){
    if(n>1){
        printf("%d ",n);
        funB(n/2); //calling funB
    }
}
int main(){
    funB(20); //time complexity - O(log n), space complexity - O(n) due to function call stack
    return 0;
}  