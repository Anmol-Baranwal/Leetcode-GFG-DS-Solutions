/*
    Problem Link: https://practice.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1
*/

class Solution {
  public:
    /*  Function to implement Bellman Ford
    *   edges: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        // Code here
        vector<int> dist(V, 1e8);   // 1e8 represents non-reachable node
        dist[S]= 0;
        for(int i=0; i<V-1; i++){   // n-1 iterations
            for(auto it: edges){
                int u= it[0];
                int v= it[1];
                int wt= it[2];
                
                if( (dist[u] != 1e8) && (dist[u] + wt < dist[v]) ){
                    dist[v]= dist[u] + wt;
                }
            }
        }
        
        // nth iteration to check negative cycle
        for(auto it: edges){
            int u= it[0];
            int v= it[1];
            int wt= it[2];
            
            if( (dist[u] != 1e8) && (dist[u] + wt < dist[v]) ){
                // negative cycle exists
                return {-1};
            }
        }
        
        // negative cycle doesn't exist
        return dist;
    }
};