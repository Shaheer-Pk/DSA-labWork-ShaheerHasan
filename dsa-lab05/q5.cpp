// Name: Shaheer Hasan Khan
// Registration No: 543016
// Section: BSCS-15-D
//
// Lab 05 - Task 5: Implementing a stack using an array

#include <iostream>
using namespace std;

class ArrayStack {
private:
    int items[5];   // fixed capacity of 5
    int top;        // index of the top element, -1 means empty

public:
    ArrayStack() {
        top = -1;
    }

    bool IsEmpty() {
        return top == -1;
    }

    bool IsFull() {
        return top == 4;   // last valid index of a 5 element array
    }

    // Add a value on top, unless the stack is already full
    void Push(int value) {
        if (IsFull()) {
            cout << "Overflow: cannot push " << value << ", stack is full." << endl;
            return;
        }
        top++;
        items[top] = value;
        cout << "Pushed " << value << endl;
    }

    // Remove and show the top value, unless the stack is empty
    void Pop() {
        if (IsEmpty()) {
            cout << "Underflow: cannot pop, stack is empty." << endl;
            return;
        }
        cout << "Popped " << items[top] << endl;
        top--;
    }

    // Show the top value without removing it
    void Peek() {
        if (IsEmpty()) {
            cout << "Underflow: cannot peek, stack is empty." << endl;
            return;
        }
        cout << "Top element is " << items[top] << endl;
    }

    // Print from the top down to the bottom
    void Display() {
        if (IsEmpty()) {
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "Stack (top to bottom): ";
        for (int i = top; i >= 0; i--) {
            cout << items[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    ArrayStack s;

    cout << " Push 10, 20, 30, 40, 50 " << endl;
    s.Push(10);
    s.Push(20);
    s.Push(30);
    s.Push(40);
    s.Push(50);
    s.Display();

    cout << "\n Sixth push should be rejected " << endl;
    s.Push(60);

    cout << "\n Pop 50, then peek 40 " << endl;
    s.Pop();
    s.Peek();
    s.Display();

    cout << "\n Empty the stack " << endl;
    s.Pop();   // 40
    s.Pop();   // 30
    s.Pop();   // 20
    s.Pop();   // 10
    s.Display();

    cout << "\n One more pop on the empty stack " << endl;
    s.Pop();
    s.Peek();

    return 0;
}