#include <cstring>
#include <iostream>
#include <unordered_map>
#include "dependencies/conversions.hpp"
#include "dependencies/tree.hpp"
#include "dependencies/count freq.hpp"
using namespace std;

unordered_map<char, int> freq,temp;
int totcount = 0;

void implement_tree()
{
    hufftree *root = new hufftree(totcount);
    hufftree *curr = root;
    int temp_count = freq.size();
    for(int i=0; i<temp_count; i++)
    {
        char ch = max_freq(freq);
        int value = freq[ch];
        freq.erase(ch);
        temp[ch] = value;

        hufftree *node = new hufftree(temp[ch]);
        curr ->right = node;
        node = new hufftree(curr ->data - temp[ch]);
        curr ->left = node;
        curr = curr ->left;
    }
}

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

    for (int i = 0; input[i] != '\0'; i++)
        totcount++;

    cout << "\nSize of text : " << totcount << endl;
    strToBinary(input);
    calcfreq(input);

    int n;
    cin >> n;
    return 0;
}