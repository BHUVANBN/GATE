#include<stdio.h>
#include<iostream>
using namespace std;

int main(){
    char str[100];
    cout<<"enter the string : \n";
    cin.getline(str,100);
    for(int i= 0; str[i]!='\0'; i++){
        str[i] = str[i] - 32;     
    }   
    cout<<"string in uppercase : "<<str<<endl;

    //toggle cases
    char str1[] = "WeLcOme";
    for(int i = 0; str1[i]!='\0'; i++){
        if(str1[i]>='a' && str1[i]<='z'){ //a=97, z=122
            str1[i] = str1[i] - 32;    
        }    
        else if(str1[i]>='A' && str1[i]<='Z'){
            str1[i] = str1[i] + 32;    
        }    
    }
    cout<<"string in toggle case : "<<str1<<endl;
    return 0;
}