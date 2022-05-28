#include <iostream>
#include <vector>
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
    if (d == 0)
        return NULL;
    node *root = new node(d);
    root->left = createTree();
    root->right = createTree();
    return root;
}

void helper(node *root, vector<int> &ans, int k)
{
    if (!root)
        return;
    ans.push_back(root->data);

    helper(root->left, ans, k);
    helper(root->right, ans, k);

    int sum = 0;
    for (int i = ans.size() - 1; i >= 0; i--)
    {
        sum += ans[i];
        if (sum == k)
        {
            for (int j = i; j < ans.size(); j++)
                cout << ans[j] << " ";
            cout << endl;
        }
    }

    ans.pop_back();
}

// ref : code lib.
void printAllKsumPath(node *root, int k)
{
    vector<int> ans;
    helper(root, ans, k);
}

int main()
{
    node *root = createTree();
    cout << "Enter k : ";
    int k;
    cin >> k;
    printAllKsumPath(root, k);
}