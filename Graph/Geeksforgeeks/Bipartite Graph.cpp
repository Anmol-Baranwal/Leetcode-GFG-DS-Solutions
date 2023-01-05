/*
    Problem Link: https://practice.geeksforgeeks.org/problems/bipartite-graph/1
*/

class Solution {
private:
    bool dfs(int col, int node, int color[], vector<int> adj[]){
        color[node]=col;
        
        for(auto adjNode: adj[node]){
            if(color[adjNode] == -1){
                if(dfs(!col, adjNode, color, adj) == false) return false;
            }
            else if(color[adjNode] == col)   return false;
        }
        return true;
    }
public:
	bool isBipartite(int V, vector<int>adj[]){
	    // using two colors 0 & 1 while -1 for unvisited
	    int color[V];
	    for(int i=0; i<V; i++)  color[i]=-1;    // auto for loop gives wrong ans!!
	    
	    for(int i=0; i<V; i++){
	        if(color[i] == -1){
	            if(dfs(0, i, color, adj) == false)   return false;
	        }
	    }
	    return true;
	}

};