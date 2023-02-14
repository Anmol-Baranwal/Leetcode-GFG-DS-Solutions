/*
    Problem Link: https://practice.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1 
*/

// -----Approach 1: Memoization ------------------------------------------------------------

class Solution{   
private:
    bool sol(int idx, int target, vector<vector<int>>& dp, vector<int>& arr){
        if(target == 0) return true;
        if(idx == 0)    return (arr[0] == target);
        
        if(dp[idx][target] != -1)   return dp[idx][target];
        
        bool nonPick= sol(idx-1, target, dp, arr);
        bool pick= false;
        if(target >= arr[idx]){
            pick= sol(idx-1, target - arr[idx], dp, arr);
        }
        
        return dp[idx][target]= pick or nonPick;
    }
public:
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n= arr.size();
        vector<vector<int>> dp(n, vector<int>(sum+1, -1));
        return sol(n-1, sum, dp, arr);
    }
};

// -----Approach 2: Tabulation ------------------------------------------------------------

class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int sum){ 
        int n= arr.size();
        vector<vector<bool>> dp(n, vector<bool>(sum+1, false));
        
        for(int i=0; i<n; i++){
            dp[i][0]= true;         // 1st base condition
        }
        if(arr[0] <= sum)   dp[0][arr[0]]= sum;      // 2nd base condition
        
        for(int idx=1; idx<n; idx++){
            for(int target=1; target<=sum; target++){
                bool nonPick= dp[idx-1][target];
                bool pick= false;
                if(target >= arr[idx]){
                    pick= dp[idx-1][target - arr[idx]];
                }
                
                dp[idx][target]= pick | nonPick;
            }
        }
        return dp[n-1][sum];
    }
};

// -----Approach 3: Space Optimization ------------------------------------------------------------

class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int sum){
        // space optimization -> O(n) from O(sum*n) 
        int n= arr.size();
        vector<bool> prev(sum+1, false), curr(sum+1, false);
        
        prev[0]= true;
        if(arr[0] <= sum)   prev[arr[0]]= sum;      
        
        for(int idx=1; idx<n; idx++){
            curr[0] = true;
            for(int target=1; target<=sum; target++){
                
                bool nonPick= prev[target];
                bool pick= false;
                if(target >= arr[idx]){
                    pick= prev[target - arr[idx]];
                }
                
                curr[target]= pick | nonPick;
            }
            prev= curr;
        }
        return prev[sum];
    }
};

