// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// class

struct MinHeapNode
{
    char data;
    int freq;

    MinHeapNode *left, *right;

    MinHeapNode(char data, int freq)
    {
        this->data = data;
        this->freq = freq;

        left = right = NULL;
    }
};

// comparator for minheap
struct Compare
{
    bool operator()(MinHeapNode *a, MinHeapNode *b)
    {
        return a->freq > b->freq;
    }
};

void preOrderAnswer(MinHeapNode *root, vector<string> &ans, string &path)
{
    if (!root)
        return;

    // leaf node found
    if (root->left == NULL and root->right == NULL)
    {
        ans.push_back(path);
        return;
    }

    // move left with '0' in the path
    path += '0';
    preOrderAnswer(root->left, ans, path);
    path.pop_back();

    // move right with '1' in the path
    path += '1';
    preOrderAnswer(root->right, ans, path);
    path.pop_back();
}

// ref: gfg
class Solution
{
public:
    vector<string> huffmanCodes(string S, vector<int> f, int N)
    {
        if (N == 0)
            return {};

        if (N == 1)
            return {"0"};

        priority_queue<MinHeapNode *, vector<MinHeapNode *>, Compare> pq;

        for (int i = 0; i < N; i++)
            pq.push(new MinHeapNode(S[i], f[i]));

        while (pq.size() != 1)
        {
            // min 2 freq in the pq
            MinHeapNode *temp1 = pq.top();
            pq.pop();

            MinHeapNode *temp2 = pq.top();
            pq.pop();

            // can be any symbol as we concerned mainly with the freq. and the direction node is made in the tree
            MinHeapNode *combinedNode = new MinHeapNode('$', temp1->freq + temp2->freq);

            // attach it the child
            combinedNode->left = temp1;
            combinedNode->right = temp2;

            // add the new node to pq
            pq.push(combinedNode);
        }

        // the only remaining node int he pq. is the root node
        MinHeapNode *root = pq.top();
        vector<string> ans;
        string path;

        // answer filling using preorder trav.
        preOrderAnswer(root, ans, path);
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        string S;
        cin >> S;
        int N = S.length();
        vector<int> f(N);
        for (int i = 0; i < N; i++)
        {
            cin >> f[i];
        }
        Solution ob;
        vector<string> ans = ob.huffmanCodes(S, f, N);
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
} // } Driver Code Ends