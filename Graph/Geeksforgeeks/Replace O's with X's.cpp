/*
    Problem Link: https://practice.geeksforgeeks.org/problems/replace-os-with-xs0052/1
*/

class Solution{
private:
    void dfs(int row, int col, vector<vector<int>>& vis, vector<vector<char>>& mat){
        vis[row][col]=1;
        int n= mat.size();
        int m= mat[0].size();
        
        int delrow[]={0, -1, 0, +1}; // -1,0,1,0  dont understand how same thing e.g.
        int delcol[]={1, 0, -1, 0};  // 0,1,0,-1  these comment set giving wrong output 
        for(int i=0; i<4; i++){
            int nrow= row + delrow[i];
            int ncol= col + delcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && mat[nrow][ncol]=='O'){
                dfs(nrow, ncol, vis, mat);
            }
        }
    }
public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // DFS code here
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        // traversing 1st row & last row
        for(int j=0; j<m; j++){
            if(!vis[0][j] && mat[0][j]=='O'){
                dfs(0, j, vis, mat);
            }
            if(!vis[n-1][j] && mat[n-1][j]=='O'){
                dfs(n-1, j, vis, mat);
            }
        }
        
        // traversing 1st and last col
        for(int i=0; i<n; i++){
            if(!vis[i][0] && mat[i][0]=='O'){
                dfs(i, 0, vis, mat);
            }
            if(!vis[i][m-1] && mat[i][m-1]=='O'){
                dfs(i, m-1, vis, mat);
            }
        }
        
        // converting remaining O to X
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j]=='O' && !vis[i][j])   mat[i][j]='X';
            }
        }
        return mat;
    }
};