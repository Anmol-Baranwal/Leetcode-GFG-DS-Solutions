/*
    Problem Link: https://leetcode.com/problems/two-sum/
    
    Time: 11 ms (Beats 88.96%), Space: 10.8 MB (Beats 46.94%)
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mpp;
        vector<int> v;
        
        for(size_t i=0; i<nums.size(); i++){
            if( mpp.find( target-nums[i] )!=mpp.end() ){
                v.push_back( mpp[target-nums[i]] );   
                v.push_back( i );
                return v;
            }
            mpp[nums[i]]= i;
        }
        return v;
    }
};