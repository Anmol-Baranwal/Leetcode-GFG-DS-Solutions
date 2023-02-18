/*
    Problem Link: https://practice.geeksforgeeks.org/problems/longest-palindromic-subsequence-1612327878/1
*/


// -----Approach: Space Optimization ------------------------------------------------------------

class Solution{
  public:
    int longestPalinSubseq(string A) {
        
        int n= A.size();

        string B= A;
        reverse(A.begin(), A.end());      
        // longest palindromic subsequence will be the longest common subsequence of string A & reverse of string A i.e. B

        int m= B.size();

        vector<int> prev(m+1, 0), curr(m+1, 0);  

        for(int j=0; j<=m; j++) prev[j]= 0;    

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(A[i-1] == B[j-1])    curr[j]= 1 + prev[j-1];

                else    curr[j] = max( prev[j], curr[j-1] );
            }
            prev= curr;
        }

        return prev[m];
    }
};