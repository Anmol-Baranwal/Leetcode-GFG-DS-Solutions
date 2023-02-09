// -----Approach 1: Space Optimisation ------------------------------------------------------------

/*
    Problem Link: https://leetcode.com/problems/climbing-stairs/
    
    Time: 0 ms (Beats 100%), Space: 6 MB (Beats 42.22%)
*/

class Solution {
public:
    int climbStairs(int n) {
        
        int prev2=0, prev=1, curr;

        if(n<=1)    return 1;

        for(int i=1; i<=n; i++){    // we can also run from 2 -> n+1 according to the problem
            curr= prev + prev2;
            prev2= prev;
            prev= curr;
        }
        return curr;
    }
};

// -----Approach 2: Memoization ------------------------------------------------------------

/*
    Problem Link: https://leetcode.com/problems/climbing-stairs/
    
    Time: 0 ms (Beats 100%), Space: 6.2 MB (Beats 31.2%)
*/

class Solution {
private:
    int count(int idx, vector<int>& dp){
        if(idx == 0 || idx == 1)    return 1;

        if(dp[idx] != -1)   return dp[idx];
        return dp[idx]= count(idx-1, dp) + count(idx-2, dp);
    }
public:
    int climbStairs(int n) {
        if(n==0 || n==1)    return 1;
        
        vector<int> dp(n+1, -1);
        return count(n, dp);
    }
};

// -----Approach 2: Tabulation ------------------------------------------------------------

/*
    Problem Link: https://leetcode.com/problems/climbing-stairs/
    
    Time: 0 ms (Beats 100%), Space: 6.3 MB (Beats 17.24%)
*/

class Solution {
public:
    int climbStairs(int n) {
        
        vector<int> dp(n+1, -1);
        dp[0]=1, dp[1]=1;

        if(n==0 || n==1)    return dp[n];

        for(int i=2; i<=n; i++){
            dp[i]= dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};
