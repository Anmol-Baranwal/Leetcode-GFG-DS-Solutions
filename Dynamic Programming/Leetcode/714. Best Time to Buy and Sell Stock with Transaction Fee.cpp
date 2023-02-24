// -----Approach 1: Memoization ------------------------------------------------------------

/*
    Problem Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/
    
    Time: 249 ms (Beats 37.14%), Space: 94.8 MB (Beats 25.94%)
*/

class Solution {
private:
    int sol(int idx, int buy, vector<int>& prices, vector<vector<int>>& dp, int fee){
        if(idx == prices.size())    return 0;

        if(dp[idx][buy] != -1)  return dp[idx][buy];
        if(buy)
            return dp[idx][buy]= max(-prices[idx] + sol(idx+1, 0, prices, dp, fee), sol(idx+1, 1, prices, dp, fee));
        else
            return dp[idx][buy]= max(prices[idx] -fee + sol(idx+1, 1, prices, dp, fee), sol(idx+1, 0, prices, dp, fee));
    }
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n= prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));

        // if we can buy -> 1   , if we cant buy -> 0
        return sol(0, 1, prices, dp, fee);   
    }
};

// -----Approach 2: Tabulation ------------------------------------------------------------

/*
    Problem Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/
    
    Time: 243 ms (Beats 42.74%), Space: 90.8 MB (Beats 52%)
*/

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n= prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2, 0));   

        for(int idx=n-1; idx>=0; idx--){
                
            dp[idx][1]= max(-prices[idx] + dp[idx+1][0], dp[idx+1][1]);     // we can also deduct the fee when buying, it would mean the same
                
            dp[idx][0]= max(prices[idx] - fee + dp[idx+1][1], dp[idx+1][0]);

        }
        
        return dp[0][1];  
    }
};

// -----Approach 3: Space Optimization ------------------------------------------------------------

/*
    Problem Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/
    
    Time: 127 ms (Beats 71.48%), Space: 55.1 MB (Beats 83.90%)
*/

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n= prices.size();
        vector<int> front(2, 0), curr(2, 0);      

        front[0] = front[1] = 0;

        for(int idx=n-1; idx>=0; idx--){
            
            curr[1]= max(-prices[idx] - fee + front[0], front[1]);
            
            curr[0]= max(prices[idx] + front[1], front[0]);

            front= curr;
        }
        
        return front[1];  
    }
};

// -----Approach 4: Space Optimization (4 variables) ------------------------------------------------------

/*
    Problem Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/
    
    Time: 97 ms (Beats 97.6%), Space: 54.8 MB (Beats 99.33%)
*/

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n= prices.size();
                                                                
        int frontBuy= 0, frontBuyNot= 0, currBuy, currBuyNot;    
                                                                
        for(int idx=n-1; idx>=0; idx--){                        
            
            currBuy= max(-prices[idx] - fee + frontBuyNot, frontBuy);

            currBuyNot= max(prices[idx] + frontBuy, frontBuyNot);

            frontBuyNot= currBuyNot;
            frontBuy= currBuy;
        }
        
        return frontBuy; 
    }
};