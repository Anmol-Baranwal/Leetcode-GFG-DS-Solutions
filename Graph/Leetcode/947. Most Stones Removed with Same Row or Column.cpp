/*
    Problem Link: https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/
    
    Time: 48 ms (Beats 96.24%), Space: 21.4 MB (Beats 17.87%)
*/

// Disjoint Set class to use unionBySize & finding ultimate parent of a node
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

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int maxRow= 0;
        int maxCol= 0;
        for(auto it: stones){
            maxRow= max(maxRow, it[0]);
            maxCol= max(maxCol, it[1]);
        }
        
        DisjointSet ds(maxRow + maxCol + 1); // extra 1 may not be needed   (total nodes will be: rows + cols)
        unordered_map<int,int> stoneNodes;
        for(auto it: stones){
            int nodeRow= it[0];
            int nodeCol= it[1] + maxRow + 1;
            ds.unionBySize(nodeRow, nodeCol);   // using union by size in Disjoint Set (you can use rank as well)
            stoneNodes[nodeRow]=1;
            stoneNodes[nodeCol]=1;
        }
        int cnt=0;
        for(auto it: stoneNodes){
            if(ds.findUParent(it.first) == it.first){   // we just have to use map to count them once for ulParent
                cnt++;
            }
        }
        return stones.size() - cnt;     // n components - 1 stone from each component
    }
};