// -----Approach 1: Memoization ------------------------------------------------------------

/*
    Problem Link: https://leetcode.com/problems/minimum-cost-to-cut-a-stick/
    
    Time: 118 ms (Beats 27.95%), Space: 10.4 MB (Beats 45.20%)
*/

class Solution {
private:
    int sol(int i, int j, vector<int>& cuts, vector<vector<int>>& dp){
        if(i > j)   return 0;

        if(dp[i][j] != -1)  return dp[i][j];

        int mi= 1e9;
        for(int idx=i; idx<=j; idx++){
            int cost= cuts[j+1] - cuts[i-1] + sol(i, idx-1, cuts, dp) + sol(idx+1, j, cuts, dp);

            mi= min(mi, cost);
        }
        return dp[i][j]= mi;
    }
public:
    int minCost(int n, vector<int>& cuts) {
        
        int m= cuts.size();
        vector<vector<int>> dp(m+1, vector<int>(m+1, -1));

        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());

        return sol(1, m, cuts, dp);
    }
};

// -----Approach 2: Tabulation ------------------------------------------------------------

/*
    Problem Link: https://leetcode.com/problems/minimum-cost-to-cut-a-stick/
    
    Time: 71 ms (Beats 71.74%), Space: 10.2 MB (Beats 76.27%)
*/

class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        
        int m= cuts.size();
        vector<vector<int>> dp(m+2, vector<int>(m+2, 0));

        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());

        
        for(int i=m; i>=1; i--){
            for(int j=1; j<=m; j++){
                if(i > j)   continue;

                int mi= 1e9;
                for(int idx=i; idx<=j; idx++){
                    int cost= cuts[j+1] - cuts[i-1] + dp[i][idx-1] + dp[idx+1][j];

                    mi= min(mi, cost);
                }
                dp[i][j]= mi;
            }
        }

        return dp[1][m];
    }
};