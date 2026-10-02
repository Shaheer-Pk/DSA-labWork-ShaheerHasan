/*
 * Shaheer Hasan Khan
 * BSCS-15-D
 * 543016
 */

#include <iostream>
#include <limits>
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
    // Here we combine everything together to make our menu driven application :)

    // Inserts a new node in front of the current first node.
    void InsertAtBeginning(int addData) {
        node* newNode = new node;
        newNode->data = addData;
        newNode->next = head;   // also works on an empty list (head is nullptr)
        head = newNode;
    }

    // Inserts a new node at the end of the list.
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

    // Prints the position (first node = 1) of the first node holding searchData.
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

    // Removes only the first node that holds delData.
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

    int CountNodes() const {
        int total = 0;
        node* curr = head;
        while (curr != nullptr) {
            total++;
            curr = curr->next;
        }
        return total;
    }

    void PrintSecondNode() const {
        if (head == nullptr || head->next == nullptr) {
            cout << "The list has fewer than two nodes." << endl;
            return;
        }
        cout << "Second node: " << head->next->data << endl;
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

void showMenu() {
    cout << endl;
    cout << "===== Singly Linked List Menu =====" << endl;
    cout << "1. Insert at beginning" << endl;
    cout << "2. Insert at end" << endl;
    cout << "3. Search by value" << endl;
    cout << "4. Delete by value" << endl;
    cout << "5. Display all nodes" << endl;
    cout << "6. Count nodes" << endl;
    cout << "7. Display second node" << endl;
    cout << "8. Exit" << endl;
    cout << "Enter your choice: ";
}

int main() {
    List numbers;
    int choice = 0;
    int value;

    do {
        showMenu();

        if (!(cin >> choice)) {
            if (cin.eof()) {
                break;   // input ended, fall through to cleanup
            }
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');    // Superior way to clean the buffer from new lines
            cout << "Invalid choice. Please enter a number from 1 to 8." << endl;
            choice = 0;
            continue;
        }

        switch (choice) {
            case 1:
                cout << "Enter value to insert at beginning: ";
                cin >> value;
                numbers.InsertAtBeginning(value);
                break;
            case 2:
                cout << "Enter value to insert at end: ";
                cin >> value;
                numbers.AddNode(value);
                break;
            case 3:
                cout << "Enter value to search for: ";
                cin >> value;
                numbers.SearchNode(value);
                break;
            case 4:
                cout << "Enter value to delete: ";
                cin >> value;
                numbers.DeleteNode(value);
                break;
            case 5:
                numbers.PrintList();
                break;
            case 6:
                cout << "Number of nodes: " << numbers.CountNodes() << endl;
                break;
            case 7:
                numbers.PrintSecondNode();
                break;
            case 8:
                cout << "Exiting. Releasing all nodes..." << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a number from 1 to 8." << endl;
        }
    } while (choice != 8);

    numbers.ClearList();
    return 0;
}