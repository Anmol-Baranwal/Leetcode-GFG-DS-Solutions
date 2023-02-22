// -----Approach 1: Memoization ------------------------------------------------------------

/*
    Problem Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
    
    Time: 14 ms (Beats 30.26%), Space: 17.2 MB (Beats 6.83%)
*/

class Solution {
private:
    int sol(int idx, int buy, vector<int>& prices, vector<vector<int>>& dp){
        if(idx == prices.size())    return 0;

        if(dp[idx][buy] != -1)  return dp[idx][buy];
        if(buy)
            return dp[idx][buy]= max(-prices[idx] + sol(idx+1, 0, prices, dp), sol(idx+1, 1, prices, dp));
        else
            return dp[idx][buy]= max(prices[idx] + sol(idx+1, 1, prices, dp), sol(idx+1, 0, prices, dp));
    }
public:
    int maxProfit(vector<int>& prices) {
        
        int n= prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));

        // if we can buy -> 1   , if we cant buy -> 0
        return sol(0, 1, prices, dp);
    }
};

// -----Approach 2: Memoization ------------------------------------------------------------

/*
    Problem Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
    
    Time: 21 ms (Beats 8.50%), Space: 17.3 MB (Beats 7.82%)
*/

class Solution {
private:
    int sol(int idx, int buy, vector<int>& prices, vector<vector<int>>& dp){
        if(idx == prices.size())    return 0;

        if(dp[idx][buy] != -1)  return dp[idx][buy];
        if(buy){
            int buyYes= -prices[idx] + sol(idx+1, 0, prices, dp);   // we cannot buy now
            int buyNot= sol(idx+1, 1, prices, dp);      // we have the possibility of buying

            return dp[idx][buy]= max(buyYes, buyNot);
        } 
        else{
            int sellYes= prices[idx] + sol(idx+1, 1, prices, dp);
            int sellNot= sol(idx+1, 0, prices, dp);

            return dp[idx][buy]= max(sellYes, sellNot);
        }
    }
public:
    int maxProfit(vector<int>& prices) {
        
        int n= prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));

        // if we can buy -> 1   , if we cant buy -> 0
        return sol(0, 1, prices, dp);
    }
};

// -----Approach 3: Tabulation ------------------------------------------------------------

/*
    Problem Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
    
    Time: 16 ms (Beats 19.71%), Space: 15.2 MB (Beats 22.49%)
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n= prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2, 0));   

        for(int idx=n-1; idx>=0; idx--){
                
            // we can omit buy for loop since each if else will run once
            dp[idx][1]= max(-prices[idx] + dp[idx+1][0], dp[idx+1][1]);
                
            dp[idx][0]= max(prices[idx] + dp[idx+1][1], dp[idx+1][0]);

        }
        
        return dp[0][1];
    }
};

// -----Approach 4: Space Optimization ------------------------------------------------------------

/*
    Problem Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
    
    Time: 7 ms (Beats 75.48%), Space: 13.1 MB (Beats 65.55%)
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n= prices.size();
                                                                //  ----------------------------
        int frontBuy= 0, frontBuyNot= 0, currBuy, currBuyNot;   //  | currBuyNot | frontBuyNot |     we would only need front to calculate curr 
                                                                //  | currBuy    | frontBuy    |     we exchange values to calculate next set
        for(int idx=n-1; idx>=0; idx--){                        //  ----------------------------
            
            currBuy= max(-prices[idx] + frontBuyNot, frontBuy);

            currBuyNot= max(prices[idx] + frontBuy, frontBuyNot);

            frontBuyNot= currBuyNot;
            frontBuy= currBuy;
        }
        
        return frontBuy;
    }
};

// -----Approach 5: Space Optimization ------------------------------------------------------------

/*
    Problem Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
    
    Time: 4 ms (Beats 86.80%), Space: 13.1 MB (Beats 22.49%)
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n= prices.size();
        vector<int> front(2, 0), curr(2, 0);      

        front[0] = front[1] = 0;

        for(int idx=n-1; idx>=0; idx--){
            
            curr[1]= max(-prices[idx] + front[0], front[1]);
            
            curr[0]= max(prices[idx] + front[1], front[0]);

            front= curr;
        }
        
        return front[1];
    }
};