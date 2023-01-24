/*
    Problem Link: https://leetcode.com/problems/network-delay-time/description/
    
    Time: 7 ms (Beats 47.79%), Space: 11.2 MB (Beats 39.88%)
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0, h=nums.size()-1;
        while(l<=h){
            int m= l+h >> 1;
            if(nums[m]==target) 
                return m;
            if(nums[l]<=nums[m]){ 
                if(nums[l]<=target && target<=nums[m]) 
                    h=m-1;
                else 
                    l=m+1;
            }
            else{
                if(nums[m]<=target && target<=nums[h]) 
                    l=m+1;
                else 
                    h=m-1;
            }
        }
        return -1;
    }
};
