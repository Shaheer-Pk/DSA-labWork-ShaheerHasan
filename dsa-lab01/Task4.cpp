#include <iostream>
using namespace std;

int main() {
    int arr[8];
    int largest, smallest, largest_index, smallest_index;
    bool repeated = false;

    cout << "Enter 8 numbers" << endl;

    // Not using sizeof becauase array size is fixed
    for (int i = 0; i < 8; i++) {
        cout << "Enter number " << i+1 << ": ";
        cin >> arr[i];
    }

    largest = arr[0];
    smallest = arr[0];
    smallest_index = 0;
    largest_index = 0;

    for (int i = 0; i < 8; i++) {
        if (arr[i] > largest) {
            largest = arr[i];
            largest_index = i;
        }
        if (arr[i] < smallest) {
            smallest = arr[i];
            smallest_index = i;
        }
    }
    

    cout << "Largest Number is: " << largest << "\nIndex is: " << largest_index << endl;
    cout << "Smallest Number is: " << smallest << "\nIndex is: " << smallest_index <<endl;

    // Repeated checks:
    int already_found[8];

    for (int i = 0; i < 8; i++) {
        // To check if the number has been reported
        bool already_reported = false;
        bool isReported = false;

        // If the number has been reported skip it
        for (int k = 0; k < 8; k++) {
            if (arr[i] == already_found[k]){
                isReported = true;
                break;
            }
        }

        if (isReported) {
            continue;
        }

        for (int j = i + 1; j < 8; j++) {
            if (already_reported) {
                continue;
            }
            if (arr[i] != arr[j]) {
                continue;
            }
            already_reported = true;
            cout << "Number: " << arr[i] << " With an index of: " << i << " Has been repeated!" << endl;
            already_found[i] = arr[i];
        }
    }
}