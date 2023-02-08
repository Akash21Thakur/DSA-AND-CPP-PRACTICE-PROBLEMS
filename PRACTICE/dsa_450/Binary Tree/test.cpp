#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int i)
    {
        this->data = i;
        left = right = NULL;
    }
};

Node *createTree(int i, int n, vector<int> &v)
{
    if (i >= n)
        return NULL;
    Node *root = new Node(v[i]);

    root->left = createTree(2 * i + 1, n, v);

    root->right = createTree(2 * i + 2, n, v);

    return root;
}

Node *lcaFunc(Node *root, int a, int b)
{
    if (!root)
        return NULL;

    if (root->data == a or root->data == b)
        return root;

    Node *l = lcaFunc(root->left, a, b);
    Node *r = lcaFunc(root->right, a, b);

    if (l and r)
        return root;

    if (l)
        return l;
    return r;
}

int findDist1(Node *root, int val, int dist)
{
    if (!root)
        return -1;

    if (root->data == val)
        return dist;

    int a = findDist1(root->left, val, dist + 1);
    if (a != -1)
        return a;

    // definitly on the right if not left
    return findDist1(root->right, val, dist + 1);
}

int findDist(Node *root, int a, int b)
{
    // find lca
    // find d1 and d2 of a and b from lca resp.
    // return d1+d2

    Node *lca = lcaFunc(root, a, b);

    int d1 = findDist1(lca, a, 0);
    int d2 = findDist1(lca, b, 0);

    return d1 + d2;
}

int main()
{
    int input1, input2, input3;
    cin >> input1 >> input2 >> input3;
    int n = max(input2, input3);
    vector<int> v(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        v[i] = i + 1;
    }

    Node *root = createTree(0, n, v);

    cout << findDist(root, input2, input3) * input1 << endl;
}