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
    float marks;

    Student (int roll, string name, float marks) {
        this -> rollNumber = roll;
        this -> fullname = name;
        this -> marks = marks;
    }
};

void displayIfExists(const Student* s) {
    if (s == nullptr) {
        cout << "No record availaible" << endl;
        return;
    }
    cout << "Roll Number is: " << s -> rollNumber << endl;
    cout << "Fullname is: " << s -> fullname << endl;
    cout << "Marks is: " << s -> marks << endl;
}

int main() {
    int roll;
    string name;
    float marks;
    Student* sp = nullptr;

    cout << "\nStudent details BEFORE allocation:\n";
    displayIfExists(sp);

    cout << "Enter the rollnumber: ";
    cin >> roll;

    cin.ignore();   // To clear the input buffer (the trailing newline)

    cout << "Enter the fullname: ";
    getline(cin, name);     // getline to store fullname because cin stops capturing after a whitespace

    cout << "Enter marks: ";
    cin >> marks;

    sp = new Student(roll,name,marks);
    
    cout << "\nStudent details AFTER allocation:\n";
    displayIfExists(sp);

    // Now we set the ptr to null and delete obj
    delete sp;
    sp = nullptr;

    cout << "\nStudent details after deletion and setting it to nullptr:\n";
    displayIfExists(sp);
}