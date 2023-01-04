/*
    Problem Link: https://leetcode.com/problems/course-schedule-ii
    
    Time: 81 ms (Beats 7.17%), Space: 13.7 MB (Beats 28.53%)
*/

class Solution {
private:
    bool bfsCheck(int start, vector<int>& color, int col, vector<vector<int>>& graph){
        queue<int> q;
        q.push(start);
        color[start]=0;
        while(!q.empty()){
            int node= q.front();
            q.pop();

            for(auto adjNode: graph[node]){
                if(color[adjNode]==-1){
                    color[adjNode]= !color[node];
                    q.push(adjNode);
                }
                else if(color[adjNode]==color[node])    return false;
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int V= graph.size();
        vector<int> color(V,-1);
        for(int i=0;i<V;i++){
            if(color[i]==-1){
                if(bfsCheck(i, color, 0, graph)==false)    return false;
            }
        }
        return true;
    }
};