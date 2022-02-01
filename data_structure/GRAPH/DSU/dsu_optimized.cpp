#include<iostream>
#include<list>

using namespace std;

class Graph
{
    int V;
    list<pair<int,int>> l;

    public:
    Graph(int v)
    {
        this->V=v;
    }

    void addEdge(int x,int y)
    {
        l.push_back(make_pair(x,y));
    }

    //FIND WITH PATH COMPRESSION
    int findSet(int i,int* parent)
    {
        if(parent[i]==-1)
          return i;

        return parent[i]=findSet(parent[i],parent);  
    }

    //UNION BY RANK

    void unionSet(int x,int y,int*parent,int*rank)
    {
        int s1=findSet(x,parent);
        int s2=findSet(y,parent);

        if(s1!=s2)
        {
            if(rank[s1]<rank[s2])
            {
                parent[s1]=s2;
                rank[s2]+=rank[s1];
            }
            else
            {
                parent[s2]=s1;
                rank[s1]+=rank[s2];
            }
        }
    }

    //check function => O(1) approximately
    bool ifCycle()
    {
        int* parent = new int[V];
        int* rank = new int[V];

        for(int i=1;i<=V;i++)
        {
            parent[i]=-1;
            rank[i]=1;
        }

        for(auto edge: l)
        {
            int i=edge.first;
            int j=edge.second;

            int s1=findSet(i,parent);
            int s2=findSet(j,parent);

            if(s1!=s2)
            {
                unionSet(i,j,parent,rank);
            }
            else
              return true;
        }

        delete[]parent;
        delete[]rank;
        return false;
    }

};

int main()
{
    Graph g(4);

    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    // g.addEdge(4,1);

    if(g.ifCycle())
      cout<<"CYCLE IS PRESENT"<<endl;
    else
      cout<<"CYCLE NOT PRESENT"<<endl;  
}