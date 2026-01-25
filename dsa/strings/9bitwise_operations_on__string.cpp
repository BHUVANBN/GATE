//each character is stored as a binary number
//1 byte = 8 bits, 0th bit is most significant bit, 7th bit is least significant bit
// 7   6   5   4   3   2   1   0 <---bits
// 128 64  32  16  8   4   2   1 <---decimal values
/* 
binary forms of decimal numbers
1 = 00000001
2 = 00000010

left and right shift operators
2<<1 = 00000100 = 4
2<<3 = 00010000 = 16
2>>1 = 00000001 = 1

bitwise operations
and operator
0&0 = 0
0&1 = 0
1&0 = 0
1&1 = 1

or operator
0|0 = 0
0|1 = 1
1|0 = 1
1|1 = 1

not operator
~0 = 1
~1 = 0

masking - to check if a bit is set or not 
eg: check weather 5th bit of H is set or not
    H = 01001000
    a = 00000000
    step 1 : a = 1, 00000001
    step 2 : left shift a by 5 times, a = 00100000
    step 3 : perform and operation, H & a = 01001000 & 00100000 = 00000000 (not set)
    step 4 : if result is 0, then 5th bit is not set, else it is set

merging - to set a bit
eg: set 2nd bit of H
    H = 01001000
    a = 00000000
    step 1 : a = 1, 00000001
    step 2 : left shift a by 2 times, a = 00000010
    step 3 : perform or operation, H | a = 01001000 | 00000010 = 01001010

*/
//finding duplicates in the string
//for 26 characters we need 26 bits, but we have only 8 bits in a byte
//so we will use 4 bytes i.e 32 bits, one int is enough

#include <iostream>
using namespace std;
int main() {
    char str[] = "finding";
    int a = 0,x=0;
    //bits are set if the letter is present in the string - merging
    for(int i = 0; str[i] != '\0'; i++){
        x = 1;
        x = x << (str[i] - 'a'); //f-a i.e 102-97 = 5, 5th bit must be set 
        if((x & a)> 0){ //checks if the bit is set or not 
            cout<<"duplicate character is "<<str[i]<<endl;
        }
        a = a | x; //if not set, set it using merging
    }
    return 0;
}