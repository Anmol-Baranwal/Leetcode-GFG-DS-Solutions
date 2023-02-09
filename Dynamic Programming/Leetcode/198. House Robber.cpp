// -----Approach 1: Memoization ------------------------------------------------------------

/*
    Problem Link: https://leetcode.com/problems/house-robber/
    
    Time: 2 ms (Beats 48.81%), Space: 7.9 MB (Beats 6.83%)
*/

class Solution {
private:
    int sum(int idx, vector<int>& nums, vector<int>& dp){
        if(idx == 0)    return nums[0];
        if(idx < 0)     return 0;
        if(dp[idx] != -1)    return dp[idx];

        int pick= nums[idx] + sum(idx-2, nums, dp);
        int nonPick= 0 + sum(idx-1, nums, dp);

        return dp[idx]= max(pick, nonPick);
    }
public:
    int rob(vector<int>& nums) {
        int n= nums.size();
        vector<int> dp(n, -1);
        return sum(n-1, nums, dp);
    }
};

// -----Approach 1: Tabulation ------------------------------------------------------------

/*
    Problem Link: https://leetcode.com/problems/house-robber/
    
    Time: 0 ms (Beats 100%), Space: 8 MB (Beats 6.83%)
*/

class Solution {
public:
    int rob(vector<int>& nums) {
        int n= nums.size();
        vector<int> dp(n, 0);
        dp[0]= nums[0];
        for(int i=1; i<n; i++){
            int pick= nums[i];

            if(i>1){
                pick+= dp[i-2];
            }

            int nonPick= 0 + dp[i-1];

            dp[i]= max(pick, nonPick);
        }
        return dp[n-1];
    }
};

// -----Approach 1: Space Optimization ------------------------------------------------------------

/*
    Problem Link: https://leetcode.com/problems/house-robber/
    
    Time: 0 ms (Beats 100%), Space: 7.5 MB (Beats 96.51%)
*/

class Solution {
public:
    int rob(vector<int>& nums) {
        int n= nums.size();
        int prev= nums[0];
        int prev2= 0;
        for(int i=1; i<n; i++){
            int pick= nums[i];
            if(i>1) pick+= prev2;

            int nonPick= 0 + prev;
            
            int curr= max(pick, nonPick);
            prev2= prev;
            prev= curr;
        }
        return prev;
    }
};
