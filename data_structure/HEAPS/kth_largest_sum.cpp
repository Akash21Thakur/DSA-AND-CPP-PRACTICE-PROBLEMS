#include<iostream>
#include<queue>
using namespace std;

//Time : O(n^2logk) n^2 -> for all the sum, (log(k)) -> times the pq.pop()
// Space : log(n) for the minHeap

int kth_largest_sum(int *a,int k,int n)
{
    int preSum[k+1];
    preSum[0]=0;
    preSum[1]=a[0];

    for(int i=1;i<n;i++)
    {
        preSum[i+1]=preSum[i]+a[i];    //calculates the pre contiguous sum 
    }

    priority_queue<int,vector<int>,greater<int>> pq;  //minHeap

    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            int x=preSum[j]-preSum[i-1];

            if(pq.size()<k)
              pq.push(x);
            else{              //when size becomes k then check if top is less than x,replacing it from the minHeap
                if(pq.top()<x)
                {
                    pq.pop();
                    pq.push(x);
                }
            }  
        }
    }

    return pq.top();  //the top gives the kth largest as...all the k-1 largest element are stored below it

}

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
      cin>>a[i];
      cout<<"Enter k : ";
      int k;
      cin>>k;
    cout<<"\nKth largest sum of a contiguous array : "<<kth_largest_sum(a,k,n)<<endl;;  
}