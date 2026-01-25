#include<stdio.h>
#include<iostream>
using namespace std;

int main(){
    char str[100];
    cout<<"enter a string: ";
    cin.ignore();
    cin.getline(str,100); //cin.getline(string_name, size);

    int i;
    for( i=0; str[i]!='\0'; i++){
        //loop to find length of string
        //hello\0
        //empty loop body, return the i before '\0', cso i is from 0 to n-1
    }
    cout<<"Length of the string is: "<<i+1<<endl;
    return 0;
}