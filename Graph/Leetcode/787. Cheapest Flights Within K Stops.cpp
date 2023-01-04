/*
    Problem Link: https://leetcode.com/problems/cheapest-flights-within-k-stops/
    
    Time: 53 ms (Beats 41.39%), Space: 13.7 MB (Beats 41.42%)
*/

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];
        for(auto it: flights){
            adj[it[0]].push_back({it[1], it[2]});
        }
        queue<pair<int, pair<int,int>>> q;
        q.push({0, {src, 0}});  // {stops, {node, dist}}
        vector<int> dist(n, 1e9);
        dist[src]=0;

        while(!q.empty()){
            int stops= q.front().first;
            int node= q.front().second.first;
            int dis= q.front().second.second;
            q.pop();

            for(auto it: adj[node]){
                int wt= it.second;
                int adjNode= it.first;

                if(stops > k)   continue;
                if( (dis + wt < dist[adjNode]) && (stops <= k) ){
                    dist[adjNode]= dis + wt;
                    q.push({stops + 1, {adjNode, dis + wt}});
                }
            }
        }

        if(dist[dst] == 1e9) return -1;
        return dist[dst];
    }
};