/*
    Problem Link: https://practice.geeksforgeeks.org/problems/print-adjacency-list-1587115620/1
*/

class Solution {
  public:
    // Function to return the adjacency list for each vertex.
    vector<vector<int>> printGraph(int V, vector<int> adj[]) {
        // Code here
        vector<vector<int>> adjLs(V);
        
        for(int i=0; i<V; i++){
            adjLs[i].push_back(i);
            for(auto j: adj[i]){
                adjLs[i].push_back(j);
            }
        }
        return adjLs;
    }
};
