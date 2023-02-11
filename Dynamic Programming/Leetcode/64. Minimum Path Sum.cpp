// -----Approach 1: Memoization ------------------------------------------------------------

/*
    Problem Link: https://leetcode.com/problems/minimum-path-sum/
    
    Time: 6 ms (Beats 94.28%), Space: 10.2 MB (Beats 6.73%)
*/

class Solution {
private:
    int sol(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp){
        if(i==0 && j==0)    return grid[i][j];
        if(i<0 || j<0)  return 1e9;

        if(dp[i][j] != -1)  return dp[i][j];
        int up= grid[i][j] + sol(i-1, j, grid, dp);
        int left= grid[i][j] + sol(i, j-1, grid, dp);

        return dp[i][j]= min(up, left);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m= grid.size();
        int n= grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));

        return sol(m-1, n-1, grid, dp);
    }
};

// -----Approach 2: Tabulation ------------------------------------------------------------

/*
    Problem Link: https://leetcode.com/problems/minimum-path-sum/
    
    Time: 10 ms (Beats 72.12%), Space: 10.2 MB (Beats 6.73%)
*/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m= grid.size();
        int n= grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i==0 && j==0)    dp[i][j]= grid[i][j];
                else{
                    int up= grid[i][j];
                    if(i > 0)   up+= dp[i-1][j];
                    else    up+= 1e9;

                    int left= grid[i][j];
                    if(j > 0) left+= dp[i][j-1];
                    else    left+= 1e9;

                    dp[i][j]= min(left, up);
                }
            }
        }

        return dp[m-1][n-1];
    }
};

// -----Approach 3: Space Optimization ------------------------------------------------------------

/*
    Problem Link: https://leetcode.com/problems/minimum-path-sum/
    
    Time: 8 ms (Beats 83.65%), Space: 10.1 MB (Beats 59.22%)
*/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m= grid.size();
        int n= grid[0].size();
        vector<int> prev(n, 0);

        for(int i=0; i<m; i++){
            vector<int> curr(n, 0);
            for(int j=0; j<n; j++){
                if(i==0 && j==0)    curr[j]= grid[i][j];
                else{
                    int up= grid[i][j];
                    if(i > 0)   up+= prev[j];
                    else    up+= 1e9;

                    int left= grid[i][j];
                    if(j > 0) left+= curr[j-1];
                    else    left+= 1e9;

                    curr[j]= min(left, up);
                }
            }
            prev= curr;
        }

        return prev[n-1];
    }
};
