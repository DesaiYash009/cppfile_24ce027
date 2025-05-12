#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    vector<pair<string, int>> students;
    string name;
    int score;

    for (int i = 0; i < n; ++i) {
        cout << "Enter name and score for student " << i + 1 << ": ";
        cin >> name >> score;
        students.push_back({name, score});
    }

    sort(students.begin(), students.end(),
              [](const pair<string, int>& a, const pair<string, int>& b) {
                  return a.second > b.second;
                  });

    cout << "\nRanked Student List:\n";
    int rank = 1;
    for (auto it = students.begin(); it != students.end(); ++it) {
        cout << "Rank " << rank << ": " << it->first << " (Score: " << it->second << ")\n";
        ++rank;
    }

    cout<<"\n\n24CE027_yash Desai\n";
    return 0;
}
