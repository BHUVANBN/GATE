//Paranthesis matching is used to check if the parantheses in a string are balanced or not
#include<iostream>
using namespace std;

class Stack {
private:
    int top;
    int size;
    char* stack;

public:
    Stack(int s = 100) {
        size = s;
        top = -1;
        stack = new char[size];
    }
    ~Stack() {
        delete[] stack;
    }
    void push(char x) {
        if (top == size - 1) return;
        stack[++top] = x;
    }
    char pop() {
        if (top == -1) return '\0';
        return stack[top--];
    }
    bool isEmpty() {
        return top == -1;
    }
};

int main() {
    char A[] = "((a+b)*c)";
    Stack s(sizeof(A)-1);
    for (int i = 0; A[i] != '\0'; i++) {
        if (A[i] == '(')
            s.push(A[i]);
        else if (A[i] == ')') {
            if (s.isEmpty()) {
                cout << "Unbalanced\n";
                return 0;
            }
            s.pop();
        }
    }
    cout << (s.isEmpty() ? "Balanced" : "Unbalanced") << endl;
    return 0;
}
