// -----Approach 1: Memoization ------------------------------------------------------------

/*
    Problem Link: https://leetcode.com/problems/partition-equal-subset-sum/
    
    Time: 321 ms (Beats 57.96%), Space: 95.2 MB (Beats 25.34%)
*/

class Solution {
private:
    bool sol(int idx, int target, vector<vector<int>>& dp, vector<int>& nums){
        if(target == 0) return true;
        if(idx == 0)    return (nums[0] == target);
        
        if(dp[idx][target] != -1)   return dp[idx][target];
        
        bool nonPick= sol(idx-1, target, dp, nums);
        bool pick= false;
        if(target >= nums[idx]){
            pick= sol(idx-1, target - nums[idx], dp, nums);
        }
        
        return dp[idx][target]= pick or nonPick;
    }
public:
    bool canPartition(vector<int>& nums) {
        int sum=0, n= nums.size();
        for(auto &i: nums){
            sum+= i;
        }
        if(sum % 2) return false;

        int target= sum/2;              // target is half of the total sum
        vector<vector<int>> dp(n, vector<int>(target+1, -1));
        return sol(n-1, target, dp, nums);      

    }
};

// -----Approach 2: Tabulation  ------------------------------------------------------------

/*
    Problem Link: https://leetcode.com/problems/partition-equal-subset-sum/
    
    Time: 443 ms (Beats 31.9%), Space: 13.2 MB (Beats 60.59%)
*/

class Solution {
private:
    bool sol(vector<int>& nums, int sum){
        int n= nums.size();
        vector<vector<bool>> dp(n, vector<bool>(sum+1, false));
        
        for(int i=0; i<n; i++){
            dp[i][0]= true;         // 1st base condition
        }
        if(nums[0] <= sum)   dp[0][nums[0]]= sum;      // 2nd base condition
        
        for(int idx=1; idx<n; idx++){
            for(int target=1; target<=sum; target++){
                bool nonPick= dp[idx-1][target];
                bool pick= false;
                if(target >= nums[idx]){
                    pick= dp[idx-1][target - nums[idx]];
                }
                
                dp[idx][target]= pick | nonPick;
            }
        }
        return dp[n-1][sum];
    }
public:
    bool canPartition(vector<int>& nums) {
        int totSum=0, n= nums.size();
        for(auto &i: nums){
            totSum+= i;
        }
        if(totSum % 2) return false;

        int target= totSum/2;              // target is half of the total sum
        return sol(nums, target);      

    }
};

// -----Approach 3: Space Optimization  ------------------------------------------------------------

/*
    Problem Link: https://leetcode.com/problems/partition-equal-subset-sum/
    
    Time: 371 ms (Beats 43.40%), Space: 9.8 MB (Beats 85.85%)
*/

class Solution {
private:
    bool sol(vector<int>& nums, int sum){
        int n= nums.size();
        vector<bool> prev(sum+1, false), curr(sum+1, false);
        
        prev[0]= true;
        if(nums[0] <= sum)   prev[nums[0]]= sum;      
        
        for(int idx=1; idx<n; idx++){
            curr[0] = true;
            for(int target=1; target<=sum; target++){
                
                bool nonPick= prev[target];
                bool pick= false;
                if(target >= nums[idx]){
                    pick= prev[target - nums[idx]];
                }
                
                curr[target]= pick | nonPick;
            }
            prev= curr;
        }
        return prev[sum];
    }
public:
    bool canPartition(vector<int>& nums) {
        int totSum=0, n= nums.size();
        for(auto &i: nums){
            totSum+= i;
        }
        if(totSum % 2) return false;

        int target= totSum/2;              // target is half of the total sum
        return sol(nums, target);      

    }
};
