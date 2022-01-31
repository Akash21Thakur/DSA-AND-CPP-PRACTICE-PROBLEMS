#include<iostream>
#include<vector>
using namespace std;

class heap
{
    vector<int> v;
    bool minHeap;

    bool compare(int a,int b)
    {
        if(minHeap) return a<b;
        else return a>b;
    }

    void heapify(int idx)
    {
        int left=2*idx;
        int right=left+1;
        int minIdx=idx,last=v.size()-1;

        if(left<=last and compare(v[left],v[idx]) )
          minIdx=left;
        if(right<=last and compare(v[right],v[minIdx]))
          minIdx=right;

        if(minIdx!=idx)
        {
            swap(v[idx],v[minIdx]);
            heapify(minIdx);
        }    
    }

    public:

    heap(int size,bool minH)
    {
        v.reserve(size);
        v.push_back(-1);
        minHeap=minH;
    }

    void insert(int d)
    {
        v.push_back(d);
        int idx=v.size()-1;
        int parent=idx/2;
        while(idx>1 and compare(v[idx],v[parent]))
        {
            swap(v[idx],v[parent]);
            idx=parent;
            parent/=2;
        }
    }

    int top()
    {
        return v[1];
    }

    void pop()
    {
        int last=v.size()-1;
        swap(v[1],v[last]);
        v.pop_back();
        heapify(1);
    }

    bool empty()
    {
        return v.size()==1;
    }

};

int main()
{
    heap h(10,false);
    int n;
    // cin>>n;

    for(int i=0;i<10;i++)
      {
          cin>>n;
          h.insert(n);
      }

    while(!h.empty())
    {
        cout<<h.top()<<" ";
        h.pop();
    }  

}