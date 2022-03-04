#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

//just transpose the matrix
//reverse all the rows
void rotateImage(vector<vector<int>> &v)
{
    int n=v.size();
    //transpose
    for(int i=0;i<n;i++)
      for(int j=0;j<i;j++)
         swap(v[i][j],v[j][i]);

    //rotate all the rows
     for(int i=0;i<n;i++)
     {
         reverse(v[i].begin(),v[i].end());
     }     
}

int main()
{
    int n;
    cout << "Size : ";
    cin >> n;
    vector<vector<int>> v(n, vector<int>(n));

    cout << "Enter elements in the matrix : ";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> v[i][j];

    rotateImage(v);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout<<v[i][j]<<" ";
        cout << endl;
    }
}