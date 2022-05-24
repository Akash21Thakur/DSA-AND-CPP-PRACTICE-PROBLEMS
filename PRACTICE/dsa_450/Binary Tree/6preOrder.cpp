#include <iostream>
#include <stack>

using namespace std;

class node
{
public:
    int data;
    node *left, *right;

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

void preOrderRec(node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preOrderRec(root->left);
    preOrderRec(root->right);
}

void preOrderItr(node *root)
{
    stack<node *> s;
    s.push(root);
    cout << "PRE-ORDER ITERATIVE : ";
    while (!s.empty())
    {
        node *temp = s.top();
        s.pop();

        cout << temp->data << " ";

        if (temp->right)
            s.push(temp->right);
        if (temp->left)
            s.push(temp->left);
    }
    cout << endl;
}

int main()
{
    node *root = createTree();

    cout << "PRE-ORDER RECURSIVE : ";
    preOrderRec(root);
    cout << endl;
    preOrderItr(root);
}