/*
 * Shaheer Hasan Khan
 * BSCS-15-D
 * 543016
 */

#include <iostream>
using namespace std;

class List {
private:
    struct node {
        int data;
        node* next;
    };
    // Our actual data member apart from the struct blueprint above 
    node* head;

public:
    // Constructor to initialize the head
    List() : head(nullptr) {}

    // Reads three integers and links them in the order they were entered.
    void CreateThreeNodes() {
        node* tail = nullptr;

        for (int i = 1; i <= 3; i++) {
            int value;
            cout << "Enter value " << i << ": ";
            cin >> value;

            node* newNode = new node;
            newNode->data = value;
            newNode->next = nullptr;

            if (head == nullptr) {
                head = newNode;
            } else {
                tail->next = newNode;
            }
            tail = newNode;
        }
    }

    // const because it should be immutable (Only responsibility is to print not modify)
    void PrintList() const {
        if (head == nullptr) {
            cout << "The list is empty." << endl;
            return;
        }

        node* curr = head;
        while (curr != nullptr) {
            cout << curr->data << " -> ";
            curr = curr->next;
        }
        cout << "NULL" << endl;
    }

    void ClearList() {
        node* curr = head;
        while (curr != nullptr) {
            node* nextNode = curr->next;   // save the link before deleting
            delete curr;
            curr = nextNode;
        }
        head = nullptr;
    }
};

int main() {
    List numbers;

    cout << "List before creation" << endl;
    numbers.PrintList();

    cout << endl << "Creating the list" << endl;
    numbers.CreateThreeNodes();

    cout << endl << "List after creation" << endl;
    numbers.PrintList();

    numbers.ClearList();

    cout << endl << "List after deletion" << endl;
    numbers.PrintList();
    return 0;
}