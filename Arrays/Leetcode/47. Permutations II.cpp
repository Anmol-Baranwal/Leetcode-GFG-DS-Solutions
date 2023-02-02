// -----Approach 1: using stl ------------------------------------------------------------

/*
    Problem Link: https://leetcode.com/problems/permutations-ii/
    
    Time: 14 ms (Beats 54.52%), Space: 8.3 MB (Beats 98.99%)
*/

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        vector<vector<int>> v;

        do{  
            v.push_back(nums);
        }while( next_permutation(nums.begin(), nums.end()) );
        
        return v;
    }
};

// -----Approach 2: without stl ------------------------------------------------------------

/*
    Problem Link: https://leetcode.com/problems/permutations-ii/
    
    Time: 7 ms (Beats 82.10%), Space: 8.6 MB (Beats 75.19%)
*/

class Solution {
private:
    vector<int> singlePermutation(vector<int>& nums){
        int n=nums.size();
        int i,j;
        
        for(i=n-2; i>=0; i--)
            if(nums[i]<nums[i+1])   break;  
        // here i will be 1st index and i+1 will be 2nd index that will satisfy the cond in forward 
        
        if(i<0) reverse(nums.begin(),nums.end());
        else{
            for(j=n-1; j>i; j--)
                if(nums[j]>nums[i]) break;
            
            swap(nums[i], nums[j]);
            reverse(nums.begin()+i+1, nums.end());
        }
        return nums;
    }
    
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        vector<vector<int>> v;

        vector<int> comp= nums;
        do{  
            v.push_back(nums);
            singlePermutation(nums);
            
            if(nums==comp)  break;
            
        }while( true );
        
        return v;
    }
};