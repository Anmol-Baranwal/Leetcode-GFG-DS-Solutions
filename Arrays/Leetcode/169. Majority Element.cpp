/*
    Problem Link: https://leetcode.com/problems/majority-element/
    
    Time: 43 ms (Beats 21.27%), Space: 19.5 MB (Beats 95.17%)
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt=0, curr=0; // curr is for holding current element if cnt=0
        
        for(auto i: nums){
            if(cnt==0)  curr= i;
            
            if(curr==i) cnt+= 1;
            else    cnt-=1;    
        }
        return curr;
    }
};