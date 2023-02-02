// -----Approach 1: using set ------------------------------------------------------------

/*
    Problem Link: https://leetcode.com/problems/set-mismatch/
    
    Time: 84 ms (Beats 38.18%), Space: 33.1 MB (Beats 10.79%)
*/

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n=nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        vector<int> ans;
        set<int> s;
        for(auto &i: nums)   s.insert(i);
        
        int sumSet = accumulate(s.begin(), s.end(), 0);
        ans.push_back(sum-sumSet);
        
        ans.push_back( n*(n+1)/2 - sumSet );
        
        return ans;
    }
};

// -----Approach 2: using map ------------------------------------------------------------

/*
    Problem Link: https://leetcode.com/problems/set-mismatch/
    
    Time: 179 ms (Beats 7.27%), Space: 32.9 MB (Beats 15.76%)
*/

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n=nums.size();
        int sum=(n*(n+1))/2;
        vector<int> ans;
        map<int,int> mpp;
        for(auto i: nums)   mpp[i]++;
        
        for(auto it: mpp){
            if(it.second > 1)    ans.push_back(it.first);
            sum-=it.first;
        }
        ans.push_back(sum);
        
        return ans;
    }
};

// -----Approach 3: using XOR ------------------------------------------------------------

/*
    Problem Link: https://leetcode.com/problems/set-mismatch/
    
    Time: 2 ms (Beats 7.27%), Space: 43.9 MB (Beats 93.24%)
*/

class Solution {
    public int[] findErrorNums(int[] nums) {
        int n = nums.length;
        int[] count = new int[n];
        int[] ans = {0,0};
        for(int i = 0; i < n; i++) {
            ans[1] ^= (i+1) ^ nums[i];
            if (++count[nums[i]-1] == 2)
                ans[0] = nums[i];
        }
        ans[1] ^= ans[0];
        return ans;
    }
}

// -----Approach 4: using Maths ------------------------------------------------------------

/*
    Problem Link: https://leetcode.com/problems/set-mismatch/
    
    Time: 59 ms (Beats 56.8%), Space: 21.4 MB (Beats 88.14%)
*/

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        long diff = 0;
        long square_diff = 0;
        for (int i = 0; i < size(nums); ++i) {
            diff += i + 1 - nums[i];
            square_diff += (i + 1) * (i + 1) - nums[i] * nums[i];
        }
        long s = square_diff / diff;
        const int dup = (s - diff) / 2;
        const int miss = (s + diff) / 2;
        return {dup, miss};
    }
};