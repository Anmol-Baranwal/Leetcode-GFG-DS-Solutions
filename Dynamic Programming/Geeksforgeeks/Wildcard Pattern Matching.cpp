/*
    Problem Link: https://practice.geeksforgeeks.org/problems/wildcard-pattern-matching/1
*/

// -----Approach 1: Memoization ------------------------------------------------------------

class Solution{
  private:
    int sol(int i, int j, vector<vector<int>> &dp, string pattern, string str){
        
        if(i==0 && j==0) return 1;
        if(i==0 && j>0) return 0;
        if(j==0 && i>0) {
            
            for(int ch=1; ch<=i; ch++){
                if(pattern[ch-1] != '*')
                    return 0;
                return 1;
            }
        }
        
        if(dp[i][j] != -1) return dp[i][j];
        
        if(pattern[i-1] == str[j-1] || pattern[i-1] == '?') return dp[i][j]= sol(i-1, j-1, dp, pattern, str);

        if(pattern[i-1] == '*'){
            return dp[i][j]= sol(i, j-1, dp, pattern, str) | sol(i-1, j, dp, pattern, str);
        }
        else return dp[i][j]= 0;
    }
  public:
/*You are required to complete this method*/
    int wildCard(string pattern, string str)
    {
        int n= pattern.length();
        int m= str.length();
        
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        
        return sol(n, m, dp, pattern, str);
    }
};

// -----Approach 2: Tabulation ------------------------------------------------------------

class Solution{
  public:
/*You are required to complete this method*/
    int wildCard(string pattern, string str)
    {
        int n= pattern.size();
        int m= str.size();

        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        dp[0][0]= 1;
        for (int j=1; j<=m; j++)    dp[0][j]= 0;

        for (int i=1; i<=n; i++){
            bool flag = 1;
            for(int ch=1; ch<=i; ch++){
                if(pattern[ch-1] != '*'){
                    flag= 0;
                    break;
                }
            }
            dp[i][0]= flag;
        }

        for (int i=1; i<=n; i++) {
          for (int j=1; j<=m; j++) {
          
            if (pattern[i - 1] == str[j - 1] || pattern[i - 1] == '?')
              dp[i][j]= dp[i - 1][j - 1];

            else if(pattern[i - 1] == '*')    dp[i][j]= dp[i - 1][j] | dp[i][j - 1];
            else    dp[i][j]= 0;
          }
        }

        return dp[n][m]; 
    }
};

// -----Approach 3: Space Optimization ------------------------------------------------------------

class Solution{
  public:
/*You are required to complete this method*/
    int wildCard(string pattern, string str)
    {
        int n= pattern.size();
        int m= str.size();

        // Space optimization: very tough to implement, use dry run
        vector<int> prev(m+1, 0), curr(m+1, 0);
        
        prev[0]= 1;
        for (int j=1; j<=m; j++)    prev[j]= 0;

        for (int i=1; i<=n; i++) {
            
          bool flag = 1;
          for(int ch=1; ch<=i; ch++){
              if(pattern[ch-1] != '*'){
                  flag= 0;
                  break;
              }
          }
          curr[0]= flag;
          
          // inner for loop for string matching
          for (int j=1; j<=m; j++) {
          
            if (pattern[i - 1] == str[j - 1] || pattern[i - 1] == '?')
              curr[j]= prev[j - 1];

            else if(pattern[i - 1] == '*')    curr[j]= prev[j] | curr[j - 1];
            else    curr[j]= 0;
          }
          prev= curr;
        }

        return prev[m]; 
    }
};