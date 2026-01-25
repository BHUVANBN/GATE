#include<iostream>
using namespace std;

int main(){
    char str1[] = "paint";
    char str2[] = "painting";
    int i,j;
    for(i = 0,j=0;str1[i]!='\0' && str2[j]!='\0' ; i++,j++){
        if(str1[i] != str2[j]){
            break;
        }
    } 
    if(str1[i]==str2[j]){
        cout<<"strings are equal"<<endl;
    }
    else if(str1[i]<str2[j]){
        cout<<"str1 is smaller than str2"<<endl;
    }
    else{
        cout<<"str1 is greater than str2"<<endl;
    }

    //palindrome - string that reads the same backward as forward
    //to check - reverse the string and compare it with the original string
    char str3[] = "level";
    char str4[10];
    //reverse
    int len;
    for(len=0;str3[len]!='\0';len++){
        //to get the length of the string
    }
    int x,y;
    for( x=0,y=len-1;x<=len;x++,y--){
        str4[x]=str3[y];
    }
    str4[x]='\0';
    cout<<str4<<endl;
    for(int a=0;str3[a]==str4[a];a++){
        if(str3[a]=='\0'){
            cout<<"palindrome"<<endl;
        }
    }

    
    return 0;
}
