/*
    Problem Link: https://practice.geeksforgeeks.org/problems/number-of-enclaves/1
*/

class Solution {
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        int n= grid.size();
        int m= grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<int,int>> q;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(i==0 || i==n-1 || j==0 || j==m-1){
                    if(grid[i][j]==1){
                        q.push({i, j});
                        vis[i][j]=1;
                    }
                }
            }
        }
        
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        while(!q.empty()){
            int row= q.front().first;
            int col= q.front().second;
            q.pop();
            
            for(int i=0; i<4; i++){
                int nrow= row + dr[i];
                int ncol= col + dc[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]==1){
                    q.push({nrow, ncol});
                    vis[nrow][ncol]=1;
                }
            }
        }
        
        int cnt=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1 && !vis[i][j]) cnt++;
            }
        }
        return cnt;
    }
};