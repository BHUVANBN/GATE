/*In C highest level of programming is functions and structures

structure - grouping related data members under single name
function - grouping related code under single name

    struct Rectangle{
        int length;
        int breadth;
    };
    int area(struct Rectangle rect){ //structure is passed by value, a copy of structure is created in function stack
        rect.length += 5; //modifying copy of structure donot affect original structure
        return rect.length*rect.breadth;
    }
    int main(){
        struct Rectangle r = {10,5};
        cout<<r.length<<" "<<r.breadth<<endl;
        cout<<"Area: "<<area(r)<<endl;
        return 0;
    }

*/

/*
In C++ highest level of programming is Object Oriented Programming using classes and objects
classes and constructors - grouping related data members and member functions under single name

    class Rectangle{
        private: //data members are private by default
            int length;
            int breadth;
            //constructor
        public: //member functions are public by default
            Rectangle(int l, int b){ //parameterized constructor
                length = l;
                breadth = b;
            }
            int area(){ //member function
                return length * breadth;
            }
    };
    int main(){
        Rectangle r(10,5); //object creation and initialization
        cout<<r.length<<" "<<r.breadth<<endl;
        cout<<"Area: "<<r.area()<<endl; //calling member function
        return 0;
    }

*/
// Classes - user defined data type, blueprint for creating objects
// Objects - instance of class, variable of class type

#include <iostream>
using namespace std;

class Rectangle{
    // data members are private by default
    int length;
    int breadth;
    // constructor
    public: // member functions are public by default
        Rectangle(){ // default constructor
            length = 0;
            breadth = 0;
        }
        Rectangle(int l, int b){ // parameterized constructor
            length = l;
            breadth = b;
        }
        int area(){ // member function
            return length * breadth;
        }
        int perimeter(); // member function declaration 
        int getLength(){ // getter function
            return length;
        }
        void setLength(int l){ // setter function
            length = l;
        }
        ~Rectangle(){ // destructor
            // cleanup code if any
        }
};
int Rectangle::perimeter(){ // member function definition outside class, :: is scope resolution operator
    return 2 * (length + breadth);
}
int main(){
    Rectangle r(10, 5); // object creation and initialization
    //cout << r.length << " " << r.breadth << endl; // cannot access private members
    cout << "Area: " << r.area() << endl; // calling member function
    cout << "Perimeter: " << r.perimeter() << endl; // calling member function
    r.setLength(15); // using setter function
    cout << "New Length: " << r.getLength() << endl; // using getter
    return 0;
}
//in cpp struct and class are same except struct members are public by default and class members are private by default