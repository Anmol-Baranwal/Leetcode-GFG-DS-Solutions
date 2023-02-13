// -----Approach 1: Memoization ------------------------------------------------------------

/*
    Problem Link: https://leetcode.com/problems/cherry-pickup-ii/
    
    Time: 156 ms (Beats 47.49%), Space: 17 MB (Beats 58.68%)
*/

class Solution {
private:
    int sol(int i, int j1, int j2, vector<vector<vector<int>>>& dp, vector<vector<int>>& grid){
        int n= grid.size();
        int m= grid[0].size();

        if(j1<0 || j1>=m || j2<0 || j2>=m)  return -1e9;    // since we are calculating maximum, so return very minimum value

        if(i == n-1){           // if we reach last row           
            if(j1 == j2)    return grid[i][j1];         // if both robots are at same cell only add it once
            else    return grid[i][j1] + grid[i][j2];   // if they are at different then we do it for both of them
        }

        if(dp[i][j1][j2] != -1) return dp[i][j1][j2];   // initital value of dp is -1
        int mx= -1e9;
        for(int dr = -1; dr <= 1; dr++){                // -1 to +1 for row & col will cover all the 9 conditions of the directions 
            for(int dc = -1; dc <= 1; dc++){
                int val;

                if(j1 == j2)    val= grid[i][j1] + sol(i+1, j1 + dr, j2 + dc, dp, grid);    // both robots are at same cell
                else    val= grid[i][j1] + grid[i][j2] + sol(i+1, j1 + dr, j2 + dc, dp, grid);

                mx= max(mx, val);       // calculate the max value for storing it in dp
            }
        }
        return dp[i][j1][j2]= mx;       
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n= grid.size();
        int m= grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));  // 3d vector of size n * m * m

        return sol(0, 0, m-1, dp, grid);        // since both robots will move down one row simultaneously, so we store it in one variable: i
    }
};

// -----Approach 2: Tabulation ------------------------------------------------------------

/*
    Problem Link: https://leetcode.com/problems/cherry-pickup-ii/
    
    Time: 256 ms (Beats 23.14%), Space: 16.8 MB (Beats 73.64%)
*/

class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n= grid.size();
        int m= grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, 0)));  // 3d vector of size n * m * m

        for(int j1=0; j1<m; j1++){
            for(int j2=0; j2<m; j2++){

                if(j1 == j2)    dp[n-1][j1][j2]= grid[n-1][j1];         // if both robots are at same cell only add it once in dp
                else    dp[n-1][j1][j2]= grid[n-1][j1] + grid[n-1][j2];   // if they are at different then we add both of them to dp
            }
        } 

        // cases for n-1 has been covered so, we start from n-2
        for(int i=n-2; i>=0; i--){
            for(int j1=0; j1<m; j1++){
                for(int j2=0; j2<m; j2++){
                    int mx= -1e9;

                    for(int dr = -1; dr <= 1; dr++){      // -1 to +1 for row & col will cover all the 9 conditions of the directions 
                        for(int dc = -1; dc <= 1; dc++){
                            int val;

                            if(j1 == j2)    val= grid[i][j1];    // both robots are at same cell
                            else    val= grid[i][j1] + grid[i][j2];

                            if( j1+dr < 0 || j1+dr >=m || j2+dc < 0 || j2+dc >=m )  val+= -1e9;     // boundary cases
                            else    val+= dp[i+1][j1+dr][j2+dc];          // we store using next values calculated

                            mx= max(mx, val);       // calculate the max value for storing it in dp
                        }
                    }
                    dp[i][j1][j2]= mx;
                }
            }
        }
        return dp[0][0][m-1];
    }
};

// -----Approach 3: Space Optimization ------------------------------------------------------------

/*
    Problem Link: https://leetcode.com/problems/cherry-pickup-ii/
    
    Time: 229 ms (Beats 30.40%), Space: 9.3 MB (Beats 92.19%)
*/

class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {

        // Space Optimization: 
        // you must understand how to do this for 2-D DP to 1-D DP
        // since here it is from 3-D DP to 2-D DP

        int n= grid.size();
        int m= grid[0].size();
        vector<vector<int>> after(m, vector<int>(m, 0)), curr(m, vector<int>(m, 0));

        for(int j1=0; j1<m; j1++){
            for(int j2=0; j2<m; j2++){

                if(j1 == j2)    after[j1][j2]= grid[n-1][j1];         // if both robots are at same cell only add it once in dp
                else    after[j1][j2]= grid[n-1][j1] + grid[n-1][j2];   // if they are at different then we add both of them to dp
            }
        } 

        // cases for n-1 has been covered so, we start from n-2
        for(int i=n-2; i>=0; i--){
            for(int j1=0; j1<m; j1++){
                for(int j2=0; j2<m; j2++){
                    int mx= -1e9;

                    for(int dr = -1; dr <= 1; dr++){      // -1 to +1 for row & col will cover all the 9 conditions of the directions 
                        for(int dc = -1; dc <= 1; dc++){
                            int val;

                            if(j1 == j2)    val= grid[i][j1];    // both robots are at same cell
                            else    val= grid[i][j1] + grid[i][j2];

                            if( j1+dr < 0 || j1+dr >=m || j2+dc < 0 || j2+dc >=m )  val+= -1e9;     // boundary cases
                            else    val+= after[j1+dr][j2+dc];          

                            mx= max(mx, val);       // calculate the max value for storing it in dp
                        }
                    }
                    curr[j1][j2]= mx;
                }
            }
            after= curr;    // we only need curr values for calculating next set of values thus storing it in after as a temp values
        }
        return after[0][m-1];
    }
};
