#include <iostream>
#include <sstream>
#include <map>
#include <string>

using namespace std;

int main() {
    string sentence;
    cout << "Enter a sentence: ";
    getline(cin, sentence);

    map<string, int> wordFrequency;
    stringstream ss(sentence);
    string word;

    while (ss >> word) {
        ++wordFrequency[word];
    }

    cout << "\nWord Frequency:\n";
    for (const auto& pair : wordFrequency) {
        cout << pair.first << ": " << pair.second << endl;
    }

    cout << "\n24CE027 @ Yash Desai" << endl;
    return 0;
}
