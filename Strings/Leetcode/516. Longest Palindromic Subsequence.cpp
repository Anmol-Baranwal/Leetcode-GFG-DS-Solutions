/*
    Problem Link: https://leetcode.com/problems/longest-palindromic-subsequence/
    
    Time: 159 ms (Beats 48.74%), Space: 6.7 MB (Beats 91.15%)
*/

class Solution {
public:
    int longestPalindromeSubseq(string s1) {
        int n= s1.size();

        string s2= s1;
        reverse(s1.begin(), s1.end());      
        // longest palindromic subsequence will be the longest common subsequence of string s1 & reverse of string s1 i.e. s2

        int m= s2.size();

        vector<int> prev(m+1, 0), curr(m+1, 0);     // using space optimization DP

        for(int j=0; j<=m; j++) prev[j]= 0;    

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(s1[i-1] == s2[j-1])    curr[j]= 1 + prev[j-1];

                else    curr[j] = max( prev[j], curr[j-1] );
            }
            prev= curr;
        }

        return prev[m];
    }
};