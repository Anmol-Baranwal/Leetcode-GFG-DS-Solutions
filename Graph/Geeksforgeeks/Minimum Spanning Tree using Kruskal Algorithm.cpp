/*
    Problem Link: https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1
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
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // Kruskal algorithm 
        vector<pair<int,pair<int,int>>> edges;  // {wt, {node, adjNode}}
        for(int i=0; i<V; i++){
            for(auto it: adj[i]){
                int adjNode= it[0];
                int wt= it[1];
                int node=i;
                edges.push_back({wt, {node, adjNode}});
            }
        }
        DisjointSet ds(V);
        sort(edges.begin(), edges.end());
        int miSWt= 0;
        for(auto it: edges){
            int wt= it.first;
            int u= it.second.first;
            int v= it.second.second;
            if(ds.findUParent(u) != ds.findUParent(v)){
                miSWt += wt;
                ds.unionBySize(u, v);
            }
        }
        return miSWt;
    }
};