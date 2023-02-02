/*
    Problem Link: https://leetcode.com/problems/rotate-image/
    
    Time: 0 ms (Beats 100%), Space: 7.1 MB (Beats 75.94%)
*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int m= matrix.size();
        
        for(int i=0;i<m;i++)
            for(int j=0;j<i;j++)
                swap(matrix[i][j], matrix[j][i]);
        
        for(int i=0;i<m;i++)
            reverse(matrix[i].begin(), matrix[i].end());
        
    }
};