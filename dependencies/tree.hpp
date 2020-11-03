#include <iostream>
using namespace std;

class hufftree
{
public:
    int data;
    hufftree *left;
    hufftree *right;
    hufftree(int data)
    {
        this ->data = data;
        this ->left = NULL;
        this ->right = NULL;
    }
};
