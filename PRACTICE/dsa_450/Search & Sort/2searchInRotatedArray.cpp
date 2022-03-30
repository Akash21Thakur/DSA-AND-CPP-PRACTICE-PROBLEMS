#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        //Divide array into two sorted half...decide the correct half for the target
        int n=nums.size()-1;
        int start=0,end=n;
        
        // 1. Finding the pivot index
        while(start<end)
        {
            int mid=(start+end)/2;
            if(nums[mid]>nums[n])  start=mid+1;
            else  end=mid;
        }
        
        //now we have elements 0-start-1...greater
        //start-n smaller...
        
        int beginning=start;
        if(target==nums[start])   return start;  //if target is the starting element
        
        if(target>nums[n]) //first half
        {
            start=0;
            end=beginning-1;
        }
        else   //second half
        {
            start=beginning;
            end=n;
        }
        
        //3. Simple binary search
        while(start<=end)
        {
            int mid=(start+end)/2;
            if(nums[mid]==target)   return mid;
            else if(target>nums[mid])  start=mid+1;
            else end=mid-1;
        }
        
        return -1;
    }
};

int main()
{
    int n,target;
    cin>>n>>target;
    vector<int> nums(n,0);

    for(int i=0;i<n;i++)
       cin>>nums[i];
    Solution obj;
    cout<<obj.search(nums,target);   
}