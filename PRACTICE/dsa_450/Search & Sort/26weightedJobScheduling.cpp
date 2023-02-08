#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//JOB SCHEDULING PROBLEM
//RETURN MAXIMUM PROFIT ONE CAN HAVE WITHOUT HAVING CONFLICT B/W THE JOB
//METHOD-1 DP--->   nxn
//METHOD-2 BINARY_SEARCH--->   nlogn

struct Job
{
    int start, finish, profit;
};

bool compator(Job a, Job b)
{
    return a.finish < b.finish;
}

int latestNonConflictLinearS(Job *arr, int i)
{
    for (int j = i - 1; j >= 0; j--)
    {
        if (arr[j].finish <= arr[i].start)
            return j;
    }
    return -1;
}

//optimizes the dp_solution just by making the linear search in finding conflict to binary search
int nonConflictBinaryS(Job *arr,int i)
{
    int low=0,high=i-1;

    while (low<=high)
    {
        int mid=(low+high)/2;
        if(arr[mid].finish<=arr[i].start)
        {
            if(arr[mid+1].finish<=arr[i].start)
               low=mid+1;
            else
              return mid;   
        }
        else
          high=mid-1;
    }
    return -1;
    
}

// dp_based problem...due to both the property satisfying
// algo :
//  1. Sort on the basis of finish time
//  2. create an array to store answers of subproblem
//  3. answer is  the maximum of (include_current_job,exclude)
//  ----> including should not overlap with the timing of other job


int findOptimal(Job *arr, int n)
{
    sort(arr, arr + n, compator);

    int *table = new int[n];
    table[0] = arr[0].profit;

    for (int i = 1; i < n; i++)
    {
        int inclJob = arr[i].profit;
        // int l = latestNonConflictLinearS(arr, i);  //method-1
        int l=nonConflictBinaryS(arr,i);      //method-2
        if (l != -1)
            inclJob += table[l];
        
        //max of including and excluding
        table[i] = max(inclJob, table[i - 1]);
    }

    int res=table[n-1];
    delete [] table;

    return res;
}




int main()
{
    Job arr[] = {
                 {3, 10, 20},
                 {1, 2, 50},
                 {6, 19, 100},
                 {2, 100, 200}
                };
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Optimal Profit is : " << findOptimal(arr, n) << endl;
}