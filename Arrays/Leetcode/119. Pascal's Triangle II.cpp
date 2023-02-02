/*
    Problem Link: https://leetcode.com/problems/pascals-triangle-ii/
    
    Time: 0 ms (Beats 100%), Space: 6.4 MB (Beats 50.9%)
*/

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans(rowIndex+1, 1);
        
        ans[0] = ans[rowIndex] = 1;
        long long res =1;
        
        for(int i=1; i<rowIndex; i++){
            res*= (rowIndex-i+1);
            res/= (i);
            ans[i]= res;
        }
        
        return ans;
    }
};