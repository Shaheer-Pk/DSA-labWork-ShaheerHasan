// Name: Shaheer Hasan Khan
// Registration No: 543016
// Section: BSCS-15-D
//
// Lab 05 - Task 6: Implementing a stack using linked nodes
//
// ANSWER TO THE QUESTION IN THE TASK
//  
// LIFO (Last In, First Out): the most recently pushed value is the first one
// popped, like a stack of plates where you only touch the top plate.
//
// Task 5 vs Task 6:
// - The array stack (Task 5) has a fixed capacity of 5, so the 6th push
//   overflows and is rejected.
// - The linked stack (Task 6) allocates a new node for every push, so it
//   grows until memory runs out. There is no preset limit and no IsFull().
// - Both push and pop touch only the top, so both are O(1).

#include <iostream>
using namespace std;

class LinkedStack {
private:
    // Singly linked node: the stack only ever moves downward, so no prev
    struct node {
        int data;
        node* next;
    };

    node* top;   // the head of the list is the top of the stack

public:
    LinkedStack() {
        top = nullptr;
    }

    ~LinkedStack() {
        ClearStack();
    }

    bool IsEmpty() {
        return top == nullptr;
    }

    // Push at the head: new node points to the old top, then becomes top
    void Push(int value) {
        node* newNode = new node;
        newNode->data = value;
        newNode->next = top;
        top = newNode;
        cout << "Pushed " << value << endl;
    }

    // Pop from the head: move top down, then delete the old top node
    void Pop() {
        if (IsEmpty()) {
            cout << "Underflow: cannot pop, stack is empty." << endl;
            return;
        }
        node* temp = top;          // remember the node we are removing
        cout << "Popped " << temp->data << endl;
        top = top->next;
        delete temp;
    }

    // Show the top value without removing it
    void Peek() {
        if (IsEmpty()) {
            cout << "Underflow: cannot peek, stack is empty." << endl;
            return;
        }
        cout << "Top element is " << top->data << endl;
    }

    // Print from top to bottom
    void Display() {
        if (IsEmpty()) {
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "Stack (top to bottom): ";
        node* curr = top;
        while (curr != nullptr) {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }

    // Delete every remaining node, then reset top
    void ClearStack() {
        node* curr = top;
        while (curr != nullptr) {
            node* nextNode = curr->next;   // save link before delete
            delete curr;
            curr = nextNode;
        }
        top = nullptr;
    }
};

int main() {
    LinkedStack stack;
    int choice, value;

    // Keep showing the menu until the user picks Exit
    do {
        cout << "\n===== Linked Stack Menu =====" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Display" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                stack.Push(value);
                break;
            case 2:
                stack.Pop();
                break;
            case 3:
                stack.Peek();
                break;
            case 4:
                stack.Display();
                break;
            case 5:
                cout << "Releasing remaining nodes and exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please enter 1-5.";
        }
    } while (choice != 5);

    stack.ClearStack();   // free anything still on the stack before exit
    return 0;
}