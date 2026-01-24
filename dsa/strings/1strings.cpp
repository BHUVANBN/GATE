//Character set - UTF-8, set of character supported by the compiler
//ASCII - American Standard Code for Information Interchange
//ASCII codes - for every character there is a unique number associated with it
//For example, A - 65, a - 97, 0 - 48, Space - 32, Enter - 10, etc. starting from 0 to 127, 7 bits are used to represent these characters, 
//but generally 1 byte (8 bits) is used to store these characters in memory

//unicodes - ASCII is limited to 128 characters, so to represent more characters from different languages, Unicode standard is used
//it takes 1 to 4 bytes to represent a character

#include <iostream>
#include <stdio.h>
using namespace std;
int main() {
    char ch = 'A'; // character variable of single character in single quotes 
    cout << "Character: " << ch << endl;
    printf("ASCII value: %c\n", ch); // using printf to display character
    cout << "ASCII value: " << int(ch) << endl; // type casting to int to get ASCII value

    ch = 'a';
    cout << "Character: " << ch << endl;
    cout << "ASCII value: " << int(ch) << endl;

    ch = '0';
    cout << "Character: " << ch << endl;
    cout << "ASCII value: " << int(ch) << endl;

    ch = ' ';
    cout << "Character: '" << ch << "'" << endl; // space character
    cout << "ASCII value: " << int(ch) << endl;
    
    //character array 
    char arr[] = {65, 66, 67, 68, 69, 70, 0}; // ASCII values of A, B, C, D, E, F and null character at the end
    cout << "Character Array: " << arr << endl; // prints ABCDEF
    // int arr2[] = {65, 66, 67, 68, 69, 70};
    // cout << "Integer Array as characters: "<< arr2 << endl; // prints memory address as arr2 is not a char array
    
    char arr1[5] = {'h','e'}; // rest elements will be initialized to null character
    cout << "Character Array 1: " << arr1 << endl; // prints he
    
    //strings - array of characters ending with null character '\0' (string terminator, string delimiter, null character)
    char str1[] = {'h','e','l','l','o','\0'}; // string initialization 
    char str2[] = "hello"; // string initialization using double quotes, compiler automatically adds null character at the end
    cout << "String 1: " << str1 << endl;
    printf("String 1 using printf: %s\n", str1); //%s format specifier to print string using printf
    cout << "String 2: " << str2 << endl;
    printf("String 2 using printf: %s\n", str2);

    //string as input
    char str3[20]; // character array of size 20
    cout << "Enter a string: ";
    cin >> str3; // input string, stops at whitespace
    cout << "You entered: " << str3 << endl;
    
    char str4[50];
    printf("Enter another string: ");
    scanf("%s", str4); // input string using scanf. stops at whitespace
    //to read string with spaces, we can use fgets() or cin.getline()
    printf("You entered: %s\n", str4);

    //to take string input with spaces using cin.getline()
    char str5[100];
    cout << "Enter a string with spaces: ";
    cin.getline(str5, 100); // reads a line of text including spaces
    cout << "You entered: " << str5 << endl;
    return 0;
}