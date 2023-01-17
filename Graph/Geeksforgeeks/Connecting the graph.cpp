/*
    Problem Link: https://practice.geeksforgeeks.org/problems/connecting-the-graph/1
*/

// Disjoint Set template
class DisjointSet
{
    public:
    vector<int> rank, parent, size;
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
  public:
    int Solve(int n, vector<vector<int>>& edge) {
        // code here
        DisjointSet ds(n);
        int cntExtraEdges=0;
        for(auto it: edge){
            int u= it[0];
            int v= it[1];
            if(ds.findUParent(u) == ds.findUParent(v)){
                cntExtraEdges++;
            }
            else{
                ds.unionBySize(u, v);
            }
        }
        int cnt=0;
        for(int i=0; i<n; i++){
            if(ds.parent[i] == i)   cnt++;  // parent under public in order to use this directly
        }
        if(cntExtraEdges >= cnt-1)  return cnt-1;
        else    return -1;
    }
};