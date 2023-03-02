/*
    Problem Link: https://practice.geeksforgeeks.org/problems/boolean-parenthesization5610/1
*/

// -----Approach 1: Memoization ------------------------------------------------------------

class Solution{
private:
    int mod= 1003;
    int sol(int i, int j, int isTrue, string S, vector<vector<vector<int>>>& dp){
        if(i > j)   return 0;
        
        if(i == j){
            if(isTrue)  return S[i]=='T';
            else    return S[i]=='F';
        }
        
        if(dp[i][j][isTrue] != -1)  return  dp[i][j][isTrue];
        int cnt= 0;
        for(int idx=i+1; idx<=j-1; idx= idx+2){
            int LT= sol(i, idx-1, 1, S, dp);
            int LF= sol(i, idx-1, 0, S, dp);
            int RT= sol(idx+1, j, 1, S, dp);
            int RF= sol(idx+1, j, 0, S, dp);
            
            if(S[idx]=='&'){
                if(isTrue)  cnt= (cnt + (RT * LT));
                else    cnt= (cnt + (LT*RF) + (RT*LF) + (LF*RF));
            }
            else if(S[idx]=='|'){
                if(isTrue)  cnt= (cnt + (LT*RT) + (RT*LF) + (LT*RF) ) ;
                else    cnt= (cnt + (RF * LF) );
            }
            else{   // T^T= F, F^F= F, T^F= T, F^T= T
                if(isTrue)  cnt= (cnt + (LT*RF)  + (RT*LF) ) ;
                else    cnt= (cnt + (LT*RT)  + (LF*RF) ) ;
            }
        }
        return dp[i][j][isTrue]= cnt % mod;
    }
public:
    int countWays(int N, string S){
        vector<vector<vector<int>>> dp(N, vector<vector<int>>(N, vector<int>(2, -1)));
        
        // 2 is for T/F & 1 denotes T while 0 denotes F
        return sol(0, N-1, 1, S, dp);
    }
};

// -----Approach 2: Tabulation ------------------------------------------------------------

// User function Template for C++
class Solution{
    int mod= 1003;
public:
    int countWays(int N, string S){
        vector<vector<vector<int>>> dp(N, vector<vector<int>>(N, vector<int>(2, 0)));
        
        // try to convert from memoization --> if(i==j) ....
        for(int i=0; i<N; i++){
             for(int isTrue=0; isTrue<=1; isTrue++){
                 if( (!isTrue && S[i] == 'F') || (isTrue && S[i] == 'T') ) 
                    dp[i][i][isTrue] = 1;
             } 

        }
        
        for(int i=N-1; i>=0; i--){
            for(int j=i+1; j<N; j++){
                
                if(i > j)   continue;
                
                for(int isTrue=0; isTrue<=1; isTrue++){
                    int cnt= 0;
                    for(int idx=i+1; idx<=j-1; idx= idx+2){
                        int LT= dp[i][idx-1][1];
                        int LF= dp[i][idx-1][0];
                        int RT= dp[idx+1][j][1];
                        int RF= dp[idx+1][j][0];
                        
                        // we can also do this without mod, and use only when storing in dp
                        if(S[idx]=='&'){
                            if(isTrue)  cnt= (cnt + (RT * LT) % mod) % mod;
                            else    cnt= (cnt + (LT*RF) % mod + (RT*LF) % mod + (LF*RF) % mod) % mod;
                        }
                        else if(S[idx]=='|'){   // true can be achieved in 3 ways, while false in 1 way
                            if(isTrue)  cnt= (cnt + (LT*RT) % mod + (RT*LF) % mod + (LT*RF) % mod) % mod;
                            else    cnt= (cnt + (RF * LF) % mod) % mod;
                        }
                        else{   // T^T= F, F^F= F, T^F= T, F^T= T
                            if(isTrue)  cnt= (cnt + (LT*RF) % mod + (RT*LF) % mod) % mod;
                            else    cnt= (cnt + (LT*RT) % mod + (LF*RF) % mod) % mod;
                        }
                    }
                    dp[i][j][isTrue]= cnt % mod;
                }
            }
        }
        
        return dp[0][N-1][1] % mod;
    }
};