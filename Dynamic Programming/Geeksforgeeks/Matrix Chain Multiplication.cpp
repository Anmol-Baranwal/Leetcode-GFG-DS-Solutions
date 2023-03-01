/*
    Problem Link: https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1
*/

// -----Approach 1: Memoization ------------------------------------------------------------

class Solution{
private:
    int sol(int i, int j, int arr[], vector<vector<int>>& dp){
        if(i == j)  return 0;
        
        int mi= 1e9;
        if(dp[i][j] != -1)  return dp[i][j];
        for(int k=i; k<j; k++){
            int steps= (arr[i-1] * arr[k] * arr[j]) + sol(i, k, arr, dp) + sol(k+1, j, arr, dp);
            
            mi= min(mi, steps);
        }
        
        return dp[i][j]= mi;
        
    }
public:
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        vector<vector<int>> dp(N, vector<int>(N, -1));
        
        return sol(1, N-1, arr, dp);
    }
};

// -----Approach 2: Tabulation ------------------------------------------------------------

class Solution{
public:
    int matrixMultiplication(int N, int arr[])
    {
        vector<vector<int>> dp(N, vector<int>(N, 0));
        
        // for(int i=1; i<N; i++)  dp[i][i]= 0;    // base case
        
        for(int i=N-1; i>=1; i--){
            for(int j=i+1; j<N; j++){
                int mi= 1e9;
                for(int k=i; k<j; k++){
                    int steps= (arr[i-1] * arr[k] * arr[j]) + dp[i][k] + dp[k+1][j];
                    
                    mi= min(mi, steps);
                }
                dp[i][j]= mi;
            }
        }
        
        return dp[1][N-1];
    }
};