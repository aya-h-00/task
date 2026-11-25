#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ofstream file("welcome.txt");

    if (!file.is_open()) {
        cout << "Error opening the file" << endl;
        return 1;
    }

    // 1. كتابة الجملة الأولى في الملف
    file << "Hello Everybody";

    // 2. تحريك مؤشر الكتابة إلى بداية كلمة body (الموضع 11)
    file.seekp(11);

    // 3. استبدال body بـ one مع مسافة لمسح حرف y المتبقي
    file << "one ";

    file.close();
    cout << "File updated to: Hello Everyone" << endl;

    return 0;
}
