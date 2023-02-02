/*
    Problem Link: https://leetcode.com/problems/combination-sum-ii/
    
    Time: 7 ms (Beats 68.60%), Space: 10.6 MB (Beats 69.25%)
*/

class Solution {
private:
    void findComb(int idx, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int> &v){
        if(target == 0){
            ans.push_back(v);
            return;
        }

        for(int i=idx; i<arr.size(); i++){
            if(i > idx && arr[i] == arr[i-1])   continue; 
            // i>idx  covers duplicate case with first value
            if(arr[i] > target) break;
            v.push_back(arr[i]);
            findComb(i+1, target - arr[i], arr, ans, v); // i+1
            v.pop_back();
        }

    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end()); // imp
        vector<vector<int>> ans;
        vector<int> v;
        findComb(0, target, candidates, ans, v);

        return ans;
    }
};