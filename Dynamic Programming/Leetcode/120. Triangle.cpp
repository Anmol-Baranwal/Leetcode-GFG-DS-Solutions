// -----Approach 1: Memoization ------------------------------------------------------------

/*
    Problem Link: https://leetcode.com/problems/triangle/
    
    Time: 6 ms (Beats 73.54%), Space: 9.1 MB (Beats 12.28%)
*/

class Solution {
private:
    int sol(int i, int j, vector<vector<int>>& dp, vector<vector<int>>& triangle){
        int n= triangle.size();
        if(i==n-1)  return triangle[n-1][j];

        if(dp[i][j] != -1)  return dp[i][j];
        int down= triangle[i][j] + sol(i+1, j, dp, triangle);
        int diag= triangle[i][j] + sol(i+1, j+1, dp, triangle);

        return dp[i][j]= min(down, diag);
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n= triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));  // n*n vector
        return sol(0, 0, dp, triangle);
    }
};

// -----Approach 2: Tabulation ------------------------------------------------------------

/*
    Problem Link: https://leetcode.com/problems/triangle/
    
    Time: 3 ms (Beats 97.45%), Space: 9.1 MB (Beats 35.89%)
*/

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n= triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));  // n*n vector
        
        for(int j=0; j<n; j++){
            dp[n-1][j]= triangle[n-1][j];      // if i=2-> j=0,1,2  , if i=1-> j=0,1 ....
        }
        // base cases over
        for(int i=n-2; i>=0; i--){
            for(int j=i; j>=0; j--){
                int down= triangle[i][j] + dp[i+1][j];
                int diag= triangle[i][j] + dp[i+1][j+1];

                dp[i][j]= min(down, diag);
            }
        }
        return dp[0][0];
    }
};

// -----Approach 3: Space Optimization ------------------------------------------------------------

/*
    Problem Link: https://leetcode.com/problems/triangle/
    
    Time: 11 ms (Beats 29.81%), Space: 8.7 MB (Beats 81.59%)
*/

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n= triangle.size();
        vector<int> after(n, 0), curr(n, 0);
        
        for(int j=0; j<n; j++){
            after[j]= triangle[n-1][j];      // if i=2-> j=0,1,2  , if i=1-> j=0,1 ....
        }
        // base cases over
        for(int i=n-2; i>=0; i--){
            for(int j=i; j>=0; j--){
                int down= triangle[i][j] + after[j];
                int diag= triangle[i][j] + after[j+1];

                curr[j]= min(down, diag);
            }
            after= curr;
        }
        return after[0];
    }
};
