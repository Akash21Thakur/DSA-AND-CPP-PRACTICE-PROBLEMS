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

// left view iterative
vector<int> rightViewItr(node *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;

    queue<node *> q;

    q.push(root);
    while (!q.empty())
    {
        int n = q.size();

        for (int i = 0; i < n; i++)
        {
            node *temp = q.front();
            q.pop();
            if (i == 0)
                ans.push_back(temp->data);

            if (temp->right != NULL)
                q.push(temp->right);
            if (temp->left != NULL)
                q.push(temp->left);
        }
    }
    return ans;
}

// recursive way
void helper(node *root, vector<int> &ans, int lvl)
{
    if (root == NULL)
        return;

    if (ans.size() == lvl)
        ans.push_back(root->data);

    helper(root->right, ans, lvl + 1);
    helper(root->left, ans, lvl + 1);
}

vector<int> rightViewRec(node *root)
{
    vector<int> ans;
    helper(root, ans, 0);
    return ans;
}

int main()
{
    node *root = createTree();

    cout << "Iterative : ";
    vector<int> ans = rightViewItr(root);

    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    cout << endl;

    cout << "Recursive : ";
    vector<int> ans1 = rightViewRec(root);

    for (int i = 0; i < ans1.size(); i++)
        cout << ans1[i] << " ";
    cout << endl;
}
