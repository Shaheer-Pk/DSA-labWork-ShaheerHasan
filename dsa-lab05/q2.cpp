// Name: Shaheer Hasan Khan
// Registration No: 543016
// Section: BSCS-15-D
//
// Lab 05 - Task 2: Insertion and deletion in a doubly linked list

#include <iostream>
using namespace std;

class DoublyList {
private:
    // ---- node struct copied from Task 1 ----
    struct node {
        int data;
        node* next;
        node* prev;
    };

    node* head;
    node* tail;

public:
    // ---- constructor copied from Task 1 ----
    DoublyList() {
        head = nullptr;
        tail = nullptr;
    }

    // ---- AddNode copied from Task 1 ----
    void AddNode(int value) {
        node* newNode = new node;
        newNode->data = value;
        newNode->next = nullptr;
        newNode->prev = tail;

        if (tail == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // ---- PrintForward copied from Task 1 ----
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

    // ---- PrintReverse copied from Task 1 ----
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

    // ---- ClearList copied from Task 1 ----
    void ClearList() {
        node* curr = head;
        while (curr != nullptr) {
            node* nextNode = curr->next;
            delete curr;
            curr = nextNode;
        }
        head = nullptr;
        tail = nullptr;
    }

    // ---------------- NEW in Task 2 ----------------

    // Insert a new node BEFORE the node at the given position (1-based)
    void InsertBefore(int position, int value) {
        // Positions start at 1, so anything below 1 is invalid
        if (position < 1) {
            cout << "Invalid position " << position << ". Nothing inserted." << endl;
            return;
        }

        // Walk forward until we reach the node at 'position'
        node* curr = head;
        int index = 1;
        while (curr != nullptr && index < position) {
            curr = curr->next;
            index++;
        }

        // If we ran off the end, that position does not exist
        if (curr == nullptr) {
            cout << "Invalid position " << position << ". Nothing inserted." << endl;
            return;
        }

        // If above if statement doesn't run it means it was a valid position so we begin inserting the new value
        node* newNode = new node;
        newNode->data = value;
        newNode->next = curr;          // new node sits in front of curr
        newNode->prev = curr->prev;    // and behind whatever was before curr

        if (curr->prev == nullptr) {
            // curr was the head, so the new node becomes the new head
            head = newNode;
        } else {
            curr->prev->next = newNode;
        }
        curr->prev = newNode;
    }

    // Delete only the FIRST node holding 'value'
    void DeleteNode(int value) {
        if (head == nullptr) {
            cout << "List is empty. Cannot delete " << value << "." << endl;
            return;
        }

        // Search for the first match
        node* curr = head;
        while (curr != nullptr && curr->data != value) {
            curr = curr->next;
        }

        if (curr == nullptr) {
            cout << "Value " << value << " not found. Nothing deleted." << endl;
            return;
        }

        // Fix the links around curr depending on where it sits
        if (curr == head && curr == tail) {
            // Only node in the list
            head = nullptr;
            tail = nullptr;
        } else if (curr == head) {
            head = curr->next;
            head->prev = nullptr;
        } else if (curr == tail) {
            tail = curr->prev;
            tail->next = nullptr;
        } else {
            // Somewhere in the middle: bridge over it
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
        }

        delete curr;
    }
};

// Small helper so the tests print both directions after every change
void ShowBoth(DoublyList& list) {
    cout << "Forward : ";
    list.PrintForward();
    cout << "Reverse : ";
    list.PrintReverse();
    cout << endl;
}

int main() {
    DoublyList list;

    cout << " Empty list tests " << endl;
    list.DeleteNode(10);
    list.InsertBefore(1, 5);       // nothing to insert before
    ShowBoth(list);

    cout << " Main example: 10, 20, 30 " << endl;
    list.AddNode(10);
    list.AddNode(20);
    list.AddNode(30);
    ShowBoth(list);

    cout << "Insert 15 before position 2:" << endl;
    list.InsertBefore(2, 15);
    ShowBoth(list);

    cout << "Delete 20:" << endl;
    list.DeleteNode(20);
    ShowBoth(list);                // expect 10 15 30

    cout << " Insert before head (position 1) " << endl;
    list.InsertBefore(1, 5);
    ShowBoth(list);

    cout << " Invalid positions " << endl;
    list.InsertBefore(0, 99);
    list.InsertBefore(10, 99);
    ShowBoth(list);                // list must be unchanged

    cout << " Delete head (5) " << endl;
    list.DeleteNode(5);
    ShowBoth(list);

    cout << " Delete tail (30) " << endl;
    list.DeleteNode(30);
    ShowBoth(list);

    cout << " Missing value (100) " << endl;
    list.DeleteNode(100);
    ShowBoth(list);

    cout << " Delete remaining nodes until the only node is gone " << endl;
    list.DeleteNode(10);
    ShowBoth(list);
    list.DeleteNode(15);           // this was the only node
    ShowBoth(list);

    list.ClearList();
    return 0;
}