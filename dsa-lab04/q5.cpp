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

    // Removes only the first node that holds delData.
    // (Actual Task)
    void DeleteNode(int delData) {
        if (head == nullptr) {
            cout << "Cannot delete " << delData << ": the list is empty." << endl;
            return;
        }

        // First node is the target (this also covers a one-node list).
        if (head->data == delData) {
            node* toDelete = head;
            head = head->next;
            delete toDelete;
            cout << "Deleted " << delData << " from the list." << endl;
            return;
        }

        // Stop on the node just before the target so it can be reconnected.
        node* prev = head;
        while (prev->next != nullptr && prev->next->data != delData) {
            prev = prev->next;
        }

        if (prev->next == nullptr) {
            cout << "Value " << delData << " not found, nothing deleted." << endl;
            return;
        }

        node* toDelete = prev->next;
        prev->next = toDelete->next;   // reconnect first, then release
        delete toDelete;
        cout << "Deleted " << delData << " from the list." << endl;
    }

    // Reads three integers and links them in the order they were entered.
    // Copied from q1
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
    // Copied from q4
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

    cout << "Test 1: delete from an empty list" << endl;
    numbers.DeleteNode(10);
    numbers.PrintList();

    cout << endl << "Test 2: list 10, 20, 20, 30 - delete 20 once (middle node)" << endl;
    numbers.AddNode(10);
    numbers.AddNode(20);
    numbers.AddNode(20);
    numbers.AddNode(30);
    numbers.PrintList();
    numbers.DeleteNode(20);
    numbers.PrintList();

    cout << endl << "Test 3: delete the first node (10)" << endl;
    numbers.DeleteNode(10);
    numbers.PrintList();

    cout << endl << "Test 4: delete the last node (30)" << endl;
    numbers.DeleteNode(30);
    numbers.PrintList();

    cout << endl << "Test 5: delete a missing value (99)" << endl;
    numbers.DeleteNode(99);
    numbers.PrintList();

    cout << endl << "Test 6: delete the only remaining node (20)" << endl;
    numbers.DeleteNode(20);
    numbers.PrintList();

    numbers.ClearList();
    return 0;
}