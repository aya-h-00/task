#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    // 1. فتح الملف للقراءة وطباعة محتوياته على الشاشة
    ifstream inFile("fruit.txt");
    if (!inFile.is_open()) {
        cout << "Error: Could not open fruit.txt for reading!" << endl;
        return 1;
    }

    string line;
    cout << "Contents of fruit.txt:" << endl;
    while (getline(inFile, line)) {
        cout << line << endl;
    }
    inFile.close();

    // 2. فتح نفس الملف بوضع الإضافة (append) لكتابة Fresh Fruits في نهايته
    ofstream outFile("fruit.txt", ios::app);
    if (!outFile.is_open()) {
        cout << "Error: Could not open fruit.txt for writing!" << endl;
        return 1;
    }

    outFile << "Fresh Fruits" << endl;
    outFile.close();

    cout << "\nAppended 'Fresh Fruits' to fruit.txt successfully." << endl;
    return 0;
}
