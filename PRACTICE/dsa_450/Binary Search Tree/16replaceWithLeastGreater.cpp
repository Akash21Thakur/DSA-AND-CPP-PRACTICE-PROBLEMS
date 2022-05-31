#include <iostream>
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

// insert and update succ if found
node *insert(node *root, int key, node *&succ)
{
    if (!root)
        return new node(key);

    // if key is less than root->data...move to right...
    // but need to update succ... coz it might be the answer if node found in the left side
    if (key < root->data)
    {
        succ = root;
        root->left = insert(root->left, key, succ);
    }

    // check in the right subtree
    else if (key > root->data)
    {
        root->right = insert(root->right, key, succ);
    }

    return root;
}

void replace(int *a, int n)
{
    node *root = NULL;

    // start from right to left
    for (int i = n - 1; i >= 0; i--)
    {
        node *succ = NULL;

        // insert current element and check if inorder successor exist
        root = insert(root, a[i], succ);

        // replace if found else -1
        if (succ)
            a[i] = succ->data;
        else
            a[i] = -1;
    }
}

int main()
{
    int arr[] = {8, 58, 71, 18, 31, 32, 63, 92,
                 43, 3, 91, 93, 25, 80, 28};
    int n = sizeof(arr) / sizeof(arr[0]);
    // cout << "akash thakur" << endl;
    replace(arr, n);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    // cout << "akash thakur" << endl;

    return 0;
}