#include <iostream>
using namespace std;

void reverse(int arr[], int len) {
    // The breaking out condition
    if (len <=1) {
        return;
    }

    int temp;
    temp = arr[0];
    arr[0] = arr[len - 1];
    arr[len - 1] = temp;

    // This will swap the inner elements apart from the already swapped ones and will stop when the len becomes <=1
    reverse(&arr[1], len-2);
}

int main () {
    int arr[10] {1,2,3,4,5,6,7,8,9,10};
    int len = 10;

    cout << "Original Array:" << endl;

    for (int i = 0; i < 10; i++) {
        cout << arr[i] << " ";
    }

    reverse(arr, len);

    cout << "\nReversed Array:" << endl;

    for (int i = 0; i < 10; i++) {
        cout << arr[i] << " ";
    }

}