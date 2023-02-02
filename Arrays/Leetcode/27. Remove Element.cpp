/*
    Problem Link: https://leetcode.com/problems/remove-element/
    
    Time: 4 ms (Beats 30.98%), Space: 8.8 MB (Beats 74.66%)
*/

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        
        // two pointer forward approach
        int j=0;
        for(int i=0; i<nums.size(); i++)
            if(nums[i] != val)    nums[j++]= nums[i];

        return j; 
    }
};