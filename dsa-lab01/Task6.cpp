#include <iostream>
using namespace std;

int main() {
    int arr[10];
    int k = 0; // Index for storing the next unique element

    cout << "Enter 10 integers:\n";
    for (int i = 0; i < 10; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < 10; i++) {
        // Check if arr[i] already exists in the unique prefix
        bool isDuplicate = false;
        for (int j = 0; j < k; j++) {
            if (arr[i] == arr[j]) {
                isDuplicate = true;
                break;
            }
        }

        // If it is unique, move it to index k
        if (!isDuplicate) {
            arr[k] = arr[i];
            k++;
        }
    }

    // Display the unique values
    cout << "Unique values: ";
    for (int i = 0; i < k; ++i) {
        cout << arr[i] << " ";
    }
    cout << "\nCount: " << k << endl;

    return 0;
}