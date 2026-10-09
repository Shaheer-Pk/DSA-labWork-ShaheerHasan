// Name: Shaheer Hasan Khan
// Registration No: 543016
// Section: BSCS-15-D
//
// Lab 05 - Task 3: Creating and traversing a circular linked list
//
//  
// Why a normal nullptr-based traversal never ends on a circular list:
//
// ANSWER TO THE QUESTION:
//
// In a circular list the last node's next pointer points back to the head,
// so no node ever has next == nullptr. A loop like "while (curr != nullptr)"
// just keeps going around the circle forever. We have to stop when we get
// back to the head instead.

#include <iostream>
using namespace std;

class CircularList {
private:
    // Singly linked node (no prev pointer needed here)
    struct node {
        int data;
        node* next;
    };

    node* head;
    node* tail;

public:
    CircularList() {
        head = nullptr;
        tail = nullptr;
    }

    // Append at the end using tail and keep tail->next = head
    void AddNode(int value) {
        node* newNode = new node;
        newNode->data = value;

        if (tail == nullptr) {
            // First node: it links to itself
            head = newNode;
            tail = newNode;
            newNode->next = newNode;
        } else {
            tail->next = newNode;     // old last node points to new node
            tail = newNode;           // tail moves forward
            tail->next = head;        // close the circle again
        }
    }

    // Print every value exactly once, stopping after one full cycle
    void PrintList() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }
        node* curr = head;
        do {
            cout << curr->data << " ";
            curr = curr->next;
        } while (curr != head);       // back at head means one full cycle done
        cout << endl;
    }

    // Count nodes by walking one full cycle
    int CountNodes() {
        if (head == nullptr) {
            return 0;
        }
        int count = 0;
        node* curr = head;
        do {
            count++;
            curr = curr->next;
        } while (curr != head);
        return count;
    }

    // Break the circle first so a normal nullptr loop can delete safely
    void ClearList() {
        if (tail != nullptr) {
            tail->next = nullptr;
        }
        node* curr = head;
        while (curr != nullptr) {
            node* nextNode = curr->next;   // save link before delete
            delete curr;
            curr = nextNode;
        }
        head = nullptr;
        tail = nullptr;
    }
};

int main() {
    // Test 1: empty list
    cout << "--- Empty list ---" << endl;
    CircularList empty;
    empty.PrintList();
    cout << "Count: " << empty.CountNodes() << endl << endl;

    // Test 2: one node
    cout << "--- One node ---" << endl;
    CircularList single;
    single.AddNode(10);
    single.PrintList();
    cout << "Count: " << single.CountNodes() << endl << endl;

    // Test 3: 10, 20, 30
    cout << "--- Three nodes ---" << endl;
    CircularList three;
    three.AddNode(10);
    three.AddNode(20);
    three.AddNode(30);
    three.PrintList();
    cout << "Count: " << three.CountNodes() << endl;

    empty.ClearList();
    single.ClearList();
    three.ClearList();
    return 0;
}