// -----Approach 1: Memoization ------------------------------------------------------------

/*
    Problem Link: https://leetcode.com/problems/distinct-subsequences/
    
    Time: 39 ms (Beats 76.42%), Space: 18.5 MB (Beats 69.21%)
*/

class Solution {
private:
    int sol(int i, int j, vector<vector<int>> &dp, string &s, string &t){
        if(j == 0) return 1;    // this tells that all characters of t has been matched since j has reached the end so we return 1
        if(i == 0) return 0;    // this tells that s has been reached to end so we return 0 as we may have characters left in t

        if(dp[i][j] != -1)  return dp[i][j];
        if(s[i-1] == t[j-1]){
            return dp[i][j]= sol(i-1, j-1, dp, s, t) + sol(i-1, j, dp, s, t);      // we take two cases, including the case where we look for other occurences even if it matches
        }

        return dp[i][j]= sol(i-1, j, dp, s, t);     // we are reducing s and keep searching as current ones are not matching
    }
public:
    int numDistinct(string s, string t) {
        int n= s.size();
        int m= t.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));

        return sol(n, m, dp, s, t);
    }
};

// -----Approach 2: Tabulation ------------------------------------------------------------

/*
    Problem Link: https://leetcode.com/problems/distinct-subsequences/
    
    Time: 46 ms (Beats 63.81%), Space: 18.4 MB (Beats 69.21%)
*/

class Solution {
public:
    int numDistinct(string s, string t) {
        int n= s.size();
        int m= t.size();
        vector<vector<unsigned int>> dp(n+1, vector<unsigned int>(m+1, 0));

        for(int i=0; i<=n; i++) dp[i][0] = 1;       // t has reached end (j in memoization) so we return 1
        
        // we can omit below case as everything is initialised to 0
        // for(int j=1; j<=m; j++) dp[0][j] = 0;       // avoiding j=1 to overwrite the values of 0th col by the prev for loop

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){

                if(s[i-1] == t[j-1]){
                    dp[i][j]= dp[i-1][j-1] + dp[i-1][j];  // we include the case where we look for other occurences even if it matches  
                }
                else{
                    dp[i][j]= dp[i-1][j];   // we are reducing s and keep searching as current ones are not matching
                }
            }
        }

        return dp[n][m];
    }
};

// -----Approach 3: Space Optimization (Two vectors) ------------------------------------------------------------

/*
    Problem Link: https://leetcode.com/problems/distinct-subsequences/
    
    Time: 29 ms (Beats 88.94%), Space: 6.5 MB (Beats 89.66%)
*/

class Solution {
public:
    int numDistinct(string s, string t) {
        int n= s.size();
        int m= t.size();
        vector<unsigned int> prev(m+1), curr(m+1);

        prev[0] = curr[0] = 1;  // put 1 across both vectors at 0th place similar to tabulation base case

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){

                if(s[i-1] == t[j-1]){
                    curr[j]= prev[j-1] + prev[j];   
                }
                else{
                    curr[j]= prev[j];   
                }
            }
            prev= curr;
        }

        return prev[m];
    }
};

// -----Approach 3: Space Optimization (One vector) ------------------------------------------------------------

/*
    Problem Link: https://leetcode.com/problems/distinct-subsequences/
    
    Time: 31 ms (Beats 86.67%), Space: 6.3 MB (Beats 99.47%)
*/

class Solution {
public:
    int numDistinct(string s, string t) {
        int n= s.size();
        int m= t.size();
        vector<unsigned int> prev(m+1);

        prev[0] = 1;  // put 1 across both vectors at 0th place similar to tabulation base case

        for(int i=1; i<=n; i++){

            // very important to traverse from right since we have to use prev values
            // we will overwrite the values if we traverse from left
            for(int j=m; j>=1; j--){    
                if(s[i-1] == t[j-1]){
                    prev[j]= prev[j-1] + prev[j];   // we don't need else case, use dry run
                }
            }
        }

        return prev[m];
    }
};