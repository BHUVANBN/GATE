#include<iostream>
using namespace std;

int main(){
    char str[] = "hello";
    char rev[10];  //using another char array
    int i;
    for(i=0; str[i]!='\0'; i++){
        //this stops i at last character
    }
    rev[i]='\0';
    i=i-1;
    for(int j =0;i>=0; i--,j++){    
        rev[j] = str[i];

    }
    cout<<rev<<endl;

    //using swapping the last and first characters
    char str1[] = "hello";
    int len;
    for(len = 0; str1[len]!='\0';len++){
        //to get the length of the string
    }
    cout<<"length is: "<<len<<endl;
    for(int i = 0; i<len/2; i++){
        char temp = str1[i];
        str1[i] = str1[len-i-1]; //length - i - 1 is the index of the last character
        str1[len-i-1] = temp;
    }
    cout<<str1<<endl;
    return 0;
}