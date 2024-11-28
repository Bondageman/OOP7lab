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
            cout << "�����: \"" << str << "\", ʳ������ ���: " << countWords(str) << "\n";
        }
    }
};

int main() 
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    StringArray array;

    cout << "������ ����� (��� ���������� �������� �������� Enter �� ���������� �����):\n";
    string input;
    while (true) {
        getline(cin, input);
        if (input.empty()) break; 
        array.addString(input);
    }

    array.sortStrings();
    cout << "\n³��������� ����� �� ������� ��� � �������:\n";
    array.displayStringsAndWordCounts();

    return 0;
}
