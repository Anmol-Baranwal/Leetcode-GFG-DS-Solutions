/*
    Problem Link: https://leetcode.com/problems/maximum-subarray/
    
    Time: 217 ms (Beats 25.68%), Space: 67.7 MB (Beats 59.41%)
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currSum= 0, mx= nums[0];
        for(auto it: nums){
            currSum+=it;
            mx=max(mx,currSum);
            if(currSum<0)   currSum=0;
        }
        return mx;
    }
};