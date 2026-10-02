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

    Student (int roll, string fullname, float marks) {
        this->rollNumber = roll;
        this->fullname = fullname;
        this->marks = marks;
    }
};

void printDetails(const Student* s) {
    cout << "Roll Number is: " << s -> rollNumber << endl;
    cout << "Full name is: " << s -> fullname << endl;
    cout << "Marks is: " << s -> marks << endl;
}

void updateMarks(Student* s, float new_marks) {
    s -> marks = new_marks;
}

int main () {
    int roll;
    string name;
    int marks;
    int new_marks;

    cout << "Enter the rollnumber: ";
    cin >> roll;

    cin.ignore();   // To clear the input buffer (the trailing newline)

    cout << "Enter the fullname: ";
    getline(cin, name);     // getline to store fullname because cin stops capturing after a whitespace

    cout << "Enter marks: ";
    cin >> marks;

    // Dynamically allocate the deetails
    Student* sp = new Student(roll, name, marks);

    // Print details unmodified firstly
    cout << "\nStudent details are:\n";
    printDetails(sp);

    // Then update the marks
    cout << "\nEnter new marks: ";
    cin >> new_marks;
    updateMarks(sp, new_marks);

    // Print Updated Details
    cout << "\nStudent UPDATED details are:\n";
    printDetails(sp);

    // Free up memory before program ends
    delete sp;
    sp = nullptr;

    return 0;
}
