// -----Approach 1: Memoization ------------------------------------------------------------

/*
    Problem Link: https://leetcode.com/problems/unique-paths/
    
    Time: 4 ms (Beats 24.60%), Space: 6.5 MB (Beats 53.17%)
*/

class Solution {
private:
    int cnt(int i, int j, vector<vector<int>>& dp){
        if(i==0 && j==0)    return 1;
        if(i<0 || j<0)  return 0;   

        if(dp[i][j] != -1)  return dp[i][j];
        return dp[i][j]= cnt(i-1, j, dp) + cnt(i, j-1, dp); 
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return cnt(m-1, n-1, dp);
    }
};

// -----Approach 2: Tabulation ------------------------------------------------------------

/*
    Problem Link: https://leetcode.com/problems/unique-paths/
    
    Time: 3 ms (Beats 39.78%), Space: 6 MB (Beats 73.65%)
*/

class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[m][n];

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i == 0 && j == 0)    dp[i][j]=1;
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

// -----Approach 3: Space Optimisation (with most efficient running time) ------------------------------------------------------------

/*
    Problem Link: https://leetcode.com/problems/unique-paths/
    
    Time: 0 ms (Beats 100%), Space: 6.2 MB (Beats 66.35%)
*/

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> prev(n, 0);

        for(int i=0; i<m; i++){
            vector<int> curr(n, 0);
            for(int j=0; j<n; j++){
                if(i == 0 && j == 0)    curr[j]=1;
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
