#include <bits/stdc++.h>
using namespace std;

// The shortest job first (SJF) or shortest job next, is a scheduling policy that
// selects the waiting process with the smallest execution time to execute next.
// SJN, also known as Shortest Job Next (SJN), can be preemptive or non-preemptive.

// Algorithm:

// 1. Sort all the processes according to the arrival time.
// 2. Then select that process that has minimum arrival time and minimum Burst time.
// 3. After completion of the process make a pool of processes that arrives afterward
//    till the completion of the previous process and select that process among the pool
//    which is having minimum Burst time.

bool comp(vector<int> a, vector<int> b)
{
   // if arrival is same...return less burst one...if that too is same than least id
   if (a[1] == b[1])
   {
      if (a[2] == b[2])
         return a[0] < b[0];
      return a[2] < b[2];
   }
   return a[1] < b[1];
}

int main()
{
   int n;
   cin >> n;

   vector<vector<int>> v(n);

   // id,arrival,burst
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < 3; j++)
      {
         int x;
         cin >> x;
         v[i].push_back(x);
      }
   }

   vector<int> ans;                // will store the order of job
   sort(v.begin(), v.end(), comp); // sort on the basis of comparator

   // min_heap
   priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
   // burst,arrival,id
   pq.push({v[0][2], v[0][1], v[0][0]});
   int i = 1;
   int curr_time = 0;

   while (!pq.empty())
   {
      int burst_time = pq.top()[0];
      int id = pq.top()[2];

      pq.pop();
      ans.push_back(id);
      curr_time += burst_time;

      // put all the job that has arrived in the current time range
      while (true)
      {
         if (i < n and v[i][1] <= curr_time)
         {
            pq.push({v[i][2], v[i][1], v[i][0]});
            i++;
         }
         else
            break;
      }
   }
   for (int i = 0; i < n; i++)
      cout << ans[i] << " ";
}