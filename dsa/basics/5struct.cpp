#include<iostream>
#include<cstring>
#include<typeinfo>
using namespace std;
//structure is a collection of different data types
//it is created in the stack memory 
struct Student{ //each items uses 4 bytes of memory,char uses 1 byte 
    int id;
    char name[20];
    float marks;
};

//global struct variable declaration
//struct Student{
//    int id;
//    char name[20];
//    float marks;
//} s2; //global struct variable

int main(){
    struct Student s1; //if variable of structure is created memory is allocated for all members
    //struct Student s2 = {102, "Jane Doe", 89.5}; //initialisation of structure members
    s1.id = 101;
    //s1.name = "batman"; // This line will cause an error
    strcpy(s1.name, "John Doe"); //correct way to copy string to char array
    s1.marks = 95.5;
    cout<<"ID: "<<s1.id<<endl;  
    cout<<"Name: "<<s1.name<<endl;
    cout<<"Marks: "<<s1.marks<<endl;

    cout<<sizeof(s1); // C++11 feature
    return 0; 
}