#include <iostream>
#include <stack>
#include <vector>
#include <deque>
#include <iterator>
#include <algorithm>
using namespace std;

vector<int> leftMin(vector<int> &vect)
{
    int n = vect.size();
    vector<int> ans;
    ans.push_back(-1);
    stack<int> st;
    st.push(0);

    for (int i = 1; i < n; i++)
    {
        while (!st.empty() and vect[st.top()] >= vect[i])
        {
            st.pop();
        }
        if (st.empty())
            ans.push_back(-1);
        else
            ans.push_back(vect[st.top()]);

        st.push(i);
    }

    // for(int i=0;i<n;i++)
    //    cout<<ans[i]<<" ";

    return ans;
}

vector<int> minRight(vector<int> &v)
{
    int n = v.size();
    vector<int> ans;
    stack<int> st;
    st.push(n - 1);
    ans.push_back(-1);

    for (int j = n - 2; j >= 0; j--)
    {
        while (!st.empty() and v[st.top()] >= v[j])
        {
            st.pop();
        }
        if (st.empty())
            ans.push_back(-1);
        else
            ans.push_back(v[st.top()]);

        st.push(j);
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

int maxHistogram(vector<int> &v)
{
    int n = v.size();
    vector<int> left(n), right(n);

    stack<int> st;

    for (int i = 0; i < n; i++)
    {
        if (st.empty())
        {
            left[i] = 0;
            st.push(i);
        }
        else
        {
            while (!st.empty() and v[st.top() >= v[i]])
                st.pop();

            left[i] = st.empty() ? 0 : st.top();
            st.push(i);
        }
    }

    // empty the stack
    while (!st.empty())
        st.pop();

    for (int i = n - 1; i >= 0; i--)
    {
        if (st.empty())
        {
            right[i] = 0;
            st.push(i);
        }
        else{
             while (!st.empty() and v[st.top()] >= v[i])
            st.pop();
        right[i]=st.empty() ? 0 : st.top();
        st.push(i);

        }
           
    }

    int max_area=0;
    for(int i=0;i<n;i++)
      max_area=max(max_area,v[i]*(right[i]-left[i]+1));

    return max_area;  
}

// int maximalArea(vector<vector<int>> &mat)
// {
//     vector<int> curRow=mat[0];
//     int maxAns=maxHistogram(curRow);

//     for(int i=1;i<mat.size();i++)
//     {
//         for(int j=0;i<mat[0].size();j++)
//         {
//             if(mat[i][j]==1)
//               curRow[j]+=1;
//             else
//               curRow[j]=0;  
//         }
//         int curans=maxHistogram(curRow);
//         maxAns=max(maxAns,curans);
//     }
// return maxAns;


// }


int main()
{
    // int n,m;
    // cout<<"Row-Column : ";
    // cin>>n>>m;
    // vector<vector<int>> v(n,vector<int> (m));

    // for(int i=0;i<n;i++)
    //    for(int j=0;j<m;j++)
    //       cin>>v[i][j];
int n;
    cout << "Enter size : ";
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout<<maxHistogram(a)<<endl;      

    
    // vector<int> leftMini=leftMin(a);

    // cout<<"Left Minimum Array : ";
    // for(int i=0;i<n;i++)
    //   cout<<leftMini[i]<<" ";

    // cout<<endl;
    // vector<int> rightMini = minRight(a);

    // cout << "Right Minimum Array : ";
    // for (int i = 0; i < n; i++)
    //     cout << rightMini[i] << " ";
}