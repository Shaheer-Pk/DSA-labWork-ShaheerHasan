// Name: Shaheer Hasan Khan
// Registration No: 543016
// Section: BSCS-15-D
//
// Lab 06, Task 6: Customer service queue using a linear array queue.
// Limitation Explained:
//   rear never wraps around, so once rear reaches the last slot,
//   adding stays blocked until the queue is emptied and resets.

#include <iostream>
using namespace std;

const int SIZE = 5;
int items[SIZE];
int front = -1;
int rear = -1;
int nextToken = 1;

bool isFull() {
    return rear == SIZE - 1;
}

bool isEmpty() {
    return front == -1;
}

void enqueue(int token) {
    if (isEmpty()) {
        front = 0;
    }
    rear++;
    items[rear] = token;
}

void dequeue() {
    // This is the only case where rear is resetted
    // And that is only when we are removing the last element
    // From the queue. (Explanataion above)
    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        front++;
    }
}

void addCustomer() {
    if (isFull()) {
        cout << "Cannot add customer, the queue is blocked." << endl;
        return;
    }
    cout << "Customer added with token " << nextToken << endl;
    enqueue(nextToken++);
}

void serveNext() {
    if (isEmpty()) {
        cout << "No customers waiting." << endl;
        return;
    }
    cout << "Now serving token " << items[front] << endl;
    dequeue();
}

void viewNext() {
    if (isEmpty()) {
        cout << "No customers waiting." << endl;
        return;
    }
    cout << "Next in line: token " << items[front] << endl;
}

void display() {
    if (isEmpty()) {
        cout << "No customers waiting." << endl;
        return;
    }
    cout << "Waiting (front to rear): ";
    for (int i = front; i <= rear; i++) {
        cout << items[i] << " ";
    }
    cout << endl;
}

int main() {
    int choice;

    do {
        cout << "\n1. Add customer" << endl;
        cout << "2. Serve next" << endl;
        cout << "3. View next" << endl;
        cout << "4. Display queue" << endl;
        cout << "5. Exit" << endl;
        cout << "Choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addCustomer(); break;
            case 2: serveNext(); break;
            case 3: viewNext(); break;
            case 4: display(); break;
            case 5: cout << "Goodbye." << endl; break;
            default: cout << "Invalid choice, enter 1 to 5." << endl;
        }
    } while (choice != 5);

    return 0;
}