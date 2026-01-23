#include <iostream>
using namespace std;
template <class T>
class Array { //array with its properties
    private: 
        T *A;
        //int A[10]; //static array declaration for merging example
        int size;
        int length;
    public:
        Array(){
            size = 10;
            length = 0;
            A = new T[size];
        }
        Array(int sz){ //constructor to initialize array
            size = sz;
            length = 0;
            A = new T[size];
        }
        ~Array(){ //destructor to free memory
            delete[] A;
        } 
        void display(); //traversal
        void insert(int index, T value); //insertion at given index
        T del(int index); //deletion at given index

    };
template <class T>
T Array<T>::del(int index){ //deletion at given index, time complexity O(n)
    if(index<0 || index>=length){
        return T();
    }
    T deletedValue = A[index];
    for(int i = index; i<length-1; i++){
        A[i] = A[i+1];
    }
    length--;
    return deletedValue;
}
template <class T>
void Array<T>::insert(int index, T value){ //insertion at given index, time complexity O(n)
    if(index<0 || index>length){
        return;
    }
    for(int i = length; i>index; i--){
        A[i] = A[i-1];
    }
    A[index] = value;
    length++;
}
template <class T>
void Array<T>::display(){ //traversal, time complexity O(n)
    int i;
    cout<<"Elements in the array are: ";
    for(i=0; i<length; i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
}

int main(){
    // Test with int type
    cout << "Testing Array<int>:" << endl;
    Array<int> intArray(5);
    intArray.insert(0, 10);
    intArray.insert(1, 20);
    intArray.insert(2, 30);
    intArray.display();
    
    int deleted = intArray.del(1);
    cout << "Deleted element: " << deleted << endl;
    intArray.display();
    
    // Test with float type
    cout << "\nTesting Array<float>:" << endl;
    Array<float> floatArray(5);
    floatArray.insert(0, 1.5f);
    floatArray.insert(1, 2.7f);
    floatArray.insert(2, 3.14f);
    floatArray.display();
    
    float deletedFloat = floatArray.del(0);
    cout << "Deleted element: " << deletedFloat << endl;
    floatArray.display();
    
    return 0;
}