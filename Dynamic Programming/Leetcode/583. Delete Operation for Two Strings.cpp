// -----Approach 1: Memoization ------------------------------------------------------------

/*
    Problem Link: https://leetcode.com/problems/delete-operation-for-two-strings/
    
    Time: 1332 ms (Beats 5.4%), Space: 740 MB (Beats 5.4%)
*/

class Solution {
private:
    int sol(int i, int j, vector<vector<int>>& dp, string word1, string word2){
        if(i == 0 || j == 0)    return 0;

        if(dp[i][j] != -1)  return dp[i][j];

        if(word1[i-1] == word2[j-1])    return 1 + sol(i-1, j-1, dp, word1, word2);

        return dp[i][j] = max( sol(i-1, j, dp, word1, word2), sol(i, j-1, dp, word1, word2) );
    }
    int longestCommonSubsequence(string word1, string word2) {
        int n= word1.size();
        int m= word2.size();

        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));  

        return sol(n, m, dp, word1, word2);
    }
public:
    int minDistance(string word1, string word2) {
        // you can use the example to see that the len of deletion operation in one string would be=> len(string) - len(LCS)

        return word1.size() + word2.size() - 2*longestCommonSubsequence(word1, word2);
    }
};

// -----Approach 2: Tabulation ------------------------------------------------------------

/*
    Problem Link: https://leetcode.com/problems/delete-operation-for-two-strings/
    
    Time: 32 ms (Beats 34.4%), Space: 12.3 MB (Beats 40.88%)
*/

class Solution {
private:
    int longestCommonSubsequence(string word1, string word2) {
        int n= word1.size();
        int m= word2.size();

        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));  // i will be treated as i-1 for the recurrence matching case

        for(int i=0; i<=n; i++) dp[i][0]= 0;
        for(int j=0; j<=m; j++) dp[0][j]= 0;    // on splitting the sequence, j can have values from 0 to m : making the base case

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(word1[i-1] == word2[j-1])    dp[i][j]= 1 + dp[i-1][j-1];

                else    dp[i][j] = max( dp[i-1][j], dp[i][j-1] );
            }
        }

        return dp[n][m];
    }
public:
    int minDistance(string word1, string word2) {
        // you can use the example to see that the len of deletion operation in one string would be=> len(string) - len(LCS)

        return word1.size() + word2.size() - 2*longestCommonSubsequence(word1, word2);
    }
};

// -----Approach 3: Space Optimization ------------------------------------------------------------

/*
    Problem Link: https://leetcode.com/problems/delete-operation-for-two-strings/
    
    Time: 15 ms (Beats 82.96%), Space: 6.9 MB (Beats 95.57%)
*/

class Solution {
private:
    int longestCommonSubsequence(string word1, string word2) {
        int n= word1.size();
        int m= word2.size();

         vector<int> prev(m+1, 0), curr(m+1, 0);  

        for(int j=0; j<=m; j++) prev[j]= 0;    

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(word1[i-1] == word2[j-1])    curr[j]= 1 + prev[j-1];

                else    curr[j] = max( prev[j], curr[j-1] );
            }
            prev= curr;
        }

        return prev[m];
    }
public:
    int minDistance(string word1, string word2) {
        // you can use the example to see that the len of deletion operation in one string would be=> len(string) - len(LCS)

        return word1.size() + word2.size() - 2*longestCommonSubsequence(word1, word2);
    }
};