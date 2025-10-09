#include <iostream>
using namespace std;
int main()
{
    cout << "Hello World" << endl
         << "hii";
    int age = 22;
    cout << "My age is " << age << endl;
    cout << sizeof(age) << "bytes" << endl;

    float pi = 3.14;
    cout << "Value of pi is " << pi << endl;

    char grade = 'A';
    cout << "Grade is " << (int)grade << endl;

    bool isAdult = true;
    cout << "Am I an adult? " << isAdult << endl;

    double largeDecimal = 3.141592653589793;
    int typecastlargeDecimal = (int)largeDecimal;
    cout << "Value of largeDecimal is " << typecastlargeDecimal << endl;

    int data;
    cout << "enter the data: ";
    cin >> data;
    cout << "data is: " << data << endl;

    cout<< (float)5/2;


    //operators    int a = 4, b = 6;
    cout << "a + b = " << 4 + 6 << endl;
    cout << "a - b = " << 4 - 6 << endl;
    cout << "a * b = " << 4 * 6 << endl;
    cout << "a / b = " << 4 / 6 << endl;
    cout << "a % b = " << 4 % 6 << endl;
   
    int a = 10;
    int b = a++; //post-increment, assign a to b, then increment a
    cout << "a = " << a << ", b = " << b << endl;

    int x = 10; 
    int y = ++x; //pre-increment, increment x, then assign to y
    cout << "x = " << x << ", y = " << y << endl;

    return 0;
}