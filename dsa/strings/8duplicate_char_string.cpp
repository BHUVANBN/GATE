//counting number of character in a string and storing it in hash array(hash table)
#include<iostream>
using namespace std;
//a - 97, z - 122, so we need an array of size 26 to store the count of each character
int main(){
    int arr[26]={0};
    char str[] = "finding";
    for(int i = 0; i<=25; i++){
        arr[str[i]-97]+=1;
    }
    for(int i = 0; i<=25; i++){
        if(arr[i]>1){
            cout<<(char)(i+97) <<" "<<arr[i]<<endl;
        }
    }
    return 0;
}