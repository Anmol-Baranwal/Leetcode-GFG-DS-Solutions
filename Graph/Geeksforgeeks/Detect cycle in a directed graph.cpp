/*
    Problem Link: https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1
*/

class Solution {
  private:
    bool dfs(int node, int vis[], vector<int> adj[]){
        vis[node]= 2;
        for(auto adjNode: adj[node]){
            if(!vis[adjNode]){
                if(dfs(adjNode, vis, adj)) return true;
            }
            else if(vis[adjNode]==2)    return true;
        }
        
        vis[node]= 1;
        
        return false;
    }
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        int vis[V] = {0};
        // int pathVis[V] = {0};
        
        for(int i=0; i<V; i++){
            if(!vis[i]){
                if(dfs(i, vis, adj) == true)   return true;
            }
        }
        return false;
    }
};