#include <iostream>
using namespace std;

class Student {
public:
    int rollNumber, marks;

    // The function
    void display() {
        cout << "Roll Number is: " << rollNumber << endl;
        cout << "Marks is: " << marks << endl;
    }     
};

int main() {
    // Objects
    Student s1,s2;

    // Student 1 data
    s1.rollNumber = 1;
    s1.marks = 75;

    //Student 2 data
    s2.rollNumber = 2;
    s2.marks = 90;

    s1.display();
    cout << endl;
    s2.display();

    // Changing s1 marks
    s1.marks = 80;

    cout << "\nNEW MARKS AFTER CHANGING\n\n";

    s1.display();
    cout << endl;
    s2.display();
}

