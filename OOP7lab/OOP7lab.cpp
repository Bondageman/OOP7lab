#include <iostream>
#include <vector>
#include <string>
#include <algorithm> 
#include <sstream>   
#include <Windows.h>

using namespace std;

class StringArray {
private:
    vector<string> strings; 

public:

    void addString(const string& str) {
        strings.push_back(str);
    }

    void sortStrings() {
        sort(strings.begin(), strings.end());
    }   

    int countWords(const string& str) const {
        istringstream iss(str);
        int count = 0;
        string word;
        while (iss >> word) {
            ++count;
        }
        return count;
    }

    void displayStringsAndWordCounts() const {
        for (const auto& str : strings) {
            cout << "Рядок: \"" << str << "\", Кількість слів: " << countWords(str) << "\n";
        }
    }
};

int main() 
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    StringArray array;

    cout << "Введіть рядки (для завершення введення натисніть Enter на порожньому рядку):\n";
    string input;
    while (true) {
        getline(cin, input);
        if (input.empty()) break; 
        array.addString(input);
    }

    array.sortStrings();
    cout << "\nВідсортовані рядки та кількість слів у кожному:\n";
    array.displayStringsAndWordCounts();

    return 0;
}
