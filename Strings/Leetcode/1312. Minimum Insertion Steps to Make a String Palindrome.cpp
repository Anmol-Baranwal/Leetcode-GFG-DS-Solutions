// -----Approach 3: Space Optimization ------------------------------------------------------------

/*
    Problem Link: https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/
    
    Time: 56 ms (Beats 72.14%), Space: 6.6 MB (Beats 99.70%)
*/

class Solution {
private:
    int longestPalindromeSubseq(string s1) {
        int n= s1.size();

        string s2= s1;
        reverse(s1.begin(), s1.end());      
        // longest palindromic subsequence will be the LCS of (s1, reverse string of s1)

        int m= s2.size();

        vector<int> prev(m+1, 0), curr(m+1, 0);  

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
public:
    int minInsertions(string s) {
        return s.size() - longestPalindromeSubseq(s);
    }
};
