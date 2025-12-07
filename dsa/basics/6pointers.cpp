//pointers - stores address of variable
//program can access stack memory directly, not heap memory
//ponter is used to access heap memory (outside the program stack memory)
//pointers are used to access keyboard and file I/O buffers(resoures), Parameter passing by reference in functions
#include<iostream>
using namespace std;
int main(){
    int a = 10;
    int *p; //pointer declaration
    p = &a; //pointer initialization, & is address of operator
    cout<<a<<endl; //10
    cout<<&a<<endl; //address of a
    cout<<p<<endl; //address of a
    cout<<*p<<endl; //10, * is dereference operator, gives value at that address
    
    //accessing heap memory using malloc and free
    int *pt = (int*)malloc(sizeof(int)); //C style memory allocation, ptr is pointer to heap memory, malloc returns void pointer we need to typecast it to int pointer
    *pt = 20; //storing value at that address
    cout<<pt<<endl; //address of heap memory
    cout<<*pt<<endl; //20
    //free(pt); //freeing heap memory


    int *ptr = new int; //dynamic memory allocation, ptr is pointer to heap memory in C++
    *ptr = 20; //storing value at that address
    cout<<ptr<<endl; //address of heap memory
    cout<<*ptr<<endl; //20
    delete ptr; //freeing heap memory   
    
    //pointer to array
    int arr[5] = {1, 2, 3, 4, 5};
    int *parr = arr; //array name is pointer to first element, no & needed
    for(int i=0;i<5;i++){
        cout<<parr[i]<<" "; //accessing array elements using pointer, parr[i] is same as *(parr+i), parr act as name of the array
    }
    cout<<endl;

    //all pointers take 8 bytes of memory in 64 bit system irrespective of data type
    return 0;
}