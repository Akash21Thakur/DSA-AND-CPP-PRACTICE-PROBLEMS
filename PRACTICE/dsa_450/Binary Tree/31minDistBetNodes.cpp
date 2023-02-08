// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int i)
    {
        this->data=i;
        left=right=NULL;
    }
};

// Utility function to create a new Tree Node
// Node *newNode(int val)
// {
//     Node *temp = new Node(i);
//     temp->data = val;
//     temp->left = NULL;
//     temp->right = NULL;

//     return temp;
// }

Node* createTree(int i,int n)
{
    if(i>n)
       return NULL;
    Node*root=new Node(i);
    root->left=createTree(i+1,n);
    root->right=createTree(i+1,n);

    return root;   
}

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
    Node *root = newNode(stoi(ip[0]));

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
            currNode->left = newNode(stoi(currVal));

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
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

// } Driver Code Ends
/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution
{
public:
    /* Should return minimum distance between a and b
    in a tree with given root
    */

    Node *lcaFunc(Node *root, int a, int b)
    {
        if (!root)
            return NULL;

        if (root->data == a or root->data == b)
            return root;

        Node *l = lcaFunc(root->left, a, b);
        Node *r = lcaFunc(root->right, a, b);

        if (l and r)
            return root;

        if (l)
            return l;
        return r;
    }

    // calc. dist. from lca node to val.
    // similar to finding level from lca
    int findDist1(Node *root, int val, int dist)
    {
        if (!root)
            return -1;

        if (root->data == val)
            return dist;

        int a = findDist1(root->left, val, dist + 1);
        if (a != -1)
            return a;

        // definitly on the right if not left
        return findDist1(root->right, val, dist + 1);
    }

    int findDist(Node *root, int a, int b)
    {
        // find lca
        // find d1 and d2 of a and b from lca resp.
        // return d1+d2

        Node *lca = lcaFunc(root, a, b);

        int d1 = findDist1(lca, a, 0);
        int d2 = findDist1(lca, b, 0);

        return d1 + d2;
    }
};

// { Driver Code Starts.

/* Driver program to test size function*/

int main()
{

    int t;
    scanf("%d ", &t);
    while (t--)
    {
        string s, ch;
        getline(cin, s);

        Node *root = buildTree(s);
        int n1, n2;
        scanf("%d %d ", &n1, &n2);
        Solution ob;
        cout << ob.findDist(root, n1, n2) << endl;
    }
    return 0;
}
// } Driver Code Ends