#include <iostream>
#include <queue>
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

// create tree
node *insertIntoBST(node *root, int d)
{
    if (root == NULL)
        return new node(d);

    if (root->data >= d)
        root->left = insertIntoBST(root->left, d);
    else
        root->right = insertIntoBST(root->right, d);

    return root;
}

// BUILD TREE
node *buildTree()
{
    int d;
    cin >> d;
    node *root = NULL;
    while (d != -1)
    {
        root = insertIntoBST(root, d);
        cin >> d;
    }
    return root;
}

// inorder trav.
void inOrder(node *root)
{
    if (!root)
        return;

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

// bst
// method-1 O(n^2)
// make the first element as root...
// next lesser val. moves in the left child...
// other half to end as right child

node *bstFromPre(int *pre, int *preIdx, int low, int high, int size)
{
    if (*preIdx == size or low > high)
        return NULL;

    // The first node in preorder traversal is root. So take
    // the node at preIndex from pre[] and make it root, and
    // increment preIndex
    node *root = new node(pre[*preIdx]);
    *preIdx = *preIdx + 1;

    // if current subarray has only element no need to recurr
    if (low == high)
        return root;

    // Ist element greater than root
    int i;
    for (i = low; i <= high; i++)
        if (pre[i] > root->data)
            break;

    root->left = bstFromPre(pre, preIdx, *preIdx, i - 1, size);
    root->right = bstFromPre(pre, preIdx, i, high, size);

    return root;
}

// method-2  O(n)
//  taking min and max and updating as we move ahead
node *bstFromPre2(int *pre, int *preIdx, int key, int mini, int maxi, int size)
{
    if (*preIdx >= size)
        return NULL;

    node *root = NULL;
    // If current element of pre[] is in range, then
    // only it is part of current subtree
    if (key > mini and key < maxi)
    {
        // Allocate memory for root of this
        // subtree and increment *preIndex
        root = new node(key);
        *preIdx = *preIdx + 1;

        if (*preIdx < size)
        {
            // Construct the subtree under root
            // All nodes which are in range
            // {min .. key} will go in left
            // subtree, and first such node
            // will be root of left subtree.
            root->left = bstFromPre2(pre, preIdx, pre[*preIdx], mini, key, size);
        }
        if (*preIdx < size)
        {
            // All nodes which are in range
            // {key..max} will go in right
            // subtree, and first such node
            // will be root of right subtree.
            root->right = bstFromPre2(pre, preIdx, pre[*preIdx], key, maxi, size);
        }
    }

    return root;
}
int main()
{
    int pre[] = {10, 5, 1, 7, 40, 50};
    int size = sizeof(pre) / sizeof(pre[0]);

    int preIdx = 0;
    // method-1
    //  node *root = bstFromPre(pre, &preIdx, 0, size - 1, size);

    // method-2
    node *root = bstFromPre2(pre, &preIdx, pre[0], INT_MIN, INT_MAX, size);
    inOrder(root);
}