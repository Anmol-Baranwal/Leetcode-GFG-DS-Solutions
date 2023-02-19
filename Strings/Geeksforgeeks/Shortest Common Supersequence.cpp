/*
    Problem Link: https://practice.geeksforgeeks.org/problems/shortest-common-supersequence0322/1
*/

// -----Approach 1: Tabulation ------------------------------------------------------------

class Solution
{
    private:
    int longestCommonSubsequence(string X, string Y) {
        int n= X.size();
        int m= Y.size();

        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));  

        for(int i=0; i<=n; i++) dp[i][0]= 0;
        for(int j=0; j<=m; j++) dp[0][j]= 0;    

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(X[i-1] == Y[j-1])    dp[i][j]= 1 + dp[i-1][j-1];

                else    dp[i][j] = max( dp[i-1][j], dp[i][j-1] );
            }
        }

        return dp[n][m];
    }
    public:
    //Function to find length of shortest common supersequence of two strings.
    int shortestCommonSupersequence(string X, string Y, int m, int n)
    {
        return m + n - longestCommonSubsequence(X, Y);      // use dry run to get the intuition
    }
};

// -----Approach 2: Space Optimization ------------------------------------------------------------

class Solution
{
    private:
    int longestCommonSubsequence(string X, string Y) {
        int n= X.size();
        int m= Y.size();

        vector<int> prev(m+1, 0), curr(m+1, 0);  

        for(int j=0; j<=m; j++) prev[j]= 0;    

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(X[i-1] == Y[j-1])    curr[j]= 1 + prev[j-1];

                else    curr[j] = max( prev[j], curr[j-1] );
            }
            prev= curr;
        }

        return prev[m];
    }
    public:
    int shortestCommonSupersequence(string X, string Y, int m, int n)
    {
        return m + n - longestCommonSubsequence(X, Y);      
    }
};