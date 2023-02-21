// -----Approach 1: Tabulation ------------------------------------------------------------

/*
    Problem Link: https://leetcode.com/problems/wildcard-matching/
    
    Time: 86 ms (Beats 44.90%), Space: 27.3 MB (Beats 37.76%)
*/

class Solution {
public:
    bool isMatch(string str, string p) {
        int n= p.size();
        int m= str.size();

        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        dp[0][0]= 1;
        for (int j=1; j<=m; j++)    dp[0][j]= 0;

        for (int i=1; i<=n; i++){
            bool flag = 1;
            for(int ch=1; ch<=i; ch++){
                if(p[ch-1] != '*'){
                    flag= 0;
                    break;
                }
            }
            dp[i][0]= flag;
        }

        for (int i=1; i<=n; i++) {
          for (int j=1; j<=m; j++) {
          
            if (p[i - 1] == str[j - 1] || p[i - 1] == '?')
              dp[i][j]= dp[i - 1][j - 1];

            else if(p[i - 1] == '*')    dp[i][j]= dp[i - 1][j] | dp[i][j - 1];
            else    dp[i][j]= 0;
          }
        }

        return dp[n][m];
    }
};

// -----Approach 2: Space Optimization ------------------------------------------------------------

/*
    Problem Link: https://leetcode.com/problems/wildcard-matching/
    
    Time: 34 ms (Beats 91.21%), Space: 7.3 MB (Beats 84.25%)
*/

class Solution {
public:
    bool isMatch(string str, string p) {
        int n= p.size();
        int m= str.size();

        // Space optimization: imp to implement base case, use dry run
        vector<int> prev(m+1, 0), curr(m+1, 0);
        
        prev[0]= 1;
        for (int j=1; j<=m; j++)    prev[j]= 0;

        for (int i=1; i<=n; i++) {
            
          bool flag = 1;
          for(int ch=1; ch<=i; ch++){
              if(p[ch-1] != '*'){
                  flag= 0;
                  break;
              }
          }
          curr[0]= flag;
          
          // inner for loop for string matching
          for (int j=1; j<=m; j++) {
          
            if (p[i - 1] == str[j - 1] || p[i - 1] == '?')
              curr[j]= prev[j - 1];

            else if(p[i - 1] == '*')    curr[j]= prev[j] | curr[j - 1];
            else    curr[j]= 0;
          }
          prev= curr;
        }

        return prev[m];
    }
};
