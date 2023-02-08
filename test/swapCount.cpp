#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;

    Node(int d)
    {
        this->data = d;
        left = right = NULL;
    }
};

Node *createTree()
{
    int d;
    cin >> d;

    if (d == -1)
        return NULL;

    Node *root = new Node(d);

    root->left = createTree();
    root->right = createTree();

    return root;
}

void inorder(Node *root, vector<int> &ans)
{
    if (!root)
        return;
    inorder(root->left, ans);

    ans.push_back(root->data);

    inorder(root->right, ans);
}

void countSwap(Node *root, vector<int> &ans)
{
    vector<pair<int, int>> v;

    for (int i = 0; i < ans.size(); i++)
    {
        v.push_back(make_pair(ans[i], i));
    }

    sort(v.begin(), v.end());

    int count = 0;

    for (int i = 0; i < v.size(); i++)
    {
        if (v[i].second == i)
            continue;
        swap(v[i].first, v[v[i].second].first);
        swap(v[i].second, v[v[i].second].second);

        count++;
        i--;
    }

    cout << "Swap Count : " << count << endl;
}

int main()
{
    Node *root = createTree();

    vector<int> ans;
    inorder(root, ans);

    countSwap(root, ans);  
}
