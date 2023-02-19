/*
    Problem Link: https://practice.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1
*/

// -----Approach 1: Memoization ------------------------------------------------------------

class Solution{
private:
    int sol(int idx,int W, vector<vector<int>>& dp, int val[],int wt[]){
        if(idx==0)  return (W/wt[0])*val[0];
        
        if(dp[idx][W] != -1)    return dp[idx][W];
        
        int notPick= 0 + sol(idx-1, W, dp, val, wt);
        int pick= -1e9;
        if(wt[idx] <= W)  pick= val[idx] + sol(idx, W-wt[idx], dp, val, wt);
            
        return dp[idx][W] = max(pick, notPick);
    }
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        vector<vector<int>> dp(N, vector<int> (W+1, -1));
        
        return sol(N-1, W, dp, val, wt);
    }
};

// -----Approach 2: Tabulation ------------------------------------------------------------

class Solution{
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        vector<vector<int>> dp(N, vector<int> (W+1, 0));;
        
        for(int weight=0; weight<=W; weight++)  dp[0][weight] = (weight/wt[0])*val[0];
            
        for(int idx=1; idx<N; idx++){
            for(int w=0; w<=W; w++){
                
                int notPick= 0 + dp[idx-1][w];
                int pick= 0;
                
                if(wt[idx] <= w)    pick= val[idx] + dp[idx][w - wt[idx]];
                
                dp[idx][w] = max(notPick, pick);
            }
        }
        
        return dp[N-1][W];
    }
};

// -----Approach 3: Space Optimization (Two arrays) ----------------------------------------------------

class Solution{
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        vector<int> prev(W+1, 0), curr(W+1, 0);
        
        for(int weight=0; weight<=W; weight++)  prev[weight] = (weight/wt[0])*val[0];
            
        for(int idx=1; idx<N; idx++){
            for(int w=0; w<=W; w++){
                
                int notPick= 0 + prev[w];
                int pick= 0;
                
                if(wt[idx] <= w)    pick= val[idx] + curr[w - wt[idx]];
                
                curr[w] = max(notPick, pick);
            }
            prev= curr;
        }
        
        return prev[W];
    }
};

// -----Approach 3: Space Optimization (Single array) ----------------------------------------------------

// User function Template for C++

class Solution{
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        vector<int> prev(W+1, 0);
        
        for(int weight=0; weight<=W; weight++)  prev[weight] = (weight/wt[0])*val[0];
            
        for(int idx=1; idx<N; idx++){
            for(int w=0; w<=W; w++){
                
                int notPick= 0 + prev[w];
                int pick= 0;
                
                if(wt[idx] <= w)    pick= val[idx] + prev[w - wt[idx]];
                
                prev[w] = max(notPick, pick);
            }
        }
        
        return prev[W];
    }
};