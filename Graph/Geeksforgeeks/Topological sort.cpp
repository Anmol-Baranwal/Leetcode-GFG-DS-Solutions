/*
    Problem Link: https://practice.geeksforgeeks.org/problems/topological-sort/1
*/

class Solution
{
    private:
        void dfs(int node, vector<int> &vis, vector<int> adj[], stack<int> &st){
            vis[node]=1;
            for(auto adjNode: adj[node]){
                if(!vis[adjNode]){
                    dfs(adjNode, vis, adj, st);
                }
            }
            st.push(node);
        }
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // DFS code here
	    stack<int> st;
	    vector<int> ans;
	    vector<int> vis(V, 0);
	    for(int i=0; i<V; i++){
	        if(!vis[i]){
	            dfs(i, vis, adj, st);
	        }
	    }
	    
	    while(!st.empty()){
	        ans.push_back(st.top());
	        st.pop();
	    }
	    
	    return ans;
	}
};