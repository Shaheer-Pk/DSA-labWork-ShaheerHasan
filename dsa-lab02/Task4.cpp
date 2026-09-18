#include <iostream>
using namespace std;

int main() {
    int rows, cols;

    // 2. Read and validate rows and cols
    cout << "Enter number of students and subjects: ";
    cin >> rows >> cols;

    if (rows <= 0 || cols <= 0) {
        cout << "Invalid input dimensions." << endl;
        return 1;
    }

    // 2. Allocate dynamically (int** and row pointers)
    int** marks = new int*[rows];
    for (int r = 0; r < rows; r++) {
        marks[r] = new int[cols];
    }

    // 3. Read marks using pointer notation
    cout << "Enter marks for each student:" << endl;
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            cin >> *(*(marks + r) + c);
        }
    }

    // 3. Display matrix using pointer notation
    cout << "\nMarks Matrix:" << endl;
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            cout << *(*(marks + r) + c) << "\t";
        }
        cout << endl;
    }

    // 4. Calculate student totals and track top student
    int bestStudent = 1;
    int highestTotal = -1;

    cout << "\nTotals: ";
    for (int r = 0; r < rows; r++) {
        int studentTotal = 0;
        for (int c = 0; c < cols; c++) {
            studentTotal += *(*(marks + r) + c);
        }

        cout << studentTotal << (r == rows - 1 ? "" : ", ");

        // Set baseline for first student, then keep first on ties
        if (r == 0 || studentTotal > highestTotal) {
            highestTotal = studentTotal;
            bestStudent = r + 1;
        }
    }
    cout << endl;

    cout << "Top student: " << bestStudent << " (Total: " << highestTotal << ")" << endl;

    // 5. Delete allocated memory
    for (int r = 0; r < rows; r++) {
        delete[] marks[r];
    }
    delete[] marks;
    marks = nullptr;

    return 0;
}