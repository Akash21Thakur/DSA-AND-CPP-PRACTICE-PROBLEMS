#include <iostream>
#include <queue>
using namespace std;

class node
{
public:
  int data;
  node *left;
  node *right;

  node(int d)
  {
    data = d;
    left = NULL;
    right = NULL;
  }
};

// create tree
node *insertIntoBST(node *root, int d)
{
  if (root == NULL)
    return new node(d);

  if (root->data >= d)
    root->left = insertIntoBST(root->left, d);
  else
    root->right = insertIntoBST(root->right, d);

  return root;
}

// BUILD TREE
node *buildTree()
{
  int d;
  cin >> d;
  node *root = NULL;
  while (d != -1)
  {
    root = insertIntoBST(root, d);
    cin >> d;
  }
  return root;
}

void inOrder(node *root)
{
  if (root == NULL)
    return;
  inOrder(root->left);
  cout << root->data << " ";
  inOrder(root->right);
}
void bfsPrinting(node *root)
{
  if (root == NULL)
    return;
  queue<node *> q;
  q.push(root);
  q.push(NULL);
  while (!q.empty())
  {
    node *f = q.front();

    if (f == NULL)
    {
      cout << endl;
      q.pop();
      if (!q.empty())
        q.push(NULL);
    }
    else
    {
      cout << f->data << " ";
      q.pop();
      if (f->left)
        q.push(f->left);
      if (f->right)
        q.push(f->right);
    }
  }
}

bool search(node *root, int key)
{
  if (root == NULL)
    return false;
  if (root->data == key)
    return true;
  if (root->data >= key)
    return search(root->left, key);
  return search(root->right, key);
}

// DATA DELETION
node *deleteInBST(node *root, int data)
{
  if (root == NULL)
    return NULL;
  if (data < root->data)
  {
    root->left = deleteInBST(root->left, data);
    return root;
  }
  else if (root->data == data)
  {
    // CASE-1 leaf node
    if (root->left == NULL and root->right == NULL)
    {
      delete root;
      return NULL;
    }
    // CASE-2 when 1 child is there
    if (root->left != NULL and root->right == NULL)
    {
      node *temp = root->left;
      delete root;
      return temp;
    }

    if (root->right != NULL and root->left == NULL)
    {
      node *temp = root->right;
      delete root;
      return temp;
    }

    // CASE-3 has 2 child
    node *replace = root->right;
    while (replace->left != NULL)
      replace = replace->left;

    root->data = replace->data;
    root->right = deleteInBST(root->right, data);
    return root;
  }
  else
  {
    root->right = deleteInBST(root->right, data);
    return root;
  }
}

void preOrder(node *root)
{
  if (root == NULL)
    return;
  cout << root->data << " ";
  preOrder(root->left);
  preOrder(root->right);
}
int main()
{
  node *root = buildTree();
  // bfsPrinting(root);
  // inOrder(root);
  // cout<<endl;
  // // if(search(root,14))
  // //   cout<<"DATA FOUND !"<<endl;
  // // else
  // //   cout<<"NOT FOUND !"<<endl;

  // root=deleteInBST(root,5);
  // inOrder(root);
  preOrder(root);
}