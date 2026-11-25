#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

struct Person {
    string name;
    int age;
};

int main() {
    int n;
    cout << "Enter how many persons you want to add: ";
    cin >> n;

    if (n <= 0) {
        cout << "Please enter a valid positive number." << endl;
        return 1;
    }

    // الخطوة 1: حفظ بيانات الأشخاص في ملف persons.txt
    ofstream outFile("persons.txt");
    if (!outFile.is_open()) {
        cout << "Error opening persons.txt for writing!" << endl;
        return 1;
    }

    for (int i = 0; i < n; i++) {
        Person p;
        cout << "Enter name of person " << i + 1 << ": ";
        cin >> ws;
        getline(cin, p.name);

        cout << "Enter age of person " << i + 1 << ": ";
        cin >> p.age;

        outFile << p.name << endl;
        outFile << p.age << endl;
    }
    outFile.close();

    // الخطوة 2: قراءة البيانات من الملف وتخزينها في vector<Person>
    ifstream inFile("persons.txt");
    if (!inFile.is_open()) {
        cout << "Error opening persons.txt for reading!" << endl;
        return 1;
    }

    vector<Person> persons;
    Person temp;
    while (getline(inFile, temp.name) && (inFile >> temp.age)) {
        inFile.ignore(); // تجاهل سطر الإدخال الجديد بعد قراءة العمر
        persons.push_back(temp);
    }
    inFile.close();

    if (persons.empty()) {
        cout << "No data found in persons.txt." << endl;
        return 1;
    }

    // إيجاد أصغر وأكبر شخص من الـ vector
    Person younger = persons[0];
    Person older = persons[0];

    for (size_t i = 1; i < persons.size(); i++) {
        if (persons[i].age < younger.age) {
            younger = persons[i];
        }
        if (persons[i].age > older.age) {
            older = persons[i];
        }
    }

    // حفظ النتيجة في ملف results.txt
    ofstream resultFile("results.txt");
    if (!resultFile.is_open()) {
        cout << "Error opening results.txt for writing!" << endl;
        return 1;
    }

    resultFile << "Younger Person: " << younger.name << " (" << younger.age << ")" << endl;
    resultFile << "Older Person: " << older.name << " (" << older.age << ")" << endl;
    resultFile.close();

    cout << "Saved persons to persons.txt and results to results.txt successfully." << endl;

    return 0;
}
