/*
    Problem Link: https://practice.geeksforgeeks.org/problems/palindromic-patitioning4845/1
*/

// -----Approach 1: Memoization ------------------------------------------------------------

class Solution{
private:
    bool validPalindrome(int i, int j, string s){
        while(i < j){
            if(s[i] != s[j])    return false;
            i++;
            j--;
        }
        return true;
    }
    int sol(int i, string s, vector<int>& dp){
        int n= s.size();
        if(i == n)  return 0;

        if(dp[i] != -1)     return dp[i];
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
    int palindromicPartition(string s)
    {
        int n= s.size();
        vector<int> dp(n, -1);

        return sol(0, s, dp) - 1;   // we are also partitioning at the very end, so subtract 1
    }
};

// -----Approach 2: Tabulation ------------------------------------------------------------

// User function Template for C++

class Solution{
private:
    bool validPalindrome(int i, int j, string s){
        while(i < j){
            if(s[i] != s[j])    return false;
            i++;
            j--;
        }
        return true;
    }
public:
    int palindromicPartition(string s)
    {
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