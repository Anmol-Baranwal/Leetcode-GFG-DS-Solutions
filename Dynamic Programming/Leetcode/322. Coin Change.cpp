// -----Approach 1: Memoization ------------------------------------------------------------

/*
    Problem Link: https://leetcode.com/problems/coin-change/
    
    Time: 114 ms (Beats 55.50%), Space: 45.8 MB (Beats 21.15%)
*/

class Solution {
private:
    int sol(int idx, int target, vector<vector<int>>& dp, vector<int>& coins){
        if(idx == 0){
            if(target % coins[0] == 0)    return target / coins[0];
            else    return 1e9;
        }

        if(dp[idx][target] != -1)   return dp[idx][target];
        
        int notPick= 0 + sol(idx-1, target, dp, coins);
        int pick= 1e9;
        if(coins[idx] <= target)    pick= 1 + sol(idx, target - coins[idx], dp, coins);

        return dp[idx][target]= min(pick, notPick);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n= coins.size();

        vector<vector<int>> dp(n, vector<int>(amount+1, -1));

        int ans= sol(n-1, amount, dp, coins);

        if(ans>=1e9)    return -1;
        return ans;
    }
};

// -----Approach 2: Tabulation ------------------------------------------------------------

/*
    Problem Link: https://leetcode.com/problems/coin-change/
    
    Time: 148 ms (Beats 34.59%), Space: 45.2 MB (Beats 32.62%)
*/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n= coins.size();

        vector<vector<int>> dp(n, vector<int>(amount+1, 0));

        for(int i=0; i<=amount; i++){
            if(i % coins[0] == 0)   dp[0][i]= i / coins[0];
            else dp[0][i]= 1e9;
        }

        for(int idx=1; idx<n; idx++){
            for(int T=0; T<=amount; T++){

                int notPick= 0 + dp[idx-1][T];
                int pick= 1e9;
                if(coins[idx] <= T)    pick= 1 + dp[idx][T - coins[idx]];

                dp[idx][T]= min(pick, notPick);
            }
        }

        if(dp[n-1][amount] >= 1e9)  return -1;
        return dp[n-1][amount];
    }
};

// -----Approach 3: Space Optimization ------------------------------------------------------------

/*
    Problem Link: https://leetcode.com/problems/coin-change/
    
    Time: 146 ms (Beats 36.23%), Space: 18.7 MB (Beats 39.15%)
*/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {

        int n= coins.size();
        vector<int> prev(amount+1, 0), curr(amount+1, 0);

        for(int i=0; i<=amount; i++){
            if(i % coins[0] == 0)   prev[i]= i / coins[0];
            else prev[i]= 1e9;
        }

        for(int idx=1; idx<n; idx++){
            for(int T=0; T<=amount; T++){

                int notPick= 0 + prev[T];
                int pick= 1e9;
                if(coins[idx] <= T)    pick= 1 + curr[T - coins[idx]];

                curr[T]= min(pick, notPick);
            }
            prev= curr;
        }

        if(prev[amount] >= 1e9)  return -1;
        return prev[amount];
    }
};
