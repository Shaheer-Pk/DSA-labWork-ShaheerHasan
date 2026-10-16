// Name: Shaheer Hasan Khan
// Registration No: 543016
// Section: BSCS-15-D
//
// Lab 06, Task 5: Removing values from a linear queue.

#include <iostream>
using namespace std;

const int SIZE = 5;
int items[SIZE];
int front = -1;
int rear = -1;

bool isFull() {
    return rear == SIZE - 1;
}

bool isEmpty() {
    return front == -1;
}

void enqueue(int value) {
    if (isFull()) {
        cout << "Queue is full, cannot insert " << value << endl;
        return;
    }
    if (isEmpty()) {
        front = 0;
    }
    rear++;
    items[rear] = value;
    cout << "Inserted " << value << endl;
}

// The actual task
void dequeue() {
    if (isEmpty()) {
        cout << "Queue is empty, cannot remove." << endl;
        return;
    }
    cout << "Removed " << items[front] << endl;
    if (front == rear) {
        front = -1;     // last item gone, reset
        rear = -1;
    } else {
        front++;
    }
}

void peekFront() {
    if (isEmpty()) {
        cout << "Queue is empty, nothing at the front." << endl;
        return;
    }
    cout << "Front element is " << items[front] << endl;
}

void display() {
    if (isEmpty()) {
        cout << "Queue is empty." << endl;
        return;
    }
    cout << "Queue (front to rear): ";
    for (int i = front; i <= rear; i++) {
        cout << items[i] << " ";
    }
    cout << endl;
}

int main() {
    cout << "Insert 10, 20, 30" << endl;
    enqueue(10);
    enqueue(20);
    enqueue(30);

    cout << "\nRemove once, then peek and display" << endl;
    dequeue();
    peekFront();
    display();

    cout << "\nRemove the rest, then remove from an empty queue" << endl;
    dequeue();
    dequeue();
    dequeue();
    display();

    cout << "\nInsert 40 after the reset" << endl;
    enqueue(40);
    display();

    return 0;
}