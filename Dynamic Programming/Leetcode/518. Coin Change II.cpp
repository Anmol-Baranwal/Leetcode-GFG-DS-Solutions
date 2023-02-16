// -----Approach 1: Memoization ------------------------------------------------------------

/*
    Problem Link: https://leetcode.com/problems/coin-change-ii/
    
    Time: 8 ms (Beats 93.52%), Space: 18.5 MB (Beats 42.68%)
*/

class Solution {
private:
    int sol(int idx, int target, vector<vector<int>> &dp, vector<int>& coins){
        if(idx == 0)    return ( target % coins[0] == 0);

        if(dp[idx][target] != -1)   return dp[idx][target];
        int notPick= sol(idx-1, target, dp, coins);
        int pick= 0;
        if(coins[idx] <= target)    pick= sol(idx, target - coins[idx], dp, coins);

        return dp[idx][target] = notPick + pick;
    }
public:
    int change(int amount, vector<int>& coins) {
        int n= coins.size();

        vector<vector<int>> dp(n, vector<int>(amount+1, -1));

        return sol(n-1, amount, dp, coins);
    }
};

// -----Approach 2: Tabulation ------------------------------------------------------------

/*
    Problem Link: https://leetcode.com/problems/coin-change-ii/
    
    Time: 57 ms (Beats 25.99%), Space: 18.5 MB (Beats 49.75%)
*/

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n= coins.size();

        vector<vector<int>> dp(n, vector<int>(amount+1, 0));

        for(int T=0; T<=amount; T++)    dp[0][T] = (T % coins[0] == 0);

        for(int idx=1; idx<n; idx++){
            for(int T=0; T<=amount; T++){
                int notPick= dp[idx-1][T];
                int pick= 0;
                if(coins[idx] <= T)    pick= dp[idx][T-coins[idx]];

                dp[idx][T] = notPick + pick;
            }
        }

        return dp[n-1][amount];
    }
};

// -----Approach 2: Space Optimization ------------------------------------------------------------

/*
    Problem Link: https://leetcode.com/problems/coin-change-ii/
    
    Time: 28 ms (Beats 57.9%), Space: 7.3 MB (Beats 84.77%)
*/

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n= coins.size();

        vector<int> prev(amount+1, 0), curr(amount+1, 0);

        for(int T=0; T<=amount; T++)    prev[T] = (T % coins[0] == 0);

        for(int idx=1; idx<n; idx++){
            for(int T=0; T<=amount; T++){
                int notPick= prev[T];
                int pick= 0;
                if(coins[idx] <= T)    pick= curr[T-coins[idx]];

                curr[T] = notPick + pick;
            }
            prev= curr;
        }

        return prev[amount];
    }
};
