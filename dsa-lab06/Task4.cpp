// Name: Shaheer Hasan Khan
// Registration No: 543016
// Section: BSCS-15-D
//
// Lab 06, Task 4: Inserting values into a linear queue.

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
        front = 0;      // first insertion
    }
    rear++;
    items[rear] = value;
    cout << "Inserted " << value << endl;
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
    cout << "Display on an empty queue" << endl;
    display();

    cout << "\nInsert 10, 20, 30" << endl;
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();

    cout << "\nFill the queue, then insert one more" << endl;
    enqueue(40);
    enqueue(50);
    enqueue(60);
    display();

    return 0;
}