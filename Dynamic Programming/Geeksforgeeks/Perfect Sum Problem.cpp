/*
    Problem Link: https://practice.geeksforgeeks.org/problems/perfect-sum-problem5633/1
*/

// -----Approach 1: Memoization ------------------------------------------------------------\

class Solution{
    private:
        int mod= 1e9+7; // 1000000007;
	      int sol(int idx, int sum, vector<vector<int>>& dp, vector<int>& arr){
            
            if(sum == 0)    return 1;
            if(idx == 0)    return (arr[0] == sum);
            
            if(dp[idx][sum] != -1)  return dp[idx][sum];
            
            int notPick= sol(idx-1, sum, dp, arr)%mod;
            int pick= 0;
            if(arr[idx] <= sum) pick= sol(idx-1, sum - arr[idx], dp, arr)%mod;
            
            return dp[idx][sum] = ((pick + notPick)%mod);
        }
	public:
        
	    int perfectSum(int arr[], int n, int sum)
	    {
            // Your code goes here
            vector<int> temp;
            int cntZero = 0;
            
            for(int i = 0; i < n; i++)
                if(arr[i] != 0) temp.push_back(arr[i]);
                else    cntZero++;          // array can include zero so use different logic to handle this
                    
            int size = temp.size();
            vector<vector<int>> dp(size, vector<int> (sum+1, -1));
            
            int mult = (int)(pow(2, cntZero))%mod;      // we can calculate the no of combinations if there are n zeros, just 2*n with the result
            return ( ( sol(size-1, sum, dp, temp)*mult )%mod );
	    }
	  
};

// -----Approach 2: Memoization ------------------------------------------------------------\

class Solution{
    private:
        int mod= 1e9+7; // 1000000007;
	    int sol(int idx, int sum, vector<vector<int>>& dp, int arr[]){
            
            if(idx == 0){
                if(sum == 0 && arr[0] == 0) return 2;
                if(sum ==0 || sum == arr[0])    return 1;
                return 0;
            }
            
            if(dp[idx][sum] != -1)  return dp[idx][sum];
            
            int notPick= sol(idx-1, sum, dp, arr)%mod;
            int pick= 0;
            if(arr[idx] <= sum) pick= sol(idx-1, sum - arr[idx], dp, arr)%mod;
            
            return dp[idx][sum] = ((pick + notPick)%mod);
        }
	public:
        
	    int perfectSum(int arr[], int n, int sum)
	    {
            // Your code goes here
            
            vector<vector<int>> dp(n, vector<int> (sum+1, -1));
            
            return sol(n-1, sum, dp, arr)%mod;
	    }
	  
};

// -----Approach 3: Tabulation ------------------------------------------------------------\

class Solution{
	public:
        
	    int perfectSum(int arr[], int n, int sum)
	    {
            // Your code goes here
            int mod = 1e9+7;
            int dp[n+1][sum+1];
            for(int i=0; i<n+1; i++) dp[i][0]=1;
            for(int j=1; j<sum+1; j++) dp[0][j]=0;
            
            for(int i=1; i<n+1; i++){
                for(int s=0; s<=sum; s++){
                    if(arr[i-1] <= s){
                        dp[i][s]= (dp[i-1][s-arr[i-1]] + dp[i-1][s])%mod;
                    }
                    else{
                        dp[i][s]=(dp[i-1][s]) %mod;
                    }
                }
            }
            return dp[n][sum];
	    }
	  
};
