#include <iostream>
using namespace std;
int main()
{
    int age;
    cout << "Enter your age: ";
    cin >> age;
    if (age >= 18)
    {
        cout << "You are an adult" << endl;
    }
    else if (age < 0)
    {
        cout << "Invalid age" << endl;
    }
    else
    {
        cout << "You are not an adult" << endl;
    }

    //ternary operator
    string result = (age >= 18) ? "You are an adult" : "You are not an adult";
    cout << result << endl;
    return 0;
}