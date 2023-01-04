/*
    Problem Link: https://leetcode.com/problems/number-of-islands/
    
    Time: 43 ms (Beats 75.48%), Space: 12.2 MB (Beats 86.86%)
*/

class Solution {
private:
    void dfs(int row, int col, vector<vector<char>>& grid){
        int n= grid.size();
        int m= grid[0].size();
        grid[row][col]= '0'; // mark the value to avoid duplicate
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        for (int i=0; i<4; i++) {
            int nrow = row + dr[i];
            int ncol = col + dc[i];
            if (nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]=='1'){
                dfs(nrow, ncol, grid);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        
        int n= grid.size();
        int m= grid[0].size();

        int cnt= 0;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (grid[i][j] == '1') {
                    cnt++;
                    dfs(i, j, grid);
                }
            }
        }
        return cnt;;
    }
};