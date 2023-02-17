/*
    Problem Link: https://practice.geeksforgeeks.org/problems/rod-cutting0840/1 
*/

// -----Approach 1: Memoization (Time Limit Exceeded) ------------------------------------------------------------

class Solution{
  private:
    int sol(int idx, int tar, vector<vector<int>>& dp, int price[]){
        if(idx == 0)    return tar*price[0];
        
        if(dp[idx][tar] != -1)  return dp[idx][tar];
        int notPick= 0 + sol(idx-1, tar, dp, price);
        int pick= -1e9;
        int rodLength= idx + 1; // consider it a 0 based indexing
        if(rodLength <= tar)    pick= price[idx] + sol(idx, tar - rodLength, dp, price);
        
        return max(pick, notPick);
    }
  public:
    int cutRod(int price[], int n) {
        //code here
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        
        return sol(n-1, n, dp, price);
    }
};

// -----Approach 2: Tabulation ------------------------------------------------------------

class Solution{
  public:
    int cutRod(int price[], int n) {
        //code here
        vector<vector<int>> dp(n, vector<int>(n+1, 0));
        
        for(int i=0; i<=n; i++)  dp[0][i]= i*price[0];
        
        for(int idx=1; idx<n; idx++){
            for(int T=0; T<=n; T++){
                int notPick= 0 + dp[idx-1][T];
                int pick= -1e9;
                int rodLength= idx + 1; // consider it a 0 based indexing
                if(rodLength <= T)    pick= price[idx] + dp[idx][T - rodLength];
                
                dp[idx][T] = max(pick, notPick);
            }
        }
        return dp[n-1][n];
    }
};

// -----Approach 3: Space Optimization ------------------------------------------------------------

class Solution{
  public:
    int cutRod(int price[], int n) {
        //code here
        vector<int> prev(n+1, 0);
        
        for(int i=0; i<=n; i++)  prev[i]= i*price[0];
        
        for(int idx=1; idx<n; idx++){
            for(int T=0; T<=n; T++){
                int notPick= 0 + prev[T];
                int pick= -1e9;
                int rodLength= idx + 1; // consider it a 0 based indexing
                if(rodLength <= T)    pick= price[idx] + prev[T - rodLength];
                
                prev[T] = max(pick, notPick);
            }
        }
        return prev[n];
    }
};