/*
    Problem Link: https://practice.geeksforgeeks.org/problems/minimum-number-of-deletions-and-insertions0209/1
*/

// -----Approach 1: Memoization ------------------------------------------------------------

class Solution{
	private:
    int sol(int i, int j, vector<vector<int>>& dp, string str1, string str2){
        if(i == 0 || j == 0)    return 0;

        if(dp[i][j] != -1)  return dp[i][j];

        if(str1[i-1] == str2[j-1])    return 1 + sol(i-1, j-1, dp, str1, str2);

        return dp[i][j] = max( sol(i-1, j, dp, str1, str2), sol(i, j-1, dp, str1, str2) );
    }
    int longestCommonSubsequence(string str1, string str2) {
        int n= str1.size();
        int m= str2.size();

        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));  

        return sol(n, m, dp, str1, str2);
    }
	public:
	int minOperations(string str1, string str2) 
	{ 
	    return str1.size() + str2.size() - 2*longestCommonSubsequence(str1, str2);
	} 
};

// -----Approach 2: Tabulation ------------------------------------------------------------

class Solution{
	private:
    int longestCommonSubsequence(string str1, string str2) {
        int n= str1.size();
        int m= str2.size();

        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));  

        for(int i=0; i<=n; i++) dp[i][0]= 0;
        for(int j=0; j<=m; j++) dp[0][j]= 0;   

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(str1[i-1] == str2[j-1])    dp[i][j]= 1 + dp[i-1][j-1];

                else    dp[i][j] = max( dp[i-1][j], dp[i][j-1] );
            }
        }

        return dp[n][m];
    }
	public:
	int minOperations(string str1, string str2) 
	{ 
	    return str1.size() + str2.size() - 2*longestCommonSubsequence(str1, str2);
	    
	} 
};

// -----Approach 3: Space Optimization (Two arrays) ----------------------------------------------------

class Solution{
	private:
    int longestCommonSubsequence(string str1, string str2) {
        int n= str1.size();
        int m= str2.size();

        vector<int> prev(m+1, 0), curr(m+1, 0);  

        for(int j=0; j<=m; j++) prev[j]= 0;    

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(str1[i-1] == str2[j-1])    curr[j]= 1 + prev[j-1];

                else    curr[j] = max( prev[j], curr[j-1] );
            }
            prev= curr;
        }

        return prev[m];
    }
	public:
	int minOperations(string str1, string str2) 
	{ 
	    return str1.size() + str2.size() - 2*longestCommonSubsequence(str1, str2);
	    
	} 
};