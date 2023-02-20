// -----Approach: Space Optimization ------------------------------------------------------------

/*
    Problem Link: https://leetcode.com/problems/edit-distance/
    
    Time: 9 ms (Beats 81.74%), Space: 6.4 MB (Beats 94.13%)
*/

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n= word1.size();
        int m= word2.size();

        vector<int> prev(m+1, 0), curr(m+1, 0);

            
        for(int j=0; j<=m; j++) prev[j]= j;    

        for(int i=1; i<=n; i++){
            // implementing this case: for(int i=0; i<=n; i++) dp[i][0]= i; 
            // in tabulation, putting ith value in every row at 0th col 
            curr[0]= i;        

            for(int j=1; j<=m; j++){
                if(word1[i-1] == word2[j-1]){
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