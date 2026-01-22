//Generic class is a class that can work with any data type
//template class is a blueprint for creating generic class

#include <iostream>
using namespace std;

template <class T> //template declaration
class Arithmetic{
    T a;
    T b;
    public:
        Arithmetic(T x, T y){
            this->a = x; //this pointer refers to current object
            this->b = y;
        }
        T add(){
            return a + b;
        }
        T subtract(){
            return a - b;
        }
        T multiply(); //this method is implemented outside the class
};
template <class T> //template definition for member function outside class
T Arithmetic<T>::multiply(){
    return a * b;
}
int main(){
    Arithmetic<int> arInt(10, 5); //object creation for int type
    cout << "Integer Addition: " << arInt.add() << endl;
    cout << "Integer Subtraction: " << arInt.subtract() << endl;
    cout << "Integer Multiplication: " << arInt.multiply() << endl;

    Arithmetic<float> arFloat(10.7, 5.5); //object creation for float type
    cout << "Float Addition: " << arFloat.add() << endl;
    cout << "Float Subtraction: " << arFloat.subtract() << endl;        
    cout << "Float Multiplication: " << arFloat.multiply() << endl;
    return 0;
}
     