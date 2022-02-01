//HEAPSORT
#include<iostream>
#include<vector>
using namespace std;

void heapify(int *a,int size,int idx)
{
    int largest=idx;
    int left=idx*2+1;
    int right=left+1;

    if(left<size and a[left]>a[largest])
       largest=left;
    if(right<size and a[right]>a[largest])
          largest=right;

    if(largest!=idx) {
        swap(a[idx],a[largest]);
        heapify(a,size,largest);
    }     
}

void heapSort(int *a,int size)
{
    for(int i=size/2-1;i>=0;i--)
       heapify(a,size,i);

    for(int i=size-1;i>0;i--){
        swap(a[0],a[i]);
        heapify(a,i,0);
    }   
}

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
       cin>>a[i];

    heapSort(a,n);
    for(int i=0;i<n;i++)
       cout<<a[i]<<" ";   
}