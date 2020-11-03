#include <cstring>
#include <iostream>
#include <unordered_map>
#include "dependencies/conversions.hpp"

using namespace std;

unordered_map<char, int> freq;

void calcfreq(string input)
{
    for (int i = 0; i < input.size(); i++)
        freq[input[i]]++;
}

int main()
{
    string input;
    getline(cin, input);

    system("cls");
    cout << "Input Details ->" << endl;
    cout << "Text : ";
    for (int i = 0; input[i] != '\0'; i++)
        cout << input[i];

    int size = 0;
    for (int i = 0; input[i] != '\0'; i++)
        size++;

    cout << "\nSize of text : " << size << endl;
    strToBinary(input);
    calcfreq(input);

    int n;
    cin >> n;
    return 0;
}