#include <iostream>
using namespace std;

int main() {
    int n = 3;
    int* values = new int[n];

    cout << "Enter " << n << " integers:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> *(values + i);
    }

    cout << "Entered values: ";
    for (int i = 0; i < n; i++) {
        cout << *(values + i) << " ";
    }
    cout << endl;

    // Release allocation correctly and reset pointer
    delete[] values;
    values = nullptr;

    return 0;
}