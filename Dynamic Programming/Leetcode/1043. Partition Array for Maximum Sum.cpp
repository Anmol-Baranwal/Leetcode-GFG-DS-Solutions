// -----Approach 1: Memoization ------------------------------------------------------------

/*
    Problem Link: https://leetcode.com/problems/partition-array-for-maximum-sum/
    
    Time: 21 ms (Beats 49.69%), Space: 8.6 MB (Beats 76.38%)
*/

class Solution {
private:
    int sol(int i, int k, vector<int>& arr, vector<int>& dp){
        int n= arr.size();
        if(i == n)  return 0;

        if(dp[i] != -1) return dp[i];
        int mx= -1e9, ans= 0;
        for(int j= i; j< min(i+k, n); j++){
            mx= max(mx, arr[j]);
            int sum= (j-i+1)*mx + sol(j+1, k, arr, dp);
            ans= max(ans, sum);
        }
        return dp[i]= ans;
    }
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int> dp(arr.size(), -1);

        return sol(0, k, arr, dp);
    }
};

// -----Approach 2: Tabulation ------------------------------------------------------------

/*
    Problem Link: https://leetcode.com/problems/partition-array-for-maximum-sum/
    
    Time: 14 ms (Beats 84.42%), Space: 8.5 MB (Beats 76.38%)
*/

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n= arr.size();
        vector<int> dp(n+1, 0);

        for(int i=n-1; i>=0; i--){
            int mx= -1e9, ans= 0;

            for(int j= i; j< min(i+k, n); j++){
                mx= max(mx, arr[j]);
                int sum= (j-i+1)*mx + dp[j+1];      // j-i+1 will be the length of the partition
                ans= max(ans, sum);
            }
            dp[i]= ans;
        }

        return dp[0];
    }
};
