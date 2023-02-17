/*
    Problem Link: https://practice.geeksforgeeks.org/problems/longest-common-subsequence-1587115620/1
*/

// -----Approach 1: Memoization ------------------------------------------------------------

class Solution
{
    private:
    int sol(int i, int j, vector<vector<int>>& dp, string s1, string s2){
        if(i == 0 || j == 0)    return 0;

        if(dp[i][j] != -1)  return dp[i][j];

        if(s1[i-1] == s2[j-1])    return 1 + sol(i-1, j-1, dp, s1, s2);

        return dp[i][j] = max( sol(i-1, j, dp, s1, s2), sol(i, j-1, dp, s1, s2) );
    }
    public:
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int x, int y, string s1, string s2)
    {
        // your code here
        int n= s1.size();
        int m= s2.size();

        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));  // i will be treated as i-1 for the recurrence matching case

        return sol(n, m, dp, s1, s2);
    }
};

// -----Approach 2: Tabulation ------------------------------------------------------------

class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int x, int y, string s1, string s2)
    {
        // your code here
        int n= s1.size();
        int m= s2.size();

        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));  // i will be treated as i-1 for the recurrence matching case

        for(int i=0; i<=n; i++) dp[i][0]= 0;
        for(int j=0; j<=m; j++) dp[0][j]= 0;    // on splitting the sequence, j can have values from 0 to m : making the base case

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(s1[i-1] == s2[j-1])    dp[i][j]= 1 + dp[i-1][j-1];

                else    dp[i][j] = max( dp[i-1][j], dp[i][j-1] );
            }
        }

        return dp[n][m];
    }
};

// -----Approach 3: Space Optimization ------------------------------------------------------------

class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int x, int y, string s1, string s2)
    {
        // your code here
        int n= s1.size();
        int m= s2.size();

        vector<int> prev(m+1, 0), curr(m+1, 0); 

        for(int j=0; j<=m; j++) prev[j]= 0; 

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(s1[i-1] == s2[j-1])    curr[j]= 1 + prev[j-1];

                else    curr[j] = max( prev[j], curr[j-1] );
            }
            prev= curr;
        }

        return prev[m];
    }
};