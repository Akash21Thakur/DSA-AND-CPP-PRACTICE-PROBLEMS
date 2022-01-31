#include <iostream>
using namespace std;

class node
{
public:
    node *left;  // for 0
    node *right; // for 1
};

class trie
{
    node *root;

public:
    trie()
    {
        root = new node();
    }

    void insert(int d)   
    {
        node *temp = root;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (d >> i) & 1;
            //if the bit is found the moves to it, else create a child node with the value "bit"
            //following the tries property
            if (bit == 0)
            {
                if (temp->left == NULL)
                    temp->left = new node();
                temp = temp->left;
            }
            else
            {

                if (temp->right == NULL)
                    temp->right = new node();
                temp = temp->right;
            }
        }
    }

    int find_max_xor_helper(int num)   //to find the maximum xor with the inserted element with num
    {
        int cur_ans = 0;
        node *temp = root;

        for (int j = 31; j >= 0; j--)  //considering 32 bit number
        {
            int bit = (num >> j) & 1;
            if (bit == 0)   
            {
                if (temp->right)     //search for the complementary bit , if present
                {
                    temp = temp->right;
                    cur_ans += (1 << j);
                }
                else
                    temp = temp->left;
            }
            else
            {
                if (temp->left)
                {
                    temp = temp->left;
                    cur_ans += (1 << j);
                }
                else
                    temp = temp->right;
            }
        }
        return cur_ans;
    }

    int max_xor(int *a, int n)
    {
        int max_ans = 0;

        for (int i = 0; i < n; i++)
        {
            insert(a[i]);
            int temp = find_max_xor_helper(a[i]);
            cout << temp << " ";
            max_ans = max(max_ans, temp);
        }
        cout<<endl;
        return max_ans;
    }
};

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    trie t;

    cout << endl
         << t.max_xor(a, n);
    // maximum subarray xor
    // int cxor[n];
    // cxor[0]=0;
    // for(int i=1;i<n;i++)
    //   cxor[i]=cxor[i-1]^a[i];

    // // cout<<endl<<endl;;
    // cout<<t.max_xor(cxor,n)<<endl;       
}