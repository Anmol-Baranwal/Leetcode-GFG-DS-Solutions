/*
    Problem Link: https://leetcode.com/problems/course-schedule-ii
    
    Time: 58 ms (Beats 40.8%), Space: 13.4 MB (Beats 95.29%)
*/

class Solution {
private:
    int dfs(int node, int col, vector<int>& color, vector<vector<int>>& graph){
        color[node]=col;
        for(auto adjNode: graph[node]){
            if(color[adjNode]==-1){
                if(dfs(adjNode, !col, color, graph)==false) return false;
            }
            else if(color[adjNode]==col)    return false;
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int V= graph.size();
        vector<int> color(V,-1);
        for(int i=0;i<V;i++){
            if(color[i]==-1){
                if(dfs(i, 0, color, graph)==false)    return false;
            }
        }
        return true;
    }
};