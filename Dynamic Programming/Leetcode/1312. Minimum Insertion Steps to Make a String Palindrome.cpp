// -----Approach 1: Memoization (TLE) -------------------------------------------------------

/*
    Problem Link: https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/
*/

// Time Limit Exceeded

class Solution {
private:
    int sol(int i, int j, vector<vector<int>>& dp, string s1, string s2){
        if(i == 0 || j == 0)    return 0;

        if(dp[i][j] != -1)  return dp[i][j];

        if(s1[i-1] == s2[j-1])    return 1 + sol(i-1, j-1, dp, s1, s2);

        return dp[i][j] = max( sol(i-1, j, dp, s1, s2), sol(i, j-1, dp, s1, s2) );
    }
    int longestPalindromeSubseq(string s1) {
        int n= s1.size();

        string s2= s1;
        reverse(s1.begin(), s1.end());      

        int m= s2.size();

        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));  

        return sol(n, m, dp, s1, s2);
    }
public:
    int minInsertions(string s) {
        return s.size() - longestPalindromeSubseq(s);
    }
};

// -----Approach 2: Tabulation ------------------------------------------------------------

/*
    Problem Link: https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/
    
    Time: 100 ms (Beats 37.4%), Space: 28.5 MB (Beats 48.18%)
*/

class Solution {
private:
    int longestPalindromeSubseq(string s1) {
        int n= s1.size();

        string s2= s1;
        reverse(s1.begin(), s1.end());       // longest palindromic subsequence will be the LCS(s1, reverse_string of s1)

        int m= s2.size();

        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));  

        for(int i=0; i<=n; i++) dp[i][0]= 0;
        for(int j=0; j<=m; j++) dp[0][j]= 0;    

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(s1[i-1] == s2[j-1])    dp[i][j]= 1 + dp[i-1][j-1];

                else    dp[i][j] = max( dp[i-1][j], dp[i][j-1] );
            }
        }

        return dp[n][m];
    }
public:
    int minInsertions(string s) {
        return s.size() - longestPalindromeSubseq(s);
    }
};

// -----Approach 3: Space Optimization ------------------------------------------------------------

/*
    Problem Link: https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/
    
    Time: 56 ms (Beats 72.14%), Space: 6.6 MB (Beats 99.70%)
*/

class Solution {
private:
    int longestPalindromeSubseq(string s1) {
        int n= s1.size();

        string s2= s1;
        reverse(s1.begin(), s1.end());      
        // longest palindromic subsequence will be the LCS of (s1, reverse string of s1)

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
public:
    int minInsertions(string s) {
        return s.size() - longestPalindromeSubseq(s);
    }
};
