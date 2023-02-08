#include <iostream>
#include <queue>
#include <stack>
#include <map>
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

void inorder(node *head)
{
    if (head == NULL)
        return;
    inorder(head->left);
    cout << head->data << " ";
    inorder(head->right);
}

void preorder(node *head)
{
    if (head == NULL)
        return;
    cout << head->data << " ";
    preorder(head->left);
    preorder(head->right);
}

void postorder(node *head)
{
    if (head == NULL)
        return;
    postorder(head->left);
    postorder(head->right);
    cout << head->data << " ";
}

void level1(node *head)
{
    if (!head)
        return;
    queue<node *> q;
    q.push(head);
    q.push(NULL);

    while (!q.empty())
    {
        node *curr = q.front();
        // q.pop();
        if (curr == NULL)
        {
            q.pop();
            // cout << endl;
            if (!q.empty())

                q.push(NULL);
        }
        else
        {
            q.pop();
            cout << curr->data << " ";
            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }
    }
}

void reverselevel(node *root)
{
    if (!root)
        return;
    queue<node *> q;
    q.push(root);
    q.push(NULL);
    stack<int> st;
    while (!q.empty())
    {
        node *curr = q.front();
        q.pop();

        if (curr == NULL)
        {
            if (!q.empty())
                q.push(NULL);
        }

        else
        {
            st.push(curr->data);
            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }
    }

    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
}

int height(node *root)
{
    if (root == NULL)
        return 0;
    if (root->left == NULL and root->right == NULL)
        return 1;

    return 1 + max(height(root->left), height(root->right));
}

int dia1(node *root)
{
    if (root == NULL)
        return 0;

    return max((height(root->left) + height(root->right) + 1), max(dia1(root->left), dia1(root->right)));
}

int fastDia(node *root, int &maxi)
{
    if (!root)
        return 0;

    int lh = fastDia(root->left, maxi);
    int rh = fastDia(root->right, maxi);

    maxi = max(maxi, lh + rh + 1);

    return max(lh, rh) + 1;
}

void inorderItr(node *root)
{
    if (!root)
        return;
    // vector<int> ans;
    stack<node *> st;
    node *curr = root;

    while (true)
    {

        while (curr)
        {
            st.push(curr);
            curr = curr->left;
        }

        if (!st.empty())
        {
            node *temp = st.top();
            st.pop();
            cout << temp->data << " ";
            curr = temp->right;
        }
        else
            break;
    }
}

void preorderItr(node *root)
{
    if (!root)
        return;

    stack<node *> st;
    st.push(root);
    while (!st.empty())
    {
        node *curr = st.top();
        cout << curr->data << " ";
        st.pop();

        if (curr->right)
            st.push(curr->right);
        if (curr->left)
            st.push(curr->left);
    }
}

void postItr1(node *root)
{
    if (!root)
        return;
    stack<node *> st1, st2;
    node *temp = root;
    st1.push(root);

    while (!st1.empty())
    {
        temp = st1.top();
        st2.push(st1.top());
        st1.pop();
        if (temp->left)
            st1.push(temp->left);
        if (temp->right)
            st1.push(temp->right);
    }

    while (!st2.empty())
    {
        cout << st2.top()->data << " ";
        st2.pop();
    }
}

void postItr2(node *root)
{
    if (!root)
        return;

    stack<node *> st;
    node *curr = root;
    while (!st.empty() or curr != NULL)
    {
        if (curr)
        {
            st.push(curr);
            curr = curr->left;
        }
        else
        {
            node *temp = st.top()->right;
            if (temp == NULL)
            {
                temp = st.top();
                st.pop();

                cout << temp->data << " ";

                while (!st.empty() and temp == st.top()->right)
                {
                    temp = st.top();
                    st.pop();
                    cout << temp->data << " ";
                }
            }
            else
                curr = temp;
        }
    }
}

void leftview(node *root, vector<int> &ans, int level)
{
    if (!root)
        return;
    if (ans.size() < level)
        ans.push_back(root->data);
    leftview(root->left, ans, level + 1);
    leftview(root->right, ans, level + 1);
}

void topView(node *root)
{
    if (!root)
        return;

    queue<pair<node *, int>> q;
    map<int, int> mp;

    q.push({root, 0});

    while (!q.empty())
    {
        auto temp = q.front();
        q.pop();

        node *curr = temp.first;
        int level = temp.second;

        if (mp.find(level) == mp.end())
            mp[level] = curr->data;

        if (curr->left)
            q.push({curr->left, level - 1});
        if (curr->right)
            q.push({curr->right, level + 1});
    }

    for (auto x : mp)
        cout << x.second << " ";
}

void bottomview(node *root)
{
    if (!root)
        return;

    queue<pair<node *, int>> q;
    map<int, int> mp;

    q.push({root, 0});

    while (!q.empty())
    {
        auto temp = q.front();
        q.pop();

        node *curr = temp.first;
        int level = temp.second;

        // if (mp.find(level) == mp.end())
        mp[level] = curr->data;

        if (curr->left)
            q.push({curr->left, level - 1});
        if (curr->right)
            q.push({curr->right, level + 1});
    }

    for (auto x : mp)
        cout << x.second << " ";
}

int isBal(node *root)
{
    if (!root)
        return true;

    int lh = isBal(root->left);
    int rh = isBal(root->right);

    if (lh == -1 or rh == -1 or abs(lh - rh) > 1)
        return -1;

    return max(lh, rh) + 1;
}

void diag(node *root)
{
    if (!root)
        return;
    node *temp = root;
    queue<node *> q;
    q.push(root);

    while (!q.empty())
    {
        node *t = q.front();
        q.pop();

        while (t)
        {
            if (t->left)
                q.push(t->left);
            cout << t->data << " ";
            t = t->right;
        }
        // cout << endl;
    }
}

int main()
{
    node *head = createTree();
    // inorder(head);
    // cout << endl;
    // preorder(head);
    // cout << endl;
    // preorderItr(head);
    // cout << "itr-inorder : ";
    // inorderItr(head);
    // postorder(head);
    // cout << endl;
    // postItr1(head);
    // cout << endl;
    // postItr2(head);
    // level1(head);
    // cout << endl;
    // reverselevel(head);
    // cout << "Height ; " << height(head);

    // cout << "Diameter : " << dia1(head) << endl;
    // int maxi = 0;
    // fastDia(head, maxi);
    // cout << "Fast Diameter : " << maxi << endl;

    // vector<int> ans;
    // leftview(head, ans, 1);
    // for (auto x : ans)
    //     cout << x << " ";

    // topView(head);
    // bottomview(head);

    // int val = isBal(head);
    // if (val == -1)
    //     cout << "Not Balanced " << endl;
    // else
    //     cout << "Balanced  " << endl;
    diag(head);
}