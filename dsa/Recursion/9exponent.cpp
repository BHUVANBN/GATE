#include<stdio.h>
int pow(int base, int power){
    if (power <=0)return 1;
    return base * pow(base, power - 1);

}
int pow_optimised(int base, int power){
    /*
    2^5 =  2 * (2^2)^2 -> reduces the number of multiplications
    2^4 = (2^2)^2 
    */
    if (power == 0) return 1;
    if (power % 2 == 0){ //even power
        return pow_optimised(base*base, power / 2);
    }
    else{ //odd power
        return base * pow_optimised(base*base, (power - 1)/2);
    }
}
int main(){
    printf("2^5 = %d\n", pow(2,5)); //output - 32
    printf("2^5 = %d\n", pow_optimised(2,5)); //output - 32, time complexity - O(log n), space complexity - O(log n)
    return 0;
}
//time complexity - O(n)
//space complexity - O(n) due to function call stack