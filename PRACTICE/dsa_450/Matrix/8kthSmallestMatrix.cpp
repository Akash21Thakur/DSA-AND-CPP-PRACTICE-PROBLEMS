#include <iostream>
#include<climits>
using namespace std;
#define MAX 4

// https://www.geeksforgeeks.org/kth-smallest-element-in-a-row-wise-and-column-wise-sorted-2d-array-set-1/

// METHOD-1
// PUT INTO ARRAY ...SORT...RETURN AR[K-1] element


//METHOD-2
//use minHEAP for optimal complexity
// Time Complexity: The above solution involves following steps. 
//    1.Building a min-heap which takes O(n) time
//    2.Heapify k times which takes O(k Logn) time.

// Algorithm:

// 1. The idea is to use min heap. Create a Min-Heap to store the elements
// 2. Traverse the first row from start to end and build a min heap of elements from first row. A heap entry also stores row number and column number.
// 3. Now Run a loop k times to extract min element from heap in each iteration
// 4. Get minimum element (or root) from Min-Heap.
// 5. Find row number and column number of the minimum element.
// 6. Replace root with the next element from same column and min-heapify the root.
// 7. Print the last extracted element, which is the kth minimum element

struct Heap_Node
{
    int val;  // value
    int r, c; // row - column
};

void heapify(Heap_Node heapAry[], int i, int heapSize)
{
    int l = i * 2 + 1;
    int r = i * 2 + 2;
    if (l < heapSize and r < heapSize and
        heapAry[l].val < heapAry[i].val and
        heapAry[r].val < heapAry[i].val)
    {
        // swap the values
        Heap_Node temp=heapAry[r];
        heapAry[r]=heapAry[i];
        heapAry[i]=heapAry[l];
        heapAry[l]=temp;

        heapify(heapAry,l,heapSize);
        heapify(heapAry,r,heapSize);

    }

    if(l<heapSize and heapAry[l].val<heapAry[i].val)
    {
        Heap_Node temp=heapAry[i];
        heapAry[i]=heapAry[l];
        heapAry[l]=temp;

        heapify(heapAry,l,heapSize);
    }
}

int kthSmallest(int m[MAX][MAX], int n, int k)
{
    if(k<0 or k>n*n)
       return INT_MAX;
    
    //insert 1st row in the min_heap
    Heap_Node heapAry[n];
    for(int i=0;i<n;i++)
       heapAry[i]={m[0][i],0,i};

    //find the kth smallest...poping all the k-1 inserted values
    Heap_Node cur_min;
    for(int i=0;i<k;i++)
    {
        cur_min=heapAry[0];

        //insert the current minimum's next into the heap
        //if the cur_min was the last element in its column...insert the INFINITE VALUE
        int next_val=(cur_min.r<(n-1)) ? m[cur_min.r+1][cur_min.c]: INT_MAX;

        heapAry[0]={next_val,cur_min.r+1,cur_min.c};

        heapify(heapAry,0,n);
    }   
    return cur_min.val;
}

int main()
{
    int mat[MAX][MAX] = {
        {10, 20, 30, 40},
        {15, 25, 35, 45},
        {25, 29, 37, 48},
        {32, 33, 39, 50},
    };
    cout << "7th smallest element is "
         << kthSmallest(mat, 4, 7);
}