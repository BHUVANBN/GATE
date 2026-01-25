#include<iostream>
using namespace std;
//list od ASCII character and its decimal value
/*
0-9 = 48-57
A-Z = 65-90
a-z = 97-122
space = 32

*/

int valid(char str[])
{
    for(int i = 0; str[i] != '\0'; i++)
    {
        if( !( (str[i] >= '0' && str[i] <= '9') ||
               (str[i] >= 'A' && str[i] <= 'Z') ||
               (str[i] >= 'a' && str[i] <= 'z') ) )
        {
            return 0; // invalid character found
        }
    }
    return 1; // valid string
}

int main(){
    //string is valid if it contains only alphabets and numbers
    char password[]="hellohowa12Areyou";
    cout<<valid(password);
    return 0;
}

