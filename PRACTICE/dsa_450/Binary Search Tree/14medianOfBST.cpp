// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

float findMedian(struct Node *node);

// Function to Build Tree
Node *buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size())
    {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N")
        {

            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N")
        {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

int main()
{

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    // cout << t << endl;
    while (t--)
    {
        string s;
        getline(cin, s);
        Node *root = buildTree(s);

        // getline(cin, s);

        cout << findMedian(root) << endl;

        // cout<<"~"<<endl;
    }
    return 0;
} // } Driver Code Ends

/*
Structure of the binary Search Tree is as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
// your task is to complete the Function
// Function should return median of the BST
void countNode(Node *root, int &c)
{
    if (!root)
        return;
    countNode(root->left, c);
    c++;
    countNode(root->right, c);
}

void findNode(Node *root, Node *&cur, Node *&prev, int &c, int k)
{
    if (!root)
        return;
    findNode(root->left, cur, prev, c, k);
    if (c == k) // kth node
    {
        c++; // won't go to the elese case while backtracking
        cur = root;

        return;
    }
    else if (c < k) // rest other node
    {
        prev = root;
        c++;
    }

    findNode(root->right, cur, prev, c, k);
}

// one way can be store inorder and return the median..but extra space will be used
float findMedian(struct Node *root)
{
    int count = 0;
    countNode(root, count);
    Node *cur = NULL;
    Node *prev = NULL;

    int c = 1;
    int k = (count / 2) + 1;

    findNode(root, cur, prev, c, k);

    // if odd nodes
    if (count & 1)
    {
        float ans = (cur->data) * 1.0;
        return ans;
    }
    // when even node

    else
    {
        float ans = ((prev->data + cur->data) * 1.0) / (2 * 1.0);
        return ans;
    }
}
