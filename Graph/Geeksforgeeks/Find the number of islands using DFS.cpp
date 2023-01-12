/*
    Problem Link: https://practice.geeksforgeeks.org/problems/find-the-number-of-islands/1
*/

class Solution {
  private:
    void dfs(int row, int col, vector<vector<char>>& grid){
        int n= grid.size();
        int m= grid[0].size();
        grid[row][col]= '0'; // mark the value to avoid duplicate
        int dir[8][2] = {{1, 1}, {1, -1}, {-1, 1}, {1, 0}, {0, 1}, {-1, -1}, {0, -1}, {-1, 0}};
        for (int i=0; i<8; i++) {
            int nrow = row + dir[i][0];
            int ncol = col + dir[i][1];
            if (nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]=='1'){
                dfs(nrow, ncol, grid);
            }
        }
    }
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
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
        
        return cnt;
    }
};