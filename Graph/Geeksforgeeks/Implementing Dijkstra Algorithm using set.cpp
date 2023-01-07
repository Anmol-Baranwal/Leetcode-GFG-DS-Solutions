/*
    Problem Link: https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1
*/

class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        set<pair<int,int>> st; 
        vector<int> dist(V, 1e9);    
        dist[S]= 0;
        st.insert({0, S});
        
        while(!st.empty()){
            auto it= *(st.begin());
            int dis= it.first;
            int node= it.second;
            st.erase(it);
            
            for(auto it: adj[node]){
                int adjNode= it[0];
                int wt= it[1];
                
                if(dis + wt < dist[adjNode]){
                    dist[adjNode]= dis + wt;
                    st.insert({dist[adjNode], adjNode});
                }
            }
        }
        return dist;
    }
};