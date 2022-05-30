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
    if (d == -1)
        return NULL;
    node *root = new node(d);
    root->left = createTree();
    root->right = createTree();
    return root;
}

// temporary node to keep track of Node returned
// from previous recursive call during backtrack
node *temp = NULL;

node *kthAncestor(node *root, int val, int &k)
{
    if (!root)
        return NULL;

    if (root->data == val or (temp = kthAncestor(root->left, val, k)) or (temp = kthAncestor(root->right, val, k)))
    {
        if (k > 0)
            k--;
        else if (k == 0)
        {
            cout << "Kth ancestor is : " << root->data;

            // return NULL to stop further backtracking
            return NULL;
        }

        return root;
    }
}

int main()
{
    node *root = createTree();
    int k = 2, n = 5;
    node *ans = kthAncestor(root, n, k);

    if (ans)
        cout << -1 << endl;
}