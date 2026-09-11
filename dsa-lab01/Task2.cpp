#include <iostream>
using namespace std;

int main() {
    int numbers[5];
    int total = 0;

    cout << "Enter 5 numbers into the array" << endl;

    // Reading 5 numbers by user
    for (int i = 0; i < sizeof(numbers) / sizeof(numbers[0]); i++) {
        cout << "Enter Number " << i + 1 << ": ";
        cin >> numbers[i];
    }

    // Sum the user input
    for (int i = 0; i < sizeof(numbers) / sizeof(numbers[0]); i++) {
        total += numbers[i];
    }

    // Finally we display the output because why not
    cout << "Total is: " << total << endl;

}