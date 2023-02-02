// -----Approach 1: using adjacent profit ------------------------------------------------------------

/*
    Problem Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
    
    Time: 9 ms (Beats 64.59%), Space: 13 MB (Beats 63.70%)
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int totalProfit = 0;
        for (int i=1; i<prices.size(); i++) {

            if(prices[i - 1] < prices[i])   totalProfit += prices[i] - prices[i - 1];
        }
        // testcases: [1,2,3,4,5] , [2,1,4,5,2] , [1,2,1,2,7,5,7] , [1,2]
        return totalProfit;
    }
};

// -----Approach 2: general logic ------------------------------------------------------------

/*
    Problem Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
    
    Time: 20 ms (Beats 15.48%), Space: 13.1 MB (Beats 63.77%)
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int minPrice=prices[0];
        int mxProfit=0;
        int totalProfit=0;
        for(int i=0;i<n;i++){
            minPrice= min(minPrice, prices[i]);
            mxProfit= max(mxProfit, prices[i]-minPrice);
            if(i!=n-1 && prices[i+1]<prices[i] && mxProfit>0){
                totalProfit+=mxProfit;
                mxProfit=0;
                minPrice=INT_MAX;
            }
            else if(i==n-1){
                totalProfit+=mxProfit;
            }
            
            // testcases: [1,2,3,4,5] , [2,1,4,5,2] , [1,2,1,2,7,5,7] , [1,2]
        }
        return totalProfit;
    }
};
