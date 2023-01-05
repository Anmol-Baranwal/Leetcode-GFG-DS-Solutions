/*
    Problem Link: https://practice.geeksforgeeks.org/problems/distance-of-nearest-cell-having-1-1587115620/1
*/

class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // BFS Code here
	    int n= grid.size();
	    int m= grid[0].size();
	    vector<vector<int>> vis(n, vector<int>(m, 0));
	    vector<vector<int>> dist(n, vector<int>(m, 0));
	    queue<pair<pair<int,int>,int>> q;
	   // {{r,c},dist} will be the pattern
	   for(int i=0; i<n; i++){
	       for(int j=0; j<m; j++){
	           if(grid[i][j]==1){
	               q.push({{i,j}, 0});
	               vis[i][j]=1;
	           }
	       }
	   }
	   
	   while(!q.empty()){
	       int row= q.front().first.first;
	       int col= q.front().first.second;
	       int steps= q.front().second;
	       q.pop();
	       dist[row][col]= steps;
	       
	       int delrow[]={-1,0,1,0};
	       int delcol[]={0,1,0,-1};
	       for(int i=0; i<4; i++){
	           int nrow= row + delrow[i];
	           int ncol= col + delcol[i];
	           if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol]){
	               q.push({{nrow,ncol}, steps+1});
	               vis[nrow][ncol]=1;
	           }
	       }
	   }
	   return dist;
	   
	}
};