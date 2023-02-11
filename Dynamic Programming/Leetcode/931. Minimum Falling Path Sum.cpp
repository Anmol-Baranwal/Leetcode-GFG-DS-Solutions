// -----Approach 1: Memoization ------------------------------------------------------------

/*
    Problem Link: https://leetcode.com/problems/minimum-falling-path-sum/
    
    Time: 15 ms (Beats 84.82%), Space: 10.4 MB (Beats 20.86%)
*/

class Solution {
private:
    int sol(int i, int j, vector<vector<int>>& dp, vector<vector<int>>& matrix){
        if(j<0 || j>=matrix[0].size())   return 1e9;
        if(i == 0)  return matrix[0][j];

        if(dp[i][j] != -1)  return dp[i][j];
        int up= matrix[i][j] + sol(i-1, j, dp, matrix);
        int ld= matrix[i][j] + sol(i-1, j-1, dp, matrix);
        int rd= matrix[i][j] + sol(i-1, j+1, dp, matrix);

        return dp[i][j]= min(up, min(ld, rd));
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n= matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));

        int mi= 1e9;
        for(int j=0; j<n; j++){
            mi= min(mi, sol(n-1, j, dp, matrix));
        }
        return mi;
    }
};

// -----Approach 2: Tabulation ------------------------------------------------------------

/*
    Problem Link: https://leetcode.com/problems/minimum-falling-path-sum/
    
    Time: 18 ms (Beats 68.26%), Space: 10.4 MB (Beats 6.68%)
*/

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n= matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for(int j=0; j<n; j++){
            dp[0][j]= matrix[0][j];     // base cases
        }

        for(int i=1; i<n; i++){     // all the cases for 0th row has been covered
            for(int j=0; j<n; j++){
                int up= matrix[i][j] + dp[i-1][j];

                int ld= matrix[i][j];
                if(j-1 >= 0)    ld+= dp[i-1][j-1];    // checks for boundary condition
                else    ld+= 1e9;

                int rd= matrix[i][j];
                if(j+1<n)   rd+= dp[i-1][j+1];
                else    rd+= 1e9;

                dp[i][j]= min(up, min(ld, rd));

            }
        }   

        int mi= 1e9;
        for(int j=0; j<n; j++){
            mi= min(mi, dp[n-1][j]);
        }
        return mi;
    }
};

// -----Approach 3: Space Optimization ------------------------------------------------------------

/*
    Problem Link: https://leetcode.com/problems/minimum-falling-path-sum/
    
    Time: 15 ms (Beats 84.82%), Space: 9.9 MB (Beats 49.36%)
*/

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n= matrix.size();
        vector<int> prev(n, 0), curr(n, 0);

        for(int j=0; j<n; j++){
            prev[j]= matrix[0][j];     
        }

        for(int i=1; i<n; i++){     
            for(int j=0; j<n; j++){
                int up= matrix[i][j] + prev[j];

                int ld= matrix[i][j];
                if(j-1 >= 0)    ld+= prev[j-1];   
                else    ld+= 1e9;

                int rd= matrix[i][j];
                if(j+1<n)   rd+= prev[j+1];
                else    rd+= 1e9;

                curr[j]= min(up, min(ld, rd));

            }
            prev= curr;
        }   

        int mi= 1e9;
        for(int j=0; j<n; j++){
            mi= min(mi, prev[j]);
        }
        return mi;
    }
};
