#include <iostream>
#include <vector>
using namespace std;

struct node
{
    int data;
    struct node *left, *right;

    node(int d)
    {
        this->data = d;
        left = right = NULL;
    }
};

node *insertNode(node *root, int d)
{
    if (root == NULL)
        return new node(d);

    if (d < root->data)
        root->left = insertNode(root->left, d);
    else
        root->right = insertNode(root->right, d);

    return root;
}

node *createTree()
{
    int d;
    cin >> d;
    node *root = NULL;
    while (d != -1)
    {
        root = insertNode(root, d);
        cin >> d;
    }
    return root;
}

// MERGE TWO BST
// METH-1  mLogn
// INSERT 1 BY 1 all the elements of node-1 to node-2

// method-2  O(m+n),O(m+n)
//  store inorder trav. of two bst in two arrays
//  merge two sorted array
//  tree from sorted array

void inOrder(node *root, vector<int> &v)
{
    if (!root)
        return;

    inOrder(root->left, v);
    v.push_back(root->data);
    inOrder(root->right, v);
}

vector<int> mergeTwoSortedArray(vector<int> &a1, vector<int> &a2)
{
    int n = a1.size(), m = a2.size();
    vector<int> v(m + n);

    int i = 0, j = 0, k = 0;

    while (i < n and j < m)
    {
        if (a1[i] < a2[j])
        {
            v[k++] = a1[i++];
        }
        else // if(a2[j]<a1[i])
        {
            v[k++] = a2[j++];
        }
    }

    while (i < n)
    {
        v[k++] = a1[i++];
    }

    while (j < m)
    {
        v[k++] = a2[j++];
    }

    return v;
}

node *bstFromArray(vector<int> &v, int low, int high)
{
    if (low > high)
        return NULL;

    int mid = (low + high) / 2;

    node *root = new node(v[mid]);

    root->left = bstFromArray(v, low, mid - 1);
    root->right = bstFromArray(v, mid + 1, high);

    return root;
}

node *mergeTwoBst(node *a, node *b)
{
    vector<int> v1, v2;
    inOrder(a, v1);

    inOrder(b, v2);

    vector<int> v = mergeTwoSortedArray(v1, v2);

    node *root = bstFromArray(v, 0, v.size() - 1);

    return root;
}

int main()
{
    cout << "Tree-1 : ";
    node *a = createTree();
    cout << "Tree-2 : ";
    node *b = createTree();

    node *root = mergeTwoBst(a, b);
    vector<int> v;
    inOrder(root, v);
    for (auto x : v)
        cout << x << " ";
}