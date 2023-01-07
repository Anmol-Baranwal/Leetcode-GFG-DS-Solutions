/*
    Problem Link: https://practice.geeksforgeeks.org/problems/shortest-path-in-a-binary-maze-1655453161/1
*/

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        // code here
        int n= grid.size();
        int m= grid[0].size();

        queue<pair<pair<int,int>, int>> q;
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        dist[source.first][source.second]= 0;
        q.push({{source.first, source.second}, 0});

        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        if(source.first == destination.first && source.second == destination.second) return 0;
        while(!q.empty()){
            int dis= q.front().second;
            int row= q.front().first.first;
            int col= q.front().first.second;
            q.pop();

            for(int i=0; i<4; i++){
                int nrow= row + dr[i];
                int ncol= col + dc[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1 && dist[nrow][ncol]>dis+1){
                    dist[nrow][ncol]= dis+1;
                    if(nrow == destination.first && ncol == destination.second) return dis + 1;
                    q.push({{nrow, ncol}, dis+1});
                }
            }
        }
        return -1;
    }
};