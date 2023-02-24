// -----Approach 1: Memoization ------------------------------------------------------------

/*
    Problem Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/
    
    Time: 8 ms (Beats 40.72%), Space: 12.1 MB (Beats 30.68%)
*/

class Solution {
private:
    int sol(int idx, int buy, vector<int>& prices, vector<vector<int>>& dp){
        if(idx >= prices.size())    return 0;   // because of idx+2

        if(dp[idx][buy] != -1)  return dp[idx][buy];
        if(buy)
            return dp[idx][buy]= max(-prices[idx] + sol(idx+1, 0, prices, dp), sol(idx+1, 1, prices, dp));
        else
            return dp[idx][buy]= max(prices[idx] + sol(idx+2, 1, prices, dp), sol(idx+1, 0, prices, dp));
    }
public:
    int maxProfit(vector<int>& prices) {
        
        int n= prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));

        // if we can buy -> 1   , if we cant buy -> 0
        return sol(0, 1, prices, dp);
    }
};

// -----Approach 2: Tabulation ------------------------------------------------------------

/*
    Problem Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/
    
    Time: 8 ms (Beats 40.72%), Space: 11.8 MB (Beats 58.26%)
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n= prices.size();
        vector<vector<int>> dp(n+2, vector<int>(2, 0)); 

        for(int idx=n-1; idx>=0; idx--){
            // we can omit buy for loop since each if else will run once
            dp[idx][1]= max(-prices[idx] + dp[idx+1][0], dp[idx+1][1]);
                
            dp[idx][0]= max(prices[idx] + dp[idx+2][1], dp[idx+1][0]);
        }
        
        return dp[0][1];
    }
};

// -----Approach 3: Space Optimization ------------------------------------------------------------

/*
    Problem Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/
    
    Time: 3 ms (Beats 87.55%), Space: 11.3 MB (Beats 78.61%)
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n= prices.size();
        vector<int> front1(2, 0), front2(2, 0), curr(2, 0);  

        for(int idx=n-1; idx>=0; idx--){
            // we can omit buy for loop since each if else will run once
            curr[1]= max(-prices[idx] + front1[0], front1[1]);
                
            curr[0]= max(prices[idx] + front2[1], front1[0]);

            front2= front1;
            front1= curr;
        }
        
        return front1[1];
    }
};