// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
Node *newNode(int val)
{
    Node *temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
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
/* Tree node structure  used in the program

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

int height(Node *root)
{
    if (root == NULL)
        return 0;

    return (max(height(root->left), height(root->right)) + 1);
}

class Solution
{
public:
    // Function to return the diameter of a Binary Tree.
    int diameter(Node *root)
    {
        /*meth-1 O(n^2)
        // diameter is max, edges between 2 nodes in a tree
        // dia=max(left_height+right_height,left_diameter,right_diameter)

        if(root==NULL)
          return 0;

        // int left_height=height(root->left);
        // int right_height=height(root->right);
        int diameter_with_root=height(root->left) + height(root->right) + 1;

        int left_diameter=diameter(root->left);
        int right_diameter=diameter(root->right);

        return max(diameter_with_root,max(left_diameter,right_diameter));
        */

        // meth-2  striver...O(n)
        // update the max_diameter(passed by reference)...calc. diameter and height in 1 go

        int maxi = 0;
        calcFastDiameter(root, maxi);
        return maxi;
    }

    int calcFastDiameter(Node *root, int &maxi)
    {
        if (root == NULL)
            return 0;

        int lh = calcFastDiameter(root->left, maxi);
        int rh = calcFastDiameter(root->right, maxi);

        maxi = max(maxi, lh + rh + 1); // diameter is sum of left_h,right_h and 1(curr_node)

        return 1 + max(lh, rh); // returns the height
    }
};

// { Driver Code Starts.

/* Driver program to test size function*/
int main()
{
    int t;
    scanf("%d\n", &t);
    while (t--)
    {
        string s;
        getline(cin, s);
        Node *root = buildTree(s);
        Solution ob;
        cout << ob.diameter(root) << endl;
    }
    return 0;
}
// } Driver Code Ends

/*
pair<int,int> calcD(Node*root)
    {
        pair<int,int> p;
        if(root==NULL)
        {
            p.first=0;
            p.second=0;
            return p;
        }

        pair<int,int> l=calcD(root->left);
        pair<int,int> r=calcD(root->right);

        p.first=max(l.first,r.first)+1;
        p.second=max(l.first+r.first,max(l.second,r.second));

        return p;
    }


class Solution {
  public:
    // Function to return the diameter of a Binary Tree.
    // pair<int> calcD(Node*root)
    // {
    //     pair<int> p;
    //     if(root==NULL)
    //     {
    //         p.first=0;
    //         p.second=0;
    //         return p;
    //     }

    //     pair<int> l=calcD(root->left);
    //     pair<int> r=calcD(root->right);

    //     p.first=max(l.first,r.first)+1;
    //     p.second=max(l.first+r.first,max(l.second,r.second));

    //     return p;
    // }

    int diameter(Node* root) {
        pair<int,int> ans=calcD(root);
        return ans.second+1;
    }
};
*/