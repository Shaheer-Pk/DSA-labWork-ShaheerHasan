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
    node* head;

public:
    List() : head(nullptr) {}

    // Reads three integers and links them in the order they were entered.
    // Copied from q1.cpp
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

    // Inserts a new node at the end of the list.
    // (Actual Task)
    void AddNode(int addData) {
        node* newNode = new node;
        newNode->data = addData;
        newNode->next = nullptr;

        // In case we are adding the very first node
        if (head == nullptr) {
            head = newNode;
            return;
        }

        node* curr = head;
        // Traverse till the end and make it point to new node
        while (curr->next != nullptr) {
            curr = curr->next;
        }
        curr->next = newNode;
    }

    int CountNodes() const {
        int total = 0;
        node* curr = head;
        while (curr != nullptr) {
            total++;
            curr = curr->next;
        }
        return total;
    }

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
    int n;

    cout << "How many numbers do you want to add? ";
    cin >> n;

    for (int i = 1; i <= n; i++) {
        int value;
        cout << "Enter number " << i << ": ";
        cin >> value;
        numbers.AddNode(value);
    }

    cout << endl << "List: ";
    numbers.PrintList();
    cout << "Count: " << numbers.CountNodes() << endl;

    numbers.ClearList();

    cout << endl << "List after deletion" << endl;
    numbers.PrintList();
    return 0;
}