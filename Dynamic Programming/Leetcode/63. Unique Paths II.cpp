// -----Approach 1: Tabulation (1st way -> more efficient) ------------------------------------------------------------

/*
    Problem Link: https://leetcode.com/problems/unique-paths-ii/
    
    Time: 0 ms (Beats 100%), Space: 7.6 MB (Beats 83.74%)
*/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m= obstacleGrid.size();
        int n= obstacleGrid[0].size();
        int dp[m][n];

        if(obstacleGrid[0][0]==1 || obstacleGrid[m-1][n-1]==1)  return 0;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i == 0 && j == 0)    dp[i][j]=1;
                else{
                    int up=0, left=0;
                    if(i>0 && !obstacleGrid[i-1][j]) up= dp[i-1][j];
                    if(j>0 && !obstacleGrid[i][j-1]) left= dp[i][j-1];

                    dp[i][j]= up + left;
                }
            }
        }
        return dp[m-1][n-1];
    }
};

// -----Approach 1: Tabulation (2nd way) ------------------------------------------------------------

/*
    Problem Link: https://leetcode.com/problems/unique-paths-ii/
    
    Time: 7 ms (Beats 34.84%), Space: 7.6 MB (Beats 93.92%)
*/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m= obstacleGrid.size();
        int n= obstacleGrid[0].size();
        int dp[m][n];

        if(obstacleGrid[0][0]==1 || obstacleGrid[m-1][n-1]==1)  return 0;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i == 0 && j == 0)    dp[i][j]=1;
                else if(obstacleGrid[i][j]==1)  dp[i][j]=0;
                else{
                    int up=0, left=0;
                    if(i>0) up= dp[i-1][j];
                    if(j>0) left= dp[i][j-1];

                    dp[i][j]= up + left;
                }
            }
        }
        return dp[m-1][n-1];
    }
};

// -----Approach 2: Space Optimisation ------------------------------------------------------------

/*
    Problem Link: https://leetcode.com/problems/unique-paths-ii/
    
    Time: 3 ms (Beats 79.88%), Space: 7.8 MB (Beats 51.10%)       
*/

// both ways in space optimisation similar to tabulation have nearly same running time and memory
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m= obstacleGrid.size();
        int n= obstacleGrid[0].size();
        vector<int> prev(n, 0);

        if(obstacleGrid[0][0]==1 || obstacleGrid[m-1][n-1]==1)  return 0;

        for(int i=0; i<m; i++){
            vector<int> curr(n, 0);
            for(int j=0; j<n; j++){
                if(i == 0 && j == 0)    curr[j]=1;
                else if(obstacleGrid[i][j]==1)  curr[j]=0;
                else{
                    int up=0, left=0;
                    if(i>0) up= prev[j];
                    if(j>0) left= curr[j-1];

                    curr[j]= up + left;
                }
            }
            prev= curr;
        }
        return prev[n-1];
    }
};

