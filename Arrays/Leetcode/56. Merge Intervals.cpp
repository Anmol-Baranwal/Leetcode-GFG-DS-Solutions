/*
    Problem Link: https://leetcode.com/problems/merge-intervals/
    
    Time: 76 ms (Beats 30.98%), Space: 20.1 MB (Beats 17.71%)
*/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> mergeInt;
        if(intervals.size()==0) return mergeInt;
        
        sort(intervals.begin(),intervals.end());
        vector<int> work= intervals[0];
        
        for(auto v: intervals){
            if(v[0]<=work[1])   work[1]= max(work[1],v[1]); // [1,3] & [2,6] so if 2 is less than 3 then merge
            else{
                mergeInt.push_back(work);  // otherwise put the pair in merge intervals and move on to next
                work= v;
            }
        }
        mergeInt.push_back(work);
        return mergeInt;
    }
};