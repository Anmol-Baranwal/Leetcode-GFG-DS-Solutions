/*
    Problem Link: https://practice.geeksforgeeks.org/problems/alex-travelling/1 
*/

class Solution {
  public:
    int minimumCost(vector<vector<int>>& flights, int n, int k) {
        // code here
        vector<pair<int,int>> adj[n+1]; // 1 based indexing
        for(auto it: flights){
            adj[it[0]].push_back({it[1], it[2]});
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, k});

        vector<int> dist(n+1, 1e9);
        dist[k]= 0;

        while(!pq.empty()){
            int dis= pq.top().first;
            int node= pq.top().second;
            pq.pop();

            for(auto it: adj[node]){
                int adjNode= it.first;
                int wt= it.second;
                
                if(wt + dis < dist[adjNode]){
                    dist[adjNode]= dis + wt;
                    pq.push({dis + wt, adjNode});
                }
            }
        }
        int ans = *max_element(dist.begin() + 1, dist.end());
        if(ans == 1e9)  return -1;

        return ans;
        
    }
};