#include<iostream>
#include<unordered_set>
#include<vector>
#include<set>

using namespace std;

class Point {
    
    public:
    int x;
    int y;
    Point(int x,int y)
    {
        this->x=x;
        this->y=y;
    }
    
};

class Compare
{
    public:
    bool operator()(Point p1,Point p2)
    {
        if(p1.x==p2.x)   return p1.y<p2.y;
        return p1.x<p2.x;
    }
};

int countRect(vector<Point> v)
{
    set<Point,Compare> s;

    for(auto x:v)
    s.insert(x);

    int count=0;

    for(auto it=s.begin();it!=prev(s.end());it++)
    {
        for(auto jt=next(it);jt!=s.end();jt++)
        {
            Point p1=*it;
            Point p2=*jt;

            if(p1.x==p2.x or p1.y==p2.y)
              continue;

            Point p3(p2.x,p1.y);
            Point p4(p1.x,p2.y);

            if(s.find(p3)!=s.end() and s.find(p4)!=s.end())
               count++;  
        }
        
    }
    return count/2;
}


int main()
{
    int m;
    cin>>m;
    int x,y;
    vector<Point> v;
    while(m--)
    {
        cin>>x>>y;
        Point p(x,y);
        v.push_back(p);

    }

    cout<<countRect(v)<<endl;

}