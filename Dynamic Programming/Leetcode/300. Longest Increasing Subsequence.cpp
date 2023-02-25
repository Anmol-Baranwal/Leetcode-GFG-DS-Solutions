// -----Approach 1: Memoization ------------------------------------------------------------

/*
    Problem Link: https://leetcode.com/problems/longest-increasing-subsequence/
    
    Time: 1471 ms (Beats 10.5%), Space: 292.3 MB (Beats 17.37%)
*/

class Solution {
private:
    int sol(int idx, int prevIdx, vector<vector<int>>& dp, vector<int>& nums){
        if(idx == nums.size())  return 0;

        if(dp[idx][prevIdx+1] != -1)  return dp[idx][prevIdx+1];

        int notPick= sol(idx+1, prevIdx, dp, nums);
        int pick= 0;
        if(prevIdx == -1 || nums[prevIdx] < nums[idx])
            pick= 1 + sol(idx+1, idx, dp, nums);

        return dp[idx][prevIdx+1]= max(pick, notPick);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        
        int n= nums.size();
        vector<vector<int>> dp(n, vector<int>(n+1, -1));

        return sol(0, -1, dp, nums);
    }
};

// -----Approach 2: Tabulation ------------------------------------------------------------

/*
    Problem Link: https://leetcode.com/problems/longest-increasing-subsequence/
    
    Time: 688 ms (Beats 26.10%), Space: 292.2 MB (Beats 17.37%)
*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        int n= nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

        // no need for base case since dp is inititalised to 0

        for(int idx=n-1; idx>=0; idx--){
            for(int prevIdx= idx-1; prevIdx>=-1; prevIdx--){
                int notPick= dp[idx+1][prevIdx+1];  // second parameter is stored as in + 1 state
                int pick= 0;
                if(prevIdx == -1 || nums[prevIdx] < nums[idx])
                    pick= 1 + dp[idx+1][idx+1];
        
                dp[idx][prevIdx+1]= max(pick, notPick);
            }
        }

        return dp[0][0];    // second parameter: -1 + 1
    }
};

// -----Approach 3: Space Optimization ------------------------------------------------------------

/*
    Problem Link: https://leetcode.com/problems/longest-increasing-subsequence/
    
    Time: 438 ms (Beats 37.30%), Space: 10.7 MB (Beats 32.53%)
*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        int n= nums.size();
        vector<int> front(n+1, 0), curr(n+1, 0);

        for(int idx=n-1; idx>=0; idx--){
            for(int prevIdx= idx-1; prevIdx>=-1; prevIdx--){
                int notPick= front[prevIdx+1];  // second parameter is stored as in + 1 state
                int pick= 0;
                if(prevIdx == -1 || nums[prevIdx] < nums[idx])
                    pick= 1 + front[idx+1];
        
                curr[prevIdx+1]= max(pick, notPick);
            }
            front= curr;
        }

        return front[0];    // second parameter: -1 + 1
    }
};

// ------------------ NOT DP APPROACH ---------------------------------

// -----Approach 4: Binary Search: O(nlogn) ------------------------------------------------------------

/*
    Problem Link: https://leetcode.com/problems/longest-increasing-subsequence/
    
    Time: 11 ms (Beats 86.25%), Space: 10.3 MB (Beats 93.20%)
*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        int n= nums.size();
        vector<int> v;       
        v.push_back(nums[0]);
        
        int cnt= 1;
        for(int idx=1; idx<n; idx++){
            if(nums[idx] > v.back()){
                v.push_back(nums[idx]);
                cnt++;
            }   
            else {
                int i= lower_bound(v.begin(), v.end(), nums[idx]) - v.begin();
                v[i]= nums[idx];
            }
        }

        return cnt;     // can also return v.size() : S.C. will decrease & T.c. will increase
    }
};