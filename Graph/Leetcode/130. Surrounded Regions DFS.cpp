/*
    Problem Link: https://leetcode.com/problems/surrounded-regions/
    
    Time: 15 ms (Beats 79.9), Space: 10 MB (Beats 68.3%)
*/

class Solution {
private:
    void dfs(int row, int col, vector<vector<char>>& vis, vector<vector<char>>& board){
        vis[row][col]=1;
        int n= board.size();
        int m= board[0].size();
        int dr[]= {0, -1, 0, +1};
        int dc[]= {1, 0, -1, 0};
        for(int i=0; i<4; i++){
            int nrow= row + dr[i];
            int ncol= col + dc[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && board[nrow][ncol]=='O'){
                // cout<<"row= "<<nrow<<" col= "<<ncol<<"\n"; // use this to how dfs call goes through based on dr & dc 
                dfs(nrow, ncol, vis, board);
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int n= board.size();
        int m= board[0].size();
        vector<vector<char>> vis(n, vector<char>(m, 0));

        //traverse 1st & last row
        for(int j=0; j<m; j++){
            if(!vis[0][j] && board[0][j]=='O'){
                dfs(0, j, vis, board);
            }
            if(!vis[n-1][j] && board[n-1][j]=='O'){
                dfs(n-1, j, vis, board);
            }
        }

        // traverse 1st and last col
        for(int i=0; i<n; i++){
            if(!vis[i][0] && board[i][0]=='O'){
                dfs(i, 0, vis, board);
            }
            if(!vis[i][m-1] && board[i][m-1]=='O'){
                dfs(i, m-1, vis, board);
            }
        }

        // convert O to X for the remaining nodes
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }
    }
};

