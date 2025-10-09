#include<iostream>
#include<cstring>
#include<typeinfo>
using namespace std;

struct Student{
    int id;
    char name[20];
    float marks;
};

int main(){
    struct Student s1;
    s1.id = 101;
    strcpy(s1.name, "John Doe");
    s1.marks = 95.5;
    cout<<"ID: "<<s1.id<<endl;  
    cout<<"Name: "<<s1.name<<endl;
    cout<<"Marks: "<<s1.marks<<endl;

    cout<<sizeof(s1); // C++11 feature
    return 0; 
}