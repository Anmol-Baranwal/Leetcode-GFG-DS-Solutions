// -----Approach 1: Memoization ------------------------------------------------------------

/*
    Problem Link: https://leetcode.com/problems/target-sum/
    
    Time: 19 ms (Beats 65.96%), Space: 12 MB (Beats 46.87%)
*/

class Solution {
private:
    int sol(int idx, int target, vector<vector<int>>& dp, vector<int>& nums){
        if(idx == 0){
            if(target == 0 && nums[0] == 0) return 2;
            if(target ==0 || target == nums[0])    return 1;
            return 0;
        }
        
        if(dp[idx][target] != -1)  return dp[idx][target];
        
        int notPick= sol(idx-1, target, dp, nums);
        int pick= 0;
        if(nums[idx] <= target) pick= sol(idx-1, target - nums[idx], dp, nums);
        
        return dp[idx][target] = pick + notPick;
    }
    
public:
    // we just need to find all such pairs of subsets whose sum difference is equal to our given target.
    int findTargetSumWays(vector<int>& nums, int target) {
        int n= nums.size();
        
        int totSum=0; 
        for(auto &it: nums)  totSum+= it;

        if( (totSum - target < 0) || ((totSum -target) % 2) )    return false;

        int s2 = (totSum-target)/2;
        vector<vector<int>> dp(n,vector<int>(s2+1,-1));

        return sol(n-1, s2, dp, nums);
    }
};

// -----Approach 2: Tabulation ------------------------------------------------------------

/*
    Problem Link: https://leetcode.com/problems/target-sum/
    
    Time: 18 ms (Beats 67.52%), Space: 12 MB (Beats 50.79%)
*/

class Solution {
public:
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int n= nums.size();
        
        int totSum=0; 
        for(int i=0; i<n; i++)  totSum+= nums[i];

        if( (totSum - target < 0) || ((totSum -target) % 2) )    return 0;

        int s1 = (totSum-target)/2;             // formula derived when s1 + s2 = totalSum & s1-s2=target
        // we just need to find all such pairs of subsets whose sum difference is equal to s1 (new target).
        vector<vector<int>> dp(n,vector<int>(s1+1, 0));

        if(nums[0] == 0) dp[0][0] =2;  // notPick & pick so 2 cases
        else dp[0][0] = 1;            // notPick
        if(nums[0]!=0 && nums[0]<=s1) dp[0][nums[0]] = 1;  // pick

        for(int idx= 1; idx<n; idx++){
            for(int T= 0; T<=s1; T++){

                int notPick = dp[idx-1][T];

                int pick = 0;
                if(nums[idx]<=T)    pick = dp[idx-1][T-nums[idx]];

                dp[idx][T]= notPick + pick;
            }
        }
        return dp[n-1][s1];
    }
};

// -----Approach 2: Space Optimization ------------------------------------------------------------

/*
    Problem Link: https://leetcode.com/problems/target-sum/
    
    Time: 12 ms (Beats 82.97%), Space: 9.6 MB (Beats 55.8%)
*/

class Solution {
public:
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int n= nums.size();
        
        int totSum=0; 
        for(int i=0; i<n; i++)  totSum+= nums[i];

        if( (totSum - target < 0) || ((totSum -target) % 2) )    return 0;

        int s1 = (totSum-target)/2;             // formula derived when s1 + s2 = totalSum & s1-s2=target
        // we just need to find all such pairs of subsets whose sum difference is equal to s1 (new target).
        vector<int> prev(s1+1, 0), curr(s1+1, 0);

        if(nums[0] == 0) prev[0] =2;  // notPick & pick so 2 cases
        else prev[0] = 1;            // notPick
        if(nums[0]!=0 && nums[0]<=s1) prev[nums[0]] = 1;  // pick

        for(int idx= 1; idx<n; idx++){
            for(int T= 0; T<=s1; T++){

                int notPick = prev[T];

                int pick = 0;
                if(nums[idx]<=T)    pick = prev[T-nums[idx]];

                curr[T]= notPick + pick;
            }
            prev= curr;
        }
        return prev[s1];
    }
};
