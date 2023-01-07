/*
    Problem Link: https://practice.geeksforgeeks.org/problems/path-with-minimum-effort/1
*/

class Solution {
  public:
    int MinimumEffort(vector<vector<int>>& heights) {
        // Dijkstra Algo Code here
        
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>> >, greater<pair<int,pair<int,int>>>> pq;
        
        int n= heights.size();
        int m= heights[0].size();
        vector<vector<int>> diff(n, vector<int>(m, 1e9));
        diff[0][0]= 0;
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        
        pq.push({0, {0, 0}});
        while(!pq.empty()){
            int curr= pq.top().first;
            int r= pq.top().second.first;
            int c= pq.top().second.second;
            pq.pop();
            
            if(r == n-1 && c == m-1)    return curr;
            for(int i=0; i<4; i++){
                int nrow= r + dr[i];
                int ncol= c + dc[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){
                    int effort= max(abs(heights[r][c] - heights[nrow][ncol]), curr);  // main logic
                    if(effort < diff[nrow][ncol]){
                        diff[nrow][ncol]= effort;
                        pq.push({effort, {nrow, ncol}});
                    }
                }
            }
        }
        return 0;
    }
};