#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

//method-1 naive
// add all the element in the 1d array and sort, add the sorted element back to input matrix

//method-2
//use priority queue for better complexity

void printMatrix(vector<vector<int>> &v,int r,int c)
{
    priority_queue<int,vector<int>,greater<int>> pq;

    for(int i=0;i<r;i++)
      for(int j=0;j<c;j++)
        pq.push(v[i][j]);

    for(int i=0;i<r;i++)
      for(int j=0;j<c;j++)
        {
            v[i][j]=pq.top();
            pq.pop();
        }    

    for(int i=0;i<r;i++)
      {
          for(int j=0;j<c;j++)
             cout<<v[i][j]<<" ";
          cout<<endl;    
      }    




}

int main()
{
    int r,c;
    cout<<"Row --- Column : ";
    cin>>r>>c;
    vector<vector<int>> v(r,vector<int>(c));

    for(int i=0;i<r;i++)
      for(int j=0;j<c;j++)
        cin>>v[i][j];

    printMatrix(v,r,c);    
}