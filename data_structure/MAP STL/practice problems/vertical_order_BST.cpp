#include <iostream>
#include <map>
#include <vector>
using namespace std;

class node
{

public:
    int data;
    node *left;
    node *right;
    node(int d)
    {
        this->data = d;
        left = right = NULL;
    }
};

void verticalOrderBst(node *root, map<int, vector<int>> &m, int d)
{
    if (root == NULL)
        return;

    m[d].push_back(root->data);
    verticalOrderBst(root->left, m, d - 1);
    verticalOrderBst(root->right, m, d + 1);
}

int main()
{
    node *root = new node(15);
    root->left = new node(12);
    root->left->right = new node(14);
    root->left->left = new node(10);
    root->left->left->left = new node(5);
    root->right = new node(25);
    root->right->left = new node(20);
    root->right->right = new node(50);

    map<int, vector<int>> m;
    //  int d=0;
    verticalOrderBst(root, m, 0);

    for (auto x : m)
    {
        cout << x.first << " => ";
        for (int i : x.second)
            cout << i << " ";
        cout << endl;
    }
}