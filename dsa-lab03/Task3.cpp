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

int main() {
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

    Student* sp = new Student(roll, name, marks);

    // Display student details
    cout << "\nStudent Details (via pointer)\n";
    sp -> printDetails();

    // Delete the object and make the pointer null
    delete sp;
    sp = nullptr;

    return 0;
}