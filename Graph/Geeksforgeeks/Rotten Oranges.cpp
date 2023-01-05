/*
    Problem Link: https://practice.geeksforgeeks.org/problems/rotten-oranges2536/1
*/

class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int n= grid.size();
        int m= grid[0].size();
        queue<pair<pair<int,int>, int>> q;
        // {{r,c},t} will be the queue pattern
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int cnt= 0, cntIn= 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1)   cntIn++;
                
                if(grid[i][j]==2){
                    q.push({{i,j}, 0});
                    vis[i][j]=2;
                }
            }
        }
        int tmx=0;
        while(!q.empty()){
            int row= q.front().first.first;
            int col= q.front().first.second;
            int t= q.front().second;
            q.pop();
            tmx= max(tmx, t);
            
            int delrow[]={-1,0,1,0};
            int delcol[]={0,1,0,-1};
            for(int i=0; i<4; i++){
                int nrow= row + delrow[i];
                int ncol= col + delcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1 && vis[nrow][ncol] !=2){
                    q.push({{nrow, ncol}, t+1});
                    cnt++;
                    vis[nrow][ncol]=2; // to make sure it is never visited twice
                }
            }
        }
        if(cnt != cntIn) return -1;
  
        return tmx;
    }
};