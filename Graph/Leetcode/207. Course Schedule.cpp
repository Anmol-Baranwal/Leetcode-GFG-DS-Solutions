/*
    Problem Link: https://leetcode.com/problems/course-schedule
    
    Time: 31 ms (Beats 63.24%), Space: 13.6 MB (Beats 73.66%)
*/

class Solution {
public:
    bool canFinish(int V, vector<vector<int>>& prerequisites) {
        vector<int> adj[V];
        for(auto it: prerequisites){
            adj[it[1]].push_back(it[0]);
        }
        int indegree[V];
        for(int i=0;i<V;i++)    indegree[i]=0; 
        for(int i=0;i<V;i++){
            for(auto adjNode: adj[i]){
                indegree[adjNode]++;
            }
        }

        queue<int> q;
        for(int i=0;i<V;i++){
            if(indegree[i]==0)  q.push(i);
        }
        vector<int> ans;
        while(!q.empty()){
            int node= q.front();
            q.pop();
            ans.push_back(node);
            for(auto adjNode: adj[node]){
                indegree[adjNode]--;
                if(indegree[adjNode]==0)    q.push(adjNode);
            }
        }
        if(ans.size()==V)   return true;
        return false;
    }
};
