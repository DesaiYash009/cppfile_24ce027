
#include <iostream>
#include <vector>
using namespace std;

int recursiveSum(const vector<int>& arr, int n) {
    if (n == 0)
     {
         return 0;
     }
    else
    {
        return arr[n - 1] + recursiveSum(arr, n - 1);
    }
}

int iterativeSum(const vector<int>& arr) {
    int sum = 0;
    for (int num : arr) {
        sum += num;
    }
    return sum;
}

int main() {
    int size;

    cout << "Enter the size of the array: ";
    cin >> size;

    vector<int> numbers(size);
    cout << "Enter " << size << " elements:\n";
    for (int i = 0; i < size; ++i) {
        cout << "Element " << i + 1 << ": ";
        cin >> numbers[i];
    }

    int sumRecursive = recursiveSum(numbers, size);
    int sumIterative = iterativeSum(numbers);

    cout << "\n Results \n";
    cout << "Sum using recursion: " << sumRecursive << endl;
    cout << "Sum using iteration: " << sumIterative << endl;

    cout<<"\nn24CE027_yash Desai.\n";

    return 0;
}
