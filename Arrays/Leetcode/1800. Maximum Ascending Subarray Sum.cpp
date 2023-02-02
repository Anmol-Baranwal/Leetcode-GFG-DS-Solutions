/*
    Problem Link: https://leetcode.com/problems/maximum-subarray/
    
    Time: 8 ms (Beats 5.75%), Space: 8.2 MB (Beats 99.34%)
*/

class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int sum= nums[0], mx= nums[0];
        for(size_t i=1;i<nums.size(); i++){
            
            if(nums[i]>nums[i-1])   sum+=nums[i];
            
            else sum=nums[i];
            
            mx=max(sum,mx);
            
        }
        return mx;
    }
};