/*
    Problem Link: https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1
*/

class Solution {
  private:
    void dfs(int node, vector<int>& vis, vector<int> adj[], vector<int>& ans){
        vis[node]=1;
        ans.push_back(node);
        
        for(auto it: adj[node]){
            if(!vis[it]){
                dfs(it, vis, adj, ans);
            }
        }
    }
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> vis(V, 0);
        vector<int> ans; // size is not equal to V
        dfs(0, vis, adj, ans);
        
        return ans;
    }
};