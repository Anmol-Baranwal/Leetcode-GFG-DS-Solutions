/*
    Problem Link: https://practice.geeksforgeeks.org/problems/number-of-ways-to-arrive-at-destination/1
*/

class Solution {
  public:
    int countPaths(int n, vector<vector<int>>& roads) {
        // code here
        vector<pair<int,int>> adj[n];
        for(auto it: roads){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        
        vector<int> dist(n, 1e9);
        vector<int> ways(n, 0);
        ways[0]= 1;
        dist[0]= 0;
        int mod= (int)(7 + 1e9);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0, 0});
        while(!pq.empty()){
            int dis= pq.top().first;
            int node= pq.top().second;
            pq.pop();
            
            for(auto it: adj[node]){
                int adjNode= it.first;
                int wt= it.second;
                
                if(wt + dis < dist[adjNode]){
                    dist[adjNode]= dis + wt;
                    pq.push({dist[adjNode], adjNode});
                    ways[adjNode]= ways[node];
                }
                else if(wt + dis == dist[adjNode]){
                    ways[adjNode]= (ways[adjNode] + ways[node]) % mod;
                }
            }
        }
        return ways[n-1]%mod;
    }
};