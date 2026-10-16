// Name: Shaheer Hasan Khan
// Registration No: 543016
// Section: BSCS-15-D
//
// Lab 06, Task 2: Stack implemented with a singly linked list.

#include <iostream>
using namespace std;

struct Node {
    int data;       
    Node* next;   
};

Node* top = nullptr;    // Default top node


// Returns true when the stack has no nodes.
bool isEmpty() {
    return top == nullptr;
}

// Creates a new node and places it at the head (top) of the list.
void push(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = top;    // the new node sits on top of the old top
    top = newNode;          // the new node becomes the top
    cout << "Pushed " << value << endl;
}

// Removes the head node, prints its value, and frees its memory.
void pop() {
    if (isEmpty()) {
        cout << "Stack underflow: cannot pop, the stack is empty." << endl;
        return;
    }
    Node* removed = top;            // remember the node we are about to delete
    cout << "Popped " << removed->data << endl;
    top = top->next;                // the next node becomes the new top
    delete removed;                 // give the memory back
}

// Shows the top value without removing it.
void peek() {
    if (isEmpty()) {
        cout << "Cannot peek: the stack is empty." << endl;
        return;
    }
    cout << "Top element is " << top->data << endl;
}

// Walks from the top node to the bottom node and prints each value.
void display() {
    if (isEmpty()) {
        cout << "Stack is empty." << endl;
        return;
    }
    cout << "Stack (top to bottom): ";
    for (Node* current = top; current != nullptr; current = current->next) {
        cout << current->data << " ";
    }
    cout << endl;
}

// Deletes every remaining node so no memory is leaked at program exit.
void clearStack() {
    int freedCount = 0;
    while (top != nullptr) {
        Node* removed = top;
        top = top->next;
        delete removed;
        freedCount++;
    }
    cout << "Released " << freedCount << " remaining node(s)." << endl;
}

int main() {
    cout << "Basic operations" << endl;
    push(5);
    push(15);
    push(25);
    display();
    pop();
    peek();
    display();

    cout << "\nEmpty the stack, then pop from an empty stack" << endl;
    pop();
    pop();
    display();
    pop();                  

    cout << "\nLeave some nodes behind, then clean up before exit" << endl;
    push(35);
    push(45);
    display();
    clearStack();           
    display();

    return 0;
}