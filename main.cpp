#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <iomanip>

using namespace std;

int main() {
    cout << "Enter text: ";
    string input;
    getline(cin, input);

    map<string, int> wordCount;
    stringstream ss(input);
    string word;

    while (ss >> word) {
        wordCount[word]++;
    }

    cout << "Result:\n";
    for (const auto& pair : wordCount) {
        cout << pair.first << " — " << pair.second << endl;  
    }

    return 0;
}
