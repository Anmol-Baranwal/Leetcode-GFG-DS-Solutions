// -----Approach 1: Memoization ------------------------------------------------------------

/*
    Problem Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii
    
    Time: 844 ms (Beats 12.74%), Space: 218 MB (Beats 18.18%)
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
    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));    
        // buy/not buy->2 size &  transaction till two->3 size

        return sol(0, 1, 2, dp, prices);
    }
};

// -----Approach 2: Memoization ------------------------------------------------------------

/*
    Problem Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii
    
    Time: 399 ms (Beats 53.97%), Space: 132.7 MB (Beats 53.66%)
*/

class Solution {
private:
    int sol(int idx, int limit, vector<vector<int>>& dp, vector<int>& prices){
        if(limit == 4 || idx == prices.size())  return 0;

        if(dp[idx][limit] != -1)  return dp[idx][limit];
        if(limit%2 == 0){
            return dp[idx][limit]= max(-prices[idx] + sol(idx+1, limit+1, dp, prices), sol(idx+1, limit, dp, prices));
        } else {
            return dp[idx][limit]= max(prices[idx] + sol(idx+1, limit+1, dp, prices), sol(idx+1, limit, dp, prices));
        }
    }
public:
    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        vector<vector<int>> dp(n, vector<int>(4, -1));    
        // we have a limit of two transacations: buy (0:even) , sell (1:odd), buy(0:even), sell(1:odd)  -> so size 4

        return sol(0, 0, dp, prices);
    }
};

// -----Approach 3: Tabulation ------------------------------------------------------------

/*
    Problem Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii
    
    Time: 711 ms (Beats 46.94%), Space: 207.2 MB (Beats 36.3%)
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));    
        
        // these base cases are not necessary since dp is initialised to 0, just for practice
        
        // --> the case of limit == 0 in memoization
        // for(int idx=0; idx<n; idx++){
        //     for(int buy=0; buy<=1; buy++){
        //         dp[idx][buy][0]= 0;
        //     }
        // }

        // --> the case of idx == n in memoization
        // for(int buy=0; buy<=1; buy++){
        //     for(int limit=0; limit<=2; limit++){
        //         dp[n][buy][limit]= 0;
        //     }
        // }

        for(int idx=n-1; idx>=0; idx--){
            for(int buy=0; buy<=1; buy++){
                for(int limit=1; limit<=2; limit++){  // limit=1 case already covered by base case
                    if(buy){
                        dp[idx][buy][limit]= max(-prices[idx] + dp[idx+1][0][limit], dp[idx+1][1][limit]);
                    } else {
                        dp[idx][buy][limit]= max(prices[idx] + dp[idx+1][1][limit-1], dp[idx+1][0][limit]);
                    }
                }
            }
        }
        
        return dp[0][1][2];
    }
};

// -----Approach 4: Tabulation ------------------------------------------------------------

/*
    Problem Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii
    
    Time: 354 ms (Beats 57.46%), Space: 135.2 MB (Beats 52.3%)
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        vector<vector<int>> dp(n+1, vector<int>(5, 0));

        // for(int idx=1; idx<=n; idx++)   dp[idx][4]= 0; // base case

        for(int idx=n-1; idx>=0; idx--){
            for(int limit=3; limit>=0; limit--){
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
    Problem Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii
    
    Time: 239 ms (Beats 66.15%), Space: 75.3 MB (Beats 89.39%)
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        vector<vector<int>> front(2, vector<int>(3, 0));   
        vector<vector<int>> curr(2, vector<int>(3, 0));     

        for(int idx=n-1; idx>=0; idx--){
            for(int limit=1; limit<=2; limit++){  // limit=0 case already covered by base case
                
                curr[1][limit]= max(-prices[idx] + front[0][limit], front[1][limit]);
                
                curr[0][limit]= max(prices[idx] + front[1][limit-1], front[0][limit]);
            }
            front= curr;
        }
        
        return front[1][2];
    }
};

// -----Approach 6: Space Optimization ------------------------------------------------------------

/*
    Problem Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii
    
    Time: 187 ms (Beats 73.55%), Space: 75.2 MB (Beats 97.22%)
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        vector<int> front(5, 0), curr(5, 0);

        for(int idx=n-1; idx>=0; idx--){
            for(int limit=3; limit>=0; limit--){
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