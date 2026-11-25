#include <iostream>
#include <fstream>

using namespace std;

int main() {
    char name[20];
    int id;
    float grade;
    char delim = '$';
    char choice;

    // فتح الملف بوضع الإضافة (ios::app) لإضافة سجلات الطلاب دون مسح السجلات السابقة
    ofstream outFile("students.txt", ios::app);

    if (!outFile.is_open()) {
        cout << "Error opening students.txt!" << endl;
        return 1;
    }

    do {
        cout << "Enter Student Name: ";
        cin >> ws;
        cin.getline(name, 20);

        cout << "Enter Student ID: ";
        cin >> id;

        cout << "Enter Student Grade: ";
        cin >> grade;

        // كتابة السجل بنفس الصيغة المطلوبة: Name, ID, Grade $
        outFile << name << ", " << id << ", " << grade << " " << delim << endl;

        cout << "Do you want to add another record? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    outFile.close();
    cout << "All student records saved to students.txt successfully." << endl;

    return 0;
}
