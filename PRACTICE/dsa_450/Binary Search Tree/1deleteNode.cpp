#include <iostream>
using namespace std;

//  * Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (!root)
            return NULL;

        // inOrder traversal approach

        // LEFT
        if (key < root->val)
        {
            root->left = deleteNode(root->left, key);
            return root;
        }

        // ROOT
        else if (key == root->val)
        {
            // when a leaf node
            if (!root->left and !root->right)
            {
                delete root;
                return NULL;
            }

            // when only left child
            if (root->left and !root->right)
            {
                TreeNode *temp = root->left;
                delete root;
                return temp;
            }

            // when only right child
            if (root->right and !root->left)
            {
                TreeNode *temp = root->right;
                delete root;
                return temp;
            }

            // when both the child are not null

            // the curr. node will be replaced by the right->child's leftmost node
            TreeNode *replace = root->right;
            while (replace->left)
                replace = replace->left;

            // change root val. with replace_node val
            root->val = replace->val;
            // delete replace_node  to avoid duplicacy
            root->right = deleteNode(root->right, replace->val);
            return root;
        }

        // RIGHT
        else
        {
            root->right = deleteNode(root->right, key);
            return root;
        }
    }
};