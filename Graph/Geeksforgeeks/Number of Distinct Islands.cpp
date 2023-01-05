/*
    Problem Link: https://practice.geeksforgeeks.org/problems/number-of-distinct-islands/1
*/

class Solution {
  private:
    void dfs(int row, int col, vector<vector<int>>& vis, vector<vector<int>>& grid, 
            vector<pair<int,int>>& vec, int rowB, int colB){
        vis[row][col]=1;
        vec.push_back({row - rowB, col - colB});
        int n= grid.size();
        int m= grid[0].size();
        
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        for(int i=0; i<4; i++){
            int nrow= row + dr[i];
            int ncol= col + dc[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]==1){
                dfs(nrow, ncol, vis, grid, vec, rowB, colB);
            }
        }
    }
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n= grid.size();
        int m= grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        set<vector<pair<int,int>>> st;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j] && grid[i][j]==1){
                    vector<pair<int,int>> vec;
                    dfs(i, j, vis, grid, vec, i, j); // 2nd i & j is for base coordinates
                    st.insert(vec);
                }
            }
        }
        return st.size();
    }
};