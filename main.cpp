#include <cstring>
#include <iostream>
#include <unordered_map>
#include "dependencies/conversions.hpp"
#include "dependencies/map.hpp"
#include "dependencies/tree.hpp"
#include "dependencies/graphics.hpp"

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

using namespace std;

unordered_map<char, int> freq, temp;
int totcount = 0;
unordered_map<char, string> freq2;

void compressed(string s)
{
    //gotoxy(50, 1);
    cout << "\nSize after compression is: " << sizeof(hufftree);
    cout << "\nCompressed encoded message is:" << endl;
    for(int i=0; s[i] != '\0'; i++)
        cout << freq2[s[i]];
}

char find_key_value(int data)
{
    for (auto i : temp)
        if (i.second == data)
            return i.first;
}

void encode(hufftree *root, string s="\0")
{
    if (root->left == NULL && root->right == NULL)
    {
        freq2[find_key_value(root->data)] = s;
        return;
    }
    else if (root->left == NULL)
        encode(root->right, s + "1");
    else if (root->right == NULL)
        encode(root->left, s + "0");
    else
    {
        encode(root->right, s + "1");
        encode(root->left, s + "0");
    }
}

hufftree *implement_tree()
{
    hufftree *root = new hufftree(totcount);
    hufftree *curr = root;
    int temp_count = freq.size();
    for (int i = 0; i < temp_count; i++)
    {
        char ch = max_freq(freq);
        int value = freq[ch];
        freq.erase(ch);
        temp[ch] = value;

        hufftree *node = new hufftree(temp[ch]);
        curr->right = node;
        node = new hufftree(curr->data - temp[ch]);
        curr->left = node;
        curr = curr->left;
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
    encode(root);                       //Causing the program to exit instantly.
    compressed(input);

    int n;
    cin >> n;
    return 0;
}
