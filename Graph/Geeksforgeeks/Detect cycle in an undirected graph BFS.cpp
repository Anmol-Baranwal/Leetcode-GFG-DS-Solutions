/*
    Problem Link: https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1
*/

class Solution {
  // BFS
  private:
    bool bfs(int node, vector<bool>& vis, vector<int> adj[]){
        vis[node]=1;
        queue<pair<int,int>> q;
        q.push({node, -1});
        while(!q.empty()){
            int node= q.front().first;
            int parent= q.front().second;
            q.pop();
            
            for(auto adjNode: adj[node]){
                if(!vis[adjNode]){
                    vis[adjNode]=1;
                    q.push({adjNode, node});
                }
                else if(adjNode != parent)  return true;
            }
        }
        return false;
    }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> vis(V,0);
        for(int i=0; i<V; i++){
            if(!vis[i]){
                if(bfs(i, vis, adj)) return true;   
            }
        }
        return false;
    }
};