#include<iostream>
//reference variable - alias to another variable, only in cpp
//reference must be initialised during declaration
//used in function parameter passing to avoid copying large data
using namespace std;
int main(){

    int a = 10;
    int &ref = a; //ref is reference to a
    cout<<a<<endl; //10
    cout<<ref<<endl; //10
    return 0;
}