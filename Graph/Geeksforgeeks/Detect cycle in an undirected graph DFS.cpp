/*
    Problem Link: https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1
*/

class Solution {
  // DFS
  private:
    bool dfs(int node, int parent, vector<int>& vis, vector<int> adj[]){
        vis[node]=1;
        for(auto adjNode: adj[node]){
            if(!vis[adjNode]){
                if(dfs(adjNode, node, vis, adj)) return true;   
            }
            else if(adjNode != parent)   return true;
        }
        return false;
    }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> vis(V,0);
        for(int i=0; i<V; i++){
            if(!vis[i]){
                if(dfs(i, -1, vis, adj))    return true;   
            }
        }
        return false;
    }
};