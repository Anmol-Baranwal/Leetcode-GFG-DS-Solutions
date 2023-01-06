/*
    Problem Link: https://leetcode.com/problems/network-delay-time/description/
    
    Time: 287 ms (Beats 29.71%), Space: 43.5 MB (Beats 44.24%)
*/

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<pair<int,int>> adj[n+1]; // 1 based indexing
        // make adjacency list
        for(auto it: times){
            adj[it[0]].push_back({it[1], it[2]});
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, k});

        vector<int> dist(n+1, 1e9);
        dist[k]= 0;     // initialize 0 as min distance to K itself

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

        int ans = *max_element(dist.begin() + 1, dist.end());   // start from 1 based on indexing
        if(ans == 1e9)  return -1;

        return ans;
    }
};