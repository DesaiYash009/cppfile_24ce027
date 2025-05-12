
#include <iostream>
#include <fstream>
#include <cstring>
#include <cctype>

using namespace std;
int countWords(const char* line) {
    int wordCount = 0;
    bool inWord = false;

    for (int i = 0; line[i] != '\0'; ++i) {
        if (isspace(line[i])) {
            inWord = false;
        } else if (!inWord) {
            inWord = true;
            wordCount++;
        }
    }

    return wordCount;
}

int main() {
    const int MAX_LINE_LENGTH = 1024;
    char filename[100];

    cout << "Enter the filename to analyze: ";
    cin.getline(filename, 100);

    ifstream file(filename);


    if (!file.is_open()) {
        cerr << "Error: Could not open file \"" << filename << "\". Please check if it exists and you have permission to read it.\n";
        return 1;
    }



    int capacity = 10;
    int size = 0;
    char** lines = new char*[capacity];

    int totalChars = 0;
    int totalWords = 0;
    int totalLines = 0;

    char buffer[MAX_LINE_LENGTH];

    while (file.getline(buffer, MAX_LINE_LENGTH)) {
        totalLines++;

        totalChars += strlen(buffer);

        totalWords += countWords(buffer);

        if (size >= capacity) {
            capacity *= 2;
            char** newLines = new char*[capacity];

            for (int i = 0; i < size; ++i)
                newLines[i] = lines[i];

            delete[] lines;
            lines = newLines;
        }


        lines[size] = new char[strlen(buffer) + 1];
        strcpy(lines[size], buffer);
        size++;
    }

    file.close();


    cout << "\n--- File Statistics ---\n";
    cout << "Total Characters: " << totalChars << endl;
    cout << "Total Words     : " << totalWords << endl;
    cout << "Total Lines     : " << totalLines << endl;

    for (int i = 0; i < size; ++i)
        delete[] lines[i];

    delete[] lines;

    cout<<endl<<"24CE027 yash Desai"<<endl;

    return 0;
}
