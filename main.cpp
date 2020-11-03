#include <cstring>
#include <iostream>
#include <unordered_map>
#include "dependencies/conversions.hpp"
#include "dependencies/tree.hpp"
#include "dependencies/map.hpp"
using namespace std;

unordered_map<char, int> freq,temp;
int totcount = 0;   
unordered_map<char, string> freq2;

char find_key_value(int data)
{
    for(auto i : temp)
    {
        if(i.second == data)
            return i.first;
    }
}

void encode(hufftree *root, string s = '\0')
{
    if(root == NULL)
    {
        freq2[find_key_value(root ->data)] = s;
    }

    encode(root ->right, s+'1');
    encode(root ->left, s+'2');

}

hufftree *implement_tree()
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
    return root;
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
    hufftree *root = implement_tree();
    encode(root);

    int n;
    cin >> n;
    return 0;
}