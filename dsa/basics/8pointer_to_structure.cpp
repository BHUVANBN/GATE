#include<iostream>
using namespace std;

struct Rectangle{
    int length;
    int breadth;
};

int main(){
    //in cpp program struct is not mandatory while declaring structure variable - we can write directly as: Rectangle r;
    struct Rectangle r = {10, 5}; //static memory allocation
    struct Rectangle *p = &r; //pointer to structure, p stores address of r
    
    cout<< r.length<<endl; //accessing structure member using variable
    cout<< r.breadth<<endl;
    
    cout<< (*p).length<<endl; //accessing structure member using pointer, dereferencing pointer first then accessing member
    cout<< p->breadth<<endl; //accessing structure member using pointer, arrow operator
    
    //creating object in heap memory using pointer - dynamic memory allocation
    struct Rectangle *ptr;
    ptr = (struct Rectangle*)malloc(sizeof(struct Rectangle)); //C style memory allocation
    ptr->length = 15; //accessing member using arrow operator
    ptr->breadth = 7;
    cout<< ptr->length<<endl;
    cout<< ptr->breadth<<endl;
    return 0;
}