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

void inOredrRec(node *root)
{
    if (root == NULL)
        return;
    inOredrRec(root->left);
    cout << root->data << " ";
    inOredrRec(root->right);
}

void inOrderItr(node *root)
{
    stack<node *> s;

    node *cur = root;

    cout << "IN-ORDER ITERATIVE : ";

    while (true)
    {
        // takes left most node of the current node
        // left
        while (cur != NULL)
        {
            s.push(cur);
            cur = cur->left;
        }

        if (!s.empty())
        {
            node *temp = s.top();
            s.pop();
            // root
            cout << temp->data << " ";
            // right
            cur = temp->right;
        }
        else
            break;
    }
    cout << endl;
}




int main()
{
    node *root = createTree();

    cout << "IN-ORDER RECURSIVE : ";
    inOredrRec(root);
    cout << endl;
    
    inOrderItr(root);
}