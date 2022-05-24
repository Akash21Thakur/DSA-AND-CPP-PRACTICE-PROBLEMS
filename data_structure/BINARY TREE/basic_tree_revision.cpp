#include <iostream>
#include <queue>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        this->data = d;
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

// pre order
void preOrder(node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

// post order
void postOrder(node *root)
{
    if (root == NULL)
        return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

// inorder
void inOrder(node *root)
{
    if (root == NULL)
        return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

// height of tree
int height(node *root)
{
    if (root == NULL)
        return 1;
    int l = height(root->left);
    int r = height(root->right);

    return max(l, r) + 1;
}

// print kth level
void printKthLevel(node *root, int k)
{
    if (root == NULL)
        return;
    if (k == 1)
    {
        cout << root->data << " ";
        return;
    }
    printKthLevel(root->left, k - 1);
    printKthLevel(root->right, k - 1);
}

// level order printing
void levelOrderPrinting(node *root)
{
    if (root == NULL)
        return;
    int n = height(root);
    for (int i = 1; i <= n; i++)
    {
        printKthLevel(root, i);
        cout << endl;
    }
}

// BFS-PRINTING ...LEVEL ORDER O(N)
// USING QUEUE

void bfsPrinting(node *root)
{
    if (!root)
        return;
    queue<node *> q;

    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        node *f = q.front();
        if (f == NULL)
        {
            q.pop();
            cout << endl;

            if (!q.empty())
                q.push(NULL);
        }
        else
        {
            q.pop();
            cout << f->data << " ";
            if (f->left)
                q.push(f->left);
            if (f->right)
                q.push(f->right);
        }
    }
}

int main()
{
    node *root = createTree();

    cout << "PRE-ORDER : ";
    preOrder(root);

    cout << "\nPOST-ORDER : ";
    postOrder(root);

    cout << "\nIN-ORDER : ";
    inOrder(root);

    cout << "\nLEVEL-ORDER : \n";
    // levelOrderPrinting(root);

    bfsPrinting(root);
}