//Comnination is the selection of r objects from n objects without considering the order
//nCr = n! / (r! * (n-r)!)
#include<stdio.h>
//function to calculate factorial
int fact(int n){
    if(n<=1) return 1;
    return n * fact(n-1);
}
//function to calculate nCr using factorial function
int nCr_factorial(int n, int r){
    return fact(n) / (fact(r) * fact(n-r));
}
//Pascal's triangle approach - value of nCr can be calculated using the values of (n-1)C(r-1) and (n-1)Cr
/*
            1
           1 1
          1 2 1
         1 3 3 1
        1 4 6 4 1
       1 5 10 10 5 1

            0C0
          1C0 1C1
        2C0 2C1 2C2
      3C0 3C1 3C2 3C3
    4C0 4C1 4C2 4C3 4C4
  5C0 5C1 5C2 5C3 5C4 5C5  

  eg: 2C1 = 1C0 + 1C1 = 2
      4C2 = 3C1 + 3C2 = 3 + 3 = 6
*/
//function to calculate nCr using pascal's triangle
int nCr_pascal(int n, int r){
    if(r==0 || r==n) return 1;
    return nCr_pascal(n-1,r-1) + nCr_pascal(n-1,r);
}
int main(){
    int n,r;
    printf("Enter the value of n and r: ");
    scanf("%d %d",&n,&r);
    printf("The value of %dC%d using factorial method is: %d\n",n,r,nCr_factorial(n,r));
    printf("The value of %dC%d using pascal's triangle method is: %d\n",n,r,nCr_pascal(n,r));   
    return 0;
}
