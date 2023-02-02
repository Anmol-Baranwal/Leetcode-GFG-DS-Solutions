/*
    Problem Link: https://leetcode.com/problems/longest-consecutive-sequence/
    
    Time: 2174 ms (Beats 11.52%), Space: 51.2 MB (Beats 34.48%)
*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int,int> mpp;       // map is better than set in terms of complexity
        int cnt=0;
        
        for(int i=0;i<nums.size();i++)   mpp[nums[i]]=cnt;
        
        for(auto num: nums){
            if( mpp.find(num-1)==mpp.end() ){
                int currNum= num;
                int currVal= 1;
            
                while(mpp.find(currNum+1)!=mpp.end()){
                    currVal+= 1;
                    currNum+= 1;  
                }
                
                cnt= max(currVal, cnt);
            }
        }
        return cnt;
    }
};
