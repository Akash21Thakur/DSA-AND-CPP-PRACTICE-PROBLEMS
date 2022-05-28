#include <iostream>
#include <queue>
#include <unordered_map>
#include <climits>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

node *createTree()
{
    int d;
    cin >> d;
    if (d == -1)
        return NULL;
    node *root = new node(d);
    root->left = createTree();
    root->right = createTree();
    return root;
}

unordered_map<node *, int> dp;

int maxSumNonAdjacentNodes(node *root)
{
    if (!root)
        return 0;

    if (dp[root])
        return dp[root];

    // include current node
    int incl = root->data;
    if (root->left)
    {
        incl += maxSumNonAdjacentNodes(root->left->left);
        incl += maxSumNonAdjacentNodes(root->left->right);
    }
    if (root->right)
    {
        incl += maxSumNonAdjacentNodes(root->right->left);
        incl += maxSumNonAdjacentNodes(root->right->right);
    }

    // exclude cur. node
    int excl = maxSumNonAdjacentNodes(root->left) + maxSumNonAdjacentNodes(root->right);

    return dp[root] = max(incl, excl);
}

int main()
{
    node *root = createTree();

    cout << maxSumNonAdjacentNodes(root) << endl;
}