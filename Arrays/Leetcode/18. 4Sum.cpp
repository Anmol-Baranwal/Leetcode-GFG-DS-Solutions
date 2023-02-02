/*
    Problem Link: https://leetcode.com/problems/4sum/
    
    Time: 51 ms (Beats 88.4%), Space: 13.2 MB (Beats 87.57%)
*/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        vector<vector<int>> res;
    
        if (nums.empty())   return res;
        sort(nums.begin(), nums.end());
        int n=nums.size();
    
        for (int i=0; i<n; i++) {
        
            for (int j=i+1; j<n; j++) {
            
                long long rem = (long long)target - (long long)nums[i] - (long long)nums[j];
            
                int start= j + 1;
                int end= n - 1;
            
                while(start < end) {
                
                    int two_sum = nums[start] + nums[end];
                
                    if (two_sum < rem) start++;
                
                    else if (two_sum > rem) end--;
                
                    else {
                    
                        vector<int> ans(4, 0);
                        ans[0] = nums[i];
                        ans[1] = nums[j];
                        ans[2] = nums[start];
                        ans[3] = nums[end];
                        res.push_back(ans);
                    
                        while (start < end && nums[start] == ans[2]) ++start;
                    
                        while (start < end && nums[end] == ans[3]) --end;
                    }
                }
                while(j+1 < n && nums[j + 1] == nums[j]) ++j;
            }
            while (i+1 < n && nums[i + 1] == nums[i]) ++i;
        
        }
            return res;
    }
};