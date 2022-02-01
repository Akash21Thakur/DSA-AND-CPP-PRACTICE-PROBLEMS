#include<iostream>
#include<queue>
#include<vector>
using namespace std;

typedef pair<int,pair<int,int>> node;//val,x,y

vector<int> mergeKArray(vector<vector<int>> v)
{
    vector<int> ans;
    priority_queue<node,vector<node>,greater<node>> pq;

    for(int i=0;i<v.size();i++)
      pq.push({v[i][0],{i,0}});

    while(!pq.empty())
    {
        int element=pq.top().first;
        int x=pq.top().second.first;
        int y=pq.top().second.second;

        pq.pop();
        ans.push_back(element);

        if(y+1<v[x].size())
        {
            pq.push({v[x][y+1],{x,y+1}});
        }

    }
    return ans;  

}

int main()
{
    vector<vector<int>> v={{2,4,5,6},{8,10,15,20,25},{1,3,7,9,10}};
    cout<<"akash"<<endl;
    vector<int> a=mergeKArray(v);
    for(int i=0;i<a.size();i++)
       cout<<a[i]<<" ";



}