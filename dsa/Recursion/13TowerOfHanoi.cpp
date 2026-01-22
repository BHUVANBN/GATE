//Tower of Hanoi is a classic problem in recursion
// Problem statement: There are three rods and n disks. The objective of the puzzle is to move the entire stack to another rod, obeying the following simple rules:
// 1. Only one disk can be moved at a time.
// 2. Each move consists of taking the upper disk from one of the stacks and placing it on top of another stack or on an empty rod.
// 3. No larger disk may be placed on top of a smaller disk.
// The minimum number of moves required to solve the Tower of Hanoi puzzle is 2^n - 1, where n is the number of disks.
#include<stdio.h>
//function to solve tower of hanoi problem
void tower_of_hanoi(int n, char source, char target, char auxiliary){ //time complexity - O(2^n)
    if(n>0){
        //move n-1 disks from source to auxiliary
        tower_of_hanoi(n-1,source,auxiliary,target);
        //move the nth disk from source to target
        printf("Move disk %d from rod %c to rod %c\n",n,source,target);
        //move the n-1 disks from auxiliary to target
        tower_of_hanoi(n-1,auxiliary,target,source);
    }

}
int main(){
    int n;
    printf("Enter the number of disks: ");
    scanf("%d",&n);
    tower_of_hanoi(n,'A','C','B'); //A, B and C are names of rods
    printf("Total number of steps: %d\n",(1<<n)-1); //2^n - 1
    return 0;   
}