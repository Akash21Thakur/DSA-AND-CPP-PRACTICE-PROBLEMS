
#include<iostream>
#include<vector>
using namespace std;

struct node {
    int data;
    node*left,*right;
};

struct node* getnode(int data)
{
    struct node*newnode=new node;
    newnode->data=data;
    newnode->left=newnode->right=NULL;
    return newnode;
}

void inorder(node*root,vector<int> &v)
{
    if(root==NULL)   return;

    inorder(root->left,v);
    v.push_back(root->data);
    inorder(root->right,v);
}


void replaceValues(node*root,vector<int> a,int *i)
{
    if(root==NULL)  return;

    root->data=a[++*i];
    replaceValues(root->left,a,i);
    replaceValues(root->right,a,i);
}

void BSTtoMINheap(node*root)
{
    vector<int> sorted;
    inorder(root,sorted);
    int i=-1;
    replaceValues(root,sorted,&i);
}

void preTrav(node*root)
{
    if(!root)   return;

    cout<<root->data<<" ";
    preTrav(root->left);
    preTrav(root->right);
}

int main()
{
    struct node*root=getnode(4);
    root->left=getnode(2);
    root->left->left=getnode(1);
    root->left->right=getnode(3);
    root->right=getnode(8);
    root->right->left=getnode(6);
    root->right->right=getnode(10);
      preTrav(root);
      cout<<endl;
    BSTtoMINheap(root);
    preTrav(root);
    cout<<endl;

}