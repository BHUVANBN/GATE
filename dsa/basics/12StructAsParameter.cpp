//structure is passed as reference by default in cpp
#include<iostream>
using namespace std;

struct Rectangle{
    int length;
    int breadth;
};

//call by value
int area(Rectangle rect){ //structure is passed by value, a copy of structure is created in function stack
    rect.length += 5; //modifying copy of structure donot affect original structure
    return rect.length*rect.breadth;
}
//call by address using pointers
int areaByAddress(Rectangle *r){ //structure is passed by address using pointer
    r->length += 5; //modifying structure will affect original structure
    return r->length*r->breadth;
}

//call by reference
int areaByReference(Rectangle &r){ //structure is passed by reference using reference variable, no copy is created
    r.length += 5; //modifying structure will affect original structure
    return r.length*r.breadth;
}   

//function returning structure created in heap memory
Rectangle* getRectangle(){
    Rectangle *r = (Rectangle*)malloc(sizeof(Rectangle)); //dynamically allocating memory for structure
    r->length = 10;
    r->breadth = 5;
    return r; //returning pointer to structure
}

int main(){
    Rectangle r = {10,5};
    cout<<r.length<<" "<<r.breadth<<endl;

    cout<<"Area: "<<area(r)<<endl;
    cout<<"Area by Address: "<<areaByAddress(&r)<<endl;
    cout<<"Area by Reference: "<<areaByReference(r)<<endl;
    
    cout<<r.length<<" "<<r.breadth<<endl; //length modified by address and reference functions
    
    Rectangle *newRect = getRectangle();
    cout<<"New Rectangle Length: "<<newRect->length<<", Breadth: "<<newRect->breadth<<endl;
    
    return 0;
}

//structure with array can be sent as parameter as pass by value