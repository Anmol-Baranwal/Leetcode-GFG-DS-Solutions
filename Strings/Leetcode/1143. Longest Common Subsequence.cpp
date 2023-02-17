/*
    Problem Link: https://leetcode.com/problems/longest-common-subsequence/
    
    Time: 30 ms (Beats 76.5%), Space: 6.5 MB (Beats 95.67%)
*/

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n= text1.size();
        int m= text2.size();

        vector<int> prev(m+1, 0), curr(m+1, 0);     // space optimization in DP

        for(int j=0; j<=m; j++) prev[j]= 0;    

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(text1[i-1] == text2[j-1])    curr[j]= 1 + prev[j-1];

                else    curr[j] = max( prev[j], curr[j-1] );
            }
            prev= curr;
        }

        return prev[m];
    }
};