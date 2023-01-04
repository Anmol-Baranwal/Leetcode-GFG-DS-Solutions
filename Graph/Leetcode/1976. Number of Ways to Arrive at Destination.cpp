/*
    Problem Link: https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/
    
    Time: 116 ms (Beats 48.8%), Space: 32.5 MB (Beats 79.23%)
*/

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        // Dijkstra algorithm
        typedef long long ll;   // for storing dist
        typedef pair<long long, long long> ppl; // for priority queue
        vector<pair<int,int>> adj[n];
        for(auto it: roads){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        priority_queue<ppl,vector<ppl>,greater<ppl>> pq; 
        pq.push({0, 0}); // {distance, node}
        vector<ll> dist(n, LLONG_MAX);
        vector<int> ways(n, 0);
        dist[0]= 0;
        ways[0]= 1;
        int mod= (int)(1e9 + 7);

        while(!pq.empty()){
            ll dis= pq.top().first;
            int node= pq.top().second;
            pq.pop();

            for(auto it: adj[node]){
                int adjNode= it.first;
                int wt= it.second;

                if(dis + wt < dist[adjNode]){
                    dist[adjNode]= dis + wt;
                    pq.push({dist[adjNode], adjNode});
                    ways[adjNode]= ways[node];
                }
                else if( dis + wt == dist[adjNode]){
                    ways[adjNode]= (ways[node] + ways[adjNode]) % mod;
                }
            }
        }
        return ways[n-1] % mod;
    }
};