#include <iostream>

using namespace std;

int main() {
    int sales[2][3];
    int (*rowPtr)[3] = sales;

    // (1) objectives
    cout << "Enter value: ";
    for (int r = 0; r < 2; r++) {
        for (int c = 0; c < 3; ++c) {
            cin >> *(*(rowPtr + r) + c);
        }
    }

    // Display the table using pointer notation
    cout << "Sales Table:" << endl;
    for (int r = 0; r < 2; r++) {
        for (int c = 0; c < 3; c++) {
            cout << *(*(rowPtr + r) + c) << "\t";
        }
        cout << endl;
    }
    cout << endl;

    // (2) objectives
    // Branch totals
    for (int r = 0; r < 2; r++) {
        int branchTotal = 0;
        for (int c = 0; c < 3; c++) {
            branchTotal += *(*(rowPtr + r) + c);
        }
        cout << "Branch " << (r + 1) << " total: " << branchTotal << endl;
    }

    // Day Totals
    for (int c = 0; c < 3; c++) {
        int dayTotal = 0;
        for (int r = 0; r < 2; ++r) {
            dayTotal += *(*(rowPtr + r) + c);
        }
        cout << "Day " << (c + 1) << " total: " << dayTotal << endl;
    }

    return 0;
}