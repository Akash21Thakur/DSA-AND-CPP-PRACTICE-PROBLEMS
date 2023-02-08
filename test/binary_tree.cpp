#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>
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

void inorder(node *root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void inorderItr(node *root)
{
    if (!root)
        return;
    stack<node *> st;
    node *cur = root;

    cout << "\nInorder : ";
    while (true)
    {
        while (cur)
        {
            st.push(cur);
            cur = cur->left;
        }

        if (!st.empty())
        {
            node *temp = st.top();
            st.pop();

            cout << temp->data << " ";
            // if(cur->right)
            cur = temp->right;
        }
        else
            break;
    }
}

void preorder(node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";

    preorder(root->left);
    preorder(root->right);
}

void preItr(node *root)
{
    if (!root)
        return;
    stack<node *> st;

    st.push(root);
    cout << "\nPreorder recurr : ";
    while (!st.empty())
    {
        node *temp = st.top();
        st.pop();

        cout << temp->data << " ";
        if (temp->right)
            st.push(temp->right);
        if (temp->left)
            st.push(temp->left);
    }

    cout << endl;
}

void postorder(node *root)
{
    if (!root)
        return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

void postItr(node *root)
{
    if (!root)
        return;

    stack<node *> st1; // for trav.
    stack<node *> st2; // store answer

    st1.push(root);

    while (!st1.empty())
    {
        node *temp = st1.top();
        st1.pop();

        st2.push(temp);

        if (temp->left)
            st1.push(temp->left);
        if (temp->right)
            st1.push(temp->right);
    }

    cout << "\nPostorder : ";
    while (!st2.empty())
    {
        cout << st2.top()->data << " ";
        st2.pop();
    }
}

// level order traversal
// bfs
void levelOrderTrav(node *root)
{
    if (!root)
        return;

    queue<node *> q;
    q.push(root);
    q.push(NULL);
    cout << "\nLevel Order Trav. " << endl;
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
                q.push(NULL);
        }
        else
        {
            cout << temp->data << " ";

            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
    }
}

void reverseLevel(node *root)
{
    if (!root)
        return;
    queue<node *> q;
    q.push(root);
    q.push(NULL);
    bool flag = 0;
    vector<int> ans;
    cout << "REVERSE LEVEL ORDER TRAV : " << endl;
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        if (temp == NULL)
        {
            if (flag)
            {
                for (int i = 0; i < ans.size(); i++)
                    cout << ans[i] << " ";
            }
            else
            {
                for (int i = ans.size() - 1; i >= 0; i--)
                    cout << ans[i] << " ";
            }
            flag = !flag;
            cout << endl;

            if (!q.empty())
                q.push(NULL);
            ans.clear();
        }
        else
        {
            ans.push_back(temp->data);
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
    }
}

int height(node *root)
{
    if (!root)
        return 0;

    int lh = height(root->left);
    int rh = height(root->right);

    return max(lh, rh) + 1;
}

int diameter(node *root)
{
    if (!root)
        return 0;
    int lh = height(root->left);
    int rh = height(root->right);
    return max(lh + rh, max(diameter(root->left), diameter(root->right)));
}

int fastDiameter(node *root, int &maxi)
{
    if (!root)
        return 0;

    int lh = fastDiameter(root->left, maxi);
    int rh = fastDiameter(root->right, maxi);

    maxi = max(lh + rh + 1, maxi);

    return max(lh, rh);
}

void leftView(node *root, vector<int> &ans, int level)
{
    if (!root)
        return;

    if (ans.size() < level)
        ans.push_back(root->data);
    leftView(root->left, ans, level + 1);
    leftView(root->right, ans, level + 1);
}

void rightView(node *root, vector<int> &ans, int level)
{
    if (!root)
        return;

    if (ans.size() < level)
        ans.push_back(root->data);

    rightView(root->right, ans, level + 1);
    rightView(root->left, ans, level + 1);
}

void topView(node *root, map<int, int> &mp, int line)
{
    if (!root)
        return;
    if (mp.find(line) == mp.end())
        mp[line] = root->data;

    topView(root->left, mp, line - 1);
    topView(root->right, mp, line + 1);
}

void rightView(node *root, map<int, int> &mp, int line)
{
    if (!root)
        return;

    mp[line] = root->data;
    rightView(root->left, mp, line - 1);
    rightView(root->right, mp, line + 1);
}

void zigzag(node *root)
{
    if (!root)
        return;
    vector<vector<int>> ans;
    bool flag = 1;
    cout << "ZIG-ZAG TRAV. " << endl;
    queue<node *> q;
    q.push(root);
    q.push(NULL);
    vector<int> arr;
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        if (temp == NULL)
        {
            if (flag)
            {
                reverse(arr.begin(), arr.end());
            }
            ans.push_back(arr);
            arr.clear();
            flag = !flag;
            if (!q.empty())
                q.push(NULL);
        }
        else
        {
            arr.push_back(temp->data);
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
    }

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }
}

bool isBal(node *root)
{
    if (!root)
        return true;
    int lh = height(root->left);
    int rh = height(root->right);
    if (abs(lh - rh) <= 1 and isBal(root->left) and isBal(root->right))
        return true;
    return false;
}

// meth-2
int isBal2(node *root)
{
    if (!root)
        return 0;

    int lh = isBal2(root->left);
    int rh = isBal2(root->right);

    if (lh == -1 or rh == -1 or abs(lh - rh) > 1)
        return -1;

    return max(lh, rh) + 1;
}

int main()
{
    // node *root = createTree();
    // cout << "INORDER REC : ";
    // inorder(root);
    // inorderItr(root);
    // cout << endl;
    // // cout << "PREORDER REC : ";
    // preorder(root);
    // // cout << "PRE ITR : ";
    // preItr(root);
    // // cout << "POST REC : ";
    // cout << endl;
    // postorder(root);
    // postItr(root);
    // cout << endl;

    // levelOrderTrav(root);
    // cout << endl;
    // reverseLevel(root);

    // cout << "height of tree : " << height(root) << endl;
    // cout << "Diameter of tree : " << diameter(root) << endl;
    // int maxi = 0;
    // cout << "Fast Diameter : " << fastDiameter(root, maxi) << endl;

    // vector<int> ans;
    // int level = 1;
    // leftView(root, ans, level);
    // cout << "LEFT VIEW : " << endl;
    // for (int i = 0; i < ans.size(); i++)
    //     cout << ans[i] << " ";
    // cout << endl
    //      << "RIGHT VIEW : " << endl;
    // ans.clear();
    // rightView(root, ans, 1);
    // for (int i = 0; i < ans.size(); i++)
    //     cout << ans[i] << " ";
    // cout << endl;

    // top view
    // map<int, int> mp;
    // int line = 0;

    // topView(root, mp, line);
    // cout << "TOP VIEW : " << endl;
    // for (auto x : mp)
    //     cout << x.second << " ";

    // bottom view
    // mp.clear();
    // rightView(root, mp, line);
    // cout << "\nBOTTOM VIEW : " << endl;
    // for (auto x : mp)
    //     cout << x.second << " ";

    // zigzag(root);

    // if (isBal(root))
    //     cout << "Balanced";
    // else
    //     cout << "Not Balanced";

    // int var = isBal2(root);
    // if (var != -1)
    //     cout << "Balanced";
    // else
    //     cout << "Not Balanced";
}