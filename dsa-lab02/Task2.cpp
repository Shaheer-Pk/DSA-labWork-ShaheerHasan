#include <iostream>
#include <iomanip>
using namespace std;

int main() {

    // (1) objectives
    int n = 0;
    do {
        cout << "Enter the number of students: ";
        cin >> n;
        if (n <= 0) {
            cout << "Invalid number, must be positive" << endl;
        }
    } while (n <= 0);
    
    
    int *marks = new int[n];

    cout << "Enter " << n << " student marks: " << endl;

    for (int i = 0; i < n; i++) {
        cout << "Student " << i+1 << " marks: ";
        cin >> *(marks + i);
    }

    // (2) objectives
    int total = 0, greater = 0, lesser = 0;
    float average = 0;

    for (int i = 0; i<n; i++) {
        total += *(marks + i);
        average = total / n;
        if (*(marks + i) >= 50) {
            greater++;
        }
        else {
            lesser++;
        }
    }

    cout << "\n\nStudent Marks Displaying:\n";
    cout << "Total is: " << total << endl;
    cout << "Marks greater than or equal to 50 is: " << greater << endl;
    cout << "Marks less than 50 is: " << lesser << endl;
    cout << "Average marks of all students are: " << fixed << setprecision(2) << average << endl;
    for (int i = 0; i < n; i++) {
        
        cout << "Student " << i+1 << " marks is: " << *(marks + i) << endl;
    }

    // (3) objectives
    delete[] marks;
    marks = nullptr;
}
