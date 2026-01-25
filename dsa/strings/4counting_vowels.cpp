#include<iostream>
using namespace std;
int main(){
    char str[]="hello how are   you";
    int vowels=0,consonants=0,words=1;
    for(int i=0; str[i]!='\0'; i++){
        if(str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='o' || str[i]=='u'){
            vowels++;
        }
        else if(str[i]>='a' && str[i]<='z'){
            consonants++;
        }
        else if(str[i]==' '){ //number of spaces + 1 = number of words
            if(str[i-1]!=' '){ //to avoid counting multiple spaces as one word
                words++;
            }
        }
    }
    cout<<"vowels: "<<vowels<<endl;
    cout<<"consonants: "<<consonants<<endl;
    cout<<"words: "<<words<<endl;
    return 0;
}