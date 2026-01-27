//Anagrams are the strings that contain the same characters but in different order
#include<iostream>
using namespace std;

int main(){
    //condition - there must be no duplicate characters in the string
    //if there are duplicate use a array instead of mask, and increment the count of each character
    char str1[] = "decimal";
    char str2[] = "medical";

    int mask = 0; 
    
    // set bits for str1
    for (int i = 0; str1[i] != '\0'; i++){
        int bit = 1 << (str1[i] - 'a');
        mask |= bit;
    }

    // unset bits using str2
    for (int i = 0; str2[i] != '\0'; i++){
        int bit = 1 << (str2[i] - 'a');
        mask &= ~bit;
    }

    if (mask == 0)
        cout << "Anagram (by bitmask logic)\n";
    else
        cout << "Not anagram\n";

    return 0;
}
