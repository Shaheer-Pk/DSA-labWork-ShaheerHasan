// Name: Shaheer Hasan Khan
// Registration No: 543016
// Section: BSCS-15-D  (fill in D or E)
//
// Lab 06, Task 1: Stack implemented with a fixed-size array.

#include <iostream>
using namespace std;

const int SIZE = 5;      
int items[SIZE];         
int top = -1;            

// Returns true when no more values can be pushed.
bool isFull() {
    return top == SIZE - 1;
}

// Returns true when there is nothing to pop or peek.
bool isEmpty() {
    return top == -1;
}

// Adds a value on top of the stack, unless the stack is already full.
void push(int value) {
    if (isFull()) {
        cout << "Stack overflow: cannot push " << value << ", the stack is full." << endl;
        return;
    }
    top++;                  
    items[top] = value;     
    cout << "Pushed " << value << endl;
}

// Removes the top value, prints it, and moves the top marker down.
void pop() {
    if (isEmpty()) {
        cout << "Stack is empty, cannot pop" << endl;
        return;
    }
    cout << "Popped " << items[top] << endl;
    top--;                  // the old value is simply ignored from now on
}

// Shows the top value without removing it.
void peek() {
    if (isEmpty()) {
        cout << "Cannot peek, the stack is empty." << endl;
        return;
    }
    cout << "Top element is " << items[top] << endl;
}

// Prints the stack from the top (index top) down to the bottom (index 0).
void display() {
    if (isEmpty()) {
        cout << "Stack is empty." << endl;
        return;
    }
    cout << "Stack (top to bottom): ";
    for (int i = top; i >= 0; i--) {
        cout << items[i] << " ";
    }
    cout << endl;
}

int main() {
    cout << "Basic operations" << endl;
    push(10);
    push(20);
    push(30);
    display();
    pop();
    peek();
    display();

    cout << "\nFill the stack, then try a sixth insertion" << endl;
    push(40);
    push(50);
    push(60);               
    display();
    push(70);               

    cout << "\nRemove everything, then pop from an empty stack" << endl;
    while (!isEmpty()) {
        pop();
    }
    display();
    pop();                  
    peek();                 

    return 0;
}