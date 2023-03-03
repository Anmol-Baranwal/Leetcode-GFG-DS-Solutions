// -----Approach: Tabulation ------------------------------------------------------------

/*
    Problem Link: https://leetcode.com/problems/number-of-longest-increasing-subsequence/
    
    Time: 208 ms (Beats 47.74%), Space: 13.3 MB (Beats 54.96%)
*/

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n= nums.size();
        vector<int> dp(n, 1), cnt(n, 1);     

        int mx= 0;
        for(int idx=0; idx<n; idx++){
            for(int prevIdx= 0; prevIdx<idx; prevIdx++){    

                if(nums[prevIdx] < nums[idx] && dp[idx] < 1 + dp[prevIdx]){
                    dp[idx]= 1 + dp[prevIdx];    
                    cnt[idx]= cnt[prevIdx];
                }
                else if(nums[prevIdx] < nums[idx] && dp[idx] == 1 + dp[prevIdx]){
                    cnt[idx]+= cnt[prevIdx];        // increase the count
                }
            }
            mx= max(mx, dp[idx]);
        }

        int ans=0;
        for(int i=0; i<n; i++){
            if(dp[i] == mx) ans+= cnt[i];
        }

        return ans;
    }
};