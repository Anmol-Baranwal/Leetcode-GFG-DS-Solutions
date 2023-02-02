/*
    Problem Link: https://leetcode.com/problems/combination-sum/
    
    Time: 5 ms (Beats 78.8%), Space: 10.8 MB (Beats 81.75%)
*/

class Solution {
private:
    void findComb(int idx, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int> &v){
        
        if(idx == arr.size()){
            if(target == 0){
                ans.push_back(v);
            } 
            return;
        }
        
        if(arr[idx] <= target){
            v.push_back(arr[idx]);
            findComb(idx, target - arr[idx], arr, ans, v);
            v.pop_back(); // imp cond
        }
        findComb(idx+1, target, arr, ans, v); // idx+1
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> v;

        findComb(0, target, candidates, ans, v);
        return ans;
    }
};