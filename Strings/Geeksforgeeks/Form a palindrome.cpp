/*
    Problem Link: https://practice.geeksforgeeks.org/problems/form-a-palindrome1455/1
*/

// -----Approach: Space Optimization ------------------------------------------------------------

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