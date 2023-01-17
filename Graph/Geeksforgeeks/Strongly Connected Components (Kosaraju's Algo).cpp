/*
    Problem Link: https://practice.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1
*/

class Solution
{
    private:
        void dfs(int node, vector<int>& vis, vector<int> adj[], stack<int>& st){
            vis[node]=1;
            for(auto it: adj[node]){
                if(!vis[it]){
                    dfs(it, vis, adj, st);
                }
            }
            st.push(node);
        }

        void dfs2(int node, vector<int> adjT[], vector<int>& vis){
            vis[node]=1;
            for(auto it: adjT[node]){
                if(!vis[it]){
                    dfs2(it, adjT, vis);
            }
            }
        }
        
	public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<int> adj[])
    {
        //code here
        vector<int> vis(V, 0);
        stack<int> st;
        // step 1 (storing based on the finishing time)
        for(int i=0; i<V; i++){
            if(!vis[i]){
                dfs(i, vis, adj, st);
            }
        }
        // step 2 (transpose)
        vector<int> adjT[V];
        for(int i=0; i<V; i++){
            vis[i]=0;
            for(auto it: adj[i]){
                // converting i-->it  to  it-->i
                adjT[it].push_back(i);
            }
        }
        
        int scc=0;
        while(!st.empty()){
            int node= st.top();
            st.pop();
            if(!vis[node]){
                scc++;
                dfs2(node, adjT, vis);
            }
        }
        
        return scc;
    }
};
