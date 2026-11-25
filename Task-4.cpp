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
    cout << "Enter number of persons: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid number of persons." << endl;
        return 1;
    }

    // 1. إدخال بيانات الأشخاص وحفظها في ملف persons.txt
    ofstream outFile("persons.txt");
    if (!outFile.is_open()) {
        cout << "Error opening persons.txt" << endl;
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

    // 2. قراءة البيانات من الملف وتخزينها في vector<Person>
    ifstream inFile("persons.txt");
    if (!inFile.is_open()) {
        cout << "Error reading persons.txt" << endl;
        return 1;
    }

    vector<Person> persons;
    Person temp;
    while (getline(inFile, temp.name) && (inFile >> temp.age)) {
        inFile.ignore(); // لتخطي سطر جديد بعد العمر
        persons.push_back(temp);
    }
    inFile.close();

    if (persons.empty()) {
        cout << "No persons data found." << endl;
        return 1;
    }

    // إيجاد الأصغر سناً والأكبر سناً
    Person younger = persons[0];
    Person older = persons[0];

    for (int i = 1; i < persons.size(); i++) {
        if (persons[i].age < younger.age) {
            younger = persons[i];
        }
        if (persons[i].age > older.age) {
            older = persons[i];
        }
    }

    // حفظ النتائج في ملف results.txt
    ofstream resFile("results.txt");
    if (!resFile.is_open()) {
        cout << "Error opening results.txt" << endl;
        return 1;
    }

    resFile << "Younger Person: " << younger.name << " (" << younger.age << " years old)" << endl;
    resFile << "Older Person: " << older.name << " (" << older.age << " years old)" << endl;
    resFile.close();

    cout << "Data saved to persons.txt and results saved to results.txt successfully." << endl;

    return 0;
}
