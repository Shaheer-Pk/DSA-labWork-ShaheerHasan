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
    // Copied From q1.cpp
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

    // Inserts a new node in front of the current first node.
    // (Actual Task)
    void InsertAtBeginning(int addData) {
        node* newNode = new node;
        newNode->data = addData;
        newNode->next = head;   // also works on an empty list (head is nullptr)
        head = newNode;
    }

    // Inserts a new node at the end of the list.
    // Copied from q2
    void AddNode(int addData) {
        node* newNode = new node;
        newNode->data = addData;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
            return;
        }

        node* curr = head;
        while (curr->next != nullptr) {
            curr = curr->next;
        }
        curr->next = newNode;
    }

    // Copied from q3
    int CountNodes() const {
        int total = 0;
        node* curr = head;
        while (curr != nullptr) {
            total++;
            curr = curr->next;
        }
        return total;
    }

    // Prints the position (first node = 1) of the first node holding searchData.
    // Copied from q3
    void SearchNode(int searchData) const {
        int position = 1;
        node* curr = head;

        while (curr != nullptr) {
            if (curr->data == searchData) {
                cout << "Value " << searchData << " found at position " << position << endl;
                return;
            }
            curr = curr->next;
            position++;
        }
        cout << "Value not found" << endl;
    }

    // Copied from q3
    void PrintSecondNode() const {
        if (head == nullptr || head->next == nullptr) {
            cout << "The list has fewer than two nodes." << endl;
            return;
        }
        cout << "Second node: " << head->next->data << endl;
    }

    // Copied from q1
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

    // Copied from q1
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

    cout << "Starting list: ";
    numbers.PrintList();

    cout << endl << "Insert 20 at the beginning:" << endl;
    numbers.InsertAtBeginning(20);
    numbers.PrintList();

    cout << endl << "Insert 10 at the beginning:" << endl;
    numbers.InsertAtBeginning(10);
    numbers.PrintList();

    cout << endl << "Append 30 at the end:" << endl;
    numbers.AddNode(30);
    numbers.PrintList();

    numbers.ClearList();
    cout << endl << "List after deletion" << endl;
    numbers.PrintList();
    return 0;
}