#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;


void toLowerCase(char* str) {
    for (int i = 0; str[i]; ++i)
        str[i] = tolower(str[i]);
}


bool areEqual(const char* word1, const char* word2) {
    return strcmp(word1, word2) == 0;
}

int main() {
    const int MAX_PARAGRAPH_LENGTH = 1000;


    char paragraph[MAX_PARAGRAPH_LENGTH];
    cout << "Enter a paragraph:\n";
    cin.getline(paragraph, MAX_PARAGRAPH_LENGTH);
    toLowerCase(paragraph);


    char** wordList = nullptr;
    int* wordCount = nullptr;
    int wordCapacity = 10;
    int wordSize = 0;


    wordList = new char*[wordCapacity];
    wordCount = new int[wordCapacity];

    const char* delimiters = " ,.;:!?\"'\n\t";
    char* token = strtok(paragraph, delimiters);

    while (token != nullptr) {
        bool found = false;


        for (int i = 0; i < wordSize; ++i) {
            if (areEqual(wordList[i], token)) {
                wordCount[i]++;
                found = true;
                break;
            }
        }


        if (!found) {

            if (wordSize >= wordCapacity) {
                wordCapacity *= 2;


                char** newWordList = new char*[wordCapacity];
                int* newWordCount = new int[wordCapacity];


                for (int i = 0; i < wordSize; ++i) {
                    newWordList[i] = wordList[i];
                    newWordCount[i] = wordCount[i];
                }


                delete[] wordList;
                delete[] wordCount;


                wordList = newWordList;
                wordCount = newWordCount;
            }

            wordList[wordSize] = new char[strlen(token) + 1];
            strcpy(wordList[wordSize], token);
            wordCount[wordSize] = 1;
            wordSize++;
        }

        token = strtok(nullptr, delimiters);
    }


    cout << "\nWord Frequency Count:\n";
    for (int i = 0; i < wordSize; ++i) {
        cout << wordList[i] << " : " << wordCount[i] << endl;
    }


    for (int i = 0; i < wordSize; ++i) {
        delete[] wordList[i];
    }
    delete[] wordList;
    delete[] wordCount;

    cout<<endl<<"24ce027 yash Desai"<<endl;

    return 0;
}
