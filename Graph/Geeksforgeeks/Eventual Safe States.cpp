/*
    Problem Link: https://practice.geeksforgeeks.org/problems/eventual-safe-states/1
*/

class Solution {
  private:
    bool dfs(int node, vector<int> &vis, vector<int> &pathVis, vector<int> &check, vector<int> adj[]){
        vis[node]= 1;
        pathVis[node]= 1;
        check[node]= 0;
        
        for(auto adjNode: adj[node]){
            if(!vis[adjNode]){
                if(dfs(adjNode, vis, pathVis, check, adj)){
                    check[node]= 0;
                    return true;
                }
            }
            else if(pathVis[adjNode]){      // this will trigger the true condition in dfs
                check[node]= 0;
                return true;    
            }
        }
        check[node]= 1;
        pathVis[node]= 0;
        return false;
    }
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        vector<int> vis(V, 0);
        vector<int> pathVis(V, 0);
        vector<int> check(V, 0);
        
        vector<int> ans;
        for(int i=0; i<V; i++){
            if(!vis[i]){
                dfs(i, vis, pathVis, check, adj);
            }
        }
        
        for(int i=0; i<V; i++){
            if(check[i] == 1)   ans.push_back(i);
        }
        
        return ans;
    }
};