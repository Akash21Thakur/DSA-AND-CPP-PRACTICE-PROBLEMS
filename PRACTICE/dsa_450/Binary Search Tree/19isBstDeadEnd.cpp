// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

void insert(Node **tree, int val)
{
    Node *temp = NULL;
    if (!(*tree))
    {
        temp = new Node(val);
        *tree = temp;
        return;
    }

    if (val < (*tree)->data)
    {
        insert(&(*tree)->left, val);
    }
    else if (val > (*tree)->data)
    {
        insert(&(*tree)->right, val);
    }
}

int getCountOfNode(Node *root, int l, int h)
{

    if (!root)
        return 0;

    if (root->data == h && root->data == l)
        return 1;

    if (root->data <= h && root->data >= l)
        return 1 + getCountOfNode(root->left, l, h) +
               getCountOfNode(root->right, l, h);

    else if (root->data < l)
        return getCountOfNode(root->right, l, h);

    else
        return getCountOfNode(root->left, l, h);
}

bool isDeadEnd(Node *root);
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        Node *root;
        Node *tmp;
        // int i;

        root = NULL;

        int N;
        cin >> N;
        for (int i = 0; i < N; i++)
        {
            int k;
            cin >> k;
            insert(&root, k);
        }

        cout << isDeadEnd(root);
        cout << endl;
    }
}

// } Driver Code Ends

/*The Node structure is
struct Node {
int data;
Node * right, * left;
};*/

/*You are required to complete below method */

// DEAD END... FOR ANY NODE WE CAN NODE INSERT NODE TO ITS LEFT OR RIGHT
// ALGO:
// range of root(1,INT_MAX)
// range root.left(1,root.data-1)
// range root.right(root.data+1,INT_MAX)
// if at any time mini==maxi return true... as dead end found

bool helper(Node *root, int mini, int maxi)
{
    if (!root)
        return false;

    if (mini == maxi)
        return true;

    return helper(root->left, mini, root->data - 1) or helper(root->right, root->data + 1, maxi);
}

bool isDeadEnd(Node *root)
{
    return helper(root, 1, INT_MAX);
}