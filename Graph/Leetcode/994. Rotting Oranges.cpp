/*
    Problem Link: https://leetcode.com/problems/rotting-oranges/
    
    Time: 4 ms (Beats 91.33%), Space: 13.4 MB (Beats 21.36%)
*/

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n= grid.size();
        int m= grid[0].size();
        queue<pair<pair<int,int>, int>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int cntIn= 0, cnt= 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1)   cntIn++;

                else if(grid[i][j]==2){
                    q.push({{i, j}, 0});
                    vis[i][j]= 1;
                }
            }
        }
        int timeMx= 0;
        while(!q.empty()){
            int row= q.front().first.first;
            int col= q.front().first.second;
            int t= q.front().second;
            q.pop();

            timeMx= max(t, timeMx);
            int dr[]={-1,0,1,0};
            int dc[]={0,1,0,-1};
            for(int i=0; i<4; i++){
                int nrow= row + dr[i];
                int ncol= col + dc[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]==1){
                    q.push({{nrow, ncol}, t + 1});
                    vis[nrow][ncol]= 1;
                    cnt++;
                }
            }
        }
        if(cnt != cntIn)    return -1;  // fresh orange & no of times they are reached in BFS

        return timeMx;
    }
};