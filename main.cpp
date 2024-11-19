#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

class StudentGroup {
private:
    map<string, vector<string>> groups;

public:
    void addStudent(const string& group, const string& student) {
        groups[group].push_back(student);
    }

    void removeStudent(const string& group, const string& student) {
        auto& students = groups[group];
        auto it = find(students.begin(), students.end(), student);
        if (it != students.end()) {
            students.erase(it);
            cout << "Student " << student << " removed from group " << group << ".\n";
        }
        else {
            cout << "Student not found in the group.\n";
        }
    }

    void showGroup(const string& group) {
        if (groups.find(group) != groups.end()) {
            cout << "Group " << group << ": ";
            for (const auto& student : groups[group]) {
                cout << student << ", ";
            }
            cout << endl;
        }
        else {
            cout << "Group not found.\n";
        }
    }
};

int main() {
    StudentGroup groupManager;
    int choice;

    do {
        cout << "\nMenu:\n";
        cout << "1. Add a student\n";
        cout << "2. Remove a student\n";
        cout << "3. Show students in a group\n";
        cout << "4. Exit\n";
        cout << "Your choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            string group, student;
            cout << "Enter group: ";
            getline(cin, group);
            cout << "Enter student name: ";
            getline(cin, student);
            groupManager.addStudent(group, student);
        }
        else if (choice == 2) {
            string group, student;
            cout << "Enter group: ";
            getline(cin, group);
            cout << "Enter student name to remove: ";
            getline(cin, student);
            groupManager.removeStudent(group, student);
        }
        else if (choice == 3) {
            string group;
            cout << "Enter group to view: ";
            getline(cin, group);
            groupManager.showGroup(group);
        }
        else if (choice == 4) {
            cout << "Exiting...\n";
        }
        else {
            cout << "Invalid choice, please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
