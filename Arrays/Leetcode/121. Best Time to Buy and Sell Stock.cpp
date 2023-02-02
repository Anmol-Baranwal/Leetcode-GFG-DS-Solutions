/*
    Problem Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
    
    Time: 340 ms (Beats 5.75%), Space: 93.3 MB (Beats 91.1%)
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mxProfit=0, minPrice=INT_MAX;
        for(auto &i: prices){
            minPrice= min(minPrice, i);
            mxProfit=max(mxProfit, i - minPrice); 
        }
        return mxProfit;
    }
};