#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int main() {
    ofstream outFile("students.txt", ios::app);
    if (!outFile.is_open()) {
        cout << "Error: Could not open students.txt!" << endl;
        return 1;
    }

    char choice = 'y';

    while (choice == 'y' || choice == 'Y') {
        char name[20];
        int id;
        float grade;
        char delim = '$';

        cout << "Enter student name (up to 19 chars): ";
        cin.ignore();
        cin.getline(name, 20);

        cout << "Enter student ID: ";
        cin >> id;

        cout << "Enter student grade: ";
        cin >> grade;

        // حفظ السجل بنفس تنسيق المثال المفصول بـ '$'
        outFile << name << ", " << id << ", " << grade << " " << delim << endl;

        cout << "Do you want to add another student? (y/n): ";
        cin >> choice;
    }

    outFile.close();
    cout << "All student records saved to students.txt." << endl;

    return 0;
}
