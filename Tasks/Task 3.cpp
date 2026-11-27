#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string filename = "welcome.txt";
    string text = "Hello Everybody";

    // 1. كتابة الجملة الأولى في الملف welcome.txt
    ofstream outFile(filename);
    if (!outFile.is_open()) {
        cout << "Error opening file for writing!" << endl;
        return 1;
    }
    outFile << text << endl;
    outFile.close();

    // 2. قراءة المحتوى من الملف
    ifstream inFile(filename);
    if (!inFile.is_open()) {
        cout << "Error opening file for reading!" << endl;
        return 1;
    }
    string content;
    getline(inFile, content);
    inFile.close();

    // 3. البحث عن "body" واستبداله بـ "one"
    string target = "body";
    string replacement = "one";
    size_t pos = content.find(target);

    if (pos != string::npos) {
        content.replace(pos, target.length(), replacement);
    }

    // 4. كتابة النتيجة النهائية (Hello Everyone) في نفس الملف
    ofstream finalFile(filename);
    if (!finalFile.is_open()) {
        cout << "Error opening file to save final result!" << endl;
        return 1;
    }
    finalFile << content << endl;
    finalFile.close();

    cout << "Final text: " << content << endl;
    return 0;
}
