#include <iostream>
using namespace std;

int main() {
    // An array named arr to hold the required elements
    int arr[5] = {2,4,6,8,10};

    // Swapping the third element (6) and changing it to 7
    arr[2] = 7;

    // Prints out the elements with a new line each print
    for(int i = 0; i < sizeof(arr)/ sizeof(arr[0]); i++) {
        cout << arr[i] << endl;
    }
}