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
    int count;
    cout << "Enter number of persons: ";
    cin >> count;

    if (count <= 0) {
        cout << "Number of persons must be greater than 0." << endl;
        return 1;
    }

    string dataFile = "persons.txt";

    // الخطوة 1: إدخال البيانات وحفظها في الملف كـ string و integer
    ofstream outFile(dataFile);
    if (!outFile.is_open()) {
        cout << "Error opening " << dataFile << " for writing!" << endl;
        return 1;
    }

    for (int i = 0; i < count; i++) {
        Person p;
        cout << "Enter name and age for person " << (i + 1) << ": ";
        cin >> p.name >> p.age;
        outFile << p.name << " " << p.age << endl;
    }
    outFile.close();

    // الخطوة 2: قراءة البيانات من الملف وتخزينها في vector<Person>
    ifstream inFile(dataFile);
    if (!inFile.is_open()) {
        cout << "Error opening " << dataFile << " for reading!" << endl;
        return 1;
    }

    vector<Person> persons;
    Person temp;
    while (inFile >> temp.name >> temp.age) {
        persons.push_back(temp);
    }
    inFile.close();

    if (persons.empty()) {
        cout << "No person data found in " << dataFile << endl;
        return 1;
    }

    // إيجاد الأصغر والأكبر سنًا (مع مراعاة وجود أكثر من شخص بنفس العمر)
    int minAge = persons[0].age;
    int maxAge = persons[0].age;

    for (size_t i = 1; i < persons.size(); i++) {
        if (persons[i].age < minAge) {
            minAge = persons[i].age;
        }
        if (persons[i].age > maxAge) {
            maxAge = persons[i].age;
        }
    }

    // حفظ النتائج في ملف results.txt
    ofstream resFile("results.txt");
    if (!resFile.is_open()) {
        cout << "Error opening results.txt for writing!" << endl;
        return 1;
    }

    resFile << "Younger person(s) (Age: " << minAge << "):" << endl;
    for (const auto& p : persons) {
        if (p.age == minAge) {
            resFile << p.name << " - " << p.age << endl;
        }
    }

    resFile << "\nOlder person(s) (Age: " << maxAge << "):" << endl;
    for (const auto& p : persons) {
        if (p.age == maxAge) {
            resFile << p.name << " - " << p.age << endl;
        }
    }

    resFile.close();
    cout << "Done! Data saved to persons.txt and results.txt." << endl;

    return 0;
}
