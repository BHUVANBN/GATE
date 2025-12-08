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

class Rectangle
{
    public: // data members are private by default
        int length;
        int breadth;
        // constructor
    public: // member functions are public by default
        Rectangle(int l, int b)
        { // parameterized constructor
            length = l;
            breadth = b;
        }
        int area()
        { // member function
            return length * breadth;
        }
};
int main()
{
    Rectangle r(10, 5); // object creation and initialization
    cout << r.length << " " << r.breadth << endl;
    cout << "Area: " << r.area() << endl; // calling member function
    return 0;
}