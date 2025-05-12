#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
    int n, id;
    cout << "Enter number of transaction IDs: ";
    cin >> n;

    set<int> uniqueIDs;

    cout << "Enter " << n << " transaction IDs:\n";
    for (int i = 0; i < n; ++i) {
        cin >> id;
        uniqueIDs.insert(id);
    }

    cout << "\nUnique Transaction IDs (sorted):\n";
    for (auto it = uniqueIDs.begin(); it != uniqueIDs.end(); ++it) {
        cout << *it << " ";
    }

    cout<<"\n\n24CE027_Yash Desai\n";

    return 0;
}
