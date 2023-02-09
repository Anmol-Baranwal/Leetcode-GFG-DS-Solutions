// -----Approach: Soace optimisation ------------------------------------------------------------

/*
    Problem Link: https://leetcode.com/problems/house-robber-ii/
    
    Time: 5 ms (Beats 26.14%), Space: 7.9 MB (Beats 67.60%)
*/

class Solution {
private:
    int nonAdjacentSum(vector<int>& nums){
        int n= nums.size();
        int prev= nums[0];
        int prev2= 0;
        for(int i=1; i<n; i++){
            int pick= nums[i];
            if(i>1) pick+= prev2;

            int nonPick= 0 + prev;
            
            int curr= max(pick, nonPick);
            prev2= prev;
            prev= curr;
        }
        return prev;
    }
public:
    int rob(vector<int>& nums) {
        int n= nums.size();
        if(n==1)    return nums[0];

        vector<int> temp1, temp2;
        for(int i=0; i<n; i++){
            // excluding 1st element
            if( i!=0 )  temp1.push_back(nums[i]);
            // excluding last element
            if( i!=n-1 )    temp2.push_back(nums[i]);
        }
        return max(nonAdjacentSum(temp1), nonAdjacentSum(temp2));
    }
};
