#include <iostream>
using namespace std;

int main() {
    int n;

    // Read and validate initial size n (1-10)
    cout << "Enter number of students (1-10): ";
    cin >> n;

    if (n < 1 || n > 10) {
        cout << "Invalid input range." << endl;
        return 1;
    }

    // Allocate initial block of n marks
    int* marks = new int[n];

    cout << "Enter " << n << " initial marks:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> *(marks + i);
    }

    // Read additional mark to be appended
    int newMark;
    cout << "Enter new student mark: ";
    cin >> newMark;

    // Allocate a second block of size n + 1
    int* newMarks = new int[n + 1];

    // Copy original values using pointer notation
    for (int i = 0; i < n; i++) {
        *(newMarks + i) = *(marks + i);
    }

    // Insert new mark at the final position
    *(newMarks + n) = newMark;

    // Release old block and update pointer and size
    delete[] marks;
    marks = newMarks;
    n = n + 1;

    // Display all values using pointer notation
    cout << "Updated marks array: ";
    for (int i = 0; i < n; i++) {
        cout << *(marks + i) << " ";
    }
    cout << endl;

    // Release final block exactly once
    delete[] marks;
    marks = nullptr;

    return 0;
}