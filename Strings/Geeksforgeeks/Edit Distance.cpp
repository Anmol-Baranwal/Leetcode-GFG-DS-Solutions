/*
    Problem Link: https://practice.geeksforgeeks.org/problems/edit-distance3702/1
*/

// -----Approach 1: Memoization ------------------------------------------------------------

class Solution {
  private:
    int sol(int i, int j, vector<vector<int>>& dp, string s, string t){
        if(i == 0)  return j;
        if(j == 0)  return i;

        // to understand the base case, suppose we are at index -1 in horse, and index 1 at ros i.e. o
        // now f(-1, 1) signifies how many operations will it take to convert "" to "ro"
        // this will be 2 insert operations, so we return j+1 where j is pointing to 'o' in ros
        // similary for other case
 
        if(dp[i][j] != -1)  return dp[i][j];
        if(s[i-1] == t[j-1])    return dp[i][j]= sol(i-1, j-1, dp, s, t);

        // insert operation ->  sol(i, j-1)
        // delete operation ->  sol(i-1, j)
        // replace operation -> sol(i-1, j-1)
        // finding minimum of these operations
        int insert= sol(i, j-1, dp, s, t);
        int del= sol(i-1, j, dp, s, t);
        int replace= sol(i-1, j-1, dp, s, t);

        return dp[i][j]= 1 + min(insert, min(del, replace));
    }
  public:
    int editDistance(string s, string t) {
        // Code here
        int n= s.size();
        int m= t.size();

        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));

        return sol(n, m, dp, s, t);
    }
};

// -----Approach 2: Tabulation ------------------------------------------------------------

class Solution {
  public:
    int editDistance(string s, string t) {
        // Code here
        int n= s.size();
        int m= t.size();

        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        for(int i=0; i<=n; i++) dp[i][0]= i;    // explained in memoization
        for(int j=0; j<=m; j++) dp[0][j]= j;    // just convert as usual

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(s[i-1] == t[j-1]){
                    dp[i][j]= dp[i-1][j-1];
                }
                else{
                    dp[i][j]= 1 + min(dp[i][j-1], min(dp[i-1][j], dp[i-1][j-1]));
                    // insert operation ->  dp[i][j-1]
                    // delete operation ->  dp[i-1][j]
                    // replace operation -> dp[i-1][j-1]
                }
            }
        }
        return dp[n][m];
    }
};

// -----Approach 3: Space Optimization ------------------------------------------------------------

class Solution {
  public:
    int editDistance(string s, string t) {
        // Code here
        int n= s.size();
        int m= t.size();

        vector<int> prev(m+1, 0), curr(m+1, 0);

            
        for(int j=0; j<=m; j++) prev[j]= j;    

        for(int i=1; i<=n; i++){
            // implementing this case: for(int i=0; i<=n; i++) dp[i][0]= i; 
            // in tabulation, putting ith value in every row at 0th col 
            curr[0]= i;        

            for(int j=1; j<=m; j++){
                if(s[i-1] == t[j-1]){
                    curr[j]= prev[j-1];
                }
                else{
                    curr[j]= 1 + min(curr[j-1], min(prev[j], prev[j-1]));
                }
            }
            prev= curr;
        }
        return prev[m];
    }
};