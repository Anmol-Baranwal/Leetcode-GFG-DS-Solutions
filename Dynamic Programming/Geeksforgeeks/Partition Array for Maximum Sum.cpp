/*
    Problem Link: https://practice.geeksforgeeks.org/problems/partition-array-for-maximum-sum/1
*/

// -----Approach 1: Memoization ------------------------------------------------------------

class Solution{
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
    int solve(int n, int k, vector<int>& arr){
        vector<int> dp(n, -1);

        return sol(0, k, arr, dp);
    }
};

// -----Approach 2: Tabulation ------------------------------------------------------------

class Solution{
    public:
    int solve(int n, int k, vector<int>& arr){
    
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