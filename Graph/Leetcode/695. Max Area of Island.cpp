/*
    Problem Link: https://leetcode.com/problems/max-area-of-island/
    
    Time: 28 ms (Beats 39.38%), Space: 24 MB (Beats 39.73%)
*/

class Solution {
private:
    int dfs(int row, int col, vector<vector<int>>& vis, vector<vector<int>>& grid, int& cnt){
        vis[row][col]=1;
        int n= grid.size();
        int m= grid[0].size();

        int dr[] = {-1, 0, +1, 0};
        int dc[] = {0, 1, 0, -1};
        cnt++;
        for(int i=0; i<4; i++){
            int nrow= row+dr[i];
            int ncol= col+dc[i];
            if(nrow>=0 && nrow<n && ncol<m && ncol>=0 && grid[nrow][ncol]==1 && !vis[nrow][ncol]){
                dfs(nrow, ncol, vis, grid, cnt);
            }
        }
        return cnt;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n= grid.size();
        int m= grid[0].size();
        vector<vector<int>> vis(n, vector<int> (m, 0));
        int mx=0, cnt=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j] && grid[i][j]==1){
                    dfs(i, j, vis, grid, cnt);
                    mx= max(mx, cnt);
                    cnt= 0;
                }
            }
        }
        return mx;
    }
};
