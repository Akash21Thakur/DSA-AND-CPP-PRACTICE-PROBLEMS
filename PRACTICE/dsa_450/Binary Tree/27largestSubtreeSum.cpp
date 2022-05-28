#include <iostream>
#include <queue>
#include <utility>
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

// update ans and return curSum

int helper(node *root, int &ans)
{
    if (!root)
        return 0;

    int curSum = root->data + helper(root->left, ans) + helper(root->right, ans);

    ans = max(ans, curSum);

    return curSum;
}

int largestSubtreeSum(node *root)
{
    int ans = INT_MIN;
    helper(root, ans);

    return ans;
}

int main()
{
    node *root = createTree();

    cout << largestSubtreeSum(root);
}