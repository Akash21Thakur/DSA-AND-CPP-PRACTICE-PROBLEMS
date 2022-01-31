  #include<iostream>
#include<queue>
#include<climits>
#include<vector>

using namespace std;

class node{
    public:
    int data;
    node*left;
    node*right;

    node(int d)
    {
        data=d;
        left=NULL;
        right=NULL;
    }
};

node* createTree(node*root,int d)
{
   if(root==NULL)
      return new node(d);

    if(d<=root->data)
       root->left= createTree(root->left,d);
    else
       root->right= createTree(root->right,d);     
    return root;
}

node* buildTree()
{
    int d;
    cin>>d;
    node*root=NULL;
    while(d!=-1){
        root=createTree(root,d);
        cin>>d;
    }
    return root;
}

void bfsPrinting(node*root)
{
    if(root==NULL)
       return;
    queue<node*> q;
    q.push(root);
    q.push(NULL); 

    while(!q.empty())
    {
        node*temp=q.front();
        if(temp==NULL)
        {
            // cout<<"N ";
            cout<<endl;
            q.pop();
            if(!q.empty())
               q.push(NULL);
        }
        else{
            q.pop();
            cout<<temp->data<<" ";
            if(temp->left)
              q.push(temp->left);
            
            if(temp->right)
              q.push(temp->right);
            // if(!temp->left and !temp->right)
            //   cout<<"N ";    
        }
    }  
}

//CHECK IF BST
//TOP_BOTTOM APPROACH
bool isBST(node*root,int mini=INT_MIN,int maxi=INT_MAX)
{
    if(root==NULL)
       return true;
    
    if(root->data>=mini and root->data<maxi and isBST(root->left,mini,root->data) and isBST(root->right,root->data,maxi))
       return true;

    return false;   
}

//inorder traversal to check if bst
void isBST1(node*root,node*&prev,int &f)
{
   if(root==NULL)
      return;
   isBST1(root->left,prev,f);
   if(prev!=NULL and root->data<=prev->data)
   {
       f=0;
       return;
   }   
   prev=root;
   isBST1(root->right,prev,f);
}

//BST TO LINKED LIST
class LinkedList{
    public:
    node*head;
    node*tail;
};

LinkedList createList(node*root)
{
    LinkedList l;

    //when the tree is empty
     if(root==NULL)
       {
           l.head=l.tail=NULL;
           return l;
       }

    //when leaf node   
     if(root->left==NULL and root->right==NULL)
     {
         l.tail=l.head=root;
         return l;
     }  

    //when left is not null but right is
    if(root->left and root->right==NULL)
    {
        LinkedList temp=createList(root->left);
        temp.tail->right=root;
        l.head=temp.head;
        l.tail=root;
        return l;
    } 
    
    //when right is not null but left is
    if(root->left==NULL and root->right)
    {
        LinkedList temp=createList(root->right);
        root->right=temp.head;
        l.head=root;
        l.tail=temp.tail;
        return l;
    }

    //when node has both the child

    LinkedList tempLeft=createList(root->left);
    LinkedList tempright=createList(root->right);

    tempLeft.tail->right=root;
    root->right=tempright.head;

    l.head=tempLeft.head;
    l.tail=tempright.tail;

    return l;
}

//CONSTRUST BST FROM PREORDER TRAVERSAL
node* constructBST(int *preorder,int *index,int key,int min,int max,int n)
{
    if(*index>=n)
      return NULL;

    node*root=NULL;
    if(key>min and key<max)
     {
         root=new node(key);
         *index+=1;
         if(*index<n)
            root->left=constructBST(preorder,index,preorder[*index],min,key,n);
         if(*index<n)
            root->right=constructBST(preorder,index,preorder[*index],key,max,n);              
     }  
      return root;
}

//CONSTRUST BST FROM POSTORDER TRAVERSAL
node* constructBST1(int *postorder,int *index,int key,int min,int max)
{
    if(*index<0)
      return NULL;

    node*root=NULL;
    if(key>min and key<max)
     {
         root=new node(key);
         *index-=1;
         if(*index>=0)
            root->right=constructBST1(postorder,index,postorder[*index],key,max);
         if(*index>=0)
            root->left=constructBST1(postorder,index,postorder[*index],min,key);
                       
     }  
      return root;
}

void inorder(node*root)
{
    if(root==NULL)
      return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);  
}

//search element in BST
node* searchKey(node*root,int key)
{
  if(root==NULL or root->data==key)
     return root;
  if(key<root->data)
     return searchKey(root->left,key);
  return searchKey(root->right,key);      
}

//minimum element in bst
int minElement(node*root)
{
    //recursive way
    if(root==NULL)
     return -1;
    if(root->left)   return minElement(root->left);
    else return root->data; 

    //iterative way
    // if(root==NULL) return -1;
    // while(root->left)
    //    root=root->left;s
    // return root->data;   
}

//maximum element
int maxElement(node*root)
{
    if(root==NULL)  return -1;

    if(root->right)  return maxElement(root->right);
    else   return root->data;
}

void inorder1(vector<int> &a,node *root)
{
    if(!root)  return;
    
    inorder1(a,root->left);
    a.push_back(root->data);
    inorder1(a,root->right);
}

void mergeTwoArray(vector<int> ar1,vector<int> ar2,int n1,int n2,vector<int> &ar3)
{
    int i=0,j=0;
    while(i<n1 and j<n2)
    {
        if(ar1[i]<ar2[j])
            ar3.push_back(ar1[i++]);
        else
            ar3.push_back(ar2[j++]);
    }
    
    while(i<n1)
        ar3.push_back(ar1[i++]);
    while(j<n2)
        ar3.push_back(ar2[j++]);
    for(int i=0;i<n1+n2;i++)
       cout<<ar3[i]<<" ";
    cout<<endl;       
}
node* buildBST1(vector<int> v,int start,int end)
{
    if(start>end)   return NULL;
    int mid=(start+end)/2;
    node* root=new node(v[mid]);
    root->left=buildBST1(v,start,mid-1);
    root->right=buildBST1(v,mid+1,end);
        return root;
}
node* mergeTwoBST(node* root1,node* root2)
{
    vector<int> ar1,ar2;
       inorder1(ar1,root1);
       inorder1(ar2,root2);
       int n1=ar1.size(),n2=ar2.size();
       vector<int> ar3;
       ar3.reserve(n1+n2);
       mergeTwoArray(ar1,ar2,n1,n2,ar3);
       return buildBST1(ar3,0,n1+n2-1);
}

int main()
{
    cout<<"bst-1"<<endl;
    node*root1=buildTree();
    cout<<"bst-2"<<endl;
    node*root2=buildTree();

    node*root=mergeTwoBST(root1,root2);
    bfsPrinting(root);

    // bfsPrinting(root);
    // node*temp=new node(10);
    // temp->left=new node(12);
    // temp->right=new node(15);
    // // bfsPrinting(temp);
    // // if(isBST(temp))
    // //    cout<<"YES , ITS A BST !"<<endl;
    // // else 
    // //    cout<<"NOT A BST !"<<endl;   
    // node*prev=NULL;
    // int f=1;
    // isBST1(root,prev,f);
    // if(f)   
    //   cout<<"bst"<<endl;
    // else
    //   cout<<"not a bst"<<endl;
    // cout<<endl<<endl<<endl;
    // LinkedList ans=createList(root);
    // node* temp=ans.head;
    // while(temp!=NULL)
    // {
    //     cout<<temp->data<<" ";
    //     temp=temp->right;
    // }  
    // int pre[]={50,40,10,45,60,55,75,70,80};
    // int idx=0;
    // node*root=constructBST(pre,&idx,pre[0],INT_MIN,INT_MAX,9);
    // // bfsPrinting(root);
    // int post[]={10,45,40,55,70,80,75,60,50};
    // int idx=8;
    // node*root=constructBST1(post,&idx,post[8],INT_MIN,INT_MAX);
    // inorder(root);
    // cout<<endl;
    // bfsPrinting(root);
    // cout<<"MINIMUM : "<<minElement(root)<<endl;
    // cout<<"MAXIMUM : "<<maxElement(root)<<endl;
}