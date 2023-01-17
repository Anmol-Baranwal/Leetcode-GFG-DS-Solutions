/*
    Problem Link: https://practice.geeksforgeeks.org/problems/number-of-provinces/1
*/

// Disjoint set template
class DisjointSet
{
    vector<int> rank, parent, size;
        public:
    DisjointSet(int n){
        rank.resize(n+1, 0);
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=1; i<=n; i++){
            parent[i]=i;
            size[i]=1;
        } 
    }

    int findUParent(int node){
        if(node == parent[node])    
            return node;

        return parent[node]= findUParent(parent[node]);
    }

    void unionByRank(int u, int v){
        int ulp_u= findUParent(u);
        int ulp_v= findUParent(v);
        if(ulp_u == ulp_v)  return;
        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u]= ulp_v;
        }
        else if(rank[ulp_v] < rank[ulp_u]){
            parent[ulp_v]= ulp_u;     // smaller to bigger component
        }
        else{
            parent[ulp_v]= ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v){
        int ulp_u= findUParent(u);
        int ulp_v= findUParent(v);
        if(ulp_u == ulp_v)  return;
        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u]= ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else{
            parent[ulp_u]= ulp_v;
            size[ulp_v] += size[ulp_u];
        }
    }
};

// main solution 
class Solution {
  private:
    void dfs(int node, int vis[], vector<int> adjLs[]){
        vis[node]=1;
        for(auto &it: adjLs[node]){
            if(!vis[it]){
                dfs(it, vis, adjLs);
            }
        }
    }
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        DisjointSet ds(V);
        for(int i=0; i<V; i++){
            for(int j=0; j<V; j++){
                if(adj[i][j]==1){
                    // edge between i & j
                    ds.unionBySize(i, j);
                }
            }
        }
        int cnt=0;
        for(int i=0; i<V; i++){
            if(ds.findUParent(i) == i)  cnt++;  
            // we can also use ds.parent[i] if the parent, size.. is declared within public
        }
        return cnt;
        
    }
};