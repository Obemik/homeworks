#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <numeric>
#include <iomanip>

using namespace std;

double calculateAverage(const vector<int>& grades) {
    if (grades.empty()) {
        return 0.0;
    }
    return static_cast<double>(accumulate(grades.begin(), grades.end(), 0)) / grades.size();
}

int main() {
    map<string, vector<int>> studentRecords;
    string studentName;
    string command;

    cout << "Student Grades Management Program.\n";
    cout << "Enter 'add' to add a student and their grades.\n";
    cout << "Enter 'list' to display all students and their average grades.\n";
    cout << "Enter 'exit' to quit the program.\n";

    while (true) {
        cout << "\nCommand: ";
        cin >> command;

        if (command == "add") {
            cout << "Enter the student's name: ";
            cin.ignore();
            getline(cin, studentName);

            cout << "Enter grades (separated by spaces): ";
            vector<int> grades;
            int grade;
            while (cin.peek() != '\n') {
                cin >> grade;
                grades.push_back(grade);
            }
            cin.ignore();

            studentRecords[studentName].insert(
                studentRecords[studentName].end(), grades.begin(), grades.end()
            );

            cout << "Student's data updated.\n";

        }
        else if (command == "list") {
            if (studentRecords.empty()) {
                cout << "No students in the list.\n";
                continue;
            }

            cout << "List of students and their average grades:\n";
            for (const auto& pair : studentRecords) {
                const string& name = pair.first;
                const vector<int>& grades = pair.second;
                double average = calculateAverage(grades);
                cout << name << ": average grade = " << fixed << setprecision(2) << average << "\n";
            }

        }
        else if (command == "exit") {
            cout << "Program terminated.\n";
            break;
        }
        else {
            cout << "Unknown command. Please try again.\n";
        }
    }

    return 0;
}
