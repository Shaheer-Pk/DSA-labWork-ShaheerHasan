// Name: Shaheer Hasan Khan
// Registration No: 543016
// Section: BSCS-15-D
//
// Lab 05 - Task 4: Deletion in a circular linked list

#include <iostream>
using namespace std;

class CircularList {
private:
    // ---- node struct copied from Task 3 ----
    struct node {
        int data;
        node* next;
    };

    node* head;
    node* tail;

public:
    // ---- constructor copied from Task 3 ----
    CircularList() {
        head = nullptr;
        tail = nullptr;
    }

    // ---- AddNode copied from Task 3 ----
    void AddNode(int value) {
        node* newNode = new node;
        newNode->data = value;

        if (tail == nullptr) {
            head = newNode;
            tail = newNode;
            newNode->next = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
            tail->next = head;
        }
    }

    // ---- PrintList copied from Task 3 ----
    void PrintList() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }
        node* curr = head;
        do {
            cout << curr->data << " ";
            curr = curr->next;
        } while (curr != head);
        cout << endl;
    }

    // ---- CountNodes copied from Task 3 ----
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

    // ---- ClearList copied from Task 3 ----
    void ClearList() {
        if (tail != nullptr) {
            tail->next = nullptr;
        }
        node* curr = head;
        while (curr != nullptr) {
            node* nextNode = curr->next;
            delete curr;
            curr = nextNode;
        }
        head = nullptr;
        tail = nullptr;
    }

    // ---------------- NEW in Task 4 ----------------

    // Remove the first node that holds 'value'
    void DeleteNode(int value) {
        if (head == nullptr) {
            cout << "List is empty. Cannot delete " << value << "." << endl;
            return;
        }

        // 'prev' trails one step behind 'curr'. Starting prev at tail
        // means it is already correct when curr is the head.
        node* prev = tail;
        node* curr = head;
        bool found = false;

        // Search at most one full cycle (stop when we are back at head)
        do {
            if (curr->data == value) {
                found = true;
                break;
            }
            prev = curr;
            curr = curr->next;
        } while (curr != head);

        if (!found) {
            cout << "Value " << value << " not found. Nothing deleted." << endl;
            return;
        }

        if (curr == head && curr == tail) {
            // Only node in the list
            head = nullptr;
            tail = nullptr;
        } else if (curr == head) {
            // Deleting head: head moves forward, tail must point to new head
            head = head->next;
            tail->next = head;
        } else if (curr == tail) {
            // Deleting tail: previous node becomes tail and points to head
            prev->next = head;
            tail = prev;
        } else {
            // Middle node: just bridge over it
            prev->next = curr->next;
        }

        delete curr;
    }
};

// Helper so each test prints the list and count after the operation
void Show(CircularList& list) {
    cout << "List : ";
    list.PrintList();
    cout << "Count: " << list.CountNodes() << endl << endl;
}

int main() {
    CircularList list;

    cout << " Empty list " << endl;
    list.DeleteNode(10);
    Show(list);

    cout << " Build 10, 20, 30 " << endl;
    list.AddNode(10);
    list.AddNode(20);
    list.AddNode(30);
    Show(list);

    cout << " Missing value (99) " << endl;
    list.DeleteNode(99);
    Show(list);

    cout << " Delete 10 (head) " << endl;
    list.DeleteNode(10);
    Show(list);

    cout << " Delete 30 (tail) " << endl;
    list.DeleteNode(30);
    Show(list);

    cout << " Delete 20 (only node) " << endl;
    list.DeleteNode(20);
    Show(list);                    // head and tail are now nullptr

    cout << " Middle node: 10, 20, 30 -> delete 20 " << endl;
    list.AddNode(10);
    list.AddNode(20);
    list.AddNode(30);
    list.DeleteNode(20);
    Show(list);
    list.ClearList();

    cout << " Duplicates: 10, 20, 20, 30 -> delete 20 once " << endl;
    list.AddNode(10);
    list.AddNode(20);
    list.AddNode(20);
    list.AddNode(30);
    list.DeleteNode(20);
    Show(list);                    // expect 10 20 30

    list.ClearList();
    return 0;
}