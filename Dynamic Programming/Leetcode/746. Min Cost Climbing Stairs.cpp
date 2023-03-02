// -----Approach 1: Memoization ------------------------------------------------------------

/*
    Problem Link: https://leetcode.com/problems/min-cost-climbing-stairs/
    
    Time: 8 ms (Beats 46%), Space: 13.7 MB (Beats 83.61%)
*/

class Solution {
private:
    int sol(int idx, vector<int>& cost, vector<int>& dp){
        int n= cost.size();

        if(idx==0 || idx==1)    return 0;
        
        if(dp[idx] != -1)   return dp[idx];
        for(int i=2; i<=n; i++){
            int oneSteps= cost[i-1] + sol(i-1, cost, dp);
            int twoSteps= cost[i-2] + sol(i-2, cost, dp);
            dp[i]= min(oneSteps, twoSteps);
        }
        return dp[n];
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n= cost.size();
        vector<int> dp(n+1, -1);

        return sol(n, cost, dp);
    }
};

// -----Approach 2: Tabulation ------------------------------------------------------------

/*
    Problem Link: https://leetcode.com/problems/min-cost-climbing-stairs/
    
    Time: 7 ms (Beats 69.48%), Space: 13.9 MB (Beats 34.42%)
*/

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n= cost.size();
        vector<int> dp(n+1, 0);
        dp[0]=0, dp[1]=0;

        if(n==0 || n==1)    return dp[n];

        for(int i=2; i<=n; i++){
            int oneSteps= cost[i-1] + dp[i-1];
            int twoSteps= cost[i-2] + dp[i-2];
            dp[i]= min(oneSteps, twoSteps);
        }
        return dp[n];
    }
};

// -----Approach 3: Space Optimization ------------------------------------------------------------

/*
    Problem Link: https://leetcode.com/problems/min-cost-climbing-stairs/
    
    Time: 3 ms (Beats 95.22%), Space: 13.7 MB (Beats 57.74%)
*/

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n= cost.size();
        int prev2= 0, prev= 0;

        if(n==0 || n==1)    return 0;

        for(int i=2; i<=n; i++){
            int two= cost[i-2] + prev2;
            int one= cost[i-1] + prev;
            int curr= min(one, two);
            prev2= prev;
            prev= curr; 
        }
        return prev;
    }
};