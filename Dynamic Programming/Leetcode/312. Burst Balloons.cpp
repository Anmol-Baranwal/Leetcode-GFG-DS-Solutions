// -----Approach 1: Memoization ------------------------------------------------------------

/*
    Problem Link: https://leetcode.com/problems/burst-balloons/
    
    Time: 544 ms (Beats 49.11%), Space: 10.5 MB (Beats 25.91%)
*/

class Solution {
private:
    int sol(int i, int j, vector<int>& nums, vector<vector<int>>& dp){
        if(i > j)   return 0;

        if(dp[i][j] != -1)  return dp[i][j];
        int mx= -1e9;
        for(int idx=i; idx<=j; idx++){
            int cost= nums[i-1] * nums[idx] * nums[j+1] + sol(i, idx-1, nums, dp) + sol(idx+1, j, nums, dp);

            mx= max(mx, cost);
        }
        return dp[i][j]= mx;
    }
public:
    int maxCoins(vector<int>& nums) {
        // try to bend logic by solving from bottom up, to get intuition
        // otherwise the subproblems would be dependent

        int n= nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        
        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        return sol(1, n, nums, dp);
    }
};

// -----Approach 2: Tabulation ------------------------------------------------------------

/*
    Problem Link: https://leetcode.com/problems/burst-balloons/
    
    Time: 359 ms (Beats 83.95%), Space: 10.4 MB (Beats 64.51%)
*/

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        // try to bend logic by solving from bottom up, to get intuition
        // otherwise the subproblems would be dependent

        int n= nums.size();
        vector<vector<int>> dp(n+2, vector<int>(n+2, 0));  // n+2 due to idx+1
        
        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        for(int i=n; i>=1; i--){
            for(int j=1; j<=n; j++){
                if(i > j)   continue;

                int mx= -1e9;
                for(int idx=i; idx<=j; idx++){
                    int cost= nums[i-1] * nums[idx] * nums[j+1] + dp[i][idx-1] + dp[idx+1][j];

                    mx= max(mx, cost);
                }
                dp[i][j]= mx;
            }
        }

        return dp[1][n];
    }
};