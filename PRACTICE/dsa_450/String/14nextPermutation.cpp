#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
    
    // STRIVER -->O(N)
    //algo :
    // 1. search from end a[idx]<a[idx+1]  
    //     if not found reverse all and return 
    // 2. search from end a[temp]>a[idx]
    //         swap(a[temp],a[idx])
    // 3. reverse a(idx+1,last) 
    //         return
    
public:
    void nextPermutation(vector<int>& nums) {
        int idx=nums.size()-2;
        
        //1.
        while(idx>=0)
        {
            if(nums[idx]<nums[idx+1])
                break;
            idx--;
        }
        
        if(idx<0)
        {
            reverse(nums.begin(),nums.end());
            return;
        }
        
        //2.
        int temp=nums.size()-1;
        while(temp>idx)
        {
            if(nums[temp]>nums[idx])
                break;
            temp--;
        }
        
        swap(nums[temp],nums[idx]);
        
        //3.
        reverse(nums.begin()+idx+1,nums.end());
        
        
    }
};