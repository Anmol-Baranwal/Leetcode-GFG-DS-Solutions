// -----Approach 1: Memoization ------------------------------------------------------------

/*
    Problem Link: https://leetcode.com/problems/palindrome-partitioning-ii/
    
    Time: 544 ms (Beats 25.93%), Space: 6.6 MB (Beats 64.88%)
*/

class Solution {
private:
    bool validPalindrome(int i, int j, string& s){
        while(i < j){
            if(s[i++] != s[j--])    return false;
        }
        return true;
    }
    int sol(int i, string& s, vector<int>& dp){
        int n= s.size();
        if(i == n)  return 0;

        if(dp[i] != -1)     return dp[i];
        if(validPalindrome(i, s.size(), s)) return dp[i]=0;
        int mi= 1e9;
        for(int j=i; j<n; j++){
            if(validPalindrome(i, j, s)){
                int cost= 1 + sol(j+1, s, dp);

                mi= min(mi, cost);
            }
        }
        return dp[i]= mi;
    }
public:
    int minCut(string& s) {
        int n= s.size();
        vector<int> dp(n, -1);

        return sol(0, s, dp) - 1;   // we are also partitioning at the very end, so subtract 1
    }
};

// -----Approach 2: Tabulation ------------------------------------------------------------

/*
    Problem Link: https://leetcode.com/problems/palindrome-partitioning-ii/
    
    Time: 586 ms (Beats 20.60%), Space: 6.5 MB (Beats 89.12%)
*/

class Solution {
private:
    bool validPalindrome(int i, int j, string& s){
        while(i < j){
            if(s[i++] != s[j--])    return false;
        }
        return true;
    }
public:
    int minCut(string& s) {
        int n= s.size();
        vector<int> dp(n+1, 0);

        for(int i=n-1; i>=0; i--){
            int mi= 1e9;
            for(int j=i; j<n; j++){
                if(validPalindrome(i, j, s)){
                    int cost= 1 + dp[j+1];

                    mi= min(mi, cost);
                }
            }
            dp[i]= mi;
        }

        return dp[0] - 1;   // we are also partitioning at the very end, so subtract 1
    }
};