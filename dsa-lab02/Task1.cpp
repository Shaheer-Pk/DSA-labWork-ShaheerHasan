#include <iostream>
using namespace std;

int main(){
    int sales[5];
    int* p = sales;
    int total = 0;
    int updated_total = 0;

    cout << "Enter 5 numbers:\n" << endl;

    for (int i = 0; i<5; i++) {
        cout << "Number " << i+1 << ": ";
        cin >> *(p + i);
    }

    for (int i = 0; i<5; i++) {
        total += *(p + i);
    }

    cout << "\n\n";

    // (1) objective
    cout << "Total is: " << total << endl;
    cout << "The numbers were: ";
    for (int i =0; i< 5; i++) {
        cout << *(p + i) << " "; 
    }

    cout << "\n\n";

    // (2) objectives
    *(p + 2) += 2;      // Adds two the third day's entry

    for (int i = 0; i<5; i++) {
        updated_total += *(p + i);
    }

    cout << "UPDATED Total is: " << updated_total << endl;
    cout << "The numbers were: ";
    for (int i =0; i< 5; i++) {
        cout << *(p + i) << " "; 
    }
}