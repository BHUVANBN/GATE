#include <iostream>
using namespace std;

struct Rectangle
{
    int length;
    int breadth;
    // constructor
    // Rectangle(int l, int b)
    // { // parameterized constructor
    //     length = l;
    //     breadth = b;
    // }
    int area()
    { // member function
        return length * breadth;
    }
};
int main()
{
    Rectangle r={10, 5};// object creation and initialization
    cout << r.length << " " << r.breadth << endl;
    cout << "Area: " << r.area() << endl; // calling member function
    return 0;
}