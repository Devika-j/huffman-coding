#include <iostream>
#include <cstring>
#include "dependencies/conversions.hpp"
using namespace std;

int main()
{
    string input;
    getline(cin, input);

    system("cls");
    cout << "Input Details ->" << endl;
    cout << "Text : ";
    for(int i=0; input[i] != '\0'; i++)
        cout << input[i];

    cout << "\nSize of text : " << sizeof(input) << endl;
    strToBinary(input);

    cin.get();
    return 0;
}