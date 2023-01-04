/*
    Problem Link: https://leetcode.com/problems/critical-connections-in-a-network/
    
    Time: 702 ms (Beats 68.84%), Space: 173.3 MB (Beats 80.83%)
*/

class Solution {
private:
    int timer=1;
    void dfs(int node, int parent, vector<int>& vis, int tin[], int low[], 
            vector<int> adj[], vector<vector<int>>& ans){
        vis[node] = 1;
        tin[node] = low[node] = timer;
        timer++;
        for(auto it: adj[node]){
            if(it == parent)    continue;
            if(!vis[it]){
                dfs(it, node, vis, tin, low, adj, ans);
                low[node]= min(low[node], low[it]);
                if(low[it] > tin[node]){
                    ans.push_back({it, node});  // check the logic using dry run of a graph
                }
            } else {
                low[node]= min(low[node], tin[it]);
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        // making adjacency list
        vector<int> adj[n];
        for(auto it: connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> vis(n, 0); // to check whether nodes are visited before
        int tin[n];
        int low[n];
        vector<vector<int>> ans;
        dfs(0, -1, vis, tin, low, adj, ans);
        return ans;
    }
};