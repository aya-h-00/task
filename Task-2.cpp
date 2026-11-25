#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string fruit;

    // 1. فتح الملف للقراءة وطباعة محتوياته على الشاشة
    ifstream inFile("fruit.txt");

    if (!inFile.is_open()) {
        cout << "Error, file is not opened" << endl;
        return 1;
    }

    while (getline(inFile, fruit)) {
        cout << fruit << endl;
    }

    inFile.close();

    // 2. فتح نفس الملف بوضع الإضافة (ios::app) لكتابة Fresh Fruits في نهايته
    ofstream outFile("fruit.txt", ios::app);

    if (!outFile.is_open()) {
        cout << "Error, file is not opened" << endl;
        return 1;
    }

    outFile << "\nFresh Fruits" << endl;
    outFile.close();

    return 0;
}
