//permutations of a string - number of ways to arrange the characters of a string
//eg: abc -> abc, acb, bac, bca, cab, cba     6 possible permutations
//using tree we can generate all permutations - state space tree
/*
            abc
        /    |    \
       a     b     c
     / \    / \    / \ 
    b   c  a   c  a   b
    |   |  |   |  |   |
    c   b  c   a  b   c
    |   |  |   |  |   |
  abc acb bac bca cab cba

backtracking is used to explore all possible permutations
brute force approach - generate all possible permutations and check if they are valid 
we need recursion for backtracking to achieve brute force method
*/
#include<iostream>
using namespace std;

void perm(char s[], int k){
  static int A[10]={0}; // array to keep track of visited characters
  static char res[10]; // array to store the result
  if(s[k] == '\0'){
    res[k] = '\0';
    cout<<res<<endl;
  }
  else{
    for(int i=0; s[i]!='\0'; i++){
      if(A[i] == 0){
        res[k] = s[i];
        A[i] = 1;
        perm(s, k+1);
        A[i] = 0;
      }
    }
  }
}

int main(){
  char s[] = "abc";
  perm(s, 0);
  return 0;
}