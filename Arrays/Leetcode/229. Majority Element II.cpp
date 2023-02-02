// -----Approach 1: using map ------------------------------------------------------------

/*
    Problem Link: https://leetcode.com/problems/majority-element-ii/
    
    Time: 20 ms (Beats 40.12%), Space: 16 MB (Beats 16.83%)
*/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        map<int,int> mpp;

        for(auto i: nums)   mpp[i]++;
        
        vector<int> ans;
        for(auto it: mpp)   
            if( it.second > nums.size()/3 )  
                ans.push_back(it.first);
        
        return ans;
    }
};        

// -----Approach 2: using Boyer Moore Voting Algorithm ------------------------------------------------------------

/*
    Problem Link: https://leetcode.com/problems/majority-element-ii/
    
    Time: 16 ms (Beats 62.49%), Space: 16 MB (Beats 56.76%)
*/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1= 0, cnt2= 0, num1= -1, num2= -1;
        
        for(auto i: nums){
            if(num1 == i)   cnt1++;
            else if(num2 == i)  cnt2++;
            else if(cnt1 == 0){
                num1= i;
                cnt1++;
            }
            else if(cnt2 == 0){
                num2= i;
                cnt2++;
            }
            else{
                cnt1--;
                cnt2--;
            }
        }
        cnt1= 0, cnt2= 0;
        for(auto i: nums){
            if(i == num1)   cnt1++;
            else if(i == num2)  cnt2++;
        }
        
        vector<int> v;
        
        if(cnt1 > nums.size()/3)   v.push_back(num1);
        if(cnt2 > nums.size()/3)   v.push_back(num2);
        
        return v;
    }
};