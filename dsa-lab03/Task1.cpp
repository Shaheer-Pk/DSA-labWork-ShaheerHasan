/**
 * Student Details:
 * Name: Shaheer Hasan Khan
 * CMS: 543016
 * Section: BSCS-15-D
 */
#include <iostream>
#include <string>
using namespace std;

struct Student {
    int rollNumber;
    string fullname;
    int marks;

    Student (int roll, string fullname, int marks) {
        this->rollNumber = roll;
        this->fullname = fullname;
        this->marks = marks;
    }

    void printDetails() {
        cout << "Roll Number is: " << rollNumber << endl;
        cout << "Full name is: " << fullname << endl;
        cout << "Marks is: " << marks << endl;
    }
};

int main () {
    // Task 1
    int roll;
    string name;
    int marks;

    cout << "Enter the rollnumber: ";
    cin >> roll;

    cin.ignore();   // To clear the input buffer (the trailing newline)

    cout << "Enter the fullname: ";
    getline(cin, name);     // getline to store fullname because cin stops capturing after a whitespace

    cout << "Enter marks: ";
    cin >> marks;
    // Initialize our student variable
    Student s1(roll, name, marks);

    cout << "\nStudent Details\n";
    // Print Details
    s1.printDetails();
}
