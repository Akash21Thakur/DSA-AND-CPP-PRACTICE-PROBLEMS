#include <iostream>
#include <queue>
#include <utility>
#include <climits>
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

// INORDER TRAVERSAL
void inOrder(node *root)
{
    if (root == NULL)
        return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

// PREORDER TRAVERSAL
void preOrder(node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

// POSTORDER TRAVERSAL
void postOrder(node *root)
{
    if (root == NULL)
        return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

// HEIGHT OF THE TREE
int height(node *root)
{
    if (root == NULL)
        return 0;
    int l = height(root->left);
    int r = height(root->right);
    return max(l, r) + 1;
}

// LEVEL ORDER PRINTING O(n^2)
void kthLvl(node *root, int k)
{
    if (root == NULL)
        return;
    if (k == 1)
    {
        cout << root->data << " ";
        return;
    }
    kthLvl(root->left, k - 1);
    kthLvl(root->right, k - 1);
}

void printAllLevels(node *root)
{
    int n = height(root);
    for (int i = 1; i <= n; i++)
    {
        kthLvl(root, i);
        cout << " ";
    }
}

// BREADTH FIRST SEARCH O(n)
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
            q.pop();
            cout << f->data << " ";
            if (f->left != NULL)
                q.push(f->left);
            if (f->right != NULL)
                q.push(f->right);
        }
    }
}

// COUNT AND SUM OF NODE NODES
int count(node *root)
{
    if (root == NULL)
        return 0;
    // int l=count(root->left);
    // int r=count(root->right);
    // return l+r+1;
    return count(root->left) + count(root->right) + root->data;
}

// DIAMETER OF THE TREE O(n^2)
int diameter(node *root)
{
    if (root == NULL)
        return 0;
    int l = height(root->left);
    int r = height(root->right);
    int opt1 = l + r;
    int opt2 = diameter(root->left);
    int opt3 = diameter(root->right);
    return max(opt1, max(opt2, opt3));
}

// DIAMETER OF THE TREE O(n)
class Pair
{
public:
    int height;
    int diameter;
};

Pair diameter2(node *root)
{
    Pair p;
    if (root == NULL)
    {
        p.height = p.diameter = 0;
        return p;
    }

    Pair left = diameter2(root->left);
    Pair right = diameter2(root->right);

    p.height = max(left.height, right.height) + 1;
    p.diameter = max(left.height + right.height, max(left.diameter, right.diameter));

    return p;
}

// replace node with sum of child nodes , except leaf node
int replaceSum(node *root)
{
    if (root == NULL)
        return 0;
    if (root->left == NULL and root->right == NULL)
        return root->data;
    int temp = root->data;
    root->data = replaceSum(root->left) + replaceSum(root->right);
    return root->data + temp;
}

// CHECK IF TREE IS BALANCED
pair<int, bool> isBalanced(node *root)
{
    pair<int, bool> p;

    if (root == NULL)
    {
        p.first = 0;
        p.second = true;
        return p;
    }

    pair<int, bool> left = isBalanced(root->left);
    pair<int, bool> right = isBalanced(root->right);

    p.first = max(left.first, right.first) + 1;

    if (abs(left.first - right.first) <= 1 and left.second and right.second)
        p.second = true;
    else
        p.second = false;

    return p;
}

// CONSTRUST A BALANCED TREE FROM ARRAY
node *buildFromArray(int *a, int s, int e)
{
    if (s > e)
        return NULL;

    int mid = (s + e) / 2;
    node *root = new node(a[mid]);
    root->left = buildFromArray(a, s, mid - 1);
    root->right = buildFromArray(a, mid + 1, e);
    return root;
}

// CREATE TREE FROM POST AND IN
node *buildTrreFromTrav(int *in, int *pre, int s, int e)
{
    static int i = 0;
    if (s > e)
        return NULL;
    int j = s;
    for (; j <= e; j++)
    {
        if (pre[i] == in[j])
            break;
    }

    i++;
    node *root = new node(in[j]);
    root->left = buildTrreFromTrav(in, pre, s, j - 1);
    root->right = buildTrreFromTrav(in, pre, j + 1, e);
    return root;
}

// BUILD TREE FROM POST AND IN
node *treeFromPostIn(int *in, int *post, int s, int e)
{
    static int i = e;
    if (s > e)
        return NULL;
    int j = s;
    for (; j <= e; j++)
        if (post[i] == in[j])
            break;
    node *root = new node(in[j]);
    i--;
    root->right = treeFromPostIn(in, post, j + 1, e);
    root->left = treeFromPostIn(in, post, s, j - 1);
    return root;
}

// PRINT RIGHT VIEW
// for left_view swap line 267 and 268
void rightView(node *root, int level, int &maxilevel)
{
    if (root == NULL)
        return;
    if (maxilevel < level)
    {
        cout << root->data << " ";
        maxilevel = level;
    }

    rightView(root->right, level + 1, maxilevel);
    rightView(root->left, level + 1, maxilevel);
}

// PRINTS KTH LEVEL NODES DATA
void printKthLevel(node *root, int k)
{
    if (root == NULL or k < 0)
        return;

    if (k == 0)
    {
        cout << root->data << " ";
        return;
    }

    printKthLevel(root->left, k - 1);
    printKthLevel(root->right, k - 1);
}

// NODES AT KTH DISTANCE FROM THE TARGET
int kthDistNode(node *root, node *target, int k)
{
    if (root == NULL)
        return -1;

    if (root == target)
    {
        printKthLevel(root, k);
        return 0;
    }

    int dl = kthDistNode(root->left, target, k);
    if (dl != -1)
    {
        if (dl + 1 == k)
        {
            cout << root->data << " ";
        }
        else
        {
            printKthLevel(root->right, k - dl - 2);
        }
        return dl + 1;
    }

    int dr = kthDistNode(root->right, target, k);
    if (dr != -1)
    {
        if (dr + 1 == k)
        {
            cout << root->data << " ";
        }
        else
        {
            printKthLevel(root->left, k - dr - 2);
        }
        return dr + 1;
    }
    return -1;
}

// LOWEST COMMON ANCESTOR
node *lca(node *root, int a, int b)
{
    if (root == NULL)
        return NULL;

    if (root->data == a or root->data == b)
        return root;

    node *L = lca(root->left, a, b);
    node *R = lca(root->right, a, b);
    if (L and R)
        return root;
    if (L)
        return L;
    return R;
}

// MAXIMUM SUM PATH
int maxSumPath(node *root, int &ans)
{
    if (root == NULL)
        return 0;

    int left = maxSumPath(root->left, ans);
    int right = maxSumPath(root->right, ans);

    int maxi = max(max(root->data, root->data + left + right),
                   max(root->data + left, root->data + right));
    ans = max(ans, maxi);

    return max(root->data, max(root->data + left, root->data + right));
}

int maxiSum(node *root)
{
    int ans = INT_MIN;
    maxSumPath(root, ans);
    return ans;
}

// FIND SHORTEST DISTANCE BETWEEN TWO GIVEN NODES->DATA
int search(node *root, int key, int level)
{
    if (root == NULL)
        return -1;

    if (root->data == key)
        return level;

    int left = search(root->left, key, level + 1);
    if (left != -1)
        return left;

    return search(root->right, key, level + 1);
}

int shortestDist(node *root, int a, int b)
{
    node *lca_node = lca(root, a, b);

    int d1 = search(lca_node, a, 0);
    int d2 = search(lca_node, b, 0);

    return d1 + d2;
}

int main()
{
    node *root = createTree();
    /*

    // cout<<"IN_ORDER : ";
    // inOrder(root);
    // cout<<endl;
    // cout<<"POST_ORDER : ";
    // postOrder(root);
    // cout<<endl;
    cout<<"PRE_ORDER : ";
    preOrder(root);
    cout<<endl;
    // cout<<"Height of the tree : "<<height(root)<<endl;
    // printAllLevels(root);
    // cout<<endl;
    // bfsPrinting(root);
    // cout<<"NUMBER OF NODES : "<<count(root)<<endl;
    //  cout<<"DIAMETER OF THE TREE : "<<diameter(root)<<endl;
    //  cout<<"DIAMETER OF THE TREE-2 : "<<diameter2(root).diameter<<endl;
    // bfsPrinting(root);
    // cout<<endl;
    // replaceSum(root);
    // bfsPrinting(root);
    // if(isBalanced(root).second)
    //   cout<<"TREE IS BALANCED"<<endl;
    // else
    //   cout<<"TREE IS NOT BALANCED"<<endl;
    // int a[]={1,2,3,4,5,6,7,8,9};
    // node*r=buildFromArray(a,0,8);
    // bfsPrinting(r);
    int in[]={5 ,1 ,10 ,9 ,6 ,7 ,8 ,3 ,13 ,14 };
    int pre[]={ 8 ,10, 1, 5, 6, 9 ,7, 3, 14, 13 };
    int post[]={5 ,1 ,9 ,7 ,6 ,10 ,13 ,14 ,3 ,8};
    int n=sizeof(in)/sizeof(int);
    node*r=buildTrreFromTrav(in,pre,0,n-1);
    bfsPrinting(root);
    cout<<endl;
    bfsPrinting(r);
    cout<<endl;
    node*R=treeFromPostIn(in,post,0,n-1);
    bfsPrinting(R);



    // int m=-1,l=0;
    // rightView(root,l,m);
    // printKthLevel(root,3);
    // kthDistNode(root,root->left,2);
    // cout<<lca(root,14,13)->data<<endl;
    // node*root=new node(5);
    // root->*/
    // bfsPrinting(root);
    // cout<<"MAXIMUM SUM : "<<maxiSum(root)<<endl;

    cout << "SHORTEST DISTANCE : " << shortestDist(root, 5, 13) << endl;
    ;
}
