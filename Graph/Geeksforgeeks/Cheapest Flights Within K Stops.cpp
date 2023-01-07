/*
    Problem Link: https://practice.geeksforgeeks.org/problems/cheapest-flights-within-k-stops/1
*/

class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int K)  {
        // Code here
        vector<pair<int,int>> adj[n];
        for(auto it: flights){
            adj[it[0]].push_back({it[1], it[2]});
        }
        queue<pair<int, pair<int,int>>> q;  // we do not need priority queue
        q.push({0, {src, 0}});
        vector<int> dist(n, 1e9);
        dist[src]=0;
        
        while(!q.empty()){
            int stops= q.front().first;
            int node= q.front().second.first;
            int cost= q.front().second.second;
            q.pop();
            
            if(stops > K)   continue;
            for(auto it: adj[node]){
                int adjNode= it.first;
                int wt= it.second;
                
                if(wt + cost < dist[adjNode] && stops<=K){
                    dist[adjNode]= cost + wt;
                    q.push({stops + 1, {adjNode, cost + wt}});
                }
            }
        }
        if(dist[dst] == 1e9)    return -1;
        return dist[dst];   // dst is destination
    }
};