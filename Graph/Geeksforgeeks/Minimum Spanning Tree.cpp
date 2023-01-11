/*
    Problem Link: https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1  
*/

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // Prims algorithm 
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> vis(V, 0);
        pq.push({0, 0});
        // we dont need to carry parent since we only need to find sum not mst
        int sum=0;
        
        while(!pq.empty()){
            int wt= pq.top().first;
            int node= pq.top().second;
            pq.pop();
            
            if(!vis[node]){
                vis[node]=1;
                sum+= wt;
                
                for(auto it: adj[node]){
                    int adjNode= it[0];
                    int edgeWt= it[1];
                    if(!vis[adjNode]){
                        pq.push({edgeWt, adjNode});
                    }
                }
            }
        }
        
        return sum;
    }
};