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

void updateMarks(Student* s, float new_marks) {
    if (s == nullptr) {
        cout << "No record availaible, create one first!" << endl;
        return;
    }
    s -> marks = new_marks;
}
void createRecord(Student*& s) {
    if (s != nullptr) {
        cout << "A record already exists, please delete it first!" << endl;
        return;
    }
    int roll;
    string name;
    float marks;

    cout << "Enter the rollnumber: ";
    cin >> roll;

    cin.ignore();   // To clear the input buffer (the trailing newline)

    cout << "Enter the fullname: ";
    getline(cin, name);     // getline to store fullname because cin stops capturing after a whitespace

    cout << "Enter marks: ";
    cin >> marks;

    s = new Student(roll, name, marks);
    cout << "A new record has been created!" << endl;
}

void deleteRecord(Student*& s) {
    if (s == nullptr) {
        cout << "There is no record to delete! Create one first" << endl;
        return;
    }

    delete s;
    s = nullptr;
    cout << "Record has been deleted!" << endl;
}

int main() {
    Student* sp = nullptr; // Initialize single pointer on start
    int choice = 0;

    do {
        cout << "\n=================================" << endl;
        cout << "   STUDENT RECORD MANAGEMENT     " << endl;
        cout << "=================================" << endl;
        cout << "1. Create Record" << endl;
        cout << "2. Display Record" << endl;
        cout << "3. Update Marks" << endl;
        cout << "4. Delete Record" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice (1-5): ";
        cin >> choice;

        switch (choice) {
            case 1:
                createRecord(sp);
                break;

            case 2:
                displayIfExists(sp);
                break;

            case 3:
                float newMarks;
                cout << "\nEnter new marks: ";
                cin >> newMarks;
                updateMarks(sp, newMarks);
                break;

            case 4:
                deleteRecord(sp);
                break;

            case 5:
                // Clean up any remaining dynamic allocation before terminating
                if (sp != nullptr) {
                    delete sp;
                    sp = nullptr;
                    cout << "\nAllocated memory released upon exit." << endl;
                }
                cout << "\nExiting application. Goodbye!" << endl;
                break;

            default:
                cout << "\nInvalid choice! Please select an option between 1 and 5." << endl;
                break;
        }

    } while (choice != 5);

    return 0;
}