/*
    Problem Link: https://leetcode.com/problems/number-of-enclaves/
    
    Time: 89 ms (Beats 64.26%), Space: 27.6 MB (Beats 81.5%)
*/

class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n= grid.size();
        int m= grid[0].size();

        queue<pair<int,int>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(i == n-1 || i == 0 || j == 0 || j == m-1){
                    if(grid[i][j]==1){
                        q.push({i, j});
                        vis[i][j]=1;
                    }
                }
            }
        }

        while(!q.empty()){
            int row= q.front().first;
            int col= q.front().second;
            q.pop();

            int dr[]={-1,0,1,0};
            int dc[]={0,1,0,-1};
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