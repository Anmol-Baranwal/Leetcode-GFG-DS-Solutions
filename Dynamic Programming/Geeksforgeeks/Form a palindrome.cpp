/*
    Problem Link: https://practice.geeksforgeeks.org/problems/form-a-palindrome1455/1
*/

// -----Approach 1: Memoization ------------------------------------------------------------

class Solution{
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
    int countMin(string str){
        return str.size() - longestPalindromeSubseq(str);
    
    }
};

// -----Approach 2: Tabulation ------------------------------------------------------------

class Solution{
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
    int countMin(string str){
        return str.size() - longestPalindromeSubseq(str);
    
    }
};

// -----Approach 3: Space Optimization ------------------------------------------------------------

class Solution{
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
    int countMin(string str){
        return str.size() - longestPalindromeSubseq(str);
    
    }
};