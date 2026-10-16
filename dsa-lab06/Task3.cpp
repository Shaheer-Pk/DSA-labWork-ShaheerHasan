// Name: Shaheer Hasan Khan
// Registration No: 543016
// Section: BSCS-15-D
//
// Lab 06, Task 3: Reversing a word using a stack.

#include <iostream>
#include <string>
using namespace std;

const int SIZE = 20;
char items[SIZE];
int top = -1;

bool isFull() {
    return top == SIZE - 1;
}

bool isEmpty() {
    return top == -1;
}

void push(char c) {
    if (isFull()) {
        cout << "Stack is full." << endl;
        return;
    }
    top++;
    items[top] = c;
}

// Removes and returns the top character.
char pop() {
    return items[top--];
}

int main() {
    string word;

    cout << "Enter a word (max " << SIZE << " characters): ";
    cin >> word;

    if (word.length() > SIZE) {
        cout << "Word is too long, limit is " << SIZE << " characters." << endl;
        return 0;
    }

    for (int i = 0; i < (int)word.length(); i++) {
        push(word[i]);
    }

    cout << "Reversed: ";
    while (!isEmpty()) {
        cout << pop();
    }
    cout << endl;

    return 0;
}