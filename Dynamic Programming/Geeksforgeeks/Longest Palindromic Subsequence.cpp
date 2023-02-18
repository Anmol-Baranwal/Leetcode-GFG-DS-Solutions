/*
    Problem Link: https://practice.geeksforgeeks.org/problems/longest-palindromic-subsequence-1612327878/1
*/

// -----Approach 1: Memoization ------------------------------------------------------------

class Solution{
  private:
    int sol(int i, int j, vector<vector<int>>& dp, string A, string B){
        if(i == 0 || j == 0)    return 0;

        if(dp[i][j] != -1)  return dp[i][j];

        if(A[i-1] == B[j-1])    return 1 + sol(i-1, j-1, dp, A, B);

        return dp[i][j] = max( sol(i-1, j, dp, A, B), sol(i, j-1, dp, A, B) );
    }
  public:
    int longestPalinSubseq(string A) {
        
        int n= A.size();

        string B= A;
        reverse(A.begin(), A.end());      
        // longest palindromic subsequence will be the longest common subsequence of string A & reverse of string A i.e. B

        int m= B.size();

        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));  

        return sol(n, m, dp, A, B);
    }
};

// -----Approach 2: Tabulation ------------------------------------------------------------

class Solution{
  public:
    int longestPalinSubseq(string A) {
        
        int n= A.size();

        string B= A;
        reverse(A.begin(), A.end());      
        // longest palindromic subsequence will be the longest common subsequence of string A & reverse of string A i.e. B

        int m= B.size();

        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));  

        for(int i=0; i<=n; i++) dp[i][0]= 0;
        for(int j=0; j<=m; j++) dp[0][j]= 0;    

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(A[i-1] == B[j-1])    dp[i][j]= 1 + dp[i-1][j-1];

                else    dp[i][j] = max( dp[i-1][j], dp[i][j-1] );
            }
        }

        return dp[n][m];
    }
};

// -----Approach 3: Space Optimization ------------------------------------------------------------

class Solution{
  public:
    int longestPalinSubseq(string A) {
        
        int n= A.size();

        string B= A;
        reverse(A.begin(), A.end());      
        // longest palindromic subsequence will be the longest common subsequence of string A & reverse of string A i.e. B

        int m= B.size();

        vector<int> prev(m+1, 0), curr(m+1, 0);  

        for(int j=0; j<=m; j++) prev[j]= 0;    

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(A[i-1] == B[j-1])    curr[j]= 1 + prev[j-1];

                else    curr[j] = max( prev[j], curr[j-1] );
            }
            prev= curr;
        }

        return prev[m];
    }
};