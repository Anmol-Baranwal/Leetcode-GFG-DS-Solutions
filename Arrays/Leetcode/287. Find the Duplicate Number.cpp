/*
    Problem Link: https://leetcode.com/problems/find-the-duplicate-number/
    
    Time: 311 ms (Beats 24.89%), Space: 61.1 MB (Beats 99.62%)
*/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // without modifying: cannot use nums[i] % size
        // cannot use freq method 
        // cannot use map in stl
        
        // using cycle in linked list
        
        int slow= nums[0];
        int fast= nums[0];
        do{
            slow= nums[slow];
            fast= nums[nums[fast]];
        }while(slow!=fast);
    
        fast=nums[0];
        while(slow!=fast){
            slow= nums[slow];
            fast= nums[fast];
        }
        return slow;
    }
};
