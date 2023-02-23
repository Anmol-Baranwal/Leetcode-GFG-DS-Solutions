// -----Approach 1: Memoization ------------------------------------------------------------

/*
    Problem Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/
    
    Time: 28 ms (Beats 39.21%), Space: 17 MB (Beats 10.32%)
*/

class Solution {
private:
    int sol(int idx, int buy, int limit, vector<vector<vector<int>>>& dp, vector<int>& prices){
        if(limit == 0 || idx == prices.size())  return 0;

        if(dp[idx][buy][limit] != -1)  return dp[idx][buy][limit];
        if(buy){
            return dp[idx][buy][limit]= max(-prices[idx] + sol(idx+1, 0, limit, dp, prices), sol(idx+1, 1, limit, dp, prices));
        } else {
            return dp[idx][buy][limit]= max(prices[idx] + sol(idx+1, 1, limit-1, dp, prices), sol(idx+1, 0, limit, dp, prices));
        }
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        int n= prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(2*k, -1)));    

        return sol(0, 1, k, dp, prices);
    }
};

// -----Approach 2: Memoization ------------------------------------------------------------

/*
    Problem Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/
    
    Time: 27 ms (Beats 41.60%), Space: 14.1 MB (Beats 43.42%)
*/

class Solution {
private:
    int sol(int idx, int limit, vector<vector<int>>& dp, vector<int>& prices, int k){
        if(limit == 2*k || idx == prices.size())  return 0;

        if(dp[idx][limit] != -1)  return dp[idx][limit];
        if(limit%2 == 0){
            return dp[idx][limit]= max(-prices[idx] + sol(idx+1, limit+1, dp, prices, k), sol(idx+1, limit, dp, prices, k));
        } else {
            return dp[idx][limit]= max(prices[idx] + sol(idx+1, limit+1, dp, prices, k), sol(idx+1, limit, dp, prices, k));
        }
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        int n= prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2*k+1, -1));    
        // for k=2 transacations: 2*k states where each state is completed by buy & sell

        return sol(0, 0, dp, prices, k);
    }
};

// -----Approach 3: Tabulation ------------------------------------------------------------

/*
    Problem Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/
    
    Time: 42 ms (Beats 18.36%), Space: 17.1 MB (Beats 9.86%)
*/

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n= prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(2*k+1, 0)));    

        for(int idx=n-1; idx>=0; idx--){
            for(int buy=0; buy<=1; buy++){
                for(int limit=1; limit<=2*k-1; limit++){  // limit=0 case already covered by base case
                    if(buy){
                        dp[idx][buy][limit]= max(-prices[idx] + dp[idx+1][0][limit], dp[idx+1][1][limit]);
                    } else {
                        dp[idx][buy][limit]= max(prices[idx] + dp[idx+1][1][limit-1], dp[idx+1][0][limit]);
                    }
                }
            }
        }
        
        return dp[0][1][k];
    }
};

// -----Approach 4: Tabulation ------------------------------------------------------------

/*
    Problem Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/
    
    Time: 12 ms (Beats 82.43%), Space: 13.9 MB (Beats 56.65%)
*/

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n= prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2*k+1, 0));

        for(int idx=n-1; idx>=0; idx--){
            for(int limit=2*k-1; limit>=0; limit--){
                if(limit%2 == 0){
                    dp[idx][limit]= max(-prices[idx] + dp[idx+1][limit+1], dp[idx+1][limit]);
                } else {
                    dp[idx][limit]= max(prices[idx] + dp[idx+1][limit+1], dp[idx+1][limit]);
                }
            }
        }
        
        return dp[0][0];
    }
};

// -----Approach 5: Space Optimization ------------------------------------------------------------

/*
    Problem Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/
    
    Time: 18 ms (Beats 64.44%), Space: 11 MB (Beats 77.94%)
*/

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n= prices.size();
        vector<vector<int>> front(2, vector<int>(2*k+1, 0));   
        vector<vector<int>> curr(2, vector<int>(2*k+1, 0));     

        for(int idx=n-1; idx>=0; idx--){
            for(int limit=1; limit<=2*k-1; limit++){  // limit=0 case already covered by base case
                    
                    curr[1][limit]= max(-prices[idx] + front[0][limit], front[1][limit]);
                    
                    curr[0][limit]= max(prices[idx] + front[1][limit-1], front[0][limit]);
            }
            front= curr;
        }
        
        return front[1][k];
    }
};

// -----Approach 6: Space Optimization ------------------------------------------------------------

/*
    Problem Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/
    
    Time: 12 ms (Beats 82.43%), Space: 13.9 MB (Beats 56.65%)
*/

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n= prices.size();
        vector<int> front(2*k+1, 0), curr(2*k+1, 0);

        for(int idx=n-1; idx>=0; idx--){
            for(int limit=2*k-1; limit>=0; limit--){
                if(limit%2 == 0){
                    curr[limit]= max(-prices[idx] + front[limit+1], front[limit]);
                } else {
                    curr[limit]= max(prices[idx] + front[limit+1], front[limit]);
                }
            }
            front= curr;
        }
        
        return front[0];
    }
};