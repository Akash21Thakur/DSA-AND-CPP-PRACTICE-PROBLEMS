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
        left = right = NULL;
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

void postOrderRec(node *root)
{
    if (!root)
        return;
    postOrderRec(root->left);
    postOrderRec(root->right);

    cout << root->data << " ";
}

void postOrderItrSTK1(node *root)
{
    cout << "POST-ORDER TRAVERSAL ITERATIVE (USING 2-STACK) : ";
    stack<node *> s1; // stores the curr node element
    stack<node *> s2; // stores answer

    s1.push(root);

    while (!s1.empty())
    {
        node *temp = s1.top();
        s1.pop();

        s2.push(temp);

        if (temp->left)
            s1.push(temp->left);
        if (temp->right)
            s1.push(temp->right);
    }

    while (!s2.empty())
    {
        cout << s2.top()->data << " ";
        s2.pop();
    }
    cout << endl;
}

int main()
{
    node *root = createTree();

    cout << "POST=ORDER RECURSIVE : ";
    postOrderRec(root);
    cout << endl;

    postOrderItrSTK1(root);
}