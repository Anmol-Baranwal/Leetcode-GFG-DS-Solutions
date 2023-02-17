// -----Approach 1: Memoization (TLE) -------------------------------------------------------

/*
    Problem Link: https://leetcode.com/problems/longest-common-subsequence/
*/

// Time Limit Exceeded

class Solution {
private:
    int sol(int i, int j, vector<vector<int>>& dp, string text1, string text2){
        if(i == 0 || j == 0)    return 0;

        if(dp[i][j] != -1)  return dp[i][j];

        if(text1[i-1] == text2[j-1])    return 1 + sol(i-1, j-1, dp, text1, text2);

        return dp[i][j] = max( sol(i-1, j, dp, text1, text2), sol(i, j-1, dp, text1, text2) );
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n= text1.size();
        int m= text2.size();

        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));  // i will be treated as i-1 for the recurrence matching case

        return sol(n, m, dp, text1, text2);
    }
};

// -----Approach 2: Tabulation ------------------------------------------------------------

/*
    Problem Link: https://leetcode.com/problems/longest-common-subsequence/
    
    Time: 57 ms (Beats 20.69%), Space: 18.8 MB (Beats 44.4%)
*/

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n= text1.size();
        int m= text2.size();

        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));  // i will be treated as i-1 for the recurrence matching case

        for(int i=0; i<=n; i++) dp[i][0]= 0;
        for(int j=0; j<=m; j++) dp[0][j]= 0;    // on splitting the sequence, j can have values from 0 to m : making the base case

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(text1[i-1] == text2[j-1])    dp[i][j]= 1 + dp[i-1][j-1];

                else    dp[i][j] = max( dp[i-1][j], dp[i][j-1] );
            }
        }

        return dp[n][m];
    }
};

// -----Approach 3: Space Optimization ------------------------------------------------------------

/*
    Problem Link: https://leetcode.com/problems/longest-common-subsequence/
    
    Time: 30 ms (Beats 76.5%), Space: 6.5 MB (Beats 95.67%)
*/

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n= text1.size();
        int m= text2.size();

        vector<int> prev(m+1, 0), curr(m+1, 0);  

        for(int j=0; j<=m; j++) prev[j]= 0;    

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(text1[i-1] == text2[j-1])    curr[j]= 1 + prev[j-1];

                else    curr[j] = max( prev[j], curr[j-1] );
            }
            prev= curr;
        }

        return prev[m];
    }
};