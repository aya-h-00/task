#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string fullName;
    int id;
    double grade;

    cout << "Enter Full Name: ";
    getline(cin, fullName);

    cout << "Enter ID: ";
    cin >> id;

    cout << "Enter Grade: ";
    cin >> grade;

    ofstream studentFile("Student.txt");

    if (!studentFile.is_open()) {
        cout << "Error, file is not opened" << endl;
        return 1;
    }

    studentFile << "Full Name: " << fullName << endl;
    studentFile << "ID: " << id << endl;
    studentFile << "Grade: " << grade << endl;

    studentFile.close();
    cout << "Student data saved to Student.txt successfully." << endl;

    return 0;
}
