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

// flattening means...
// left should be null and right should act as next node
// Approach: A simple approach will be to recreate the BST from its in-order traversal. This will take O(N) extra space where N is the number of nodes in BST.

// To improve upon that, we will simulate in-order traversal of a binary tree as follows:

// Create a dummy node.
// Create a variable called ‘prev’ and make it point to the dummy node.
// Perform in-order traversal and at each step.
// Set prev -> right = curr
// Set prev -> left = NULL
// Set prev = curr
// This will improve the space complexity to O(H) in worst case as in-order traversal takes O(H) extra space.

void inOrderModified(node *curr, node *&prev)
{
    if (!curr)
        return;

    inOrderModified(curr->left, prev);
    prev->right = curr;
    prev->left = NULL;
    prev = curr;

    inOrderModified(curr->right, prev);
}

node *flatten(node *root)
{
    node *dummy = new node(-1);
    node *prev = dummy;

    inOrderModified(root, prev);

    // for the last pointing prev node
    prev->left = prev->right = NULL;

    node *ret = dummy->right;

    delete dummy;
    return ret;
}

void print(node *root)
{
    while (root)
    {
        cout << root->data << " ";
        root = root->right;
    }
};
int main()
{
    node *root = new node(5);
    root->left = new node(3);
    root->right = new node(7);
    root->left->left = new node(2);
    root->left->right = new node(4);
    root->right->left = new node(6);
    root->right->right = new node(8);

    // Calling required function
    print(flatten(root));

    return 0;
}