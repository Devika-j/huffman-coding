#include <iostream>
#include <cstring>
#include <unordered_map>
using namespace std;

char max_freq(unordered_map<char,int> freq)
{
    int max = 0;
    char ch;
    for(auto i : freq)
        if(i.second > max)
        {
            max = i.second;
            ch = i.first;
        }

    return ch;
}

