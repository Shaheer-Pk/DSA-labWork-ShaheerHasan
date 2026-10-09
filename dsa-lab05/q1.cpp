// Name: Shaheer Hasan Khan
// Registration No: 543016
// Section: BSCS-15-D
//
// Lab 05 - Task 1: Creating and traversing a doubly linked list

#include <iostream>
using namespace std;

class DoublyList {
private:
    // One node of the list: holds a value and links to both neighbours
    struct node {
        int data;
        node* next;
        node* prev;
    };

    node* head;   // first node (nullptr when list is empty)
    node* tail;   // last node  (nullptr when list is empty)

public:
    // Start with an empty list
    // Constructor btw
    DoublyList() {
        head = nullptr;
        tail = nullptr;
    }

    // Append a new node at the end of the list using tail
    void AddNode(int value) {
        node* newNode = new node;
        newNode->data = value;
        newNode->next = nullptr;
        newNode->prev = tail;      // new node points back to the old last node

        if (tail == nullptr) {
            // List was empty, so this node is both head and tail
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;  // old last node points forward to new node
            tail = newNode;        // tail moves to the new node
        }
    }

    // Walk from head to tail using the next links
    void PrintForward() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }
        node* curr = head;
        while (curr != nullptr) {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }

    // Walk from tail to head using the prev links
    void PrintReverse() {
        if (tail == nullptr) {
            cout << "List is empty." << endl;
            return;
        }
        node* curr = tail;
        while (curr != nullptr) {
            cout << curr->data << " ";
            curr = curr->prev;
        }
        cout << endl;
    }

    // Delete every node one by one, then reset head and tail
    void ClearList() {
        node* curr = head;
        while (curr != nullptr) {
            node* nextNode = curr->next;   // save the link before deleting
            delete curr;
            curr = nextNode;
        }
        head = nullptr;
        tail = nullptr;
    }
};

int main() {
    DoublyList list;
    int count, value;

    cout << "How many numbers do you want to add? ";
    cin >> count;

    for (int i = 0; i < count; i++) {
        cout << "Enter value " << (i + 1) << ": ";
        cin >> value;
        list.AddNode(value);
    }

    cout << "\nForward : ";
    list.PrintForward();
    cout << "Reverse : ";
    list.PrintReverse();

    list.ClearList();   // clean up before exit
    return 0;
}