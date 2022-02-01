#include<iostream>
#include<vector>
using namespace std;
 
void print(vector<int> v)
{
    for(int i=1;i<v.size();i++)
      cout<<v[i]<<" ";
      cout<<endl;
}

// bool compare(int a,int b)
// {
//     return a<b;
// }

void buildHeap(vector<int> &v)
{
    int n=v.size();
    for(int i=2;i<n;i++)
    {
        int idx=i;
        int parent=i/2;
        while(idx>1 and v[idx]>v[parent])
        {
            swap(v[idx],v[parent]);
            idx=parent;
            parent/=2;
        }
    }
}

//heapify for buildHeapOptimized does not need size as parameter,=>last=v.size
void heapify(int idx,vector<int> &v,int size)
{
    int left=2*idx;
    int right=left+1;

    int last=size-1,minIdx=idx;

    if(left<=last and v[left]>v[idx])
        minIdx=left;
    if(right<=last and v[right]>v[minIdx])
      minIdx=right;

    if(minIdx!=idx)
    {
        swap(v[idx],v[minIdx]);
        heapify(minIdx,v,size);
    }      

}

void buildHeapOptimized(vector<int> &v)
{
    for(int i=v.size()-1/2;i>=1;i--)
      heapify(i,v,v.size());
}

//HEAP SORT
void heapSort(vector<int> &a)
{
    buildHeapOptimized(a);
    int n=a.size();
    while(n>1)
    {
        swap(a[1],a[n-1]);
        n--;
        heapify(1,a,n);
    }
}

int main()
{
    vector<int> v;//={-1,10,20,5,6,1,8,9,4};
    print(v);
    // buildHeap(v);
    // buildHeapOptimized(v);
    int temp,n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>temp;
        v.push_back(temp);
    }
    heapSort(v);
    print(v);

    // print(v);

}