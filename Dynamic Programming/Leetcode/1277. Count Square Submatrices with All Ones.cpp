// -----Approach: Tabulation ------------------------------------------------------------

/*
    Problem Link: https://leetcode.com/problems/count-square-submatrices-with-all-ones/
    
    Time: 77 ms (Beats 57.43%), Space: 26.4 MB (Beats 33.19%)
*/

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n= matrix.size();
        int m= matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));

        for(int i=0; i<n; i++)  dp[i][0]= matrix[i][0];
        for(int j=0; j<m; j++)  dp[0][j]= matrix[0][j];

        for(int i=1; i<n; i++){
            for(int j=1; j<m; j++){
                if(!matrix[i][j])   dp[i][j]= 0;
                else{
                    dp[i][j]= 1 + min(dp[i-1][j], min(dp[i-1][j-1], dp[i][j-1]) );
                } 
            }
        }

        int sum= 0;
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                sum+= dp[i][j];
        
        return sum;
    }
};