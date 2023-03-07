// -----Approach: Tabulation ------------------------------------------------------------

/*
    Problem Link: https://leetcode.com/problems/largest-divisible-subset/
    
    Time: 56 ms (Beats 66.96%), Space: 9.1 MB (Beats 21.34%)
*/

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n= nums.size();

        int mx= 1, lastIdx= 0;
        sort(nums.begin(), nums.end());
        vector<int> dp(n, 1), hash(n);

        for(int idx=0; idx<n; idx++){
            hash[idx]= idx;
            for(int prevIdx=0; prevIdx<idx; prevIdx++){
                if(nums[idx] % nums[prevIdx] == 0 && dp[idx] < dp[prevIdx] + 1){
                    dp[idx]= dp[prevIdx] + 1;
                    hash[idx]= prevIdx;
                }
            }
            if(dp[idx] > mx){
                mx= dp[idx];
                lastIdx= idx;
            }
        }
        vector<int> v;
        v.push_back(nums[lastIdx]);

        while(hash[lastIdx] != lastIdx){
            lastIdx= hash[lastIdx];
            v.push_back(nums[lastIdx]);
        }
        reverse(v.begin(), v.end());

        return v;
    }
};