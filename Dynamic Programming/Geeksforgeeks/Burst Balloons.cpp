/*
    Problem Link: https://practice.geeksforgeeks.org/problems/burst-balloons/1
*/

// -----Approach 1: Tabulation ------------------------------------------------------------

class Solution {
public:
    int maxCoins(int N, vector<int> &arr) {
        
        int n= arr.size();
        vector<vector<int>> dp(n+2, vector<int>(n+2, 0));  // n+2 due to idx+1
        
        arr.insert(arr.begin(), 1);
        arr.push_back(1);

        for(int i=n; i>=1; i--){
            for(int j=1; j<=n; j++){
                if(i > j)   continue;

                int mx= -1e9;
                for(int idx=i; idx<=j; idx++){
                    int cost= arr[i-1] * arr[idx] * arr[j+1] + dp[i][idx-1] + dp[idx+1][j];

                    mx= max(mx, cost);
                }
                dp[i][j]= mx;
            }
        }

        return dp[1][n];
        
    }
};