// -----Approach: Space Optimization ------------------------------------------------------------

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