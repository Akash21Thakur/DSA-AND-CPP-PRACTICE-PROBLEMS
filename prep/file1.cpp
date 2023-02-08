#include <iostream>
#include <queue>
#include <vector>
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

node *create()
{
    int d;
    cin >> d;

    if (d == -1)
        return NULL;
    node *root = new node(d);
    root->left = create();
    root->right = create();

    return root;
}

void inorder(node *root)
{
    if (!root)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

vector<int> zigzag(node *root)
{
    if (!root)
        return {};

    vector<int> ans, temp;
    int flag = 0;

    queue<node *> q;

    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node *t = q.front();
        q.pop();

        if (t == NULL)
        {
            if (flag)
            {
                for (int i = temp.size() - 1; i >= 0; i--)
                    ans.push_back(temp[i]);
            }
            else
            {
                for (int i = 0; i < temp.size(); i++)
                    ans.push_back(temp[i]);
            }
            temp.clear();
            if (!q.empty())
                q.push(NULL);
        }
        temp.push_back(t->data);
        if (t->left)
            q.push(t->left);
        if (t->right)
            q.push(t->right);
    }
    cout << "akash\n";
    return ans;
}

int main()
{
    node *root = create();
    inorder(root);
    // vector<int> ans = zigzag(root);

    // for (int i = 0; i < ans.size(); i++)
    //     cout << ans[i] << " ";
    cout << endl;
}