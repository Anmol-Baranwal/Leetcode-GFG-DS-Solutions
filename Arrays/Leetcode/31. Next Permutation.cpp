/*
    Problem Link: https://leetcode.com/problems/find-the-duplicate-number/
    
    Time: 4 ms (Beats 69.69%), Space: 12.1 MB (Beats 75.20%)
*/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // next_permutation(nums.begin(),nums.end());
        int n=nums.size();
        int i,j;
        
        for(i=n-2; i>=0; i--)
            if(nums[i]<nums[i+1])   break;  
        // here i will be 1st index and i+1 will be 2nd index that will satisfy the cond
        
        if(i<0) reverse(nums.begin(),nums.end());
        else{
            for(j=n-1; j>i; j--)
                if(nums[j]>nums[i]) break;
            
            swap(nums[i], nums[j]);
            reverse(nums.begin()+i+1, nums.end());
        }
        
        // 1. reverse(nums.begin(),nums.end());
        // 2. for(auto first=nums.begin(), last=nums.end()-1; first<last ;first++,last--)
        //       swap(*first, *last);


        // we can also use stl in built function:
        // -> next_permutation(nums.begin(),nums.end());   stl algorithm for the whole logic
    }
};
