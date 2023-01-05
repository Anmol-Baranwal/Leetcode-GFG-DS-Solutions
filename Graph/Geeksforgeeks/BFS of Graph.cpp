/*
    Problem Link: https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1
*/

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        queue<int> q;
        q.push(0);
        vector<int> vis(V, 0);
        vis[0]=1;
        vector<int> ans;
        while(!q.empty()){
            int node= q.front();
            q.pop();
            ans.push_back(node);
            for(auto it: adj[node]){
                if(!vis[it]){
                    vis[it]=1;
                    q.push(it);
                }
            }
        }
        return ans;
    }
};