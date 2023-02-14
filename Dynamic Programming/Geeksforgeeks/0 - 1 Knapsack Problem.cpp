/*
    Problem Link: https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1
*/

// -----Approach 1: Memoization ------------------------------------------------------------

class Solution
{
    private:
    int sol(int idx, int W, vector<vector<int>>& dp, int wt[], int val[]){
        if(idx == 0){
            if(wt[0] <= W)  return val[0];
            else    return 0;
        }
        
        if(dp[idx][W] != -1)    return dp[idx][W];
        int notPick= 0 + sol(idx-1, W, dp, wt, val);
        int pick= -1e9;
        if(wt[idx] <= W)    
            pick= val[idx] + sol(idx-1, W - wt[idx], dp, wt, val);
            
        return dp[idx][W]= max(notPick, pick);
        
    }
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>> dp(n, vector<int>(W+1, -1));
       
       return sol(n-1, W, dp, wt, val);
    }
};

// -----Approach 2: Tabulation ------------------------------------------------------------

class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>> dp(n, vector<int>(W+1, 0));
       
       for(int i= wt[0]; i<=W; i++) dp[0][i]= val[0];
       
       for(int idx=1; idx<n; idx++){
           for(int weight=0; weight<=W; weight++){
               int notPick= 0 + dp[idx-1][weight];
                int pick= -1e9;
                if(wt[idx] <= weight)    
                    pick= val[idx] + dp[idx-1][ weight-wt[idx] ];
                    
                dp[idx][weight]= max(notPick, pick);
            }
       }
       
       return dp[n-1][W];
    }
};

// -----Approach 3: Space Optimization ------------------------------------------------------------

class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Space optimisation from O(W*n) to O(W)
       
       vector<int> prev(W+1, 0), curr(W+1, 0);
       
       for(int i= wt[0]; i<=W; i++) prev[i]= val[0];
       
       for(int idx=1; idx<n; idx++){
           for(int weight=0; weight<=W; weight++){
               int notPick= 0 + prev[weight];
                int pick= -1e9;
                if(wt[idx] <= weight)    
                    pick= val[idx] + prev[ weight-wt[idx] ];
                    
                curr[weight]= max(notPick, pick);
            }
            prev= curr;
       }
       
       return prev[W];
    }
};

// -----Approach 4: More Space Optimization ------------------------------------------------------------

class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Space optimisation from two array to single array
       
       vector<int> prev(W+1, 0);
       
       for(int i= wt[0]; i<=W; i++) prev[i]= val[0];
       
       for(int idx=1; idx<n; idx++){
           for(int weight=W; weight>=0; weight--){      // only right to left will work otherwise the values will override in prev array
               int notPick= 0 + prev[weight];
                int pick= -1e9;
                if(wt[idx] <= weight)    
                    pick= val[idx] + prev[ weight-wt[idx] ];
                    
                prev[weight]= max(notPick, pick);
            }
       }
       
       return prev[W];
    }
};
