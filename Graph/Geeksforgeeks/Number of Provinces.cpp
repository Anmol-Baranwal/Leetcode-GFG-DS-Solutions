/*
    Problem Link: https://practice.geeksforgeeks.org/problems/number-of-provinces/1
*/

class Solution{
    private:
        void dfs(int node, vector<int> adjLS, int vis[]){
            vis[node]=1;
            for(auto &it: adjLS[node]){
                if(!vis[it]){
                    dfs(it, adjLS, vis);
                }
            }
        }
    public:
        int numOfProvinces(vector<vector<int>> adj, int V){
            vector<int> adjLS(V);
            // conversion of adjacency matrix to list
            for(int i=0; i<V; i++){
                for(int j=0; j<V; j++){
                    if(adj[i][j] == 1 && i!=j){
                        adjLS[i].push_back(j);
                        adjLS[j].push_back(i);
                    }
                }
            }
            int vis[V]={0};
            int cnt=0;
            for(int i=0; i<V; i++){
                if(!vis[i]){
                    cnt++; // this will give the answer
                    dfs(i, adjLS, vis);
                }
            }
            return cnt;
        }
}