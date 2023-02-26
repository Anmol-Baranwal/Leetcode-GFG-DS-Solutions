/*
    Problem Link: https://practice.geeksforgeeks.org/problems/longest-bitonic-subsequence0824/1
*/

// -----Approach 1: Tabulation ------------------------------------------------------------

class Solution{
	public:
	int LongestBitonicSequence(vector<int>nums)
	{
	    int n= nums.size();
        vector<int> dp1(n, 1), dp2(n, 1);     

        for(int idx=0; idx<n; idx++){
            for(int prevIdx= 0; prevIdx<idx; prevIdx++){    

                if(nums[prevIdx] < nums[idx] && dp1[idx] < 1 + dp1[prevIdx])
                    dp1[idx]= 1 + dp1[prevIdx];    
            }
        }
        
        int mx= 0;
        for(int idx=n-1; idx>=0; idx--){        // for reverse
            for(int prevIdx= n-1; prevIdx>idx; prevIdx--){    

                if(nums[prevIdx] < nums[idx] && dp2[idx] < 1 + dp2[prevIdx])
                    dp2[idx]= 1 + dp2[prevIdx];    
            }
            mx= max(mx, dp2[idx] + dp1[idx] - 1);   
            // length from left (dp1) + max length from right (dp2) - 1 (current element is added twice) 
            // maximum of this would be the longest bitonic sequence
        }
        
        return mx;
	}
};